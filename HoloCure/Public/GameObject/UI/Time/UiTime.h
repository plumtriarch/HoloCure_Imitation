#pragma once

class UiTime : public IGameObject
{
public:
    ~UiTime() override = default;
    struct UiTimeDesc : public GameObjectDesc
    {
        ~UiTimeDesc() override = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void Render(HDC _hDC) override;
    void SetPosition(const float _x, const float _y) override;
    void SetTemp(const int32_t _temp) override;
    void PoolToLive() override;
    void LiveToPool() override;
private:    
    weak_ptr<class ManagerRender> render_manager_;
    float total_time_{0.f};
};
