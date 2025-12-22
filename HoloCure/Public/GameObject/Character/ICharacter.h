#pragma once

class ICharacter : public IGameObject
{
public:
    ~ICharacter() override = default;
    struct ICharacterDesc : public GameObjectDesc
    {
        virtual ~ICharacterDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override = 0;
    void PriorityUpdate(const float _delta_time) override = 0;
    void Update(const float _delta_time) override = 0;
    void LateUpdate(const float _delta_time) override = 0;
    void Render(HDC _hDC) override = 0;
    
public:
    void PoolToLive() override = 0;
    void LiveToPool() override = 0;
protected:
    int32_t max_hp_ = 0;
    int32_t current_hp_ = 0;
};
