#include "pch.h"
#include "GameObject/Player/GameObjectPlayer.h"

#include "Component/Sprite/ComponentSprite.h"

void GameObjectPlayer::Initialize(const GameObjectDesc& _desc)
{
    input_manager_ = ServiceLocator::getInstance().get<ManagerInput>();
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/watson.png", L"player", 128, 128});
}

void GameObjectPlayer::PriorityUpdate(const float _delta_time)
{
    if (input_manager_->GetKey('W'))
    {
        sprite_component_->MovePosition(0, -speed_ * _delta_time);
    }
    if (input_manager_->GetKey('S'))
    {
        sprite_component_->MovePosition(0, speed_ * _delta_time);
    }
    if (input_manager_->GetKey('A'))
    {
        sprite_component_->MovePosition(-speed_ * _delta_time, 0);
    }
    if (input_manager_->GetKey('D'))
    {
        sprite_component_->MovePosition(speed_ * _delta_time, 0);
    }
}

void GameObjectPlayer::Update(const float _delta_time)
{
}

void GameObjectPlayer::LateUpdate(const float _delta_time)
{
    render_manager_->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
}

void GameObjectPlayer::Render(HDC _hDC)
{
    sprite_component_->Render(_hDC);
}
