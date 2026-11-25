#pragma once
#include "Staff.h"

class Facility;

class Technician :
    public Staff
{
public:
    // Initialize the shared Staff properties.
    Technician(
        int staff_id, 
        std::string staff_name, 
        int hiring_cost, 
        int skill_level);
    // Display the Technician's assigned duty.
    void performDuty() override;
    // Restore facility power based on the technician's skill level.
    void restorePower(Facility& facility);
};

