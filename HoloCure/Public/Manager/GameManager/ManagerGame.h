#pragma once

class ManagerGame : public IManager
{
public:
    ~ManagerGame() override = default;
    struct ManagerGameDesc : public ManagerDesc
    {
        virtual ~ManagerGameDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void Tick();

    
private:
    shared_ptr<class ManagerTime> time_manager_;
    shared_ptr<class ManagerLevel> level_manager_;
    shared_ptr<class ManagerInput> input_manager_;
    shared_ptr<class ManagerObject> object_manager_;
    shared_ptr<class ManagerRender> render_manager_;
};
