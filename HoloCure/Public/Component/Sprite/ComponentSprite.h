#pragma once

class ComponentSprite : public IComponent
{
public:
    virtual ~ComponentSprite() = default;
    struct ComponentSpriteDesc : public ComponentDesc
    {
        ComponentSpriteDesc(const wstring& _image_path ,const wstring& _image_key, const int32_t _width, const int32_t _height, const int32_t _animation_size)
            : image_key(_image_key), image_path(_image_path), width(_width), height(_height), animation_size(_animation_size) {}
        virtual ~ComponentSpriteDesc() = default;
        const wstring image_key;
        const wstring image_path;
        int32_t width, height;
        int32_t animation_size;
    };
public:
    virtual void Initialize(const ComponentDesc& _desc);    
    void Render(HDC _hDC);
    void Render(HDC _hDC, const int32_t _pos_x, const int32_t _pos_y, const int32_t _index_y, const int32_t _index_x, const int32_t _size);
    void Render(HDC _hDC, const int32_t _state_index);
    void Render(HDC _hDC, const int32_t _state_index, ComponentCollider* _collider);
    void UpdateAnimation(const float _delta_time);
    // void MovePosition(const float _x, const float _y) { position_x += _x; position_y += _y; }
    pair<int32_t, int32_t> GetPosition() {return {static_cast<int32_t>(position_x), static_cast<int32_t>(position_y)}; }
private:
    shared_ptr<class ManagerImage> image_manager_{};
    float position_x{}, position_y{};
    int32_t width_{}, height_{};
    int32_t src_left_top_x_{}, src_left_top_y_{};
    int32_t animation_index_{0}, animation_size_{0};
    Gdiplus::Image* image_{nullptr}; 
    float sum_time_{0.f};
};
