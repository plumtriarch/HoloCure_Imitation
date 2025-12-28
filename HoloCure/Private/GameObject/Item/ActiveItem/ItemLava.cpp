#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemLava.h"

void ItemLava::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/lava.png", L"lava",30.f,29});
    speed_ = 600.f;
    end_life_time_ = 2.9f;
}

void ItemLava::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemLava::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    sprite_component_->UpdateAnimation(_delta_time);
    if (sprite_component_->GetAnimationEnd())
        is_dead_ = true;
    if (attack_done_ == true)
    {
        attack_done_ = false;
        collider_component_->SetSensor();
    }
    if (floor(life_time_/0.3f) > phase)
    {
        phase++;
        attack_done_ = true;
        collider_component_->UnSetSensor();
    }
    
    
}

void ItemLava::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemLava::Render(HDC _hDC)
{
    // IActiveItem::Render(_hDC);
    sprite_component_->Render(_hDC, 0,collider_component_.get());
}

void ItemLava::PoolToLive()
{
    IActiveItem::PoolToLive();
    sprite_component_->ResetAnimation();
    phase = 0;
    collider_component_->SetPosition(static_cast<float>(scroll_x) + (rand() % g_window_size_x) - g_window_size_x/2,
        static_cast<float>(scroll_y)  + (rand() % g_window_size_y) - g_window_size_y/2);
    collider_component_->SetSensor();
}

void ItemLava::LiveToPool()
{
    IActiveItem::LiveToPool();
    collider_component_->UnSetSensor();
}

void ItemLava::SetPosition(const float _x, const float _y)
{
    IActiveItem::SetPosition(_x, _y);
}
