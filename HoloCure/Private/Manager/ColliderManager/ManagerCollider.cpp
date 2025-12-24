#include "pch.h"
#include "Manager/ColliderManager/ManagerCollider.h"

ManagerCollider::~ManagerCollider()
{
    b2DestroyWorld(world_);
}

void ManagerCollider::Initialize(const ManagerDesc& _desc)
{
    
    b2WorldDef world_def;
    world_def = b2DefaultWorldDef();
    world_def.gravity = b2Vec2({0.0f, 0.0f});
    world_ = b2CreateWorld(&world_def);
}

b2BodyId ManagerCollider::CreateBody(b2BodyDef& _body_def)
{
    return b2CreateBody(world_, &_body_def);
}

void ManagerCollider::DestroyBody(b2BodyId _body_id)
{
    b2DestroyBody(_body_id);
}

void ManagerCollider::ColliderSmulation(const float _delta_time)
{
    b2World_Step(world_,_delta_time,4);
}

void ManagerCollider::ProcessContacts()
{
    b2SensorEvents seonsor_events = b2World_GetSensorEvents(world_);
    
    for (int i = 0; i < seonsor_events.beginCount; i++) 
    {
        b2SensorBeginTouchEvent* event = seonsor_events.beginEvents + i;
    
        b2ShapeId shapeA = event->sensorShapeId;
        b2ShapeId shapeB = event->visitorShapeId;

        // Player <-> Monster 
        if ((b2Shape_GetFilter(event->sensorShapeId).categoryBits == static_cast<int32_t>(CharacterType::PLAYER) &&
            b2Shape_GetFilter(event->visitorShapeId).categoryBits == static_cast<int32_t>(CharacterType::MONSTER)) ||
            (b2Shape_GetFilter(event->sensorShapeId).categoryBits == static_cast<int32_t>(CharacterType::MONSTER) &&
            b2Shape_GetFilter(event->visitorShapeId).categoryBits == static_cast<int32_t>(CharacterType::PLAYER)) )
        {
            ICharacter* player = nullptr;
            ICharacter* monster = nullptr;
            if (b2Shape_GetFilter(event->sensorShapeId).categoryBits == static_cast<int32_t>(CharacterType::PLAYER))
            {
                player = reinterpret_cast<ICharacter*>(b2Shape_GetUserData(shapeA));
                monster = reinterpret_cast<ICharacter*>(b2Shape_GetUserData(shapeB));
            }
            else
            {
                monster = reinterpret_cast<ICharacter*>(b2Shape_GetUserData(shapeA));
                player = reinterpret_cast<ICharacter*>(b2Shape_GetUserData(shapeB));
            }
            player->Attacked(monster->GetAttackDamage());

        }

        
        // Monster <-> PLAYER_ITEM
        // 예: 사용자 데이터를 가져와 로직 처리
        // MyActor* actorA = (MyActor*)b2Shape_GetUserData(shapeA);
        // MyActor* actorB = (MyActor*)b2Shape_GetUserData(shapeB);
        // MyCustomOnBeginContact(events.beginEvents[i]);
    }
    
}
