
#pragma once
#include "Staff.h"

class Facility;

class ContainmentSpecialist :
    public Staff
{
public:
    // Initialize the shared Staff properties.
    ContainmentSpecialist(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level);
    // Display the ContainmentSpecialist's assigned duty.
    void performDuty() override;
    // Restore anomaly stability based on the specialist's skill level.
    void stabilizeAnomaly(Facility& facility, int anomaly_id);
};


