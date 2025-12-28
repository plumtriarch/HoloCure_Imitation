#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemBomb.h"

void ItemBomb::Initialize(const GameObjectDesc& _desc)
{
    // IActiveItem::Initialize(_desc);
}

void ItemBomb::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemBomb::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
}

void ItemBomb::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemBomb::Render(HDC _hDC)
{
    IActiveItem::Render(_hDC);
}

void ItemBomb::PoolToLive()
{
    IActiveItem::PoolToLive();
}

void ItemBomb::LiveToPool()
{
    IActiveItem::LiveToPool();
}

void ItemBomb::SetPosition(const float _x, const float _y)
{
    IActiveItem::SetPosition(_x, _y);
}
