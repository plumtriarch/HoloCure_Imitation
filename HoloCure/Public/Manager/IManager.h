#pragma once

#include <memory.h>
class IManager
{
public:
    virtual ~IManager() = default;
    struct ManagerDesc 
    {
        virtual ~ManagerDesc() = default;
    };
public:
    virtual void Initialize(const ManagerDesc& _desc) = 0;
    virtual void PriorityUpdate(const float _delta_time) = 0;
    virtual void Update(const float _delta_time) = 0;
    virtual void LateUpdate(const float _delta_time) = 0;
    
public:
    template <typename T>
    static std::shared_ptr<IManager> CreateManager(const ManagerDesc& _desc)
    {
        auto obj = make_shared<T>();
        obj->Initialize(_desc);
        return obj;
    }
};
