#pragma once

class GameObjectPlayer : public ICharacter
{
public:
    ~GameObjectPlayer() override = default;
    struct GameObjectPlayerDesc : public GameObjectDesc
    {
        virtual ~GameObjectPlayerDesc() = default;
    };
    enum class State
    {
        IDLE,
        RUN
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;

public:
    void PoolToLive() override;
    void LiveToPool() override;

private:
    shared_ptr<class ComponentSprite> sprite_component_;
    shared_ptr<class ComponentSprite> sprite_rev_component_;
    shared_ptr<class ComponentCollider> collider_component_;
    shared_ptr<class ManagerInput> input_manager_;
    shared_ptr<class ManagerRender> render_manager_;

    float speed_{30.f};
    GameObjectPlayer::State state_{State::IDLE};
    bool reversed_{false};
    
};
