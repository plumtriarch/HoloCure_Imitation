#include "pch.h"
#include "./Level/LevelGamePlay.h"
#include "GameObject/Player/GameObjectPlayer.h"
void LevelGamePlay::Initialize(const LevelDesc& _desc)
{
}

void LevelGamePlay::PriorityUpdate(const float _delta_time)
{
}

void LevelGamePlay::Update(const float _delta_time)
{
}

void LevelGamePlay::LateUpdate(const float _delta_time)
{
}

void LevelGamePlay::LoadingResources()
{
    shared_ptr<ManagerObject> object_manager_ = ServiceLocator::getInstance().get<ManagerObject>(); 
    object_manager_->AddGameObjectToPool(L"player", GameObjectPlayer::CreateGameObject<GameObjectPlayer>
        (GameObjectPlayer::GameObjectPlayerDesc{}));
    is_loaded_ = true;
}

void LevelGamePlay::LevelStart()
{
    shared_ptr<ManagerObject> object_manager_ = ServiceLocator::getInstance().get<ManagerObject>(); 
    object_manager_->MovePoolToLive(L"player");
}
