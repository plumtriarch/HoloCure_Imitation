#pragma once

class ComponentCollider : public IComponent
{
public:
    ~ComponentCollider() override = default;
    struct ComponentColliderDesc : public ComponentDesc
    {
        ComponentColliderDesc(const float _radius, const int32_t _category_bits, const int32_t _mask_bits) : radius(_radius),
            category_bits(_category_bits), mask_bits(_mask_bits) {}
        virtual ~ComponentColliderDesc() = default;
        float radius{1.f};
        int32_t category_bits{0};
        int32_t mask_bits{0};
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
