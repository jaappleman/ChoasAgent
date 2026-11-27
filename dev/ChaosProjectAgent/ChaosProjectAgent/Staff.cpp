
#include "Staff.h"

#include <algorithm>
#include <iostream>

#include "Helper.h"

// ============================================================
// Staff.cpp
// Purpose: Implements shared staff functionality, including
//          employee initialization, information retrieval,
//          condition management, and status display.
// ============================================================

// ===================== Constructor ==========================

// Initialize a staff member.
Staff::Staff(int staff_id, std::string staff_name, int hiring_cost, int skill_level)
    : staffId(staff_id),
    staffName(staff_name),
    hiringCost(hiring_cost),
    skillLevel(skill_level)
{
}

// ===================== Staff Duties =========================

// Provide a general staff duty implementation.
void Staff::performDuty()
{
    std::cout << staffName
        << " is performing general staff duties.\n";
}

// ======================= Getters ============================

// Return the staff member's ID.
int Staff::getStaffId() const
{
    return staffId;
}

// Return the staff member's name.
std::string Staff::getStaffName() const
{
    return staffName;
}

// Return the staff member's hiring cost.
int Staff::getHiringCost() const
{
    return hiringCost;
}

// Return the staff member's skill level.
int Staff::getSkillLevel() const
{
    return skillLevel;
}

// Return the staff member's current condition.
int Staff::getStaffCondition() const
{
    return staffCondition;
}

// ================= Condition Management =====================

// Adjust staff condition while enforcing the 0-100 boundary.
void Staff::adjustStaffCondition(int change_amount)
{
    staffCondition = std::clamp(
        staffCondition + change_amount, 0, 100);
}

// =================== Display Functions ======================

// Display employee information and condition.
void Staff::displayInfo() const
{
    std::cout << "\n========== STAFF RECORD ==========\n";

    std::cout << "Staff ID: " << staffId << '\n';
    std::cout << "Name: " << staffName << '\n';
    std::cout << "Hiring Cost: " << hiringCost << " Credits\n";
    std::cout << "Skill Level: " << skillLevel << '\n';
    std::cout << "Staff Condition: " << staffCondition << "%\n";

    // Calculate the number of filled condition-bar blocks.
    const int bar_width = 20;
    int filled_blocks = staffCondition * bar_width / 100;

    std::cout << "Condition: [";

    // Select a display color based on staff condition.
    if (staffCondition >= 80)
    {
        std::cout << Helper::GREEN;
    }
    else if (staffCondition >= 50)
    {
        std::cout << Helper::YELLOW;
    }
    else if (staffCondition >= 25)
    {
        std::cout << Helper::ORANGE;
    }
    else
    {
        std::cout << Helper::BLINK << Helper::SCARLET;
    }

    // Display the condition bar.
    for (int i = 0; i < bar_width; ++i)
    {
        if (i < filled_blocks)
        {
            std::cout << '#';
        }
        else
        {
            std::cout << ' ';
        }
    }

    std::cout << Helper::RESET << "]\n";
    std::cout << "==================================\n";
}
