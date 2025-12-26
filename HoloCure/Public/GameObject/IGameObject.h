#pragma once

class IGameObject : public enable_shared_from_this<IGameObject>
{
public:
    virtual ~IGameObject() = default;
    struct GameObjectDesc 
    {
        virtual ~GameObjectDesc() = default;
    };
public:
    virtual void Initialize(const GameObjectDesc& _desc) = 0;
    virtual void PriorityUpdate(const float _delta_time) = 0;
    virtual void Update(const float _delta_time) = 0;
    virtual void LateUpdate(const float _delta_time) = 0;
    virtual void Render(HDC _hDC) = 0;
    virtual void SetPosition(const float _x, const float _y){};
public:
    virtual void PoolToLive() = 0;
    virtual void LiveToPool() = 0;
    bool IsDead() const { return is_dead_; }
public:
    template <typename T>
    static std::shared_ptr<T> CreateGameObject(const GameObjectDesc& _desc)
    {
        auto obj = make_shared<T>();
        obj->Initialize(_desc);
        return obj;
    }
    
protected:
    bool is_dead_{false};
};
