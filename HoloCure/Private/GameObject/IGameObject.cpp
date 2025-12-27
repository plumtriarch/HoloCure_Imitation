#include "pch.h"
#include "./GameObject/IGameObject.h"

void IGameObject::PriorityUpdate(const float _delta_time)
{
    life_time_ += _delta_time;
}

void IGameObject::PoolToLive()
{
    life_time_ = 0.f;
}
