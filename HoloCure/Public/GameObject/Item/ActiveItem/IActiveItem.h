#pragma once

class IActiveItem : public IItem
{
public:
    ~IActiveItem() override;
    struct ActiveItemDesc : public GameObjectDesc
    {
        ActiveItemDesc(const wstring& _path, const wstring& _tag, const float _radius, const int32_t _animation_size = 1) 
        : path(_path), tag(_tag), radius(_radius), animation_size(_animation_size) {}
        virtual ~ActiveItemDesc() = default;
        const wstring path;
        const wstring tag;
        const float radius;
        const int32_t animation_size;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void PoolToLive() override;
    void LiveToPool() override;
    void SetPosition(const float _x, const float _y) override;
protected:
    shared_ptr<class ComponentSprite> sprite_component_;
    shared_ptr<class ComponentCollider> collider_component_;
    shared_ptr<class ManagerRender> render_manager_;

    float speed_{100.f};
};
