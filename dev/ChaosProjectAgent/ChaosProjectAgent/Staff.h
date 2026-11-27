

#pragma once

// ============================================================
// Staff.h
// Purpose: Defines the abstract Staff base class, providing
//          shared employee information, condition management,
//          and functionality inherited by staff specializations.
// ============================================================

// ======================== Includes ==========================

#include <string>

// ===================== Class Declaration ====================

class Staff
{
private:
    // ================= Employee Information =================

    int staffId;
    std::string staffName;
    int hiringCost;
    int skillLevel;

    // ================= Employee Condition ===================

    int staffCondition = 100;

public:
    // ===================== Constructor ======================

    Staff(int staff_id, std::string staff_name, int hiring_cost, int skill_level);

    // ====================== Destructor ======================

    virtual ~Staff() = default;

    // ===================== Staff Duties =====================

    virtual void performDuty() = 0;

    // ======================= Getters ========================

    int getStaffId() const;
    std::string getStaffName() const;
    int getHiringCost() const;
    int getSkillLevel() const;
    int getStaffCondition() const;

    // ================= Condition Management =================

    void adjustStaffCondition(int change_amount);

    // =================== Display Functions ==================

    void displayInfo() const;
};
