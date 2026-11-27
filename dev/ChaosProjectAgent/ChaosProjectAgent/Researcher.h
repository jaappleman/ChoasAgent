
#pragma once

// ============================================================
// Researcher.h
// Purpose: Defines the Researcher class, a specialized Staff
//          member responsible for conducting facility research
//          and generating research points.
// ============================================================

// ======================== Includes ==========================

#include "Staff.h"

// ================= Forward Declarations ====================

class Facility;

// ===================== Class Declaration ====================

class Researcher : public Staff
{
public:
    // ===================== Constructor ======================

    // Initialize the shared Staff properties.
    Researcher(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );

    // ===================== Staff Duties =====================

    // Display the Researcher's assigned duty.
    void performDuty() override;

    // ================= Research Contributions ===============

    // Accumulate research points based on the Researcher's skill level.
    void conductResearch(Facility& facility);
};

