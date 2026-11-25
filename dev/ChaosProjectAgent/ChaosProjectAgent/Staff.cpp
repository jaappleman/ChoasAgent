#include "Staff.h"
#include <iostream>
#include <algorithm>
// constructor
Staff::Staff(int staff_id, std::string staff_name, int hiring_cost, int skill_level)
    : staffId(staff_id),
    staffName(staff_name),
    hiringCost(hiring_cost),
    skillLevel(skill_level)
{
}
void Staff::performDuty()
{
    std::cout << staffName << " is performing general staff duties.\n";
}
// getters
int Staff::getStaffId() const
{
    return staffId;
}

std::string Staff::getStaffName() const
{
    return staffName;
}

int Staff::getHiringCost() const
{
    return hiringCost;
}

int Staff::getSkillLevel() const
{
    return skillLevel;
}

// Return the staff member's current condition.
int Staff::getStaffCondition() const
{
    return staffCondition;
}

// Adjust staff condition while enforcing the 0-100 boundary.
void Staff::adjustStaffCondition(int change_amount)
{
    staffCondition = std::clamp(staffCondition + change_amount, 0, 100);
}

void Staff::displayInfo() const
{
    std::cout << "\n========== STAFF RECORD ==========\n";

    std::cout << "Staff ID: " << staffId << '\n';
    std::cout << "Name: " << staffName << '\n';
    std::cout << "Hiring Cost: " << hiringCost << " Credits\n";
    std::cout << "Skill Level: " << skillLevel << '\n';

    std::cout << "==================================\n";
}
