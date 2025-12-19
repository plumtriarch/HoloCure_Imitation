#include "pch.h"
#include "./Manager/TimeManager/ManagerTime.h"

void ManagerTime::Initialize(const ManagerDesc& _desc)
{
    const ManagerTimeDesc& desc = static_cast<const ManagerTimeDesc&>(_desc);
    
    QueryPerformanceCounter(&frame_time_);
    QueryPerformanceCounter(&last_time_);
    QueryPerformanceCounter(&fix_time_);
    QueryPerformanceFrequency(&cpu_tick_);
    
    SetTargetFps(desc.target_fps);
}

const float ManagerTime::GetDeltaTime()
{
    QueryPerformanceCounter(&frame_time_);
    if (frame_time_.QuadPart - fix_time_.QuadPart >= cpu_tick_.QuadPart)
    {
        QueryPerformanceFrequency(&cpu_tick_);
        fix_time_ = frame_time_;
    }
    while (frame_time_.QuadPart - last_time_.QuadPart < target_ticks)
    {
        QueryPerformanceCounter(&frame_time_);
    }
    delta_time_ = (frame_time_.QuadPart - last_time_.QuadPart) / static_cast<float>(cpu_tick_.QuadPart);
    last_time_ = frame_time_;
    return delta_time_ * time_factor_;
}

void ManagerTime::SetTargetFps(const uint16_t _fps)
{
    target_ticks = cpu_tick_.QuadPart / _fps;
}
