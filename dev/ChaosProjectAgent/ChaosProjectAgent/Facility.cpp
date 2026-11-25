#include "Facility.h"
#include <iostream>
#include <algorithm>

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

