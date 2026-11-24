#include "Anomaly.h"
#include <iostream>

void Anomaly::displayInfo() const
{
    std::cout << "Anomaly ID: " << anomalyId << '\n';
    std::cout << "Name: " << anomalyName << '\n';
    std::cout << "Stability: " << anomalyStability << "%\n";
}

void Anomaly::adjustStability(int change_amount)
{
    anomalyStability += change_amount;

    if (anomalyStability > 100)
    {
        anomalyStability = 100;
    }

    if (anomalyStability < 0)
    {
        anomalyStability = 0;
    }
}

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
