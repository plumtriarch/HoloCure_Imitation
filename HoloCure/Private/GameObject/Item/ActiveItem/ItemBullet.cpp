#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemBullet.h"

void ItemBullet::Initialize(const GameObjectDesc& _desc)
{
    IActiveItem::Initialize(IActiveItem::ActiveItemDesc{L"../Resources/Item/Bullet.png", L"bullet",5.f});
}

void ItemBullet::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemBullet::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
    
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
}

void ItemBullet::LiveToPool()
{
    IActiveItem::LiveToPool();
}
