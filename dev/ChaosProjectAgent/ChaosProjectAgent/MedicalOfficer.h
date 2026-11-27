

#pragma once

// ============================================================
// MedicalOfficer.h
// Purpose: Defines the MedicalOfficer class, a specialized
//          Staff member responsible for treating employees
//          and restoring their condition.
// ============================================================

// ======================== Includes ==========================

#include "Staff.h"

// ===================== Class Declaration ====================

class MedicalOfficer : public Staff
{
public:
    // ===================== Constructor ======================

    // Initialize the shared Staff properties.
    MedicalOfficer(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );

    // ===================== Staff Duties =====================

    // Display the MedicalOfficer's assigned duty.
    void performDuty() override;

    // ================= Medical Management ====================

    // Restore another staff member's condition based on medical skill.
    void treatStaff(Staff& staff);
};


