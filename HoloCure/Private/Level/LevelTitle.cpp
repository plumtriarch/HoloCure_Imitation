#include "pch.h"
#include "./Level/LevelTitle.h"
#include "GameObject/Player/GameObjectPlayer.h"
void LevelTitle::Initialize(const LevelDesc& _desc)
{
    object_manager_ = ServiceLocator::getInstance().get<ManagerObject>();
    object_manager_->AddGameObjectToPool(L"player", GameObjectPlayer::CreateGameObject<GameObjectPlayer>
        (GameObjectPlayer::GameObjectPlayerDesc{}));
    object_manager_->MovePoolToLive(L"player");
}

void LevelTitle::PriorityUpdate(const float _delta_time)
{
}

void LevelTitle::Update(const float _delta_time)
{
}

void LevelTitle::LateUpdate(const float _delta_time)
{
}

void LevelTitle::LoadingResources()
{
}

void LevelTitle::LevelStart()
{
    
}
