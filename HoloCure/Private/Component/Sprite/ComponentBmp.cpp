#include "pch.h"
#include "Component/Sprite/ComponentBmp.h"

ComponentBmp::~ComponentBmp()
{
    SelectObject(mem_dc_, oldbmp_);
    DeleteObject(bitmap_);
    DeleteDC(mem_dc_);
}

void ComponentBmp::Initialize(const ComponentDesc& _desc)
{
    const ComponentBmpDesc& desc = static_cast<const ComponentBmpDesc&>(_desc);
    HDC	hDC = GetDC(g_hWnd);

    mem_dc_ = CreateCompatibleDC(hDC);

    ReleaseDC(g_hWnd, hDC);

    bitmap_ = (HBITMAP)LoadImage(NULL,		
        desc.path.c_str(),	
        IMAGE_BITMAP,
        0, 0,		
        LR_LOADFROMFILE | LR_CREATEDIBSECTION); 
    
    oldbmp_ = (HBITMAP)SelectObject(mem_dc_, bitmap_);
}

void ComponentBmp::Render(HDC _hDC, const int32_t _pos_x, const int32_t _pos_y, const int32_t _index_y,
    const int32_t _index_x, const int32_t _size)
{
    BitBlt(_hDC, _pos_x - scroll_x + g_window_size_x/2, _pos_y - scroll_y + g_window_size_y/2, 
    _size,_size, 
    mem_dc_, _index_x * _size, _index_y * _size, SRCCOPY);
}
