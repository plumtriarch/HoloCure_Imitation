#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemMeteor.h"

void ItemMeteor::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/meteor.png", L"meteor",20.f,8});
    speed_ = 600.f;
    end_life_time_ = 5.f;
    direction_ = {-1,1};
    rotated_ = 135;
}

void ItemMeteor::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemMeteor::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    if (life_time_ >= end_life_time_)
        is_dead_ = true;
    sprite_component_->UpdateAnimation(_delta_time);
    collider_component_->MoveDir(direction_[0] * speed_ , direction_[1] * speed_);
}

void ItemMeteor::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemMeteor::Render(HDC _hDC)
{
    IActiveItem::Render(_hDC);
}

void ItemMeteor::PoolToLive()
{
    IActiveItem::PoolToLive();
    collider_component_->SetPosition(static_cast<float>(scroll_x) + (rand() % g_window_size_x)/2*3,
        static_cast<float>(scroll_y)  - g_window_size_y *3/2);
    collider_component_->SetSensor();
}

void ItemMeteor::LiveToPool()
{
    IActiveItem::LiveToPool();
    collider_component_->UnSetSensor();
}
