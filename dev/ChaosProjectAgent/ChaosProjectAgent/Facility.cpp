#include "Facility.h"
#include <iostream>
#include <algorithm>

#include "Researcher.h"
#include "Technician.h"
#include "SecurityOfficer.h"
#include "MedicalOfficer.h"
#include "ContainmentSpecialist.h"

// constructor
Facility::Facility()
    : power(100),
    credits(500),
    facilityStability(100),
    researchPoints(0),
    currentDay(1)
{
    anomalies.emplace_back(1, "Whispering Archive", 85);
    anomalies.emplace_back(2, "Shifting Corridor", 55);
    anomalies.emplace_back(3, "Forgotten Signal", 20);
}
bool Facility::hireStaff(std::unique_ptr<Staff> new_staff)
{
    // Prevent hiring a null staff pointer.
    if (new_staff == nullptr)
    {
        return false;
    }
    // Prevent duplicate staff IDs.
    if (findStaffById(new_staff->getStaffId()) != nullptr)
    {
        return false;
    }
    // Check whether the Facility can afford the hiring cost.
    if (credits < new_staff->getHiringCost())
    {
        return false;
    }

    // Deduct the hiring cost.
    adjustCredits(-new_staff->getHiringCost());

    // Transfer ownership to the Facility roster.
    staffRoster.push_back(std::move(new_staff));

    return true;
}
bool Facility::dismissStaff(int staff_id)
{
    // Search for the staff member.
    for (auto it = staffRoster.begin(); it != staffRoster.end(); ++it)
    {
        if ((*it)->getStaffId() == staff_id)
        {
            // Prevent dismissal while the employee is assigned to an upgrade.
            if (!isStaffAvailable(staff_id))
            {
                return false;
            }

            // Remove the staff member from the roster.
            staffRoster.erase(it);

            return true;
        }
    }

    // No matching staff member was found.
    return false;
}
int Facility::getStaffCount() const
{
    // Return the number of employees currently in the roster.
    return static_cast<int>(staffRoster.size());
}
bool Facility::isStaffAvailable(int staff_id) const
{
    // Verify that the employee exists in the Facility roster.
    if (findStaffById(staff_id) == nullptr)
    {
        return false;
    }

    // Check whether the employee is assigned to an upgrade.
    for (int assigned_id : staffAssignedToUpgrade)
    {
        if (assigned_id == staff_id)
        {
            return false;
        }
    }

    // The employee exists and is not assigned to an upgrade.
    return true;
}

bool Facility::assignStaffToUpgrade(int staff_id)
{
    // Verify that the employee exists and is available.
    if (!isStaffAvailable(staff_id))
    {
        return false;
    }

    // Record the employee's assignment to an upgrade.
    staffAssignedToUpgrade.push_back(staff_id);

    return true;
}
bool Facility::unassignStaffFromUpgrade(int staff_id)
{
    // Search for the employee's assignment.
    for (auto it = staffAssignedToUpgrade.begin();
        it != staffAssignedToUpgrade.end(); ++it)
    {
        if (*it == staff_id)
        {
            // Remove the employee's upgrade assignment.
            staffAssignedToUpgrade.erase(it);

            return true;
        }
    }

    // The employee was not assigned to an upgrade.
    return false;
}
bool Facility::isStaffAssignedToUpgrade(int staff_id) const
{
    // Verify that the employee exists in the Facility roster.
    if (findStaffById(staff_id) == nullptr)
    {
        return false;
    }

    // Search for the employee's ID in the assignment list.
    for (int assigned_id : staffAssignedToUpgrade)
    {
        if (assigned_id == staff_id)
        {
            return true;
        }
    }

    // The employee exists but is not assigned to an upgrade.
    return false;
}



// display stats for facility
void Facility::displayStatus() const
{
    std::cout << "\n========== FACILITY STATUS ==========\n";

    std::cout << "Current Day: " << currentDay << '\n';
    std::cout << "Power: " << power << '\n';
    std::cout << "Credits: " << credits << '\n';
    std::cout << "Research Points: " << researchPoints << '\n';
    std::cout << "Facility Stability: " << facilityStability << "%\n";

    std::cout << "Registered Anomalies: " << anomalies.size() << '\n';

    std::cout << "=====================================\n";
}
// display Anomalies in vector
void Facility::displayAnomalies() const
{
    std::cout << "\n========== ANOMALY REGISTRY ==========\n\n";

    for (const Anomaly& anomaly : anomalies)
    {
        anomaly.displayInfo();
        std::cout << "Status: " << anomaly.getStatus() << "\n\n";
    }

    std::cout << "======================================\n";
}
void Facility::displayStaffRoster() const
{
    std::cout << "\n========== FACILITY STAFF ROSTER ==========\n";

    // Handle an empty staff roster.
    if (staffRoster.empty())
    {
        std::cout << "No staff members currently employed.\n";
        return;
    }

    // Display information for every staff member.
    for (const auto& staff : staffRoster)
    {
        // Display the employee's personal information.
        staff->displayInfo();

        // Display the employee's current assignment status.
        if (isStaffAssignedToUpgrade(staff->getStaffId()))
        {
            std::cout << "Assignment Status: Assigned to Upgrade\n";
        }
        else
        {
            std::cout << "Assignment Status: Available\n";
        }

        std::cout << "------------------------------------------\n";
    }
}
// adjust Power
void Facility::adjustPower(int change_amount)
{
    power += change_amount;

    if (power < 0)
    {
        power = 0;
    }
}
// adjust Credits
void Facility::adjustCredits(int change_amount)
{
    credits += change_amount;

    if (credits < 0)
    {
        credits = 0;
    }
}
// adjust Facility Stability
void Facility::adjustFacilityStability(int change_amount)
{
    facilityStability = std::clamp(facilityStability + change_amount, 0, 100);
}
void Facility::addResearchPoints(int research_amount)
{
    if (research_amount <= 0)
    {
        return;
    }

    researchPoints += research_amount;
}
bool Facility::spendResearchPoints(int research_cost)
{
    if (research_cost <= 0)
    {
        return false;
    }

    if (researchPoints < research_cost)
    {
        return false;
    }

    researchPoints -= research_cost;

    return true;
}
// get Power
int Facility::getPower() const
{
    return power;
}
// get Credits
int Facility::getCredits() const
{
    return credits;
}
// get Facility Stability
int Facility::getFacilityStability() const
{
    return facilityStability;
}
// get current Day
int Facility::getCurrentDay() const
{
    return currentDay;
}
int Facility::getResearchPoints() const
{
    return researchPoints;
}
Staff* Facility::findStaffById(int staff_id) const
{
    // Search the staff roster for the requested ID.
    for (const auto& staff : staffRoster)
    {
        if (staff->getStaffId() == staff_id)
        {
            return staff.get();
        }
    }

    // Return nullptr if no matching staff member exists.
    return nullptr;
}
// find Anomaly* by ID
Anomaly* Facility::findAnomalyById(int anomaly_id)
{
    for (Anomaly& anomaly : anomalies)
    {
        if (anomaly.getAnomalyId() == anomaly_id)
        {
            return &anomaly;
        }
    }

    return nullptr;
}
// advance Day once
void Facility::advanceDay()
{
    currentDay++;
    consumeDailyPower();
    monitorAnomalyStability();
    processStaffContributions();
}
// consume daily power
void Facility::consumeDailyPower()
{
    adjustPower(-10);
}
// monitor anomaly instability
void Facility::monitorAnomalyStability()
{
    for (const Anomaly& anomaly : anomalies)
    {
        if (anomaly.getStability() <= 30)
        {
            adjustFacilityStability(-5);
        }
    }
}

// Process daily contributions from available staff members.
void Facility::processStaffContributions()
{
    for (const auto& staff : staffRoster)
    {
        // Skip staff members assigned to an active facility upgrade.
        if (!isStaffAvailable(staff->getStaffId()))
        {
            continue;
        }

        // Researchers generate research points.
        if (Researcher* researcher = dynamic_cast<Researcher*>(staff.get()))
        {
            researcher->conductResearch(*this);
        }

        // Technicians restore facility power.
        else if (Technician* technician = dynamic_cast<Technician*>(staff.get()))
        {
            technician->restorePower(*this);
        }

        // Security Officers restore facility stability.
        else if (SecurityOfficer* officer = dynamic_cast<SecurityOfficer*>(staff.get()))
        {
            officer->respondToSecurityThreat(*this);
        }
    }
}

bool Facility::performAnomalyMaintenance(int anomaly_id, int repair_amount)
{
    const int maintenance_cost = 50;
    const int power_cost = 10;
    Anomaly* anomaly = findAnomalyById(anomaly_id);
    if (anomaly == nullptr)
    {
        return false;
    }
    if (credits < maintenance_cost)
    {
        return false;
    }
    if (power < power_cost)
    {
        return false;
    }
    adjustCredits(-maintenance_cost);
    adjustPower(-power_cost);
    anomaly->performMaintenance(repair_amount);
    return true;
}

