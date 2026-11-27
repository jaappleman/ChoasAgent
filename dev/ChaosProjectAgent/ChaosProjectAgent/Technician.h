
#pragma once

// ============================================================
// Technician.h
// Purpose: Defines the Technician class, a specialized Staff
//          member responsible for restoring facility power
//          based on technical skill.
// ============================================================

// ======================== Includes ==========================

#include "Staff.h"

// ================= Forward Declarations ====================

class Facility;

// ===================== Class Declaration ====================

class Technician : public Staff
{
public:
    // ===================== Constructor ======================

    // Initialize the shared Staff properties.
    Technician(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );

    // ===================== Staff Duties =====================

    // Display the Technician's assigned duty.
    void performDuty() override;

    // ================= Power Contributions ==================

    // Restore facility power based on the Technician's skill level.
    void restorePower(Facility& facility);
};


