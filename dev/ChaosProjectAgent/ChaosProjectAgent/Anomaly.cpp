
#include "Anomaly.h"

// ============================================================
// Anomaly.cpp
// Purpose: Implements anomaly identification, stability
//          management, status reporting, and maintenance.
// ============================================================

// ======================== Includes ==========================

#include <iostream>
#include <algorithm>

// ====================== Constructor =========================

Anomaly::Anomaly(int anomaly_id, std::string anomaly_name,
    int starting_stability)
    : anomalyId(anomaly_id),
    anomalyName(anomaly_name),
    anomalyStability(std::clamp(starting_stability, 0, 100))
{
}

// ======================== Display ===========================

void Anomaly::displayInfo() const
{
    std::cout << "Anomaly ID: " << anomalyId << '\n';
    std::cout << "Name: " << anomalyName << '\n';
    std::cout << "Stability: " << anomalyStability << "%\n";
}

// ================ Stability Management ======================

void Anomaly::adjustStability(int change_amount)
{
    anomalyStability = std::clamp(
        anomalyStability + change_amount, 0, 100);
}

void Anomaly::performMaintenance(int repair_amount)
{
    adjustStability(repair_amount);
}

// ======================= Getters ============================

int Anomaly::getStability() const
{
    return anomalyStability;
}

int Anomaly::getAnomalyId() const
{
    return anomalyId;
}

std::string Anomaly::getAnomalyName() const
{
    return anomalyName;
}

std::string Anomaly::getStatus() const
{
    if (anomalyStability >= 70)
    {
        return "Stable";
    }
    else if (anomalyStability >= 31)
    {
        return "Unstable";
    }
    else
    {
        return "Critical";
    }
}
