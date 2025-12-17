#pragma once
#include "Manager/IManager.h"

class ManagerImage : public IManager
{
public:
    ~ManagerImage() override = default;
    struct ManagerImageDesc : public ManagerDesc
    {
        virtual ~ManagerImageDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override {};
    void Update(const float _delta_time) override {};
    void LateUpdate(const float _delta_time) override {};

public:
    void InsertPng(const wstring& _filePath, const wstring& _key);
    Gdiplus::Image* FindPng(const wstring& _key);
    void DrawPng(HDC _hDC, const wstring& _key, const int _dest_x, const int _dest_y, 
        const int _dest_width, const int _dest_height, 
        const int _src_x, const int _src_y, 
        const int _src_width, const int _src_height);
private:
    unordered_map<wstring, unique_ptr<Gdiplus::Image>> png_map_;
};
