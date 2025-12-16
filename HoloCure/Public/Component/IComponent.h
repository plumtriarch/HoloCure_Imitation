#pragma once

class IComponent
{
public:
    virtual ~IComponent() = default;
    struct ComponentDesc 
    {
        virtual ~ComponentDesc() = default;
    };
public:
    virtual void Initialize(const ComponentDesc& _desc) = 0;
    virtual void PriorityUpdate(const float _delta_time) = 0;
    virtual void Update(const float _delta_time) = 0;
    virtual void LateUpdate(const float _delta_time) = 0;
public:
    template <typename T>
    static std::shared_ptr<IComponent> CreateGameObject(const ComponentDesc& _desc)
    {
        auto obj = make_shared<T>();
        obj->Initialize(_desc);
        return obj;
    }
};
