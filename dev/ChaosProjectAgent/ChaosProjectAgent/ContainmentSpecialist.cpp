#include "ContainmentSpecialist.h"
#include "Facility.h"
#include <iostream>
// Initialize the shared Staff properties.
ContainmentSpecialist::ContainmentSpecialist(
    int staff_id,
    std::string staff_name,
    int hiring_cost,
    int skill_level)
    : Staff(staff_id, staff_name, hiring_cost, skill_level)
{
}
// Display the ContainmentSpecialist's assigned duty.
void ContainmentSpecialist::performDuty()
{
    std::cout << getStaffName()
        << " is stabilizing facility anomalies. Skill Level: "
        << getSkillLevel() << '\n';
}
// Restore anomaly stability based on the specialist's skill level.
void ContainmentSpecialist::stabilizeAnomaly(Facility& facility, int anomaly_id)
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

