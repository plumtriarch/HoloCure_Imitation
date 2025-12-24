#pragma once

class ItemBullet : public IActiveItem
{
public:
    ~ItemBullet() override = default;
    struct ItemBulletDesc : public GameObjectDesc
    {
        virtual ~ItemBulletDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void PoolToLive() override;
    void LiveToPool() override;
    
};
