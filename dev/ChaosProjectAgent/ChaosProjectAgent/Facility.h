
#pragma once

// ============================================================
// Facility.h
// Purpose: Defines the Facility class, which manages facility
//          resources, anomalies, staff, upgrades, and daily
//          operations.
// ============================================================

// ======================== Includes ==========================

#include <vector>
#include <memory>

#include "Anomaly.h"
#include "Staff.h"
#include "FacilityUpgrade.h"

// ===================== Class Declaration ====================

class Facility
{
private:
    // ================= Facility Resources ====================

    int power;
    int credits;
    int facilityStability;
    int researchPoints;
    int currentDay;

    // ================= Facility Personnel ===================

    std::vector<std::unique_ptr<Staff>> staffRoster;

    // ================= Anomaly Registry ======================

    std::vector<Anomaly> anomalies;

    // ================= Upgrade Management ====================

    std::vector<int> staffAssignedToUpgrade;
    std::vector<int> facilityUpgradeLevels;
    std::vector<std::unique_ptr<FacilityUpgrade>> activeUpgrades;

public:
    // ===================== Constructor ======================

    Facility();

    // =================== Staff Management ===================

    bool hireStaff(std::unique_ptr<Staff> new_staff);
    bool dismissStaff(int staff_id);
    int getStaffCount() const;
    bool isStaffAvailable(int staff_id) const;
    Staff* findStaffById(int staff_id) const;

    // ================= Upgrade Management ===================

    bool assignStaffToUpgrade(int staff_id);
    bool unassignStaffFromUpgrade(int staff_id);
    bool isStaffAssignedToUpgrade(int staff_id) const;
    bool startFacilityUpgrade(int upgrade_type);
    void processFacilityUpgrades();
    void completeFacilityUpgrade(int upgrade_type);
    int getUpgradeLevel(int upgrade_type) const;

    int getUpgradeCost(int upgrade_type) const;
    int getUpgradeRequiredStaff(int upgrade_type) const;
    int getUpgradeDuration(int upgrade_type) const;

    // ================== Display Functions ====================

    void displayStatus() const;
    void displayAnomalies() const;
    void displayStaffRoster() const;
    void displayFacilityUpgrades() const;

    // ================= Resource Management ===================

    void adjustPower(int change_amount);
    void adjustCredits(int change_amount);
    void adjustFacilityStability(int change_amount);
    void addResearchPoints(int research_amount);
    bool spendResearchPoints(int research_cost);

    // ======================= Getters =========================

    int getPower() const;
    int getCredits() const;
    int getFacilityStability() const;
    int getCurrentDay() const;
    int getResearchPoints() const;

    // ================= Anomaly Management ====================

    Anomaly* findAnomalyById(int anomaly_id);
    bool performAnomalyMaintenance(int anomaly_id, int repair_amount);

    // ================= Daily Operations ======================

    void advanceDay();
    void consumeDailyPower();
    void monitorAnomalyStability();
    void processStaffContributions();
    int calculateGovernmentFunding() const;
};
