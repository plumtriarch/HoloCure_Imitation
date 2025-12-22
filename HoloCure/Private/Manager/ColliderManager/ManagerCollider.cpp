#include "pch.h"
#include "Manager/ColliderManager/ManagerCollider.h"

ManagerCollider::~ManagerCollider()
{
    b2DestroyWorld(world);
}

void ManagerCollider::Initialize(const ManagerDesc& _desc)
{
    
    b2WorldDef world_def;
    world_def = b2DefaultWorldDef();
    world_def.gravity = b2Vec2({0.0f, 0.0f});
    world = b2CreateWorld(&world_def);
}

b2BodyId ManagerCollider::CreateBody(b2BodyDef& _body_def)
{
    return b2CreateBody(world, &_body_def);
}

void ManagerCollider::DestroyBody(b2BodyId _body_id)
{
    b2DestroyBody(_body_id);
}

void ManagerCollider::ColliderSmulation(const float _delta_time)
{
    b2World_Step(world,_delta_time,4);
}
