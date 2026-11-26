#pragma once
#include <vector>
#include <memory>
#include "Anomaly.h"
#include "Staff.h"

class Facility
{
private:
	int power;
	int credits;
	int facilityStability;
	int researchPoints;
	int currentDay;
	std::vector<Anomaly> anomalies;
	std::vector<std::unique_ptr<Staff>> staffRoster;
	std::vector<int> staffAssignedToUpgrade;

public:
	// default constructor
	Facility();
	// staff management
	bool hireStaff(std::unique_ptr<Staff> new_staff);
	bool dismissStaff(int staff_id);
	int getStaffCount() const;
	bool isStaffAvailable(int staff_id) const;
	bool assignStaffToUpgrade(int staff_id);
	bool unassignStaffFromUpgrade(int staff_id);
	bool isStaffAssignedToUpgrade(int staff_id) const;
	// display
	void displayStatus() const;
	void displayAnomalies() const;
	void displayStaffRoster() const;
	// adjustment setters
	void adjustPower(int change_amount);
	void adjustCredits(int change_amount);
	void adjustFacilityStability(int change_amount);
	void addResearchPoints(int research_amount);
	bool spendResearchPoints(int research_cost);
	// getters
	int getPower() const;
	int getCredits() const;
	int getFacilityStability() const;
	int getCurrentDay() const;
	int getResearchPoints() const;
	Staff* findStaffById(int staff_id) const;
	Anomaly* findAnomalyById(int anomaly_id);
	// functions
	void advanceDay();
	void consumeDailyPower();
	void monitorAnomalyStability();
	void processStaffContributions();
	bool performAnomalyMaintenance(int anomaly_id, int repair_amount);
};