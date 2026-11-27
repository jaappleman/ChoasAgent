
#include "Facility.h"

#include <algorithm>
#include <iostream>

// ============================================================
// Facility.cpp
// Purpose: Implements core facility functionality, including
//          resource management, status displays, and anomaly
//          lookup.
// ============================================================

// ===================== Constructor ==========================

Facility::Facility()
    : power(100),
    credits(1500),
    facilityStability(100),
    researchPoints(0),
    currentDay(1),
    facilityUpgradeLevels(4, 0)
{
    anomalies.emplace_back(1, "Whispering Archive", 85);
    anomalies.emplace_back(2, "Shifting Corridor", 55);
    anomalies.emplace_back(3, "Forgotten Signal", 20);
}

// =================== Display Functions ======================

// Display current facility statistics.
void Facility::displayStatus() const
{
    std::cout << "\n========== FACILITY STATUS ==========\n";

    std::cout << "Current Day: " << currentDay << '\n';
    std::cout << "Power: " << power << '\n';
    std::cout << "Credits: " << credits << '\n';
    std::cout << "Government Funding: "
        << calculateGovernmentFunding()
        << " credits/day\n";
    std::cout << "Research Points: " << researchPoints << '\n';
    std::cout << "Facility Stability: " << facilityStability << "%\n";
    std::cout << "Registered Anomalies: " << anomalies.size() << '\n';

    std::cout << "=====================================\n";
}

// Display all registered anomalies.
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

// ================= Resource Management ======================

// Adjust facility power, preventing negative values.
void Facility::adjustPower(int change_amount)
{
    power += change_amount;

    if (power < 0)
    {
        power = 0;
    }
}

// Adjust facility credits, preventing negative values.
void Facility::adjustCredits(int change_amount)
{
    credits += change_amount;

    if (credits < 0)
    {
        credits = 0;
    }
}

// Adjust facility stability, keeping it between 0 and 100.
void Facility::adjustFacilityStability(int change_amount)
{
    facilityStability = std::clamp(
        facilityStability + change_amount, 0, 100);
}

// Add research points, ignoring nonpositive amounts.
void Facility::addResearchPoints(int research_amount)
{
    if (research_amount <= 0)
    {
        return;
    }

    researchPoints += research_amount;
}

// Spend research points if sufficient points are available.
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

// ======================== Getters ============================

int Facility::getPower() const
{
    return power;
}

int Facility::getCredits() const
{
    return credits;
}

int Facility::getFacilityStability() const
{
    return facilityStability;
}

int Facility::getCurrentDay() const
{
    return currentDay;
}

int Facility::getResearchPoints() const
{
    return researchPoints;
}

// ================= Anomaly Management =======================

// Find an anomaly by ID and return its address.
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
