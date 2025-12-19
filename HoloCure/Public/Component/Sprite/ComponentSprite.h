#pragma once

class ComponentSprite : public IComponent
{
public:
    virtual ~ComponentSprite() = default;
    struct ComponentSpriteDesc : public ComponentDesc
    {
        ComponentSpriteDesc(const wstring& _image_path ,const wstring& _image_key, const int32_t _width, const int32_t _height)
            : image_key(_image_key), image_path(_image_path), width_(_width), height_(_height) {}
        virtual ~ComponentSpriteDesc() = default;
        const wstring image_key;
        const wstring image_path;
        int32_t width_, height_;
    };
public:
    virtual void Initialize(const ComponentDesc& _desc);    
    void Render(HDC _hDC);
    void Render(HDC _hDC, const int32_t _pos_x, const int32_t _pos_y, const int32_t _index_y, const int32_t _index_x, const int32_t _size);
    void MovePosition(const float _x, const float _y) { position_x += _x; position_y += _y; }
    pair<int32_t, int32_t> GetPosition() {return {static_cast<int32_t>(position_x), static_cast<int32_t>(position_y)}; }
private:
    shared_ptr<class ManagerImage> image_manager_{};
    float position_x{}, position_y{};
    int32_t width_{}, height_{};
    int32_t src_left_top_x_{}, src_left_top_y_{};
    Gdiplus::Image* image_{nullptr}; 
    
};
