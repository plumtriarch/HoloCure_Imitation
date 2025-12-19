#pragma once

class GameObjectPlayer : public IGameObject
{
public:
    ~GameObjectPlayer() override = default;
    struct GameObjectPlayerDesc : public GameObjectDesc
    {
        virtual ~GameObjectPlayerDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
private:
    shared_ptr<class ComponentSprite> sprite_component_;
    shared_ptr<class ManagerInput> input_manager_;
    shared_ptr<class ManagerRender> render_manager_;
    float speed_{100.f};
};
