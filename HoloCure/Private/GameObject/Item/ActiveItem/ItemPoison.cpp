#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemPoison.h"

void ItemPoison::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/poison.png", L"poison",70.f,1});
}

void ItemPoison::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemPoison::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    collider_component_->SetPosition(scroll_x,scroll_y);
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

void ItemPoison::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemPoison::Render(HDC _hDC)
{
    // IActiveItem::Render(_hDC);
    sprite_component_->RenderAlpha(_hDC, 0.5,collider_component_.get());
}

void ItemPoison::PoolToLive()
{
    IActiveItem::PoolToLive();
    phase = 0;
    collider_component_->SetPosition(scroll_x,scroll_y);
    collider_component_->SetSensor();
}

void ItemPoison::LiveToPool()
{
    IActiveItem::LiveToPool();
    collider_component_->UnSetSensor();
}

void ItemPoison::SetPosition(const float _x, const float _y)
{
    IActiveItem::SetPosition(_x, _y);
}
