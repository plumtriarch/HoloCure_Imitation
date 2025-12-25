#include "pch.h"
#include "Manager/LevelManager/ManagerLevel.h"
#include "Level/LevelLoading.h"
void ManagerLevel::Initialize(const ManagerDesc& _desc)
{
}

void ManagerLevel::UpdateLevel(const float _delta_time)
{
    current_level_->PriorityUpdate(_delta_time);
    current_level_->Update(_delta_time);
    current_level_->LateUpdate(_delta_time);
}

void ManagerLevel::SetLevel(unique_ptr<ILevel> _level)
{
    current_level_ = move(_level);
    is_loading_level_ = false;
}

void ManagerLevel::LoadLevel(unique_ptr<ILevel> _level)
{
    LevelLoading::LevelLoadingDesc loading_desc;
    loading_desc.next_level = move(_level);
    SetLevel(ILevel::CreateLevel<LevelLoading>(loading_desc));
    is_loading_level_ = true;
}
