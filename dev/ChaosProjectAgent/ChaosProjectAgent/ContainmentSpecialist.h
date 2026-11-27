

#pragma once


#pragma once

// ============================================================
// ContainmentSpecialist.h
// Purpose: Defines the ContainmentSpecialist class, which
//          specializes in stabilizing contained anomalies.
// ============================================================

// ======================== Includes ==========================

#include "Staff.h"

// ================= Forward Declarations ====================

class Facility;

// ===================== Class Declaration ====================

class ContainmentSpecialist : public Staff
{
public:
    // ===================== Constructor ======================

    ContainmentSpecialist(
        int staff_id,
        std::string staff_name,
        int hiring_cost,
        int skill_level
    );

    // ===================== Staff Duties =====================

    void performDuty() override;

    // ================= Anomaly Management ====================

    void stabilizeAnomaly(Facility& facility, int anomaly_id);
};




