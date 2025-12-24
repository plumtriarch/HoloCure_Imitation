#include "pch.h"
#include "./Level/LevelGamePlay.h"
#include "GameObject/Player/GameObjectPlayer.h"
#include "GameObject/Monster/GameObjectMonster.h"
#include "GameObject/Map/GameObjectTile.h"
#include "GameObject/Item/ActiveItem/ItemBullet.h"
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
    object_manager_->AddGameObjectToPool(L"monster", GameObjectMonster::CreateGameObject<GameObjectMonster>
        (GameObjectMonster::GameObjectMonsterDesc{}));
    object_manager_->AddGameObjectToPool(L"map", GameObjectTile::CreateGameObject<GameObjectTile>
        (GameObjectTile::GameObjectTileDesc{}));
    // object_manager_->AddGameObjectToPool(L"bullet", ItemBullet::CreateGameObject<ItemBullet>
    //     (ItemBullet::ItemBulletDesc{}));
    is_loaded_ = true;
}

void LevelGamePlay::LevelStart()
{
    shared_ptr<ManagerObject> object_manager_ = ServiceLocator::getInstance().get<ManagerObject>(); 
    object_manager_->MovePoolToLive(L"player");
    object_manager_->MovePoolToLive(L"monster");
    object_manager_->MovePoolToLive(L"map");
    // object_manager_->MovePoolToLive(L"bullet");

}
