#pragma once

class GameObjectDamage : public IGameObject
{
public:
    ~GameObjectDamage() override = default;
    struct GameObjectDamageDesc : public GameObjectDesc
    {
        virtual ~GameObjectDamageDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void SetPosition(const float _x, const float _y) override;
    void PoolToLive() override;
    void LiveToPool() override;
    void SetTemp(const int32_t _temp) override { damage_amount_ = _temp; }

private:
    shared_ptr<class ComponentSprite> sprite_component_;
    shared_ptr<class ManagerRender> render_manager_;
    int32_t damage_amount_{0};
};
