#pragma once

class ILevel
{
public:
    virtual ~ILevel() = default;
    struct LevelDesc 
    {
        virtual ~LevelDesc() = default;
    };
public:
    virtual void Initialize(const LevelDesc& _desc) = 0;
    virtual void PriorityUpdate(const float _delta_time) = 0;
    virtual void Update(const float _delta_time) = 0;
    virtual void LateUpdate(const float _delta_time) = 0;
    
public:
    template <typename T>
    static std::shared_ptr<ILevel> CreateLevel(const LevelDesc& _desc)
    {
        auto obj = make_shared<T>();
        obj->Initialize(_desc);
        return obj;
    }
};
