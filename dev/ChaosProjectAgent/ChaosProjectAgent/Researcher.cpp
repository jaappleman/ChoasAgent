
#include "Researcher.h"

#include <iostream>

#include "Facility.h"

// ============================================================
// Researcher.cpp
// Purpose: Implements Researcher functionality, including
//          initialization, specialized duties, and research
//          contributions to the Facility.
// ============================================================

// ===================== Constructor ==========================

// Initialize the shared Staff properties.
Researcher::Researcher(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level
)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}

// ===================== Staff Duties =========================

// Display the Researcher's assigned duty.
void Researcher::performDuty()
{
    std::cout << getStaffName()
        << " is conducting research. Skill Level: "
        << getSkillLevel() << '\n';
}

// ================= Research Contributions ===================

// Accumulate facility research points based on the Researcher's skill level.
void Researcher::conductResearch(Facility& facility)
{
    facility.addResearchPoints(getSkillLevel());
}
