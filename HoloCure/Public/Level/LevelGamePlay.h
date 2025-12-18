#pragma once

class LevelGamePlay : public ILevel
{
public:
    ~LevelGamePlay() override = default;
    struct LevelGamePlayDesc : public LevelDesc 
    {
        virtual ~LevelGamePlayDesc() = default;
    };
    
public:
    void Initialize(const LevelDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void LoadingResources() override;
    void LevelStart() override;
    
private:
    
};
