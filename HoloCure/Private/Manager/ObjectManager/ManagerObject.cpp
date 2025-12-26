#include "pch.h"
#include "Manager/ObjectManager/ManagerObject.h"

void ManagerObject::Initialize(const ManagerDesc& _desc)
{
}

void ManagerObject::AddGameObjectToPool(const wstring& _tag, shared_ptr<IGameObject> _game_object)
{
    objects_pool_[_tag].emplace(move(_game_object));
}

void ManagerObject::MovePoolToLive(const wstring& _tag)
{
    auto it = objects_pool_.find(_tag);
    if (it != objects_pool_.end() && !it->second.empty())
    {
        it->second.front()->PoolToLive();
        objects_live_[_tag].emplace_back(move(it->second.front()));
        it->second.pop();
    }
    else
    {
        cout<<1<<endl;
    }
}

void ManagerObject::ProcessDeadObject()
{
    for (auto &li : objects_live_)
    {
        auto it = li.second.begin();
        while (it !=  li.second.end())
        {
            if ((*it)->IsDead())
            {
                (*it)->LiveToPool();
                objects_pool_[li.first].emplace(move(*it));
                it = li.second.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

void ManagerObject::UpdateObject(const float _delta_time)
{
    // PriorityUpdate
    for (auto &li : objects_live_)
    {
        for (auto obj : li.second)
        {
            obj->PriorityUpdate(_delta_time);
        }
    }
    // Update
    for (auto &li : objects_live_)
    {
        for (auto obj : li.second)
        {
            obj->Update(_delta_time);
        }
    }
    
    // LateUpdate
    for (auto &li : objects_live_)
    {
        for (auto obj : li.second)
        {
            obj->LateUpdate(_delta_time);
        }
    }
}
