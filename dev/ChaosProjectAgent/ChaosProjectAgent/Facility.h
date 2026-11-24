#pragma once

#include <vector>
#include "Anomaly.h"

class Facility
{
private:
	int power;
	int credits;
	int facilityStability;
	int currentDay;
	std::vector<Anomaly> anomalies;

public:
	// default constructor
	Facility();
	// display
	void displayStatus() const;
	void displayAnomalies() const;
	// adjustment setters
	void adjustPower(int change_amount);
	void adjustCredits(int change_amount);
	void adjustFacilityStability(int change_amount);
	// getters
	int getPower() const;
	int getCredits() const;
	int getFacilityStability() const;
	int getCurrentDay() const;
	Anomaly* findAnomalyById(int anomaly_id);
	// functions
	void advanceDay();
	void consumeDailyPower();
	void monitorAnomalyStability();
};