#include "pch.h"
#include "Manager/ImageManager/ManagerImage.h"

ManagerImage::~ManagerImage()
{

}

void ManagerImage::Initialize(const ManagerDesc& _desc)
{
   
}

void ManagerImage::InsertPng(const wstring& _filePath, const wstring& _key)
{
    if (png_map_.find(_key) == png_map_.end()) {
        unique_ptr<Gdiplus::Image> image = make_unique<Gdiplus::Image>(_filePath.c_str());
        if (image && image->GetLastStatus() == Gdiplus::Ok) {
            png_map_[_key] = move(image);
        }
    }
}

Gdiplus::Image* ManagerImage::FindPng(const wstring& _key)
{
    auto it = png_map_.find(_key);
    if (it != png_map_.end()) {
        Gdiplus::Image* image = it->second.get();
        ASSERT_CRASH(image)
        return image;
    }
    return nullptr;
}

void ManagerImage::DrawPng(HDC _hDC, const wstring& _key, const int _dest_x, const int _dest_y, const int _dest_width,
    const int _dest_height, const int _src_x, const int _src_y, const int _src_width, const int _src_height)
{
    Gdiplus::Image* image = FindPng(_key);
    if (image) {
        Gdiplus::Graphics graphics(_hDC);
        graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
        
        Gdiplus::Rect srcRect(_src_x, _src_y, _src_width, _src_height);
        
        Gdiplus::Rect destRect(_dest_x, _dest_y, _dest_width, _dest_height);
        
        graphics.DrawImage(image, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel);
    }
}

void ManagerImage::DrawPng(HDC _hDC, Gdiplus::Image* _image, const int _dest_x, const int _dest_y,
    const int _dest_width, const int _dest_height, const int _src_x, const int _src_y, const int _src_width,
    const int _src_height)
{
    if (_image) {
        Gdiplus::Graphics graphics(_hDC);
        graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
        
        Gdiplus::Rect srcRect(_src_x, _src_y, _src_width, _src_height);
        
        Gdiplus::Rect destRect(_dest_x, _dest_y, _dest_width, _dest_height);
        
        graphics.DrawImage(_image, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel);
    }
}

void ManagerImage::DrawPngRotate(HDC _hDC, Gdiplus::Image* _image, const int _dest_x, const int _dest_y,
    const int _dest_width, const int _dest_height, float _angle)
{
    if (_image) {
        Gdiplus::Graphics graphics(_hDC);
        graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
        
        graphics.TranslateTransform(static_cast<REAL>(_dest_x) + static_cast<REAL>(_dest_width) / 2.0f, static_cast<REAL>(_dest_y)
            + static_cast<REAL>(_dest_height) / 2.0f);
        graphics.RotateTransform(_angle);
        graphics.TranslateTransform(-(static_cast<REAL>(_dest_x) + static_cast<REAL>(_dest_width) / 2.0f), 
            -(static_cast<REAL>(_dest_y) + static_cast<REAL>(_dest_height) / 2.0f));
        
        graphics.DrawImage(_image, _dest_x, _dest_y, _dest_width, _dest_height);
        
        graphics.ResetTransform();
    }
}
