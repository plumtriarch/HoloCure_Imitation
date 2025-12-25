#include "pch.h"
#include "GameObject/Monster/GameObjectMonster.h"

GameObjectMonster::~GameObjectMonster()
{
    collider_component_->DestroyCollider();
}

void GameObjectMonster::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/monster.png", L"monster", 128, 128,3});
    sprite_rev_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/monster_rev.png", L"monster_rev", 128, 128,3});
    collider_component_ = ComponentCollider::CreateComponent<ComponentCollider>
        (ComponentCollider::ComponentColliderDesc{10,static_cast<int32_t>(CharacterType::MONSTER)
        , static_cast<int32_t>(CharacterType::MONSTER), static_cast<int32_t>(CharacterType::PLAYER_BULLET) | static_cast<int32_t>(CharacterType::PLAYER)  , shared_from_this()});
}

void GameObjectMonster::PriorityUpdate(const float _delta_time)
{
    array<float, 2> move_dir = {0.f,0.f};
    auto [pos_x, pos_y] = collider_component_->GetPosition();
    move_dir = {static_cast<float>(scroll_x) - pos_x, static_cast<float>(scroll_y) - pos_y};
    
    if (move_dir[0] != 0.f || move_dir[1] != 0.f)
    {
        float length = sqrt(move_dir[0] * move_dir[0] + move_dir[1] * move_dir[1]);
        move_dir[0] /= length;
        move_dir[1] /= length;
    }
    
    collider_component_->MoveDir(move_dir[0] * speed_, move_dir[1] * speed_);
    if (move_dir[0] < 0.f)
        reversed_ = true;
    else if (move_dir[0] > 0.f)
        reversed_ = false;
}

void GameObjectMonster::Update(const float _delta_time)
{
    sprite_component_->UpdateAnimation(_delta_time);
    sprite_rev_component_->UpdateAnimation(_delta_time);
}

void GameObjectMonster::LateUpdate(const float _delta_time)
{
    render_manager_->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
}

void GameObjectMonster::Render(HDC _hDC)
{
    if (reversed_)
        sprite_rev_component_->Render(_hDC, monster_id_,collider_component_.get());
    else
        sprite_component_->Render(_hDC, monster_id_, collider_component_.get());
}

void GameObjectMonster::PoolToLive()
{
    collider_component_->SetContact();
    collider_component_->SetSensor();
}

void GameObjectMonster::LiveToPool()
{
    collider_component_->UnSetContact();
    collider_component_->UnSetSensor();
}
