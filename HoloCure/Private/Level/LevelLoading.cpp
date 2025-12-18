#include "pch.h"
#include "Level/LevelLoading.h"

void LevelLoading::Initialize(const LevelDesc& _desc)
{
    level_manager_ = ServiceLocator::getInstance().get<ManagerLevel>();
    const LevelLoadingDesc& desc = static_cast<const LevelLoadingDesc&>(_desc);
    LevelLoadingDesc& mutable_desc = const_cast<LevelLoadingDesc&>(desc);
    next_level_ = move(mutable_desc.next_level);
    future_ = std::async(&ILevel::LoadingResources, next_level_.get());
}

void LevelLoading::PriorityUpdate(const float _delta_time)
{
}

void LevelLoading::Update(const float _delta_time)
{
}

void LevelLoading::LateUpdate(const float _delta_time)
{
    if (next_level_->IsLoaded())
    {
        next_level_->LevelStart();
        level_manager_->SetLevel(move(next_level_));
    }
}

void LevelLoading::LoadingResources()
{
    
}

void LevelLoading::LevelStart()
{
}
