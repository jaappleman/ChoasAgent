#pragma once

#include <string>
#include <algorithm>

class Anomaly
{
private:
    int anomalyId;
    std::string anomalyName;
    int anomalyStability;

public:
    // parameterized constructor
    Anomaly(int anomaly_id, std::string anomaly_name, int starting_stability);
    // display
    void displayInfo() const;
    // adjustment setters
    void adjustStability(int change_amount);
    // getters
    int getStability() const;
    int getAnomalyId() const;
    std::string getAnomalyName() const;
    std::string getStatus() const;
    // functions
    void performMaintenance(int repair_amount);
};