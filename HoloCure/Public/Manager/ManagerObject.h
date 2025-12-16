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
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
};
