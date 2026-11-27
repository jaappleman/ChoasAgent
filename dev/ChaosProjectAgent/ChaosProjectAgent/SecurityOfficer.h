
#pragma once

// ============================================================
// SecurityOfficer.h
// Purpose: Defines the SecurityOfficer class, a specialized
//          Staff member responsible for responding to security
//          threats and maintaining facility stability.
// ============================================================

// ======================== Includes ==========================

#include "Staff.h"

// ================= Forward Declarations ====================

class Facility;

// ===================== Class Declaration ====================

class SecurityOfficer : public Staff
{
public:
    // ===================== Constructor ======================

    // Initialize the shared Staff properties.
    SecurityOfficer(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );

    // ===================== Staff Duties =====================

    // Display the SecurityOfficer's assigned duty.
    void performDuty() override;

    // ================= Security Management ===================

    // Restore facility stability based on the officer's skill level.
    void respondToSecurityThreat(Facility& facility);
};


