
#include "Game.h"

#include <iostream>
#include <string>
#include <cctype>
#include <memory>
#include <utility>

#include "Researcher.h"
#include "Technician.h"
#include "ContainmentSpecialist.h"
#include "SecurityOfficer.h"
#include "MedicalOfficer.h"

int getMenuChoice();

Game::Game()
{
    isRunning = true;
}

void Game::displayMainMenu()
{
    std::cout << "\n========== ANOMALY//CONTAINMENT ==========\n";
    std::cout << "1. View Facility Status\n";
    std::cout << "2. View Anomaly Registry\n";
    std::cout << "3. View Staff Roster\n";
    std::cout << "4. Hire Staff\n";
    std::cout << "5. Dismiss Staff\n";
    std::cout << "6. Perform Anomaly Maintenance\n";
    std::cout << "7. Advance Day\n";
    std::cout << "8. Start Campaign (Coming Soon)\n";
    std::cout << "9. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Select an option: ";
}

void Game::displayFacilityStatus()
{
    facility.displayStatus();
}

void Game::displayAnomalyRegistry()
{
    facility.displayAnomalies();
}

void Game::displayStaffRoster()
{
    facility.displayStaffRoster();
}

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

int getMenuChoice()
{
    std::string input;

    if (!std::getline(std::cin, input))
    {
        return 9;
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
            std::cout << "\nCampaign functionality is coming soon.\n";
            break;

        case 9:
            isRunning = false;
            std::cout << "\nShutting down facility systems...\n";
            break;

        default:
            std::cout << "\nInvalid selection. Please try again.\n";
            break;
        }
    }
}
