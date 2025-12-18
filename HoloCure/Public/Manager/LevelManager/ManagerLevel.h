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
    void SetLevel(unique_ptr<ILevel> _level);
    void LoadLevel(unique_ptr<ILevel> _level);
private:
    unique_ptr<ILevel> current_level_;
};
