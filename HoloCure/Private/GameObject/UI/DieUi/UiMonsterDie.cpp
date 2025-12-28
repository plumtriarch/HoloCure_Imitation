#include "pch.h"
#include "GameObject/UI/DieUi/UiMonsterDie.h"

void UiMonsterDie::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>(ComponentSprite::ComponentSpriteDesc
        {L"../Resources/Ui/monster_die.png", L"monster_die", 48, 48,10});
}

void UiMonsterDie::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void UiMonsterDie::Update(const float _delta_time)
{
    sprite_component_->UpdateAnimation(_delta_time);
    if (sprite_component_->GetAnimationEnd())
        is_dead_ = true;
}

void UiMonsterDie::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock())
    {
        render_manager->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
    }
}

void UiMonsterDie::Render(HDC _hDC)
{
    sprite_component_->RenderAnimation(_hDC);
}

void UiMonsterDie::SetPosition(const float _x, const float _y)
{
    IGameObject::SetPosition(_x, _y);
    sprite_component_->SetPosition(_x,_y);
}

void UiMonsterDie::SetTemp(const int32_t _temp)
{
    IGameObject::SetTemp(_temp);
}

void UiMonsterDie::PoolToLive()
{
    IGameObject::PoolToLive();
    sprite_component_->ResetAnimation();
}

void UiMonsterDie::LiveToPool()
{
}
