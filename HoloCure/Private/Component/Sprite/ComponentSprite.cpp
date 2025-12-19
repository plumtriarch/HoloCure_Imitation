#include "pch.h"
#include "Component/Sprite/ComponentSprite.h"

void ComponentSprite::Initialize(const ComponentDesc& _desc)
{
    const ComponentSpriteDesc& desc = static_cast<const ComponentSpriteDesc&>(_desc);
    
    image_manager_ = ServiceLocator::getInstance().get<ManagerImage>();
    image_manager_->InsertPng(desc.image_path, desc.image_key);
    image_ = image_manager_->FindPng(desc.image_key);
    width_ = desc.width_;
    height_ = desc.height_;
}

void ComponentSprite::Render(HDC _hDC)
{
    image_manager_->DrawPng(_hDC, image_, static_cast<int32_t>(position_x) - (width_/2) - scroll_x + g_window_size_x/2, 
        static_cast<int32_t>(position_y) - (height_/2) - scroll_y+ g_window_size_y/2,
        width_, height_,
        src_left_top_x_, src_left_top_y_,
        width_, height_);
}

void ComponentSprite::Render(HDC _hDC, const int32_t _pos_x, const int32_t _pos_y, const int32_t _index_y,
    const int32_t _index_x, const int32_t _size)
{
    image_manager_->DrawPng(_hDC, image_, _pos_x - scroll_x + g_window_size_x/2, 
        _pos_y - scroll_y+ g_window_size_y/2,
        _size, _size,
        _index_x * _size, _index_y * _size,
        _size, _size);
}
