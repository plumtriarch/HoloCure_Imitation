#pragma once

class ManagerLevel : public IManager
{
public:
    ~ManagerLevel() override = default;
    struct ManagerLevelDesc : public ManagerDesc
    {
        virtual ~ManagerLevelDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override {};
    void LateUpdate(const float _delta_time) override {};
    
private:
    shared_ptr<ILevel> current_level_;
};
