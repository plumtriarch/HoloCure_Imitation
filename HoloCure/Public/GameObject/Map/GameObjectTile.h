#pragma once

class GameObjectTile : public IGameObject
{
public:
    ~GameObjectTile() override = default;
    struct GameObjectTileDesc : public GameObjectDesc
    {
        virtual ~GameObjectTileDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override;
    void WrapTilePosition(int32_t& _tile_pos, const int32_t _player_pos);
    void Render(HDC _hDC) override;
    
private:
    shared_ptr<class ComponentBmp> bmp_component_;
    shared_ptr<class ManagerRender> render_manager_;
};
