#pragma once
#include "Staff.h"

class Facility;

class SecurityOfficer :
    public Staff
{
public:
    // Initialize the shared Staff properties.
    SecurityOfficer(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );
    // Display the SecurityOfficer's assigned duty.
    void performDuty() override;
    // Restore facility stability based on the officer's skill level
    void respondToSecurityThreat(Facility& facility);
};

