#pragma once

class ComponentCollider : public IComponent
{
public:
    ~ComponentCollider() override = default;
    struct ComponentColliderDesc : public ComponentDesc
    {
        ComponentColliderDesc(const float _radius) : radius(_radius) {}
        virtual ~ComponentColliderDesc() = default;
        float radius{1.f};
    };
public:
    void Initialize(const ComponentDesc& _desc) override;
    void CreateCollider();
    void DestroyCollider();
    void MoveDir(const float _x, const float _y);
    pair<float, float> GetPosition();
private:
    shared_ptr<class ManagerCollider> collider_manager_;
    b2BodyId circle_body{};
    b2BodyDef bodyDef{};
    b2Circle circle{};
    b2ShapeDef circleShapeDef{};
};
