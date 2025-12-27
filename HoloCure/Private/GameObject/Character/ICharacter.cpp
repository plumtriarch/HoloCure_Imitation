#include "pch.h"
#include "GameObject/Character/ICharacter.h"

void ICharacter::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void ICharacter::Attacked(int _damage)
{
    current_hp_ -= _damage;
    if (current_hp_ < 0)
        current_hp_ = 0;
}

void ICharacter::PoolToLive()
{
    IGameObject::PoolToLive();
}
