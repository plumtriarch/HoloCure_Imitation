#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemBullet.h"

void ItemBullet::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/Bullet.png", L"bullet",5.f});
    speed_ = 50.f;
    direction_ = {1.f,0.f};
    life_time_ = 5.f;
    rotated_ = 10.f;
}

void ItemBullet::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemBullet::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    cur_life_time_ -= _delta_time;
    if (cur_life_time_ <= 0.f)
        is_dead_ = true;
    collider_component_->MoveDir(direction_[0] * speed_, direction_[1] * speed_);
}

void ItemBullet::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemBullet::Render(HDC _hDC)
{
    IActiveItem::Render(_hDC);
}

void ItemBullet::PoolToLive()
{
    IActiveItem::PoolToLive();
    collider_component_->SetPosition(static_cast<float>(scroll_x), static_cast<float>(scroll_y));
    collider_component_->SetSensor();
    array<float,2> dir = {0.f,0.f};
    dir[0] = static_cast<float>(mouse_x) - g_window_size_x /2;
    dir[1] = static_cast<float>(mouse_y) - g_window_size_y /2;
    if (dir[0] == 0 && dir[1] == 0)
        dir[0] = 1.f;
    direction_ = dir;
    float length = sqrt(direction_[0] * direction_[0] + direction_[1] * direction_[1]);
    direction_[0] /= length;
    direction_[1] /= length;
    rotated_ = atan2(direction_[1], direction_[0]) * (180.f / 3.141592f);
}

void ItemBullet::LiveToPool()
{
    IActiveItem::LiveToPool();
    collider_component_->UnSetSensor();
}
