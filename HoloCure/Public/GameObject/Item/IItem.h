#pragma once
#include <random>

class IItem : public IGameObject
{
public:
    ~IItem() override = default;
    void Initialize(const GameObjectDesc& _desc) override = 0;
    void PriorityUpdate(const float _delta_time) override = 0;
    void Update(const float _delta_time) override = 0;
    void LateUpdate(const float _delta_time) override = 0;
    void Render(HDC _hDC) override = 0;
    void PoolToLive() override = 0;
    void LiveToPool() override = 0;
    int32_t GetAttackDamage() const { return attack_damage_; }
    void SetPosition(const float _x, const float _y) override {};
protected:
    int32_t attack_damage_ = 5;
    int32_t level_ = 0;
    float life_time_ = 0.f;
    float cur_life_time_ = 0.f;
    float speed_ = 0.f;
    array<float,2> direction_ = {0.f,0.f};
    float rotated_ = 0.f;
    
};
