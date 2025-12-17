#include "pch.h"
#include "Manager/RenderManager/ManagerRender.h"


void ManagerRender::Initialize(const ManagerDesc& _desc)
{
    hdc_ = GetDC(g_hWnd);
}

void ManagerRender::PriorityUpdate(const float _delta_time)
{
}

void ManagerRender::Update(const float _delta_time)
{
}

void ManagerRender::LateUpdate(const float _delta_time)
{
    HDC hMemDC = CreateCompatibleDC(hdc_);
    HBITMAP hMemBitmap = CreateCompatibleBitmap(hdc_, g_window_size_x, g_window_size_y);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMemBitmap);
    
    RECT rect = { 0, 0, g_window_size_x, g_window_size_y };
    HBRUSH hBrush = CreateSolidBrush(RGB(30, 30, 30));
    FillRect(hMemDC, &rect, hBrush);
    DeleteObject(hBrush);
    
    for (int i =0;i<static_cast<int>(RenderGroup::COUNT);i++)
    {
        for (auto& weak_obj : renderGroups_[i])
        {
            if (auto shared_obj = weak_obj.lock())
            {
                shared_obj->Render();
            }
        }
    }
    

    BitBlt(hdc_, 0, 0, g_window_size_x, g_window_size_y, hMemDC, 0, 0, SRCCOPY);
    
    SelectObject(hMemDC, hOldBitmap);
    DeleteObject(hMemBitmap);
    DeleteDC(hMemDC);
}
