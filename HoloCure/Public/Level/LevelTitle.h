#pragma once
#include "ILevel.h"

class LevelTitle : public ILevel
{
public:
    ~LevelTitle() override;
    struct LevelTitleDesc : public LevelDesc 
    {
        virtual ~LevelTitleDesc() = default;
    };
    
public:
    void Initialize(const LevelDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
};
