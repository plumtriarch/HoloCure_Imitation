#pragma once

class ManagerInput : public IManager
{
public:
    ~ManagerInput() override = default;
    struct ManagerInputDesc : public ManagerDesc
    {
        virtual ~ManagerInputDesc() = default;
    };
    
public:
    void Initialize(const ManagerDesc& _desc) override;
    void PriorityUpdate(const float _delta_time) override;
    void Update(const float _delta_time) override {};
    void LateUpdate(const float _delta_time) override{};
    
public:
    bool GetKey(const uint8_t _key) const { return key_state_[_key]; }
    bool GetKeyDown(const uint8_t _key) const { return key_state_[_key] && !key_prev_state_[_key]; }
    bool GetKeyUp(const uint8_t _key) const { return !key_state_[_key] && key_prev_state_[_key];}
    
private:
    bool key_state_[0xFF]{};
    bool key_prev_state_[0xFF]{};
};
