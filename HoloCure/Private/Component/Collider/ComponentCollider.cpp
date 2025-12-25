#include "pch.h"
#include "Component/Collider/ComponentCollider.h"

void ComponentCollider::Initialize(const ComponentDesc& _desc)
{
    collider_manager_ = ServiceLocator::getInstance().get<ManagerCollider>();
 
    const ComponentColliderDesc& desc = static_cast<const ComponentColliderDesc&>(_desc);
    
    body_def_ = b2DefaultBodyDef();
    body_def_.type = b2_dynamicBody;
    body_def_.position = b2Vec2({0.0f, 0.0f});
    
    circle_.center = b2Vec2({0.0f, 0.0f});
    circle_.radius = desc.radius;
    
    sensor_circle_.center = b2Vec2({0.f, 0.f});
    sensor_circle_.radius = desc.radius;
    
    circle_shape_def_ = b2DefaultShapeDef();
    circle_shape_def_.density = 1.0f;
    circle_shape_def_.filter.categoryBits = desc.category_bits;
    circle_shape_def_.filter.maskBits = desc.mask_bits;

    
    sensor_circle_shape_def_ = b2DefaultShapeDef();
    sensor_circle_shape_def_.isSensor = true;
    sensor_circle_shape_def_.filter.categoryBits = desc.category_bits;
    sensor_circle_shape_def_.filter.maskBits = desc.sensor_mask_bits;
    sensor_circle_shape_def_.userData = reinterpret_cast<void*>(desc.character.get());
    // sensor_circle_shape_def_.enableSensorEvents = true;
}

void ComponentCollider::CreateCollider()
{
    if (!b2Body_IsValid(circle_body_))
    {
        circle_body_ = collider_manager_->CreateBody(body_def_);
        circle_shape_id_ = b2CreateCircleShape(circle_body_, &circle_shape_def_, &circle_);
        sensor_circle_shape_id_ = b2CreateCircleShape(circle_body_, &sensor_circle_shape_def_, &sensor_circle_);
    }
}

void ComponentCollider::DestroyCollider()
{
    if (b2Body_IsValid(circle_body_))
    {
        collider_manager_->DestroyBody(circle_body_);
        circle_body_ = b2_nullBodyId;
    }
}

void ComponentCollider::MoveDir(const float _x, const float _y)
{
    b2Vec2 velocity = {_x, _y};
    b2Body_SetLinearVelocity(circle_body_, velocity);
}

pair<float, float> ComponentCollider::GetPosition()
{
    b2Vec2 position = b2Body_GetPosition(circle_body_);
    return {position.x, position.y};
}

void ComponentCollider::SetSensor()
{
    if (is_sensor_active_ == false)
    {
        b2Shape_EnableSensorEvents(sensor_circle_shape_id_, true);
        is_sensor_active_ = true;
    }
}

void ComponentCollider::UnsetSensor()
{
    if (is_sensor_active_ == true)
    {
        b2Shape_EnableSensorEvents(sensor_circle_shape_id_, false);
        is_sensor_active_ = false;
    }
    
}
