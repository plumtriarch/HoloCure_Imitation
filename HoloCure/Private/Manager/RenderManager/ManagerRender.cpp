#include "pch.h"
#include "Manager/RenderManager/ManagerRender.h"


ManagerRender::~ManagerRender()
{
    SelectObject(hMemDC, hOldBitmap);
    DeleteObject(hMemBitmap);
    DeleteDC(hMemDC);
    DeleteObject(hBrush);
}

void ManagerRender::Initialize(const ManagerDesc& _desc)
{
    hdc_ = GetDC(g_hWnd);
    
    hMemDC = CreateCompatibleDC(hdc_);
    hMemBitmap = CreateCompatibleBitmap(hdc_, g_window_size_x, g_window_size_y);
    hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMemBitmap);
    hBrush = CreateSolidBrush(RGB(0, 0, 0));
}

void ManagerRender::Render()
{
    RECT rect = { 0, 0, g_window_size_x, g_window_size_y };
    FillRect(hMemDC, &rect, hBrush);
    
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
}

