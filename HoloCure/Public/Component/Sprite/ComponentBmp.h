#pragma once

class ComponentBmp : public IComponent
{
public:
    ~ComponentBmp() override;
    struct ComponentBmpDesc : public ComponentDesc
    {
        ComponentBmpDesc(wstring const& path) : path(path) {}
        virtual ~ComponentBmpDesc() = default;
        wstring path;
    };
public:
    void Initialize(const ComponentDesc& _desc) override;
    void Render(HDC _hDC, const int32_t _pos_x, const int32_t _pos_y, const int32_t _index_y, const int32_t _index_x, const int32_t _size);
private:
    HDC			mem_dc_;

    HBITMAP		bitmap_;
    HBITMAP		oldbmp_;
};
