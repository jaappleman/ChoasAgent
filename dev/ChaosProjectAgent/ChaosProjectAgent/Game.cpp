
#include "Game.h"

#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "Researcher.h"
#include "Technician.h"
#include "ContainmentSpecialist.h"
#include "SecurityOfficer.h"
#include "MedicalOfficer.h"

// ============================================================
// Game.cpp
// Purpose: Implements the main game loop, menu navigation,
//          player interactions, staff management, anomaly
//          maintenance, and facility upgrades.
// ============================================================

// ================= Internal Helper Functions ================

namespace
{
    // Read and validate an integer menu choice.
    int getMenuChoice()
    {
        std::string input;

        if (!std::getline(std::cin, input))
        {
            return 10;
        }

        try
        {
            size_t position = 0;
            int choice = std::stoi(input, &position);

            while (position < input.length() &&
                std::isspace(static_cast<unsigned char>(input[position])))
            {
                position++;
            }

            if (position != input.length())
            {
                return -1;
            }

            return choice;
        }
        catch (...)
        {
            return -1;
        }
    }
}

// ===================== Constructor ==========================

// Initialize the game.
Game::Game()
{
    isRunning = true;
}

// ===================== Game Loop ============================

// Run the main game loop.
void Game::run()
{
    while (isRunning)
    {
        displayMainMenu();

        int choice = getMenuChoice();

        switch (choice)
        {
        case 1:
            displayFacilityStatus();
            break;

        case 2:
            displayAnomalyRegistry();
            break;

        case 3:
            displayStaffRoster();
            break;

        case 4:
            hireStaff();
            break;

        case 5:
            dismissStaff();
            break;

        case 6:
            performAnomalyMaintenance();
            break;

        case 7:
            advanceDay();
            break;

        case 8:
            manageFacilityUpgrades();
            break;

        case 9:
            std::cout << "\nCampaign functionality is coming soon.\n";
            break;

        case 10:
            isRunning = false;
            std::cout << "\nShutting down facility systems...\n";
            break;

        default:
            std::cout << "\nInvalid selection. Please try again.\n";
            break;
        }
    }
}

// =================== Menu Functions =========================

// Display the main game menu.
void Game::displayMainMenu()
{
    std::cout << "\n========= anomaly//containment =========\n";
    std::cout << "1. View Facility Status\n";
    std::cout << "2. View Anomaly Registry\n";
    std::cout << "3. View Staff Roster\n";
    std::cout << "4. Hire Staff\n";
    std::cout << "5. Dismiss Staff\n";
    std::cout << "6. Perform Anomaly Maintenance\n";
    std::cout << "7. Advance Day\n";
    std::cout << "8. Facility Upgrades\n";
    std::cout << "9. Start Campaign (Coming Soon)\n";
    std::cout << "10. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Select an option: ";
}

// ================= Facility Displays ========================

// Display current facility statistics.
void Game::displayFacilityStatus()
{
    facility.displayStatus();
}

// Display the anomaly registry.
void Game::displayAnomalyRegistry()
{
    facility.displayAnomalies();
}

// Display the facility staff roster.
void Game::displayStaffRoster()
{
    facility.displayStaffRoster();
}

// ================= Anomaly Maintenance =======================

// Allow the player to perform anomaly maintenance.
void Game::performAnomalyMaintenance()
{
    std::cout << "\n========== ANOMALY MAINTENANCE ==========\n";

    // Display the anomalies so the player can choose one.
    facility.displayAnomalies();

    std::cout << "\nEnter the ID of the anomaly to maintain: ";
    int anomalyId = getMenuChoice();

    if (anomalyId == -1)
    {
        std::cout << "\nInvalid anomaly ID input.\n";
        return;
    }

    // Set the amount of stability restored by maintenance.
    const int repairAmount = 25;

    // Attempt maintenance through the Facility system.
    if (facility.performAnomalyMaintenance(anomalyId, repairAmount))
    {
        std::cout << "\nMaintenance completed successfully!\n";
    }
    else
    {
        std::cout << "\nMaintenance failed. Verify the anomaly ID and facility resources.\n";
    }

    // Display the updated facility information.
    std::cout << "\nUpdated Facility Status:\n";
    facility.displayStatus();

    std::cout << "\nUpdated Anomaly Registry:\n";
    facility.displayAnomalies();
}

// ================= Facility Upgrades ========================

// Allow the player to view and initiate facility upgrades.
void Game::manageFacilityUpgrades()
{
    const std::string upgradeNames[] =
    {
        "Power Infrastructure",
        "Containment Systems",
        "Facility Expansion",
        "Research Laboratories"
    };

    std::cout << "\n========== FACILITY UPGRADES ==========\n";

    // Display upgrade options and their requirements.
    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << ". " << upgradeNames[i]
            << " | Cost: " << facility.getUpgradeCost(i)
            << " Credits | Staff: "
            << facility.getUpgradeRequiredStaff(i)
            << " | Duration: "
            << facility.getUpgradeDuration(i)
            << " Days\n";
    }

    std::cout << "5. Return to Main Menu\n";
    std::cout << "====================================\n";

    facility.displayFacilityUpgrades();

    std::cout << "\nSelect an upgrade: ";
    int choice = getMenuChoice();

    if (choice == 5)
    {
        return;
    }

    if (choice < 1 || choice > 4)
    {
        std::cout << "\nInvalid upgrade selection.\n";
        return;
    }

    int upgradeType = choice - 1;

    if (facility.startFacilityUpgrade(upgradeType))
    {
        std::cout << "\nFacility upgrade project started successfully!\n";
    }
    else
    {
        std::cout << "\nUnable to start upgrade. Check credits, staff availability, "
            "upgrade level, or active projects.\n";
    }

    facility.displayStatus();
    facility.displayStaffRoster();
    facility.displayFacilityUpgrades();
}

// ================= Daily Advancement ========================

// Advance the facility by one in-game day.
void Game::advanceDay()
{
    std::cout << "\n========== ADVANCING DAY ==========\n";

    facility.advanceDay();

    std::cout << "\nDay advanced successfully!\n";

    // Display the results of daily processing.
    facility.displayStatus();

    std::cout << "\nUpdated Anomaly Registry:\n";
    facility.displayAnomalies();
}

// =================== Staff Management =======================

// Allow the player to recruit a new staff member.
void Game::hireStaff()
{
    std::cout << "\n========== STAFF RECRUITMENT ==========\n";
    std::cout << "1. Researcher (200 Credits)\n";
    std::cout << "2. Technician (150 Credits)\n";
    std::cout << "3. Containment Specialist (200 Credits)\n";
    std::cout << "4. Security Officer (200 Credits)\n";
    std::cout << "5. Medical Officer (250 Credits)\n";
    std::cout << "=======================================\n";

    std::cout << "Select a specialization: ";
    int choice = getMenuChoice();

    int hiringCost = 0;

    switch (choice)
    {
    case 1:
    case 3:
    case 4:
        hiringCost = 200;
        break;

    case 2:
        hiringCost = 150;
        break;

    case 5:
        hiringCost = 250;
        break;

    default:
        std::cout << "\nInvalid specialization selection.\n";
        return;
    }

    std::cout << "\nEnter a staff ID: ";
    int staffId = getMenuChoice();

    if (staffId < 1)
    {
        std::cout << "\nInvalid staff ID.\n";
        return;
    }

    std::string staffName;

    std::cout << "Enter the staff member's name: ";

    if (!std::getline(std::cin, staffName) || staffName.empty())
    {
        std::cout << "\nInvalid staff name.\n";
        return;
    }

    std::cout << "Enter skill level (1-20): ";
    int skillLevel = getMenuChoice();

    if (skillLevel < 1 || skillLevel > 20)
    {
        std::cout << "\nInvalid skill level.\n";
        return;
    }

    std::unique_ptr<Staff> newStaff;

    // Create the appropriate staff specialization.
    switch (choice)
    {
    case 1:
        newStaff = std::make_unique<Researcher>(
            staffId, staffName, hiringCost, skillLevel);
        break;

    case 2:
        newStaff = std::make_unique<Technician>(
            staffId, staffName, hiringCost, skillLevel);
        break;

    case 3:
        newStaff = std::make_unique<ContainmentSpecialist>(
            staffId, staffName, hiringCost, skillLevel);
        break;

    case 4:
        newStaff = std::make_unique<SecurityOfficer>(
            staffId, staffName, hiringCost, skillLevel);
        break;

    case 5:
        newStaff = std::make_unique<MedicalOfficer>(
            staffId, staffName, hiringCost, skillLevel);
        break;
    }

    // Transfer ownership to the Facility if hiring succeeds.
    if (facility.hireStaff(std::move(newStaff)))
    {
        std::cout << "\nStaff member hired successfully!\n";
    }
    else
    {
        std::cout << "\nHiring failed. Check available credits and staff ID.\n";
    }

    facility.displayStatus();
    facility.displayStaffRoster();
}

// Allow the player to dismiss an available staff member.
void Game::dismissStaff()
{
    std::cout << "\n========== STAFF DISMISSAL ==========\n";

    facility.displayStaffRoster();

    std::cout << "\nEnter the ID of the staff member to dismiss: ";
    int staffId = getMenuChoice();

    if (staffId < 1)
    {
        std::cout << "\nInvalid staff ID.\n";
        return;
    }

    if (facility.dismissStaff(staffId))
    {
        std::cout << "\nStaff member dismissed successfully!\n";
    }
    else
    {
        std::cout << "\nDismissal failed. Verify the staff ID and assignment status.\n";
    }

    facility.displayStatus();
    facility.displayStaffRoster();
}
