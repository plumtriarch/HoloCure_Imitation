#pragma once

class ItemLava : public IActiveItem
{
public:
    
    ~ItemLava() override = default;
    struct ItemLavaDesc : public GameObjectDesc
    {
        virtual ~ItemLavaDesc() = default;
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
    int phase{};
    bool attack_done_{false};
};
