#include "pch.h"
#include "GameObject/Map/GameObjectTile.h"

void GameObjectTile::Initialize(const GameObjectDesc& _desc)
{
    render_manager_ = ServiceLocator::getInstance().get<ManagerRender>();
    // sprite_component_ = ComponentSprite::CreateComponent<ComponentSprite>
    //     (ComponentSprite::ComponentSpriteDesc{L"../Resources/Map/Stage01.png", L"stage01", 2560, 2560});
    bmp_component_ = ComponentBmp::CreateComponent<ComponentBmp>
        (ComponentBmp::ComponentBmpDesc{L"../Resources/Map/Stage01.bmp"});
}

void GameObjectTile::PriorityUpdate(const float _delta_time)
{
}

void GameObjectTile::Update(const float _delta_time)
{
}

void GameObjectTile::LateUpdate(const float _delta_time)
{
    render_manager_->AddRenderGroup(RenderGroup::BACKGROUND, shared_from_this());
}

void GameObjectTile::WrapTilePosition(int32_t& _tile_pos, const int32_t _player_pos)
{
    
    while (_player_pos - _tile_pos > 1500)
    {
        _tile_pos += 2560;
    }
    while (_player_pos - _tile_pos < -1500)
    {
        _tile_pos -= 2560;
    }
}


void GameObjectTile::Render(HDC _hDC)
{
    for (auto i = 0;i<16;i++)
    {
        int32_t tile_pos_y = 160 * (i-8) + 80;
        WrapTilePosition(tile_pos_y, scroll_y);
        for (auto j = 0;j<16;j++)
        {
            int32_t tile_pos_x = 160 * (j-8) + 80;
            WrapTilePosition(tile_pos_x, scroll_x);
            bmp_component_->Render(_hDC,tile_pos_x, tile_pos_y, i, j, 160);
        }
    }
    
}
