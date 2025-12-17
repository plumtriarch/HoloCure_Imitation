#pragma once

class ManagerObject : public IManager
{
public:
    ~ManagerObject() override = default;
    struct ManagerObjectDesc : public ManagerDesc
    {
        virtual ~ManagerObjectDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void UpdateObject(const float _delta_time);
};
