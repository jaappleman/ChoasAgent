
#pragma once

// ============================================================
// Anomaly.h
// Purpose: Defines the Anomaly class and manages anomaly
//          identity, stability, status, and maintenance.
// ============================================================

// ======================== Includes ==========================

#include <string>

// ===================== Class Declaration ====================

class Anomaly
{
private:
    // Anomaly identification
    int anomalyId;
    std::string anomalyName;

    // Anomaly condition
    int anomalyStability;

public:
    // ===================== Constructor ======================

    Anomaly(int anomaly_id, std::string anomaly_name,
        int starting_stability);

    // ===================== Display ==========================

    void displayInfo() const;

    // ================= Stability Management ==================

    void adjustStability(int change_amount);
    void performMaintenance(int repair_amount);

    // ======================= Getters =========================

    int getStability() const;
    int getAnomalyId() const;
    std::string getAnomalyName() const;
    std::string getStatus() const;
};
