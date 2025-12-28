#include "pch.h"
#include "GameObject/UI/KillCount/UiKillCount.h"

void UiKillCount::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>(ComponentSprite::ComponentSpriteDesc
        {L"../Resources/Ui/Score.png", L"Score", 30, 30,1});
    sprite_component_->SetPosition(400,-250);
}

void UiKillCount::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void UiKillCount::Update(const float _delta_time)
{
}

void UiKillCount::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock())
    {
        render_manager->AddRenderGroup(RenderGroup::HUD, shared_from_this());
    }
}

void UiKillCount::Render(HDC _hDC)
{
    sprite_component_->RenderUi(_hDC);
    SetBkMode(_hDC, TRANSPARENT);
    TCHAR buffer[32];
    wsprintf(buffer, _T("%d"), kill_count); 
    TextOut(_hDC, 1070, 100, buffer, lstrlen(buffer));
}

void UiKillCount::SetPosition(const float _x, const float _y)
{
    IGameObject::SetPosition(_x, _y);
}

void UiKillCount::SetTemp(const int32_t _temp)
{
    IGameObject::SetTemp(_temp);
}

void UiKillCount::PoolToLive()
{
    IGameObject::PoolToLive();
    kill_count = 0;
}

void UiKillCount::LiveToPool()
{
}
