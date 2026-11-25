#pragma once
#include "Staff.h"

class Facility;

class Researcher :
    public Staff
{
public:
    // Initialize the shared Staff properties.
    Researcher(
        int staff_id, 
        std::string staff_name, 
        int hiring_cost, 
        int skill_level);
    // Display the Reseracher's assigned duty.
    void performDuty() override;
    // Accumulate research points based on the researcher's skill level.
    void conductResearch(Facility& facility);
};

