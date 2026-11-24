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
    Anomaly(int anomaly_id, std::string anomaly_name, int starting_stability)
        : anomalyId(anomaly_id),
        anomalyName(anomaly_name),
        anomalyStability(std::clamp(starting_stability, 0, 100))
    {
    }

    void displayInfo() const;
    void adjustStability(int change_amount);

    // getters
    int getStability() const;
    int getAnomalyId() const;
    std::string getAnomalyName() const;
    std::string getStatus() const;
};