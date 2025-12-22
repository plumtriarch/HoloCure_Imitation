#include "pch.h"
#include "Component/Collider/ComponentCollider.h"

void ComponentCollider::Initialize(const ComponentDesc& _desc)
{
    collider_manager_ = ServiceLocator::getInstance().get<ManagerCollider>();
 
    const ComponentColliderDesc& desc = static_cast<const ComponentColliderDesc&>(_desc);
    
    bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2({0.0f, 0.0f});
    
    circle.center = b2Vec2({0.0f, 0.0f});
    circle.radius = desc.radius;
    
    circleShapeDef = b2DefaultShapeDef();
    circleShapeDef.density = 1.0f;
    circleShapeDef.filter.categoryBits = desc.category_bits;
    circleShapeDef.filter.maskBits = desc.mask_bits;
}

void ComponentCollider::CreateCollider()
{
    if (!b2Body_IsValid(circle_body))
    {
        circle_body = collider_manager_->CreateBody(bodyDef);
        b2CreateCircleShape(circle_body, &circleShapeDef, &circle);
    }
}

void ComponentCollider::DestroyCollider()
{
    if (b2Body_IsValid(circle_body))
    {
        collider_manager_->DestroyBody(circle_body);
        circle_body = b2_nullBodyId;
    }
}

void ComponentCollider::MoveDir(const float _x, const float _y)
{
    b2Vec2 velocity = {_x, _y};
    b2Body_SetLinearVelocity(circle_body, velocity);
}

pair<float, float> ComponentCollider::GetPosition()
{
    b2Vec2 position = b2Body_GetPosition(circle_body);
    return {position.x, position.y};
}
