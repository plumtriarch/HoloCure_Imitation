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
    image_manager_->DrawPng(_hDC, image_, position_x- (width_/2), position_y - (height_/2),
                             width_, height_,
                             src_left_top_x_, src_left_top_y_,
                             width_, height_);
}
