#pragma once

class ItemStick : public IActiveItem
{
public:
    ~ItemStick() override = default;
    struct ItemStickDesc : public GameObjectDesc
    {
        virtual ~ItemStickDesc() = default;
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
private:
    float angle_{};
};
