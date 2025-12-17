#pragma once

class ServiceLocator
{
public:
    ~ServiceLocator() = default;
    static ServiceLocator& getInstance();
    
public:
    template <typename Manager>
    void registerService(const IManager::ManagerDesc& _desc)
    {
        static_assert(std::is_base_of_v<IManager, Manager>, "Manager must inherit from IService");
        const auto key = std::type_index(typeid(Manager));
        if (service_map_.find(key) != service_map_.end())
        {
            CRASH("Service already registered");
        }

        auto service = IManager::CreateManager<Manager>(_desc);
        service_map_[key] = service;
    }

    template <typename Manager>
    std::shared_ptr<Manager> get() const
    {
        static_assert(std::is_base_of_v<IManager, Manager>, "Manager must inherit from IService");
        const auto it = service_map_.find(std::type_index(typeid(Manager)));
        if (it == service_map_.end())
        {
            CRASH("Service not found");
        }
        return std::static_pointer_cast<Manager>(it->second);
    }

private:
    unordered_map<type_index, shared_ptr<IManager>> service_map_;
};
