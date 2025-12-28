#pragma once

class ItemBomb : public IActiveItem
{
public:
    ~ItemBomb() override = default;
    struct ItemBombDesc : public GameObjectDesc
    {
        virtual ~ItemBombDesc() = default;
    };
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void PoolToLive() override;
    void LiveToPool() override;
    void SetPosition(const float _x, const float _y) override;
};
