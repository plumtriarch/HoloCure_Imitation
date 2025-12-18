#include "pch.h"
#include "GameObject/Player/GameObjectPlayer.h"

#include "Component/Sprite/ComponentSprite.h"

void GameObjectPlayer::Initialize(const GameObjectDesc& _desc)
{
    input_manager_ = ServiceLocator::getInstance().get<ManagerInput>();
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Character/watson.png", L"player", 64, 64});
}

void GameObjectPlayer::PriorityUpdate(const float _delta_time)
{
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
