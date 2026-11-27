
#include "ContainmentSpecialist.h"

#include <iostream>

#include "Facility.h"

// ============================================================
// ContainmentSpecialist.cpp
// Purpose: Implements containment specialist duties and
//          anomaly stabilization.
// ============================================================

// ===================== Constructor ==========================

ContainmentSpecialist::ContainmentSpecialist(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level
)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}

// ===================== Staff Duties =========================

void ContainmentSpecialist::performDuty()
{
    std::cout << getStaffName()
        << " is stabilizing facility anomalies. Skill Level: "
        << getSkillLevel() << '\n';
}

// ================= Anomaly Management =======================

void ContainmentSpecialist::stabilizeAnomaly(
    Facility& facility,
    int anomaly_id
)
{
    Anomaly* anomaly = facility.findAnomalyById(anomaly_id);

    // Stop if the requested anomaly does not exist.
    if (anomaly == nullptr)
    {
        return;
    }

    // Apply the specialist's skill level as a stability increase.
    anomaly->performMaintenance(getSkillLevel());
}
