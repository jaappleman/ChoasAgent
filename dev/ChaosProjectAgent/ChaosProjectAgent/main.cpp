// ============================================================
// main.cpp
// Purpose: Program entry point and automated system tests.
// ============================================================

// ======================== Includes ==========================

#include <iostream>

// Core game systems
#include "Game.h"
#include "Facility.h"

// Utilities and visual assets
#include "Helper.h"
#include "Subject.h"
#include "Testing.h"

// ============================================================
//                       PROGRAM ENTRY
// ============================================================

int main()
{
	// ==========================================
	//                TITLE BANNERS
	// ==========================================
	
	Helper::AnomalyBanner();

	// ==========================================
	//     UNCOMMENT TO RUN ALL SYSTEM TESTS
	// ==========================================

	/// Testing::runAllTests();
	
	// ==========================================
	//             PROGRAM EXIT
	// ==========================================

	Game game;
	game.run();

	return 0;
}