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
public:
    template <typename T>
    static std::shared_ptr<T> CreateComponent(const ComponentDesc& _desc)
    {
        auto obj = make_shared<T>();
        obj->Initialize(_desc);
        return obj;
    }
};
