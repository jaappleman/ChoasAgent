
#pragma once

// ============================================================
// FacilityUpgrade.h
// Purpose: Defines FacilityUpgrade, a derived project class
//          that manages facility improvement projects and
//          their associated staffing requirements.
// ============================================================

// ======================== Includes ==========================

#include <string>
#include <vector>

#include "FacilityProject.h"

// ===================== Class Declaration ====================

class FacilityUpgrade : public FacilityProject
{
private:
    // ================= Upgrade Information ==================

    int upgradeLevel;
    int creditCost;
    int requiredStaff;
    int upgradeType;

    // ================= Assigned Personnel ==================

    std::vector<int> assignedStaffIds;

public:
    // ===================== Constructor ======================

    FacilityUpgrade(
        std::string name,
        int currentLevel,
        int cost,
        int staffRequired,
        int duration,
        int type,
        std::vector<int> assigned_staff_ids
    );

    // ======================= Getters ========================

    int getUpgradeLevel() const;
    int getCreditCost() const;
    int getRequiredStaff() const;
    int getUpgradeType() const;

    const std::vector<int>& getAssignedStaffIds() const;
};

