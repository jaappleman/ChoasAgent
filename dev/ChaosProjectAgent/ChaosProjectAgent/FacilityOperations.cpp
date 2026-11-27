
#include "Facility.h"

#include <iostream>

// ============================================================
// FacilityOperations.cpp
// Purpose: Implements daily facility operations, including
//          resource consumption, anomaly monitoring, government
//          funding, and anomaly maintenance.
// ============================================================

// ===================== Daily Operations =====================

// Advance the facility by one in-game day.
void Facility::advanceDay()
{
    currentDay++;

    // Receive government funding based on anomaly stability.
    int governmentFunding = calculateGovernmentFunding();
    adjustCredits(governmentFunding);

    std::cout << "\nGovernment funding received: "
        << governmentFunding << " credits.\n";

    // Process the facility's daily operations.
    consumeDailyPower();
    monitorAnomalyStability();
    processStaffContributions();
    processFacilityUpgrades();
}

// Consume power required for daily facility operations.
void Facility::consumeDailyPower()
{
    adjustPower(-10);
}

// Monitor anomaly stability and apply facility penalties.
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

// ================= Government Funding =======================

// Calculate government funding based on anomaly count and stability.
int Facility::calculateGovernmentFunding() const
{
    const int base_funding_per_anomaly = 100;

    int total_funding = 0;

    for (const Anomaly& anomaly : anomalies)
    {
        total_funding += base_funding_per_anomaly
            * anomaly.getStability() / 100;
    }

    return total_funding;
}

// ================= Anomaly Maintenance =======================

// Perform maintenance on an anomaly if sufficient resources exist.
bool Facility::performAnomalyMaintenance(int anomaly_id, int repair_amount)
{
    const int maintenance_cost = 50;
    const int power_cost = 10;

    Anomaly* anomaly = findAnomalyById(anomaly_id);

    // Verify that the requested anomaly exists.
    if (anomaly == nullptr)
    {
        return false;
    }

    // Check whether the facility can afford maintenance.
    if (credits < maintenance_cost)
    {
        return false;
    }

    // Check whether sufficient power is available.
    if (power < power_cost)
    {
        return false;
    }

    // Deduct resources and perform maintenance.
    adjustCredits(-maintenance_cost);
    adjustPower(-power_cost);
    anomaly->performMaintenance(repair_amount);

    return true;
}
