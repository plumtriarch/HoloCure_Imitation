#include "pch.h"
#include "GameObject/Player/GameObjectPlayer.h"



void GameObjectPlayer::Initialize(const GameObjectDesc& _desc)
{
    input_manager_ = ServiceLocator::getInstance().get<ManagerInput>();
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/watson.png", L"player", 128, 128,6});
    sprite_rev_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/watson_rev.png", L"player_rev", 128, 128,6});
    collider_component_ = ComponentCollider::CreateComponent<ComponentCollider>
        (ComponentCollider::ComponentColliderDesc{1,static_cast<int32_t>(CharacterType::PLAYER)
        , static_cast<int32_t>(CharacterType::MONSTER) | static_cast<int32_t>(CharacterType::MONSTER_BULLET)});

    
}

void GameObjectPlayer::PriorityUpdate(const float _delta_time)
{
    state_ = GameObjectPlayer::State::IDLE;
    array<float, 2> move_dir = {0.f,0.f};
    if (input_manager_->GetKey('W'))
    {
        move_dir[1] -= speed_ / _delta_time;
        state_ = GameObjectPlayer::State::RUN;
    }
    else if (input_manager_->GetKey('S'))
    {
        move_dir[1] += speed_ / _delta_time; 
        state_ = GameObjectPlayer::State::RUN;
    }
    if (input_manager_->GetKey('A'))
    {
        move_dir[0] -= speed_ / _delta_time; 
        state_ = GameObjectPlayer::State::RUN;
        reversed_ = true;
    }
    else if (input_manager_->GetKey('D'))
    {
        move_dir[0] += speed_ / _delta_time; 
        state_ = GameObjectPlayer::State::RUN;
        reversed_ = false;
    }
    if (move_dir[0] != 0.f || move_dir[1] != 0.f)
    {
        float length = sqrt(move_dir[0] * move_dir[0] + move_dir[1] * move_dir[1]);
        move_dir[0] /= length;
        move_dir[1] /= length;
    }
    
    collider_component_->MoveDir(move_dir[0] * speed_ / _delta_time, move_dir[1] * speed_/  _delta_time);
}

void GameObjectPlayer::Update(const float _delta_time)
{
    sprite_component_->UpdateAnimation(_delta_time);
    sprite_rev_component_->UpdateAnimation(_delta_time);
}

void GameObjectPlayer::LateUpdate(const float _delta_time)
{
    auto [pos_x, pos_y] = collider_component_->GetPosition();
    scroll_y = static_cast<int32_t>(pos_y);
    scroll_x = static_cast<int32_t>(pos_x);

    render_manager_->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
}

void GameObjectPlayer::Render(HDC _hDC)
{
    if (reversed_)
        sprite_rev_component_->Render(_hDC, static_cast<int32_t>(state_),collider_component_.get());
    else
        sprite_component_->Render(_hDC, static_cast<int32_t>(state_), collider_component_.get());
}

void GameObjectPlayer::PoolToLive()
{
    collider_component_->CreateCollider();
}

void GameObjectPlayer::LiveToPool()
{
    collider_component_->DestroyCollider();
}
