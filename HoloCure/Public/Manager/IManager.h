#pragma once

#include <memory.h>
class IManager
{
public:
    virtual ~IManager() = default;
    
public:
    virtual void Initialize() = 0;
    virtual void PriorityUpdate(const float _delta_time) = 0;
    virtual void Update(const float _delta_time) = 0;
    virtual void LateUpdate(const float _delta_time) = 0;
public:
    template <typename T>
    static std::shared_ptr<IManager> CreateManager()
    {
        auto obj = make_shared<T>();
        obj->Initialize();
        return obj;
    }
};
