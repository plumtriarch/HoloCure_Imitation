#pragma once

class ItemSpawner : public IGameObject
{
public:
    ~ItemSpawner() override = default;
    struct ItemSpawnerDesc : public GameObjectDesc
    {
        virtual ~ItemSpawnerDesc() = default;
    };
public:
    void Initialize(const GameObjectDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override {};
    void Update(const float _delta_time) override;
    void LateUpdate(const float _delta_time) override {};
    void Render(HDC _hDC) override {};
    void PoolToLive() override{};
    void LiveToPool() override{};
    
public:
    void AddItemSpawner(const wstring& _item_tag, float _spawn_delay);
private:
    shared_ptr<ManagerObject> object_manager_;
    unordered_map<wstring, pair<float,float>> item_spawners_; 
};
