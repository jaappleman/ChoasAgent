
#pragma once
#include "Staff.h"

class MedicalOfficer :
    public Staff
{
public:
    // Initialize the shared Staff properties.
    MedicalOfficer(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );
    // Display the MedicalOfficer's assigned duty.
    void performDuty() override;
    // Restore another staff member's condition based on medical skill.
    void treatStaff(Staff& staff);
};

