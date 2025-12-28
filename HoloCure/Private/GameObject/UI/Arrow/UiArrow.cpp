#include "pch.h"
#include "GameObject/UI/Arrow/UiArrow.h"

void UiArrow::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>(ComponentSprite::ComponentSpriteDesc
        {L"../Resources/Ui/arrow.png", L"arrow", 128, 128,1});
}

void UiArrow::PriorityUpdate(const float _delta_time)
{
    IGameObject::PriorityUpdate(_delta_time);
}

void UiArrow::Update(const float _delta_time)
{
    float degree = atan2(mouse_y-g_window_size_y/2, mouse_x-g_window_size_x/2) * 180 / 3.14;
    if (degree < 0) degree += 360;
    rotated = degree;
}

void UiArrow::LateUpdate(const float _delta_time)
{
    if (auto render_manager = render_manager_.lock())
    {
        render_manager->AddRenderGroup(RenderGroup::DAMAGE, shared_from_this());
    }
}

void UiArrow::Render(HDC _hDC)
{
    sprite_component_->RenderRotate(_hDC, rotated, static_cast<int32_t>(scroll_x), static_cast<int32_t>(scroll_y));
}

void UiArrow::SetPosition(const float _x, const float _y)
{
    IGameObject::SetPosition(_x, _y);
}

void UiArrow::SetTemp(const int32_t _temp)
{
    IGameObject::SetTemp(_temp);
}

void UiArrow::PoolToLive()
{
    IGameObject::PoolToLive();
}

void UiArrow::LiveToPool()
{
}
