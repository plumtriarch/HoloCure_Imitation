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
    virtual void LoadingResources() = 0;
    virtual void LevelStart() = 0;
    const bool IsLoaded() const { return is_loaded_; }
    
public:
    template <typename T>
    static std::unique_ptr<ILevel> CreateLevel(const LevelDesc& _desc)
    {
        auto obj = make_unique<T>();
        obj->Initialize(_desc);
        return move(obj);
    }
protected:
    bool is_loaded_{false};
};
