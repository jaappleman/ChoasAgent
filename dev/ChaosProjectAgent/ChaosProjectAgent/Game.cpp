
#include "Game.h"
#include <iostream>

Game::Game()
{
    isRunning = true;
}

void Game::displayMainMenu()
{
    std::cout << "\n========== ANOMALY//CONTAINMENT ==========\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Select an option: ";
}

void Game::run()
{
    while (isRunning)
    {
        displayMainMenu();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "\nCampaign functionality is coming soon.\n";
            break;

        case 2:
            isRunning = false;
            std::cout << "\nShutting down facility systems...\n";
            break;

        default:
            std::cout << "\nInvalid selection. Please try again.\n";
            break;
        }
    }
}
