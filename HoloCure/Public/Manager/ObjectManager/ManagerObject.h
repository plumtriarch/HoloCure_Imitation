#pragma once

class ManagerObject : public IManager
{
public:
    ~ManagerObject() override = default;
    struct ManagerObjectDesc : public ManagerDesc
    {
        virtual ~ManagerObjectDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void AddGameObjectToPool(const wstring& _tag, shared_ptr<IGameObject> _game_object);
    void MovePoolToLive(const wstring& _tag);
    void MovePoolToLive(const wstring& _tag, const float _x, const float _y, const int32_t _temp);
    void ProcessDeadObject();
    void UpdateObject(const float _delta_time);
    
private:
    unordered_map<wstring, list<shared_ptr<IGameObject>>> objects_live_;
    unordered_map<wstring, queue<shared_ptr<IGameObject>>> objects_pool_;
    
};
