#pragma once

class ManagerBmp : public IManager
{
public:
    ~ManagerBmp() override;
    struct ManagerBmpDesc : public ManagerDesc
    {
        virtual ~ManagerBmpDesc() = default;
    };
    void Initialize(const ManagerDesc& _desc) override;
};
