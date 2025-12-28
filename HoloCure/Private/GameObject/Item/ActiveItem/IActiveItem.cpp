#include "pch.h"
#include "GameObject/Item/ActiveItem/IActiveItem.h"

IActiveItem::~IActiveItem()
{
    collider_component_->DestroyCollider();
}

void IActiveItem::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    const auto& desc = static_cast<const IActiveItem::ActiveItemDesc&>(_desc);
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
        (ComponentSprite::ComponentSpriteDesc{desc.path, desc.tag, 128, 128,desc.animation_size});
    collider_component_ = ComponentCollider::CreateComponent<ComponentCollider>
        (ComponentCollider::ComponentColliderDesc{desc.radius,static_cast<int32_t>(CharacterType::PLAYER_BULLET)
        , 0, static_cast<int32_t>(CharacterType::MONSTER), shared_from_this()});
}

void IActiveItem::PriorityUpdate(const float _delta_time)
{
    IItem::PriorityUpdate(_delta_time);
}

void IActiveItem::Update(const float _delta_time)
{
}

void IActiveItem::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock())
    {
        render_manager->AddRenderGroup(RenderGroup::PLAYER_ITEM, shared_from_this());
    }
}

void IActiveItem::Render(HDC _hDC)
{
    sprite_component_->RenderRotate(_hDC, rotated_,collider_component_.get());
}

void IActiveItem::PoolToLive()
{
    IItem::PoolToLive();
    is_dead_ = false;
}

void IActiveItem::LiveToPool()
{

}

void IActiveItem::SetPosition(const float _x, const float _y)
{
    IItem::SetPosition(_x, _y);
    collider_component_->SetPosition(_x,_y);
}
