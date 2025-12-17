#include "pch.h"
#include "Manager/InputManager/ManagerInput.h"

void ManagerInput::Initialize(const ManagerDesc& _desc)
{
}

void ManagerInput::PriorityUpdate(const float _delta_time)
{
    memcpy(key_prev_state_, key_state_, sizeof(key_state_));
    for (auto i =0;i<0xFF;i++)
    {
        if (GetAsyncKeyState(i) & 0x8000)
            key_state_[i] = true;
        else
            key_state_[i] = false;
    }
}

