#pragma once
#include "IManager.h"

class ManagerTime : public IManager
{
public:
    ~ManagerTime() override = default;
    struct ManagerTimeDesc : public ManagerDesc
    {
        ManagerTimeDesc(uint16_t _target_fps) :  target_fps(_target_fps) {}
        virtual ~ManagerTimeDesc() = default;
        uint16_t target_fps{60};
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override {};
    void LateUpdate(const float _delta_time) override {};
    const float GetDeltaTime() const { return delta_time_ * time_factor_; };
private:
    void SetTargetFps(const uint16_t _fps);
    
private:
    float delta_time_{0.f};
    float time_factor_{1.f};
    long long target_ticks{};
    
    LARGE_INTEGER frame_time_{};
    LARGE_INTEGER fix_time_{};
    LARGE_INTEGER last_time_{};
    LARGE_INTEGER cpu_tick_{};
};
