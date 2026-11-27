
#include "FacilityUpgrade.h"

#include <utility>

// ============================================================
// FacilityUpgrade.cpp
// Purpose: Implements facility upgrade projects, including
//          initialization of upgrade-specific information and
//          retrieval of upgrade details.
// ============================================================

// ===================== Constructor ==========================

// Initialize a facility upgrade project.
FacilityUpgrade::FacilityUpgrade(
    std::string name,
    int currentLevel,
    int cost,
    int staffRequired,
    int duration,
    int type,
    std::vector<int> assigned_staff_ids
)
    : FacilityProject(name, duration),
    upgradeLevel(currentLevel + 1),
    creditCost(cost),
    requiredStaff(staffRequired),
    upgradeType(type),
    assignedStaffIds(std::move(assigned_staff_ids))
{
}

// ======================= Getters ============================

// Return the target upgrade level.
int FacilityUpgrade::getUpgradeLevel() const
{
    return upgradeLevel;
}

// Return the credit cost of the upgrade.
int FacilityUpgrade::getCreditCost() const
{
    return creditCost;
}

// Return the required number of staff members.
int FacilityUpgrade::getRequiredStaff() const
{
    return requiredStaff;
}

// Return the upgrade type identifier.
int FacilityUpgrade::getUpgradeType() const
{
    return upgradeType;
}

// Return the staff assigned to this upgrade project.
const std::vector<int>& FacilityUpgrade::getAssignedStaffIds() const
{
    return assignedStaffIds;
}
