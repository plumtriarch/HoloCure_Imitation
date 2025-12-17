#include "pch.h"
#include "Manager/GameManager/ManagerGame.h"

void ManagerGame::Initialize(const ManagerDesc& _desc)
{
    time_manager_ = ServiceLocator::getInstance().get<ManagerTime>();
    input_manager_ = ServiceLocator::getInstance().get<ManagerInput>();
    level_manager_ = ServiceLocator::getInstance().get<ManagerLevel>();
    object_manager_ = ServiceLocator::getInstance().get<ManagerObject>();
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
}

void ManagerGame::Tick()
{
    const float delta_time = time_manager_->GetDeltaTime();
    input_manager_->UpdateInput();
    level_manager_->UpdateLevel(delta_time);
    object_manager_->UpdateObject(delta_time);
    render_manager_->Render();
}


