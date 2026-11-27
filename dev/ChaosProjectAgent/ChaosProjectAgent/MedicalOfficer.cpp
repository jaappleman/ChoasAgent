
#include "MedicalOfficer.h"

#include <iostream>

// ============================================================
// MedicalOfficer.cpp
// Purpose: Implements MedicalOfficer functionality, including
//          initialization, specialized duties, and staff
//          condition treatment.
// ============================================================

// ===================== Constructor ==========================

// Initialize the shared Staff properties.
MedicalOfficer::MedicalOfficer(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level
)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}

// ===================== Staff Duties =========================

// Display the MedicalOfficer's assigned duty.
void MedicalOfficer::performDuty()
{
    std::cout << getStaffName()
        << " is providing medical support to facility personnel. Skill Level: "
        << getSkillLevel() << '\n';
}

// ================= Medical Management =======================

// Restore another staff member's condition based on medical skill.
void MedicalOfficer::treatStaff(Staff& staff)
{
    staff.adjustStaffCondition(getSkillLevel());
}

