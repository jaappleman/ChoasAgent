#include "Anomaly.h"
#include <iostream>
//default constructor
Anomaly::Anomaly(int anomaly_id, std::string anomaly_name, int starting_stability)
    : anomalyId(anomaly_id),
    anomalyName(anomaly_name),
    anomalyStability(std::clamp(starting_stability, 0, 100))
{
}
// display anomaly info
void Anomaly::displayInfo() const
{
    std::cout << "Anomaly ID: " << anomalyId << '\n';
    std::cout << "Name: " << anomalyName << '\n';
    std::cout << "Stability: " << anomalyStability << "%\n";
}
// adjust anomaly Stability
void Anomaly::adjustStability(int change_amount)
{
    anomalyStability = std::clamp(anomalyStability + change_amount, 0, 100);
}
// get anomaly Stability
int Anomaly::getStability() const
{
    return anomalyStability;
}
// get anomaly ID
int Anomaly::getAnomalyId() const
{
    return anomalyId;
}
// get anomaly Name
std::string Anomaly::getAnomalyName() const
{
    return anomalyName;
}
// get anomaly Status
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
