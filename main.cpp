/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: This program simulates a game when an Alien
 * has crash landed on Earth and needs to find all the pieces
 * of his ship in order to put his spaceship back together
 * again and fly home.
**********************************************************/



#include <iostream>
#include <ctime>
#include "util.hpp"
#include "menu.hpp"
#include "Game.hpp"

using namespace std;

int main() {
    srand((unsigned int) time(nullptr));

    vector<string>menuOptions = { "Play Game", "Show Help", "Quit" };
    const auto EXIT_OPTION = static_cast<int>(menuOptions.size());

    int menuChoice = 0;
    Game* game = nullptr;


    // TODO: clean this up. it looks all wonky, and i think i introduced some sort of segfault when the user quits and tries to play again


    do {
        clearScreen();
        menuChoice = getValidInt(1, EXIT_OPTION, getMenu(menuOptions, true, "What would you like to do?\n"));

        if (menuChoice != 3) {
            delete game;
            game = new Game();
        }

        if (menuChoice == 1) {
            game->play();
            getEnter("\n\nPress [Enter] to return to the main menu...");
        } else if (menuChoice == 2) {
            game->showHelp();
            getEnter("\n\nPress [Enter] to return to the main menu...");
        }

    } while (menuChoice != EXIT_OPTION);


    cout << "\nGoodbye, friend" << endl;
    delete game;
    return 0;
}
