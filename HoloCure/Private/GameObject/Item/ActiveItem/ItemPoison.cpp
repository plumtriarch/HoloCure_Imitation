#include "pch.h"
#include "GameObject/Item/ActiveItem/ItemPoison.h"

void ItemPoison::Initialize(const GameObjectDesc& _desc)
{
    // IActiveItem::Initialize(_desc);
}

void ItemPoison::PriorityUpdate(const float _delta_time)
{
    IActiveItem::PriorityUpdate(_delta_time);
}

void ItemPoison::Update(const float _delta_time)
{
    IActiveItem::Update(_delta_time);
}

void ItemPoison::LateUpdate(const float _delta_time)
{
    IActiveItem::LateUpdate(_delta_time);
}

void ItemPoison::Render(HDC _hDC)
{
    IActiveItem::Render(_hDC);
}

void ItemPoison::PoolToLive()
{
    IActiveItem::PoolToLive();
}

void ItemPoison::LiveToPool()
{
    IActiveItem::LiveToPool();
}

void ItemPoison::SetPosition(const float _x, const float _y)
{
    IActiveItem::SetPosition(_x, _y);
}
