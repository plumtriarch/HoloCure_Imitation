#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemAx.h"

void ItemAx::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/ax.png", L"ax",20.f,8});
    speed_ = 200.f;
    end_life_time_ = 5.f;
}

void ItemAx::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
    
    angle_ += _delta_time* 360.f;
    
    double angleRad = angle_ * 3.14 / 180.0;
    direction_[0] = cos(angleRad);
    direction_[1] = sin(angleRad);
}

void ItemAx::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    if (life_time_ > end_life_time_)
        is_dead_ = true;
    sprite_component_->UpdateAnimation(_delta_time);
    collider_component_->MoveDir(direction_[0] * speed_ * (1+5* life_time_/end_life_time_),
        direction_[1] * speed_* (1+5 * life_time_/end_life_time_));
}

void ItemAx::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemAx::Render(HDC _hDC)
{
    // IActiveItem::Render(_hDC);
    sprite_component_->Render(_hDC, 0,collider_component_.get());
}

void ItemAx::PoolToLive()
{
    IActiveItem::PoolToLive();
    collider_component_->SetPosition(static_cast<float>(scroll_x), static_cast<float>(scroll_y));
    collider_component_->SetSensor();
    angle_ = static_cast<float>(rand() % 360);
}

void ItemAx::LiveToPool()
{
    IActiveItem::LiveToPool();
    collider_component_->UnSetSensor();
}

void ItemAx::SetPosition(const float _x, const float _y)
{
    IActiveItem::SetPosition(_x, _y);
}
