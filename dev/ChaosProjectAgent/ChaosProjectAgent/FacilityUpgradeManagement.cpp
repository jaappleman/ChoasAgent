
#include "Facility.h"

#include <iostream>
#include <string>
#include <utility>

// ============================================================
// FacilityUpgradeManagement.cpp
// Purpose: Implements facility upgrade management, including
//          project creation, progression, completion, staffing,
//          and upgrade specifications.
// ============================================================

// ================= Upgrade Specifications ==================

struct UpgradeSpecification
{
    int creditCost;
    int requiredStaff;
    int duration;
};

constexpr UpgradeSpecification upgradeSpecifications[] =
{
    { 300, 2, 3 }, // Power Infrastructure
    { 350, 2, 4 }, // Containment Systems
    { 500, 3, 5 }, // Facility Expansion
    { 400, 2, 4 }  // Research Laboratories
};

// ================= Upgrade Project Management ===============

// Start a new facility upgrade project.
bool Facility::startFacilityUpgrade(int upgrade_type)
{
    // Validate the upgrade type.
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(facilityUpgradeLevels.size()))
    {
        return false;
    }

    // Prevent starting an upgrade that is already at its maximum level.
    const int maximum_upgrade_level = 3;

    if (facilityUpgradeLevels[upgrade_type] >= maximum_upgrade_level)
    {
        return false;
    }

    // Prevent duplicate active upgrades of the same type.
    for (const auto& upgrade : activeUpgrades)
    {
        if (upgrade->getUpgradeType() == upgrade_type)
        {
            return false;
        }
    }

    // Retrieve the upgrade specifications.
    const UpgradeSpecification& specification =
        upgradeSpecifications[upgrade_type];

    // Check whether the facility can afford the upgrade.
    if (credits < specification.creditCost)
    {
        return false;
    }

    // Check whether enough staff are available for the upgrade.
    int availableStaff = 0;

    for (const auto& staff : staffRoster)
    {
        if (isStaffAvailable(staff->getStaffId()))
        {
            availableStaff++;
        }
    }

    if (availableStaff < specification.requiredStaff)
    {
        return false;
    }

    std::vector<int> newlyAssignedStaff;

    // Assign available staff to the upgrade.
    int staffAssigned = 0;

    for (const auto& staff : staffRoster)
    {
        if (staffAssigned >= specification.requiredStaff)
        {
            break;
        }

        int staff_id = staff->getStaffId();

        if (isStaffAvailable(staff_id))
        {
            if (assignStaffToUpgrade(staff_id))
            {
                staffAssigned++;
                newlyAssignedStaff.push_back(staff_id);
            }
        }
    }

    // Roll back only assignments made during this attempt.
    if (staffAssigned < specification.requiredStaff)
    {
        for (int staff_id : newlyAssignedStaff)
        {
            unassignStaffFromUpgrade(staff_id);
        }

        return false;
    }

    // Create the facility upgrade project.
    std::unique_ptr<FacilityUpgrade> newUpgrade =
        std::make_unique<FacilityUpgrade>(
            "Facility Upgrade",
            facilityUpgradeLevels[upgrade_type],
            specification.creditCost,
            specification.requiredStaff,
            specification.duration,
            upgrade_type,
            newlyAssignedStaff
        );

    // Deduct the upgrade cost.
    adjustCredits(-specification.creditCost);

    // Store the active project.
    activeUpgrades.push_back(std::move(newUpgrade));

    return true;
}

// Advance active upgrades and remove completed projects.
void Facility::processFacilityUpgrades()
{
    for (auto it = activeUpgrades.begin(); it != activeUpgrades.end(); )
    {
        (*it)->advanceProject();

        if ((*it)->getIsCompleted())
        {
            completeFacilityUpgrade((*it)->getUpgradeType());

            it = activeUpgrades.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// Apply the effects of a completed facility upgrade.
void Facility::completeFacilityUpgrade(int upgrade_type)
{
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(facilityUpgradeLevels.size()))
    {
        return;
    }

    // Increase the upgrade level.
    facilityUpgradeLevels[upgrade_type]++;

    std::cout << "\n========== PROJECT COMPLETED ==========\n";
    std::cout << "Facility upgrade completed successfully!\n";

    // Find the completed upgrade project.
    for (const auto& upgrade : activeUpgrades)
    {
        if (upgrade->getUpgradeType() == upgrade_type &&
            upgrade->getIsCompleted())
        {
            // Release only staff assigned to this project.
            for (int staff_id : upgrade->getAssignedStaffIds())
            {
                unassignStaffFromUpgrade(staff_id);

                Staff* releasedStaff = findStaffById(staff_id);

                if (releasedStaff != nullptr)
                {
                    std::cout << "Staff member released for duty: "
                        << releasedStaff->getStaffName()
                        << " (ID: " << staff_id << ")\n";
                }
            }

            std::cout << "======================================\n";

            break;
        }
    }
}

// ================= Upgrade Information ======================

// Get the current level of a facility upgrade.
int Facility::getUpgradeLevel(int upgrade_type) const
{
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(facilityUpgradeLevels.size()))
    {
        return -1;
    }

    return facilityUpgradeLevels[upgrade_type];
}

// Return the credit cost of an upgrade.
int Facility::getUpgradeCost(int upgrade_type) const
{
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(
            sizeof(upgradeSpecifications) / sizeof(upgradeSpecifications[0])))
    {
        return -1;
    }

    return upgradeSpecifications[upgrade_type].creditCost;
}

// Return the number of staff required for an upgrade.
int Facility::getUpgradeRequiredStaff(int upgrade_type) const
{
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(
            sizeof(upgradeSpecifications) / sizeof(upgradeSpecifications[0])))
    {
        return -1;
    }

    return upgradeSpecifications[upgrade_type].requiredStaff;
}

// Return the construction duration of an upgrade.
int Facility::getUpgradeDuration(int upgrade_type) const
{
    if (upgrade_type < 0 ||
        upgrade_type >= static_cast<int>(
            sizeof(upgradeSpecifications) / sizeof(upgradeSpecifications[0])))
    {
        return -1;
    }

    return upgradeSpecifications[upgrade_type].duration;
}

// =================== Upgrade Display ========================

// Display facility upgrade levels and active construction projects.
void Facility::displayFacilityUpgrades() const
{
    const std::string upgradeNames[] =
    {
        "Power Infrastructure",
        "Containment Systems",
        "Facility Expansion",
        "Research Laboratories"
    };

    std::cout << "\n========== FACILITY UPGRADES ==========\n";

    // Display current upgrade levels.
    for (int i = 0; i < static_cast<int>(facilityUpgradeLevels.size()); i++)
    {
        std::cout << upgradeNames[i]
            << " | Level: " << facilityUpgradeLevels[i]
            << "/3\n";
    }

    // Display active construction projects.
    std::cout << "\n--- ACTIVE CONSTRUCTION ---\n";

    if (activeUpgrades.empty())
    {
        std::cout << "No active upgrade projects.\n";
    }
    else
    {
        for (const auto& upgrade : activeUpgrades)
        {
            int upgradeType = upgrade->getUpgradeType();

            std::cout << "\n" << upgradeNames[upgradeType]
                << " | Target Level: " << upgrade->getUpgradeLevel()
                << " | Days Remaining: " << upgrade->getDaysRemaining()
                << "\nAssigned Staff: ";

            const std::vector<int>& staffIds =
                upgrade->getAssignedStaffIds();

            for (int staffId : staffIds)
            {
                std::cout << staffId << " ";
            }

            std::cout << "\n";
        }
    }

    std::cout << "====================================\n";
}
