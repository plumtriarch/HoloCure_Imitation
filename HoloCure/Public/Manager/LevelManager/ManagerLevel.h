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
    void UpdateLevel(const float _delta_time);
    
private:
    shared_ptr<ILevel> current_level_;
};
