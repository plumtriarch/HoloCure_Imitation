#include "pch.h"
#include "Component/Sprite/ComponentSprite.h"

#include "Manager/ImageManager/ManagerImage.h"

void ComponentSprite::Initialize(const ComponentDesc& _desc)
{
    image_manager_ = ServiceLocator::getInstance().get<ManagerImage>();
}

void ComponentSprite::Render(HDC _hDC)
{
    image_manager_->DrawPng(_hDC, image_, position_x- (width_/2), position_y - (height_/2),
                             width_, height_,
                             src_left_top_x_, src_left_top_y_,
                             src_width_, src_height_);
}
