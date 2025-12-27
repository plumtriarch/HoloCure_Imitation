#include "pch.h"
#include "GameObject/Item/ItemSpawner.h"

void ItemSpawner::Initialize(const GameObjectDesc& _desc)
{
    object_manager_ = ServiceLocator::getInstance().get<ManagerObject>();
}

void ItemSpawner::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void ItemSpawner::Update(const float _delta_time)
{
    for (auto &el : item_spawners_)
    {
        
        el.second.first -= _delta_time;
        if (el.second.first <= 0.f)
        {
            el.second.first = el.second.second;
            object_manager_->MovePoolToLive(el.first);
        }
    }
}

void ItemSpawner::PoolToLive()
{
    IGameObject::PoolToLive();
}

void ItemSpawner::AddItemSpawner(const wstring& _item_tag, float _spawn_delay)
{
    item_spawners_[_item_tag] = make_pair(0.5f, _spawn_delay);
}


