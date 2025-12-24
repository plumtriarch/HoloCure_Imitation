#pragma once

class ManagerCollider : public IManager
{
public:
    ~ManagerCollider() override;
    struct ManagerColliderDesc : public ManagerDesc
    {
        virtual ~ManagerColliderDesc() = default;
    };
public:
    void Initialize(const ManagerDesc& _desc) override;
    b2BodyId CreateBody(b2BodyDef& _body_def);
    void DestroyBody(b2BodyId _body_id);
    void ColliderSmulation(const float _delta_time);
    void ProcessContacts();
    
private:
    b2WorldId world_{};
};
