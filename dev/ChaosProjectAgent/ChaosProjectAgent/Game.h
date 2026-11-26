#pragma once
#include "Facility.h"

class Game
{
private:
    bool isRunning;
    Facility facility;

public:
    Game();

    void run();
    void displayMainMenu();
    void displayFacilityStatus();
    void displayAnomalyRegistry();
    void displayStaffRoster();
    void performAnomalyMaintenance();
    void advanceDay();
    void hireStaff();
    void dismissStaff();
};