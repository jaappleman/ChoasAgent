#pragma once

// ============================================================
// Helper.h
// Purpose: Provides shared utilities for console presentation,
//          input validation, randomization, and general
//          programming operations.
// ============================================================

// ======================== Includes ==========================

#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <utility>

// ===================== Helper Namespace =====================

namespace Helper
{
	// ================= Console Display Colors ================
	
	// BLUE
	const std::string BLUE = "\033[34m";
	const std::string LIGHT_BLUE = "\033[94m";
	const std::string SKY_BLUE = "\033[38;5;117m";
	const std::string DEEP_BLUE = "\033[38;5;27m";
	const std::string ELECTRIC_BLUE = "\033[38;5;39m";
	const std::string STEEL_BLUE = "\033[38;5;67m";
	const std::string ICE_BLUE = "\033[38;5;159m";
	const std::string MIDNIGHT_BLUE = "\033[38;5;17m";
	const std::string CYAN = "\033[36m";
	// GREEN
	const std::string GREEN = "\033[32m";
	const std::string LIME = "\033[38;5;118m";
	const std::string MINT = "\033[38;5;121m";
	const std::string LIGHT_GREEN = "\033[92m";
	const std::string EMERALD = "\033[38;5;40m";
	const std::string FOREST_GREEN = "\033[38;5;22m";
	const std::string TEAL = "\033[38;5;43m";
	const std::string OLIVE = "\033[38;5;142m";
	const std::string NEON_GREEN = "\033[38;5;46m";
	// RED
	const std::string RED = "\033[31m";
	const std::string CRIMSON = "\033[38;5;160m";
	const std::string SCARLET = "\033[38;5;196m";
	const std::string DARK_RED = "\033[38;5;88m";
	const std::string BRICK_RED = "\033[38;5;124m";
	const std::string CORAL_RED = "\033[38;5;203m";
	const std::string SALMON = "\033[38;5;210m";
	// PURPLE & VIOLET
	const std::string PURPLE = "\033[35m";
	const std::string LAVENDER = "\033[38;5;183m";
	const std::string VIOLET = "\033[38;5;129m";
	const std::string INDIGO = "\033[38;5;54m";
	const std::string DEEP_PURPLE = "\033[38;5;91m";
	const std::string MAGENTA = "\033[35m";
	const std::string NEON_PURPLE = "\033[38;5;165m";
	const std::string AMETHYST = "\033[38;5;141m";
	const std::string ORCHID = "\033[38;5;170m";
	// PINK
	const std::string PINK = "\033[95m";
	const std::string LIGHT_PINK = "\033[38;5;218m";
	const std::string HOT_PINK = "\033[38;5;205m";
	const std::string SOFT_PINK = "\033[38;5;213m";
	// YELLOW & GOLD
	const std::string YELLOW = "\033[33m";
	const std::string GOLD = "\033[38;5;220m";
	const std::string BRIGHT_YELLOW = "\033[93m";
	const std::string LEMON = "\033[38;5;226m";
	const std::string AMBER = "\033[38;5;214m";
	const std::string DARK_GOLD = "\033[38;5;136m";
	const std::string SUNFLOWER = "\033[38;5;220m";
	const std::string PALE_YELLOW = "\033[38;5;229m";
	const std::string CHAMPAGNE = "\033[38;5;223m";
	// ORANGE
	const std::string ORANGE = "\033[38;5;208m";
	const std::string DARK_ORANGE = "\033[38;5;166m";
	const std::string BRIGHT_ORANGE = "\033[38;5;202m";
	const std::string PEACH = "\033[38;5;216m";
	const std::string TANGERINE = "\033[38;5;208m";
	const std::string APRICOT = "\033[38;5;215m";
	// WHITE & GRAY & BLACK
	const std::string WHITE = "\033[37m";
	const std::string BRIGHT_WHITE = "\033[97m";
	const std::string SILVER = "\033[38;5;250m";
	const std::string LIGHT_GRAY = "\033[38;5;245m";
	const std::string GRAY = "\033[38;5;244m";
	const std::string DARK_GRAY = "\033[38;5;240m";
	const std::string CHARCOAL = "\033[38;5;236m";
	const std::string BLACK = "\033[38;5;16m";
	// EFFECTS
	const std::string RESET = "\033[0m";
	const std::string BOLD = "\033[1m";
	const std::string DIM = "\033[2m";
	const std::string ITALIC = "\033[3m";
	const std::string UNDERLINE = "\033[4m";
	const std::string BLINK = "\033[5m";
	const std::string REVERSE = "\033[7m";
	const std::string HIDDEN = "\033[8m";
	const std::string STRIKETHROUGH = "\033[9m";
	
	// ================= Random Number Utilities =================

	static bool CoinFlip()
	{
		/// this seeds a different random number generator that will cause problems so I need to change it
		// static std::random_device rd; // obtain a random seed
		// static std::mt19937 gen(rd()); // creates a random number generator and seeds the device
		// Think about coinflips as one or the other type number and how that may be reflected in code
		// static std::uniform_int_distribution<> distrib(0, 1); // return a value of either 1 or 0
		// This method returns a bool
		// return distrib(gen) == 1; // will return true for heads (1) or false for tails (0)
		/// simplifying to use the same seed from main
		return rand() % 2 == 1; // % 2 will = either 1 or 0 and return true for heads (1) or false for tails (0)
	}

	// ================= Console Display =========================

	// anamoly containment title banners
	static void AnomalyBanner()
	{
		std::cout << BRICK_RED << R"(
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxx)" << BLINK << SCARLET << R"([ a Joshua Appleman creation ])" << RESET << BRICK_RED << R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+^^^^^^^+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;       +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++;;    +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+x    +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxx+++^^^^+++xxxxxxx++++++++xx++++++++xxxxxxxxxxxxxx+++^^^+++xxxxxx+++++++++x+++++++++xxxx++++++++xxxxxxxxxxxxxx+++^^^^+++xxxxxxxxxxx    +xxx+++++++++++xx+++++++++++xxx
xxxxxxx+:           .++xxxx:      :+:        :+xxxxxxxxx++.          ;+xxx++       ':        .+x+:        ;+xxxxxxxx+;            ++xxxxxxxx    +xxx+        .++x;        :+xxx
xxxxxx+     :;+;:     :+xxx+x+:      .+++;     ;xxxxxxx+.    .;+;:     ++x+xx+;      :+++;         ;++;     +xxxxxx+     .;++;     :+xxxxxxx    +xxxxx+    .+xx+xxx;    :++xxxx
xxxxxx+   :xxxxxxx;    ;xxxxxx;    ;+xxxxx+;    +xxxxx+    :+xxxxx+;    +xxxxx+    :+xxxxx+:     ++xxxxx:   .xxxxxx+   .+xxxxxx+    ;+xxxxxx    +xxxxxx;    ;xxxxxx:    +x+xxxx
xxxxxx+++++xxxxxxx+.   ;xxxxxx;    xx+xxxxx+    ;xxxxx:   :+xxxxxxxx;    xxxxx+    ;xxxxxxx;    ;+xxxx+x+    +xxxxx+++++xxxxxxxx:   :+xxxxxx    +xxxxxx+:    +xxxx;    +xxxxxxx
xxxxxxxxx+x++^^^^^^    ;xxxxxx;    xxx+xxxx+.   ;xx+x+    ;xxxxxxxxxx    +xxxx+    ;xxxxxxx+    ;xxxxxxxx    +xxxxxxxxxx++^^^^^^    :+xxxxxx    +xxxxxxx+    :xx++    ;+xxxxxxx
xxxxxxx+;              ;xxxxxx;    xxxxxxxx+.   ;xxxx;    ;xxxxxxxxxx    ;xxxx+    ;xxxxxxx+    +xxxxxxxx    +xxxxxx+;              :++xxxxx    +xxxxxxxx;    ;xx:   .+xxxxxxxx
xxxxxx+     .;+++++    ;xxxxxx;    xxxxxxxx+.   ;xxxx+    ;xxxxxxxxxx    +xxxx+    ;xxxxxxx+    +xxxxxxxx    +xxxxx+     .;;++++.   :++xxxxx    +xxxxxxxx+;   .++    ;xxxxxxxxx
xxxx++.   .xxxxxxx+.   ;xxxxxx;    xxxxxxxx+.   ;xxxx+.   :+xxxxxxxx+    +xxxx+    ;xxxxxxx+    +xxxxxxxx    +xxxx+:    +xxxxxxx:   :++xxxxx    +xxxxxxxxx+.   :.   ;+xxxxxxxxx
xxxxx+    ;xxxxxx+;    ;xxxxxx;    xxxxxxxx+.   ;xxxxx;    ;+xxxxxx+    ;xxxxx+    ;xxxxxxx+    +xxxxxxxx    +xxx++:   :xxxxxx++    :++xxxxx    +xxxxxxxxxx+       .+xxxxxxxxxx
xxxx++:    ;+xx+:      ;xxx++x;    +xxxxxxx+.   :+xxxxx;     ++xx+.    ;xxx+xx+    ;xxxxxx++    ;+xxx++x+    +xxxx+;    ;+xx+:      :+x+xxxx    +x+xxxxxxxxx;      ;xxxxxxxxxxx
xxxxx++:          ;:     +x:          +x+          :xxx++:           .+x+x++          :x;          ;++          ;xx+;          ::     +x;          ;xxxxxxxx+:    ;+xxxxxxxxxxx
xxxxxxxx+;.....;++x;.   :+x;..........xx+;.........;xxxxxx++;.....;++xxxxxx+:........:+x+;........:+x+:........:+xxx+++;....;++x+:    +++:........:+xxxxxxxxx:   .+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxx+xxxxxxxxxxx+xx+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+xxxxxxxxxxxxxxxxxxxxxxxxxxxx+xxxxxxxxxxxx+xxxxxxxxxxxxxx+xxxxxxxxxxxxxxxxxxxxxxxxxxxxx;    +xxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;    ;xxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+       ;+xxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;     .+xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+xxxx++xxxxxxxxxxxxxxx
xxxxxxxxxxx+;++xxx++++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+  :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxx++  ;xxx+. :xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;  +xxxxxxxxxxxxxxxxxx++++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+  :+xxxxxxx
xxxxxxxxx+: .+x++: .+xx+xxxxx+xxx+xxxxxx+xxxx+xxxxxxxx+xxxxxxxxx+x;  +x+xxxx+xxx+xx+xxxxxxxxxxxxxxxxxxxxxxxx+xxxxxxxx+xxxxxxxxxxxxxxxx+xxx+xxx+x+xxx+xxxxxxxxxxx+xx+  :+xxxxxxx
xxxxxxxxx;  +xxx;  ;xxx+;       :+xxx;       ;xx;    :.    .++xx;      :+x+        ;+x+.   :+x;    ;.     +xx+:    :     ;+.    :+xxxxx+      .+x+:    ;     :+xx+       ++xxxx
xxxxxxxx+  ;xxx+  ;+xx+.  ;+x+;  ++x:  ;+++:  :xx+;   ;+++.  +xx++:  +++x+:  ++x+:  ;xxx+  :+xx+:   ;+++   ++x++.  :+++:   :+++   +xxx:  :+++:  ++x+.  .+++;  :+x+++  :+++xxxxx
xxxxxxx+: :xxx+: :+xxx:  ;xxxxx:.+x+  ;xxxx+:  +xx;  :xxxx;  ;+xxx;  +xxxx+++xxxx;  :xxx+  :+xxx;  +xxx++  ;+xx+.  xxxx+  .+xxx;  ;xx+  .;++++  :xx+:  +xxx+:  +xxx+  :+xxxxxxx
xxxxxx+;  +xxx;  +xxxx:  +xxxxxxxxx;  +xxxxx;  ;xx;  :xxxx;  ;+xxx;  +xxxx+;.       :xxx+  :+xxx;  +x+xx+  ;xxx+.  xxx++  :xxxx;  ;x+;          :xx+:  +xxx+:  +xxx+  :+xxxxxxx
xxxxxx+  +xxx+  ;+xxxx:  ;xx++++++x+  ;xxxxx;  ;xx;  :+xxx;  ;+xxx;  +xxx+   ;+xx;  :xxx+  :+xxx;  +xxxx+  ;xxx+.  x+xx+  :xxxx;  ;xx;  ;+xxxxxxxxx+:  +xxx+:  +xxx+  :+xxxxxxx
xxxx++. :xxx+: :+xxxxx+   +xxx;  ;x+.  +xx++  :x+x;  :+xxx;  ;+xxx;  +xxx+  .xxx+:  :xxx+  :+xxx;  +xxxx+  ;xxx+.  x+xx+  :xxxx;  ;xxx.  ++xxx++xxx+:  +xxx+:  +xxx+  :+xxxxxxx
xxxx+;  +xx+;  +xxxxxxx+:       ++xx+;       ;+x;      ;+      ;xx+     x+;          ;+.     :;      ++      ;:     .+.     :;      ;xx;        ++:      +;     .+xx:    :+xxxx
xxxx+  +xxx+  ;xxxxxxxxxx+++++++xx+xxx+++++++xxx++++++++++++++++x++x++++xxx+++++++++++++++++++++++++++x++++++++++++++++++++++++++++++xxxx++++++xxx+++++++x++++++++xxx+++++xxxxx
xxxx+++xxxx+++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++;.     .:;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+:                ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                     :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++                         ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                           .++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                             .+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+           )" << BLINK << LEMON << R"(.+xxXxxx:)" << RESET << BRICK_RED << R"(           ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+x:          )" << BLINK << LEMON << R"(+xXxXxXxxXx.)" << RESET << BRICK_RED << R"(          xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << LEMON << R"(:xXxxxxxxxxx+)" << RESET << BRICK_RED << R"(          ++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << LEMON << R"(;XxXxxxxxxxXx.)" << RESET << BRICK_RED << R"(         ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++          )" << BLINK << LEMON << R"(:xXxxxxxxxxx+)" << RESET << BRICK_RED << R"(          ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;:             )" << BLINK << LEMON << R"(;xxxxxxxxx+)" << RESET << BRICK_RED << R"(              ;+x+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;.                  )" << BLINK << LEMON << R"(;+xxx++.)" << RESET << BRICK_RED << R"(                  ;++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                                                   :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                                                         :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+:                                                               .+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+:                   :++++:                    ;+x+;                    ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++.                   :++xxxxxx+;.              :++xxx+xx+;.                   ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxx++<^^^^^^>++xxxxx+;.                   :+xxxxxxxxxxxxx+:         .+xxxxxxxxxxxxx+;.                   :++x++<^^^^^^>++xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxx++:              '^^'                   ;+xx+xxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxx++.                                 :;+xxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxx+;                                     ;+xxxxxx+xxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxx+:                                 :+xxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxx+;                                   .++xxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxx+:                                :+x+xxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxx+.                                 :++xxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxx++;                               +xxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+.                               :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxxx++                              +xxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx+:           )" << BLINK << LIME << R"(:+xxxx+:)" << RESET << BRICK_RED << R"(            +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxxx+:           )" << BLINK << NEON_PURPLE << R"(:+xxxx+:)" << RESET << BRICK_RED << R"(           .+xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx;          )" << BLINK << LIME << R"(.+xXxxxXxXx:)" << RESET << BRICK_RED << R"(          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << NEON_PURPLE << R"(:xxxxxxxxxx:)" << RESET << BRICK_RED << R"(          ;xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx:         )" << BLINK << LIME << R"(.xxxXxxxxXxxx.)" << RESET << BRICK_RED << R"(         :xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxxx:         )" << BLINK << NEON_PURPLE << R"(.xXxxxxxxxXxx.)" << RESET << BRICK_RED << R"(         :xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx:         )" << BLINK << LIME << R"(:xxXxxxxxxxxx+)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxx+:         )" << BLINK << NEON_PURPLE << R"(;xXxxxxxxxXxx;)" << RESET << BRICK_RED << R"(         .+xxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx:         )" << BLINK << LIME << R"(.xxXxxxxxxxxx:)" << RESET << BRICK_RED << R"(           .;+xxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxxx+.         )" << BLINK << NEON_PURPLE << R"(:xXxxxxxxxXxx:)" << RESET << BRICK_RED << R"(         :xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx;          )" << BLINK << LIME << R"(;xXXXXXxxXx;)" << RESET << BRICK_RED << R"(                ;++xxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxx++:            )" << BLINK << NEON_PURPLE << R"(;xxXxXxXxxx;)" << RESET << BRICK_RED << R"(          ;xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxx+.           )" << BLINK << LIME << R"(+xxxXXx+)" << RESET << BRICK_RED << R"(                     ;+xxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxx+.                 )" << BLINK << NEON_PURPLE << R"(+xxxxxX+)" << RESET << BRICK_RED << R"(           .+xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+                                           :+xx+xxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxx+;                                        +xxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxx+                                             :++xxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxx+;                                          +xxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxx+:                        .;:                   .+xx+xxxxxxxxxx;         .+xxxxxxxxxxxx+:                                           .+xxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxx+.                     ;xxxx+:                   .;+xxxxxx++:           :;+xxxxxxx+:                   :;++.                    .+xxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxx+;                :+xxxxxxxxx+;                   .;+x+:                  ;+++:                   :+xxxxxx+:                :+xxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxx+          ;+xxxxxxxxxxxxxxx+;                                                             :+xxxxxxxxxxxxx+;:           ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxx+                                                       ;+xxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxx+:                                                ;xxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxx++:                  )" << BLINK << SILVER << R"(.;;;:)" << RESET << BRICK_RED << R"(                  .++xxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxx+x+;             )" << BLINK << SILVER << R"(+xxxxXXx+:)" << RESET << BRICK_RED << R"(            :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.         )" << BLINK << SILVER << R"(.xXxxxxxXxxx:)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << SILVER << R"(;xXxxxxxxxxXx)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << SILVER << R"(;xXxxxxxxxxXx)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.         )" << BLINK << SILVER << R"(.xXxxxxxxXxx;)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxx+x+;            )" << BLINK << SILVER << R"(.+xxxxXXxx:)" << RESET << BRICK_RED << R"(            :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxxx;                  )" << BLINK << SILVER << R"(:;++:)" << RESET << BRICK_RED << R"(                  :++xxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxx+:                                                +xxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxx+.                                                      ;+xxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxxxxx+;.                                                            ;+xxxxxxx+;:.                   .:;+xxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          ;xxxxxxxxxxxxx+;.                   ;+++.                  ;++;.                   :+x+;                             :+xxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxx+           ;;+xxxxxxx+;                    ;+xxxxxx++:           .;+xxxxxxx+.                                                    :+xxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxx++.                ;+++;                    ;xxxxxxxxxxxxx;         .+xxxxxxxxxxxx+:                                                   +xxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxx+;                                        .+xxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxx+;                                                .+xxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxx;                                       :+xx+xxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxx+;                                              ;x+xxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxx:                                     ;+xxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxx+;              )" << BLINK << ORANGE << R"(.##################)" << RESET << BRICK_RED << R"(          :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxx:              )" << BLINK << ELECTRIC_BLUE << R"(.)" << RESET << BRICK_RED << R"(                    ;++xxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxx+;           )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxx;           )" << BLINK << ELECTRIC_BLUE << R"(:+xXxxXx;)" << RESET << BRICK_RED << R"(             ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+:          )" << BLINK << ELECTRIC_BLUE << R"(+xXxXxxXxXx:)" << RESET << BRICK_RED << R"(          +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+          )" << BLINK << ELECTRIC_BLUE << R"(+xxxxxxxxXxxx)" << RESET << BRICK_RED << R"(          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+          )" << BLINK << ELECTRIC_BLUE << R"(+XxxxxxxxXxXx.)" << RESET << BRICK_RED << R"(         ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxx+.         )" << BLINK << ELECTRIC_BLUE << R"(:xxXxxxxxXXx+)" << RESET << BRICK_RED << R"(          ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxx:          )" << BLINK << ELECTRIC_BLUE << R"(:xxXxxxxxx+)" << RESET << BRICK_RED << R"(           +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxx+            )" << BLINK << ELECTRIC_BLUE << R"(.+XXXx;)" << RESET << BRICK_RED << R"(               :+xxxxxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxxxxx;          )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxx+                                    :+xxxxxxxxxxxxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxxxxx+;            )" << BLINK << ORANGE << R"(.##################.)" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxx+                                      .++xxxxxx+xxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxxxxxx+:               )" << BLINK << ORANGE << R"( """""""""""""""""" )" << RESET << BRICK_RED << R"(         :+xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxx+:                                       .;+xx+xxxxxxxxxxxxxx;         .+xxxxxxxxxxxxxxxx++:                                               ;xxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxx+:                    :                   .;+xxxxxxxxxxxxx+:         .+xxxxxxxxxxxxx++:                                                 :+xxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxx+:              ;+xxx+;                    ;++xxxxxx++:              ;++xxx+xx++:                                                   :+xxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxx+xxxxxxxx++;..;+xxxxxxxxxxxxx+.                   ;++x+:                    ++x++.                   :.                                +xxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+:                                                                ;xxxxx;                           ;+xxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++:                                                         .++xxxx+xxxx+++++++++++++++++++++++++xxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                                                   :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                   )" << BLINK << PINK << R"(:++xx+;.)" << RESET << BRICK_RED << R"(                  :++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;.             )" << BLINK << PINK << R"(:xxxxxxxxx+)" << RESET << BRICK_RED << R"(              :+x+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+x+;          )" << BLINK << PINK << R"(:xXxxxxxxxxx+)" << RESET << BRICK_RED << R"(          :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << PINK << R"(;XxXxxxxxxxXx.)" << RESET << BRICK_RED << R"(         ;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          )" << BLINK << PINK << R"(;xXxxxxxxxxx+)" << RESET << BRICK_RED << R"(          ++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+x:          )" << BLINK << PINK << R"(+xXxXxXxxXx.)" << RESET << BRICK_RED << R"(          xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+           )" << BLINK << PINK << R"(.+XxxXxx;)" << RESET << BRICK_RED << R"(           :xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                              +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                           .++xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++                         :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;                     :+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+xxx+.                ;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx++:       :;+xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	)" << Helper::RESET;
	}

	// ================= Input Validation ========================

	static bool IntegerValidation(char* input)
	{
		bool isValid = false; /// set bool to false
		int intValue; /// intiate an int
		/// using sscanf_s to convert the input from a char array to an int by assigning it to the memory address of the uninitialized int intValue
		if (sscanf_s(input, "%d", &intValue) > NULL && *input != '\n') /// if statement to check if something has been entered by the user and that the input was converted to an int that is more than 0
		{
			printf("\nValid integer followed by ENTER key.\n"); /// print the result of the check of the user successfully entering an int value and pressing ENTER
			printf("User input: %d", intValue); /// print the user input valiue converted successfully to an int value of intValue
			isValid = true; /// set bool to true
		} 
		else
		{
			printf("\nUser entry not valid.\n"); /// output error message that a valid integer was not entered
			isValid = false; /// set bool to false
		}
		
		return isValid; /// return bool result
	}			
	//  Description: Validates that the parameter is a valid integer. It should accept a char* as input, converting the input into an integer and ensuring the input is valid. If the input is not a valid integer, it will return false.
	//  Example parameters: char* (the input char[] to validate)
	//  Return type: bool (true if valid, false if invalid)
	//  Good Test case is to use user input to use this as a validation.
	//  Hint: You will need to do independent research for determining if the data entered in the char* is a valid integer value.

	// ================= Number Conversion =======================

	static void PrintIntegerBinary(int* num)
	{
		if (num == NULL) /// if statement to check for a NULL pointer
		{
			printf("Error: NULL pointer passed.\n"); /// print error message for a NULL pointer
			return; /// return to main
		}

		unsigned int value = (unsigned int)(*num); /// Handle negative numbers via unsigned cast
		int totalBits = sizeof(int) * 8;           /// Number of bits in an int

		for (int i = totalBits - 1; i >= 0; i--) /// iterate through the bits from left to right
		{
			unsigned int mask = 1u << i; /// set mask for collecting the bits
			printf("%c", (value & mask) ? '1' : '0'); /// print bits from most significant to least significant
		}
	}
	//  Description: Prints the binary representation of an integer passed as a pointer
	//  Example parameters: int* num (point to the integer to convert)
	//  Return type: void
	//  Bitset is NOT allowed in this function
	//  This function must print all 32 bits of the passed integer

	// ================= Sorting Utilities =======================

	static void BubbleSort(int* arr, int size)
	{
		for (int i = 0; i < size - 1; i++) /// iterates through each position in the array, ititiating a second for loop to iterate through the array from that position, moving right after the inner loop completes
		{
			for (int j = 0; j < size - i - 1; j++) /// interates through each position in the array for each interation of i until the next element is larger than the current element, returning to move to the next position in the array and start again
			{
				if (arr[j] > arr[j + 1]) /// if statement to compare the value of the index with the value of the element that comes next in the array, completeing the code if the index is greater of the two
				{
					std::swap(arr[j], arr[j + 1]); /// switch the position (values) of the two elements if the index is greater than the element that follows in the array
				}
			}
		}
	}
	//  Description : Implements the bubble sort algorithm to sort an array of integers.
	//  It should take an array and its size as parameters and sort the array in ascending order.
	//  Example parameters : int* arr, int size(pointer to the array and its size).
	//  Return type: void

	// ================= Console Utilities =======================

	static void ClearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	//   Description: Clears any residual input from the buffer that may have been left over from previous cin operations, ensuring no invalid data is left to affect future user input.
	//   Example parameters : None required.
	//   Return type : void

	static void ClearConsoleWindow()
	{
		system("cls");
	}
	//   Description : Clears the entire console window to provide a clean slate for the user interface.This can be used when the program needs to reset its output or prompt the user for new input without clutter.
	//   Example parameters : None required.

	static void PauseConsoleWindow(bool silent = false)
	{
		ClearInputBuffer();
		if (!silent) std::cout << "Press ENTER to continue..."; /// "Press ENTER to continue..."
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /// ignore all input other than ENTER, completing the function and returning to main when ENTER is pressed
	}
	//   Description : Pauses the execution of the program, preventing it from continuing until the user presses the "Enter" key.It is commonly used to allow users to read output or messages before closing the console.
	//   Example parameters : None required.
	//   Return type : void

	static bool isPositiveInteger(char* input)
	{
		int convertedInt; /// creating unititialized variable int
		sscanf_s(input, "%d", &convertedInt); /// converting the value passed by pointer into an int
		bool isPosInt = false; /// initializing bool IsPosInt as false
		if (sscanf_s(input, "%d", &convertedInt) > NULL && *input != '\n') /// if statement to check if something has been entered by the user and that the input was converted to an int that is more than 0
		{
			printf("\nValid integer followed by ENTER key.\n"); /// print the result of the validation check of the user successfully entering an int value and pressing ENTER
			printf("User input: %d", convertedInt); /// print the user input value converted successfully to an int value of convertedInt
			
			if (convertedInt > 0) /// if statement to check if value of int convertedInt is more than 0, so positive
			{
				isPosInt = true; /// set bool to true
			}
		}
		else
		{
			printf("\nUser entry not valid integer.\n"); /// output error message to the user that a valid integer was not entered
			isPosInt = false; /// set bool to false
		}
		return isPosInt; /// return bool result
	}
	//   Description : Validates that the parameter is a positive integer.If the input is not a valid positive integer(0 should be rejected as well), it will return false.
	//   Example parameters : char\ * input(a pointer to the char \[\] value).
	//   Return type : bool(true if valid, false if invalid)
	//   Good Test case is to use user input to use this as a validation.

	// RandomNumberGenerator
	// Description: Generates a random integer within an inclusive range.
	static int RandomNumberGenerator(int min = 1, int max = 100)
	{
		if (min > max)
		{
			std::cout << "Invalid random number range.\n";
			return 0;
		}

		return min + (rand() % (max - min + 1));
	}

	// PrintIntegerHex
	// Description: Prints the hexadecimal representation of an integer.
	static void PrintIntegerHex(int* num)
	{
		if (num == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return;
		}

		std::cout << "Hexadecimal: 0x"
			<< std::hex << *num
			<< std::dec << '\n';
	}

	// PrintIntegerOct
	// Description: Prints the octal representation of an integer.
	static void PrintIntegerOct(int* num)
	{
		if (num == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return;
		}

		std::cout << "Octal: "
			<< std::oct << *num
			<< std::dec << '\n';
	}

	// UserInputBool
	// Description: Prompts the user for a valid boolean value.
	static void UserInputBool(bool* input)
	{
		if (input == nullptr)
		{
			std::cout << "Invalid boolean pointer.\n";
			return;
		}

		std::string userInput;

		while (true)
		{
			std::cout << "Enter true or false: ";
			std::cin >> userInput;

			if (userInput == "true" || userInput == "1")
			{
				*input = true;
				break;
			}
			else if (userInput == "false" || userInput == "0")
			{
				*input = false;
				break;
			}

			std::cout << "Invalid input. Please enter true or false.\n";
		}
	}

	// ================= Integer Utilities =======================

	// IntegerSwap
	// Description: Swaps the values of two integers.
	static void IntegerSwap(int* a, int* b)
	{
		if (a == nullptr || b == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return;
		}

		printf("Before: a: %d b: %d \n", *a, *b);

		int tempInt = *a;
		*a = *b;
		*b = tempInt;

		printf("\nAfter: a: %d b: %d \n", *a, *b);
	}

	static bool IsEven(int* num)
	{
		bool isEven = false; /// set bool to false
		if (*num % 2 == 0) isEven = true; /// if statement checking if the number is divisable by two with no remainder, making it even, sets bool to true
		return isEven; /// return bool result
	}
	//  Description : Checks if the number passed in is even.The method should return a boolean(true if the number is even, false otherwise).
	//  Example parameters : int\ * num(pointer to the integer to check).
	//  Return type : bool(true if even, false if not)

	// GetMaxValue
	// Description: Returns the larger of two integers.
	static int GetMaxValue(int* num1, int* num2)
	{
		if (num1 == nullptr || num2 == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return 0;
		}

		return (*num1 > *num2) ? *num1 : *num2;
	}

	// GetMinValue
	// Description: Returns the smaller of two integers.
	static int GetMinValue(int* num1, int* num2)
	{
		if (num1 == nullptr || num2 == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return 0;
		}

		return (*num1 < *num2) ? *num1 : *num2;
	}

	// ClampInteger
	// Description: Clamps an integer between a specified minimum and maximum.
	static void ClampInteger(int* value, int min, int max)
	{
		if (value == nullptr)
		{
			std::cout << "Invalid integer pointer.\n";
			return;
		}

		if (min > max)
		{
			std::cout << "Invalid range: minimum cannot exceed maximum.\n";
			return;
		}

		if (*value < min)
		{
			*value = min;
		}
		else if (*value > max)
		{
			*value = max;
		}
	}

	// ================= Mathematical Utilities ==================

	static bool IsPrime(int num)
	{
		int i = 3; /// initiating an int i with a value of 3, as prime numbers are odd, this will be the start of my interator once I complete the conditions checks for the exceptions, incrementing by 2 to only check odd numbers and reduce the amount of loops to complete to check the int value against the conditions
		bool isPrime = true; /// the default value will be true, that the number is prime
		if (num < 2) /// if statement to exclude all negative values, 0, and 1 as not being prime
		{
			isPrime = false; /// set bool to false for the exceptions
		}
		else if (num == 2) /// else if to include 2 as a special case for true, is the only even prime number (making it a special case allows me to check the rest in my loop condition without overly complicating the interation. And it is proper practice to set the strictest conditions first when using a if, else if, else statement)
		{
			isPrime = true; /// set bool to true (it is already) for the special case inclusion of 2
		}
		else if (num >= i) /// evaluating all remaining values
		{
			for (i; i <= (int)sqrt(num); i += 2) /// setting the limit to the square root of my number as it is not possible to have a factor greater than this without a factor lower than this
				/// also setting the interval to skip all positive values to remove redundancy evaluations as I will exclude all positive numbers first
			{
				if (num % 2 == 0) /// excluding all positive values for number
				{
					isPrime = false;  /// set bool value to false for all even numbers
				}
				else if (num % i == 0) /// checking for any factors of the number up to the sqrt(number) and removing any values that are divisible by those factors
				{
					isPrime = false; /// setting bool to false for all odd numbers that can be divided by numbers other than just themselves and 1
				}
			}

		}
		return isPrime; /// return bool result
	}
	//  Description : Checks if the number passed in is a prime number.The method should return a boolean value(true if the number is prime, false otherwise).
	//  Example parameters : int num(the integer to check).
	//  Return type : bool(true if prime, false otherwise)

	// UserInputChar
	// Description: Prompts the user to enter exactly one character.
	static void UserInputChar(char* input)
	{
		if (input == nullptr)
		{
			std::cout << "Invalid character pointer.\n";
			return;
		}

		std::string userInput;

		while (true)
		{
			std::cout << "Enter a single character: ";
			std::cin >> userInput;

			if (userInput.length() == 1)
			{
				*input = userInput[0];
				break;
			}

			std::cout << "Invalid input. Please enter exactly one character.\n";
		}
	}

	static bool ValidateRange(int value, int min, int max)
	{
		bool isInRange = false; /// set bool to false
		if (value >= min && value <= max) isInRange = true; /// if statement to check if int value is in the range of min-max, set bool to true
		return isInRange; /// return bool result
	}
	//  Description : Verifies that a given value lies within a specified range(inclusive).If the value is out of range, it should either prompt the user again or return an error message.
	//  Example parameters : int value, int min, int max(the value to check, and the min and max range).
	//  Return type : bool(true if within range, false if out of range)

	static int SafeDivide(int numerator, int denominator)
	{
		if (denominator == 0) return 0;
		int dividedInt = numerator / denominator;
		return dividedInt;
	}
	//  Description : Divides two numbers, but checks if the denominator is zero before performing the division.If the denominator is zero, it returns 0 to avoid division by zero errors.
	//  Example parameters : int numerator, int denominator(the numbers to divide).
	//  Return type : int(the result of the division, or 0 if denominator is zero)

	// VectorSum
	// Description: Returns the sum of all elements in a vector.
	static int VectorSum(std::vector<int>* vec)
	{
		if (vec == nullptr)
		{
			std::cout << "Invalid vector pointer.\n";
			return 0;
		}

		int sum = 0;

		for (int value : *vec)
		{
			sum += value;
		}

		return sum;
	}

}

