#pragma once

class ManagerRender : public IManager
{
public:
    ~ManagerRender() override;
    struct ManagerRenderDesc : public ManagerDesc
    {
        virtual ~ManagerRenderDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void Render();
private:
    shared_ptr<class ManagerObject> object_manager_; 
    array<list<weak_ptr<IGameObject>>, static_cast<uint8_t>(RenderGroup::COUNT)> renderGroups_;
    HDC     hdc_{nullptr};
    HDC     hMemDC{nullptr};
    HBITMAP hMemBitmap{nullptr};
    HBITMAP hOldBitmap{nullptr};
    HBRUSH  hBrush{nullptr};
};
