#include "pch.h"
#include "GameObject/Item/IItem.h"

void IItem::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void IItem::PoolToLive()
{
    IGameObject::PoolToLive();
}
