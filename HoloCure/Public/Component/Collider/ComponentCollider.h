#pragma once

class ComponentCollider : public IComponent
{
public:
    ~ComponentCollider() override = default;
    struct ComponentColliderDesc : public ComponentDesc
    {
        ComponentColliderDesc(const float _radius, const int32_t _category_bits, const int32_t _mask_bits,
            const int32_t _sensor_mask_bits, class shared_ptr<IGameObject> _character) : radius(_radius), category_bits(_category_bits), mask_bits(_mask_bits),
            sensor_mask_bits(_sensor_mask_bits), character(_character) {}
        virtual ~ComponentColliderDesc() = default;
        float radius{1.f};
        int32_t category_bits{0};
        int32_t mask_bits{0};
        int32_t sensor_mask_bits{0};
        class shared_ptr<IGameObject> character{nullptr};
    };
public:
    void Initialize(const ComponentDesc& _desc) override;
    void CreateCollider();
    void DestroyCollider();
    void MoveDir(const float _x, const float _y);
    pair<float, float> GetPosition();
    void SetSensor();
    void UnsetSensor();
private:
    shared_ptr<class ManagerCollider> collider_manager_;
    b2BodyId circle_body_{};
    b2BodyDef body_def_{};
    
    b2Circle circle_{};
    b2ShapeDef circle_shape_def_{};
    
    b2Circle sensor_circle_{};
    b2ShapeDef sensor_circle_shape_def_{};
    
    b2ShapeId circle_shape_id_{};
    b2ShapeId sensor_circle_shape_id_{};
    
    int32_t sensor_mask_bits_{};
    bool is_sensor_active_{false};
};
