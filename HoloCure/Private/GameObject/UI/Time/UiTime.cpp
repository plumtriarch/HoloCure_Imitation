#include "pch.h"
#include "GameObject/UI/Time/UiTime.h"

void UiTime::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();\

}

void UiTime::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void UiTime::Update(const float _delta_time)
{
    total_time_ += _delta_time;
}

void UiTime::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock())
    {
        render_manager->AddRenderGroup(RenderGroup::PLAYER, shared_from_this());
    }
}

void UiTime::Render(HDC _hDC)
{
    SetBkMode(_hDC, TRANSPARENT);
    TCHAR buffer[32];
    wsprintf(buffer, _T("%02d:%02d"), int(total_time_)/60, int(total_time_) % 60); // int 값을 문자열로 변환
    TextOut(_hDC, (g_window_size_x >> 1) - 20, 70, buffer, lstrlen(buffer));
}

void UiTime::SetPosition(const float _x, const float _y)
{
    IGameObject::SetPosition(_x, _y);
}

void UiTime::SetTemp(const int32_t _temp)
{
    IGameObject::SetTemp(_temp);
}

void UiTime::PoolToLive()
{
    IGameObject::PoolToLive();
    total_time_ = 0.f;
}

void UiTime::LiveToPool()
{
}
