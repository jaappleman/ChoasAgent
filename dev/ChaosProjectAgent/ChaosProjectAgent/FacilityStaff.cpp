
#include "Facility.h"

#include <iostream>
#include <utility>

#include "Researcher.h"
#include "Technician.h"
#include "SecurityOfficer.h"

// ============================================================
// FacilityStaff.cpp
// Purpose: Implements staff recruitment, dismissal, assignment,
//          roster management, and daily staff contributions.
// ============================================================

// =================== Staff Recruitment ======================

// Hire a staff member if the Facility meets all requirements.
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

// Dismiss an available staff member from the roster.
bool Facility::dismissStaff(int staff_id)
{
    // Search for the staff member.
    for (auto it = staffRoster.begin(); it != staffRoster.end(); ++it)
    {
        if ((*it)->getStaffId() == staff_id)
        {
            // Prevent dismissal while assigned to an upgrade.
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

// Return the number of employees currently in the roster.
int Facility::getStaffCount() const
{
    return static_cast<int>(staffRoster.size());
}

// ================= Staff Availability =======================

// Check whether a staff member exists and is available.
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

    return true;
}

// Find a staff member by ID.
Staff* Facility::findStaffById(int staff_id) const
{
    for (const auto& staff : staffRoster)
    {
        if (staff->getStaffId() == staff_id)
        {
            return staff.get();
        }
    }

    return nullptr;
}

// ================= Staff Assignments ========================

// Assign an available staff member to an upgrade.
bool Facility::assignStaffToUpgrade(int staff_id)
{
    if (!isStaffAvailable(staff_id))
    {
        return false;
    }

    staffAssignedToUpgrade.push_back(staff_id);

    return true;
}

// Release a staff member from an upgrade assignment.
bool Facility::unassignStaffFromUpgrade(int staff_id)
{
    for (auto it = staffAssignedToUpgrade.begin();
        it != staffAssignedToUpgrade.end(); ++it)
    {
        if (*it == staff_id)
        {
            staffAssignedToUpgrade.erase(it);

            return true;
        }
    }

    return false;
}

// Check whether a staff member is assigned to an upgrade.
bool Facility::isStaffAssignedToUpgrade(int staff_id) const
{
    if (findStaffById(staff_id) == nullptr)
    {
        return false;
    }

    for (int assigned_id : staffAssignedToUpgrade)
    {
        if (assigned_id == staff_id)
        {
            return true;
        }
    }

    return false;
}

// =================== Staff Display ==========================

// Display information and assignment status for all staff.
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

// ================= Daily Staff Contributions ================

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
