#pragma once

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
protected:
    int32_t attack_damage_ = 5;
};
