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
}

void GameObjectPlayer::PriorityUpdate(const float _delta_time)
{
    state_ = GameObjectPlayer::State::IDLE;
    if (input_manager_->GetKey('W'))
    {
        sprite_component_->MovePosition(0, -speed_ * _delta_time);
        sprite_rev_component_->MovePosition(0, -speed_ * _delta_time);
        state_ = GameObjectPlayer::State::RUN;
    }
    else if (input_manager_->GetKey('S'))
    {
        sprite_component_->MovePosition(0, speed_ * _delta_time);
        sprite_rev_component_->MovePosition(0, speed_ * _delta_time);
        state_ = GameObjectPlayer::State::RUN;
    }
    if (input_manager_->GetKey('A'))
    {
        sprite_component_->MovePosition(-speed_ * _delta_time, 0);
        sprite_rev_component_->MovePosition(-speed_ * _delta_time, 0);
        state_ = GameObjectPlayer::State::RUN;
        reversed_ = true;
    }
    else if (input_manager_->GetKey('D'))
    {
        sprite_component_->MovePosition(speed_ * _delta_time, 0);
        sprite_rev_component_->MovePosition(speed_ * _delta_time, 0);
        state_ = GameObjectPlayer::State::RUN;
        reversed_ = false;
    }
}

void GameObjectPlayer::Update(const float _delta_time)
{
    sprite_component_->UpdateAnimation(_delta_time);
    sprite_rev_component_->UpdateAnimation(_delta_time);
}

void GameObjectPlayer::LateUpdate(const float _delta_time)
{
    auto [pos_x, pos_y] = sprite_component_->GetPosition();
    scroll_y = pos_y ;
    scroll_x = pos_x ;

    render_manager_->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
}

void GameObjectPlayer::Render(HDC _hDC)
{
    if (reversed_)
        sprite_rev_component_->Render(_hDC, static_cast<int32_t>(state_));
    else
        sprite_component_->Render(_hDC, static_cast<int32_t>(state_));
}
