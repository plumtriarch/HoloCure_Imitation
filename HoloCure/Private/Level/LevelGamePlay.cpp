#include "pch.h"
#include "./Level/LevelGamePlay.h"
#include "GameObject/Player/GameObjectPlayer.h"
#include "GameObject/Monster/GameObjectMonster.h"
#include "GameObject/Map/GameObjectTile.h"
#include "GameObject/Item/ActiveItem/ItemBullet.h"
#include "GameObject/Item/ActiveItem/ItemAx.h"
#include "GameObject/Item/ActiveItem/ItemStick.h"
#include "GameObject/Item/ActiveItem/ItemLava.h"
#include "GameObject/Item/ActiveItem/ItemMeteor.h"
#include "GameObject/Item/ActiveItem/ItemPoison.h"
#include "GameObject/UI/Damage/GameObjectDamage.h"
#include "GameObject/UI/Arrow/UiArrow.h"
#include "GameObject/UI/DieUi/UiMonsterDie.h"
#include "GameObject/UI/KillCount/UiKillCount.h"
#include "GameObject/UI/Time/UiTime.h"

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
    for (int i =0;i<100;i++)
        object_manager_->AddGameObjectToPool(L"monster", GameObjectMonster::CreateGameObject<GameObjectMonster>
            (GameObjectMonster::GameObjectMonsterDesc{}));
    
    object_manager_->AddGameObjectToPool(L"map", GameObjectTile::CreateGameObject<GameObjectTile>
        (GameObjectTile::GameObjectTileDesc{}));
    for (int i =0;i<20;i++)
        object_manager_->AddGameObjectToPool(L"bullet", ItemBullet::CreateGameObject<ItemBullet>
            (ItemBullet::ItemBulletDesc{}));
    for (int i =0;i<20;i++)
        object_manager_->AddGameObjectToPool(L"ax", ItemAx::CreateGameObject<ItemAx>
            (ItemAx::ItemAxDesc{}));
    for (int i =0;i<20;i++)
        object_manager_->AddGameObjectToPool(L"stick", ItemStick::CreateGameObject<ItemStick>
            (ItemStick::ItemStickDesc{}));
    for (int i =0;i<100;i++)
        object_manager_->AddGameObjectToPool(L"meteor", ItemMeteor::CreateGameObject<ItemMeteor>
            (ItemMeteor::ItemMeteorDesc{}));
    for (int i =0;i<20;i++)
        object_manager_->AddGameObjectToPool(L"lava", ItemLava::CreateGameObject<ItemLava>
            (ItemLava::ItemLavaDesc{}));
    for (int i =0;i<6;i++)
        object_manager_->AddGameObjectToPool(L"posion", ItemPoison::CreateGameObject<ItemPoison>
            (ItemPoison::ItemPoisonDesc{}));
    for (int i =0;i<500;i++)
        object_manager_->AddGameObjectToPool(L"damage", GameObjectDamage::CreateGameObject<GameObjectDamage>
            (GameObjectDamage::GameObjectDamageDesc{}));
    for (int i =0;i<50;i++)
        object_manager_->AddGameObjectToPool(L"monster_die",  UiMonsterDie::CreateGameObject<UiMonsterDie>
            (UiMonsterDie::UiMonsterDieDesc{}));
    object_manager_->AddGameObjectToPool(L"arrow", UiArrow::CreateGameObject<UiArrow>
            (UiArrow::UiArrowDesc{}));
    object_manager_->AddGameObjectToPool(L"kill_count", UiKillCount::CreateGameObject<UiKillCount>
            (UiKillCount::UiKillCountDesc{}));
    object_manager_->AddGameObjectToPool(L"timer", UiTime::CreateGameObject<UiTime>
            (UiTime::UiTimeDesc{}));
    is_loaded_ = true;
}

void LevelGamePlay::LevelStart()
{
    shared_ptr<ManagerObject> object_manager_ = ServiceLocator::getInstance().get<ManagerObject>(); 
    object_manager_->MovePoolToLive(L"player");
    for (int i =0;i<1;i++)
        object_manager_->MovePoolToLive(L"monster");
    object_manager_->MovePoolToLive(L"map");
    object_manager_->MovePoolToLive(L"arrow");
    object_manager_->MovePoolToLive(L"kill_count");
    object_manager_->MovePoolToLive(L"timer");
    // object_manager_->MovePoolToLive(L"bullet");

}
