#pragma once

class GameObjectMonster : public ICharacter
{
public:
    ~GameObjectMonster() override;
    struct GameObjectMonsterDesc : public GameObjectDesc
    {
        virtual ~GameObjectMonsterDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void PoolToLive() override;
    void LiveToPool() override;
    void Attacked(int _damage) override;

private:
    shared_ptr<class ComponentSprite> sprite_component_;
    shared_ptr<class ComponentSprite> sprite_rev_component_;
    shared_ptr<class ComponentCollider> collider_component_;
    weak_ptr<class ManagerRender> render_manager_;
    weak_ptr<class ManagerObject> object_manager_;

    int32_t monster_id_{};
    float speed_{30.f};
    bool reversed_{false};
};
