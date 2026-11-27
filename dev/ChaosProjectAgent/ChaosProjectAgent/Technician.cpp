
#include "Technician.h"

#include <iostream>

#include "Facility.h"

// ============================================================
// Technician.cpp
// Purpose: Implements Technician functionality, including
//          initialization, specialized duties, and facility
//          power restoration.
// ============================================================

// ===================== Constructor ==========================

// Initialize the shared Staff properties.
Technician::Technician(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level
)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}

// ===================== Staff Duties =========================

// Display the Technician's assigned duty.
void Technician::performDuty()
{
    std::cout << getStaffName()
        << " is maintaining facility systems. Skill Level: "
        << getSkillLevel() << '\n';
}

// ================= Power Contributions ======================

// Restore facility power based on the Technician's skill level.
void Technician::restorePower(Facility& facility)
{
    facility.adjustPower(getSkillLevel());
}
