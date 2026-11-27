
#include "SecurityOfficer.h"

#include <iostream>

#include "Facility.h"

// ============================================================
// SecurityOfficer.cpp
// Purpose: Implements SecurityOfficer functionality, including
//          initialization, specialized duties, and facility
//          security responses.
// ============================================================

// ===================== Constructor ==========================

// Initialize the shared Staff properties.
SecurityOfficer::SecurityOfficer(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level
)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}

// ===================== Staff Duties =========================

// Display the SecurityOfficer's assigned duty.
void SecurityOfficer::performDuty()
{
    std::cout << getStaffName()
        << " is monitoring facility security. Skill Level: "
        << getSkillLevel() << '\n';
}

// ================= Security Management ======================

// Restore facility stability based on the officer's skill level.
void SecurityOfficer::respondToSecurityThreat(Facility& facility)
{
    facility.adjustFacilityStability(getSkillLevel());
}

