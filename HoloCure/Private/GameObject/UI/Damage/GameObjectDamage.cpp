#include "pch.h"
#include "GameObject/UI/Damage/GameObjectDamage.h"

void GameObjectDamage::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{L"../Resources/Ui/damage_font.png", L"damage_ui", 10, 14,1});

}

void GameObjectDamage::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
    if (life_time_ >= 1.f)
        is_dead_ = true;
}

void GameObjectDamage::Update(const float _delta_time)
{
    sprite_component_->MovePosition(0.f, -20.f * _delta_time);
}

void GameObjectDamage::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock() )
    {
        render_manager->AddRenderGroup(RenderGroup::DAMAGE, shared_from_this());
    }
    
}

void GameObjectDamage::Render(HDC _hDC)
{
    sprite_component_->Render(_hDC, damage_amount_);
}

void GameObjectDamage::SetPosition(const float _x, const float _y)
{
    IGameObject::SetPosition(_x, _y);
    sprite_component_->SetPosition(_x, _y);
}

void GameObjectDamage::PoolToLive()
{
    IGameObject::PoolToLive();
}

void GameObjectDamage::LiveToPool()
{
}
