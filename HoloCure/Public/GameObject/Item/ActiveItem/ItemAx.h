#pragma once

class ItemAx : public IActiveItem
{
public:
    ~ItemAx() override = default;
    struct ItemAxDesc : public GameObjectDesc
    {
        virtual ~ItemAxDesc() = default;
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
    float angle_{0.f};
};
