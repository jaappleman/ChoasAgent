
#pragma once

// ============================================================
// Game.h
// Purpose: Defines the Game class, which manages the main
//          game loop, player interaction, menu navigation,
//          and communication with the Facility system.
// ============================================================

// ======================== Includes ==========================

#include "Facility.h"

// ===================== Class Declaration ====================

class Game
{
private:
    // =================== Game State =========================

    bool isRunning;

    // ================= Facility Management ==================

    Facility facility;

public:
    // ===================== Constructor ======================

    Game();

    // ===================== Game Loop ========================

    void run();

    // =================== Menu Functions =====================

    void displayMainMenu();

    // ================= Facility Displays ====================

    void displayFacilityStatus();
    void displayAnomalyRegistry();
    void displayStaffRoster();

    // ================= Player Actions =======================

    void performAnomalyMaintenance();
    void manageFacilityUpgrades();
    void advanceDay();
    void hireStaff();
    void dismissStaff();
};
