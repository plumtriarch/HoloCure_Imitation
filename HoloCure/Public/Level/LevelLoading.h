#pragma once

class LevelLoading : public ILevel
{
public:
    ~LevelLoading() override = default;
    struct LevelLoadingDesc : public LevelDesc
    {
        unique_ptr<ILevel> next_level;
        virtual ~LevelLoadingDesc() = default;
    };
public:
    void Initialize(const LevelDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void LoadingResources() override;
    void LevelStart() override;

private:
    shared_ptr<ManagerLevel> level_manager_;
    unique_ptr<ILevel> next_level_;
    std::future<void> future_;
    
};
