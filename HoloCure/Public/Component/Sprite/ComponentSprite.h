#pragma once

class ComponentSprite : public IComponent
{
public:
    virtual ~ComponentSprite() = default;
    struct ComponentSpriteDesc : public ComponentDesc
    {
        virtual ~ComponentSpriteDesc() = default;
    };
public:
    virtual void Initialize(const ComponentDesc& _desc);    
    void Render(HDC _hDC);
private:
    shared_ptr<class ManagerImage> image_manager_{};
    int32_t position_x{}, position_y{};
    int32_t width_{}, height_{};
    int32_t src_left_top_x_{}, src_left_top_y_{};
    int32_t src_width_{}, src_height_{};
    Gdiplus::Image* image_{nullptr}; 
    
};
