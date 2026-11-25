
#pragma once
#include <string>

class Staff
{
private:
    int staffId;
    std::string staffName;
    int hiringCost;
    int skillLevel;
    int staffCondition = 100;

public:
    // parameterized constructor
    Staff(int staff_id, std::string staff_name, int hiring_cost, int skill_level);
    virtual ~Staff() = default;
    // duty perform
    virtual void performDuty() = 0;
    // getters
    int getStaffId() const;
    std::string getStaffName() const;
    int getHiringCost() const;
    int getSkillLevel() const;
    int getStaffCondition() const;

    void adjustStaffCondition(int change_amount);
    // display info
    void displayInfo() const;
};