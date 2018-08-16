/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Game.cpp is the class implementation
**  file for the Game class. This file contains
**  definitions for the member functions of the Game class.
**********************************************************/

#include <iostream>
#include <algorithm>
#include <random>
#include "Game.hpp"
#include "menu.hpp"


using namespace std;


/**
 * @name Game
 * @brief Game class constructor
 * @param none
 * @return none
 */
Game::Game() {
    // initialize the alien
    player = new Alien(TOTAL_ISLANDS - 1);

    // initialize the option lists
    gameOpts = {"Resume", "Show Help", "Quit"};
    boolOpts = {"Yes", "No"};
    playerOpts = {"Move Left", "Move Down", "Move Up", "Move Right\n", "Show Menu", "Show Help", "Quit"};
}


/**
 * @name ~Game
 * @brief Game class destructor
 * @param none
 * @return none
 */
Game::~Game() {
    delete player;

    // delete the islands
    for (auto &island : islands) {
        delete island;
    }

    // delete the spaceship pieces
    // TODO: make sure there's no conflict between handling the ship pieces like this & having them in a Bag w/ Alien
    for (auto &piece : spaceship) {
        delete piece;
    }
}


/**
 * @name setupGame
 * @brief triggers the setting up of the islands, the player, and the spaceship
 * @param none
 * @return void
 */
void Game::setupGame() {
    setupIslands();
    setupPlayer();
    setupSpaceship();
}


/**
 * @name setupPlayer
 * @brief sets up the Player (Alien) and places it at the starting location in the game
 * @param none
 * @return void
 */
void Game::setupPlayer() {
    player->setHomeland(islands[TOTAL_ISLANDS - 1]);
    player->setSpace(islands[0]->getSpace(6, 6));
    player->getSpace()->setElement(player);
    player->uncoverAdjacentSpaces();
}


/**
 * @name setupIslands
 * @brief sets up each of the islands that are used in the game along with all of the Spaces
 *  that populate each island and all of the Elements that populate each Island
 * @param none
 * @return void
 */
void Game::setupIslands() {
    //
    // initialize the islands w/ their levels & sizes
    //
    islands[0] = new Island(0, 15, 20);
    islands[1] = new Island(1, 20, 25);
    islands[2] = new Island(2, 20, 25);
    islands[3] = new Island(3, 25, 30);
    islands[4] = new Island(4, 25, 30);
    islands[5] = new Island(5, 30, 35);
    islands[6] = new Island(6, 30, 35);
    islands[7] = new Island(7, 20, 25);

    // set the game for each island
    for (auto &island : islands) {
        island->setGame(this);
    }


    //
    // link the islands to the islands above & below
    //
    islands[0]->setAbove(islands[1]);
    islands[1]->setAbove(islands[2]);
    islands[2]->setAbove(islands[3]);
    islands[3]->setAbove(islands[4]);
    islands[4]->setAbove(islands[5]);
    islands[5]->setAbove(islands[6]);
    islands[6]->setAbove(islands[7]);

    islands[1]->setBelow(islands[0]);
    islands[2]->setBelow(islands[1]);
    islands[3]->setBelow(islands[2]);
    islands[4]->setBelow(islands[3]);
    islands[5]->setBelow(islands[4]);
    islands[6]->setBelow(islands[5]);
    islands[7]->setBelow(islands[6]);


    //
    // setup the island layouts
    //

    // { WATER, ROAD, SAND, SLIDER, OUTER_SPACE};

    // island 0
    islands[0]->addSpaces({0, 0}, WATER, {4, 20}, true);
    islands[0]->complete(1, 1, 0);

    // island 1
    islands[1]->addSpaces({9, 0}, ROAD, {2, 25}, true);
    islands[1]->addSpaces({0, 12}, ROAD, {20, 2}, true);
    islands[1]->addSpaces({8, 11}, SAND, {4, 4}, true);
    islands[1]->complete(1, 1, 1);

    // island 2
    islands[2]->addSpaces({0, 10}, WATER, {7, 15}, true);
    islands[2]->addSlider({14, 14}, LEFT, 11);
    islands[2]->addSlider({14, 3}, UP, 10);
    islands[2]->addSlider({5, 3}, RIGHT, 11);
    islands[2]->complete(1, 2, 1);

    // island 3
    islands[3]->addSpaces({5, 5}, SAND, {15, 20}, true);
    islands[3]->addSpaces({6, 6}, ROAD, {2, 18}, true);
    islands[3]->addSpaces({17, 6}, ROAD, {2, 18}, true);
    islands[3]->addSpaces({6, 6}, ROAD, {12, 2}, true);
    islands[3]->addSpaces({6, 22}, ROAD, {12, 2}, true);
    islands[3]->addSpaces({9, 9}, WATER, {7, 12}, true);
    islands[3]->addSpaces({11, 13}, OUTER_SPACE, {3, 4}, true);
    islands[3]->complete(1, 2, 2);

    // island 4
    islands[4]->addSpaces({7, 1}, WATER, {11, 11}, true);
    islands[4]->addSpaces({11, 5}, WATER, {3, 25}, true);
    islands[4]->addSpaces({10, 1}, OUTER_SPACE, {5, 7}, true);
    islands[4]->addSpaces({12, 12}, SAND, {1, 1}, true);
    islands[4]->addSpaces({7, 12}, SAND, {1, 1}, true);
    islands[4]->addSpaces({19, 8}, SAND, {2, 2}, true);
    islands[4]->addSpaces({5, 20}, SAND, {2, 2}, true);
    islands[4]->addSpaces({5, 13}, SAND, {2, 2}, true);
    islands[4]->complete(1, 1, 3);
    islands[4]->addSpaces({3, 1}, GRASS, {19, 2}, true);

    // island 5
    islands[5]->addSpaces({0, 18}, OUTER_SPACE, {30, 20}, true);
    islands[5]->addSpaces({3, 30}, GRASS, {3, 3}, true);
    islands[5]->addSpaces({22, 26}, GRASS, {3, 3}, true);
    islands[5]->addSpaces({12, 23}, GRASS, {2, 2}, true);
    islands[5]->addSpaces({4, 31}, ELEVATOR, {1, 1}, true);
    islands[5]->complete(0, 2, 1);

    // island 6
    islands[6]->addSpaces({0, 0}, WATER, {30, 25}, true);
    islands[6]->addSpaces({0, 0}, GRASS, {30, 7}, true);
    islands[6]->addSlider({24, 11}, UP, 8);
    islands[6]->addSlider({5, 16}, DOWN, 8);
    islands[6]->addSlider({18, 23}, UP, 8);
    islands[6]->complete(0, 2, 1);


    // island 7 (Alien HomeLand)
    // no need to add any spaces...it's already going to be homeland
    islands[7]->complete(0, 1, 0); //   the only way for the Alien to get to the Island 7 - homeland is with the ship

    // link all the island spaces
    linkAdjacentIslandSpaces();



    //
    // Add Island Elements
    //


    //
    // island 0
    //
    islands[0]->addItem({-1, -1}, MONEY);
    islands[0]->addItem({-1, -1}, FOOD);
    islands[0]->addItem({-1, -1}, RANDOM_ITEM);
    islands[0]->addItem({-1, -1}, RANDOM_ITEM);
    islands[0]->addEarthling(CARTOGRAPHER);
    islands[0]->addEarthling(BOOKIE);
    islands[0]->addEarthling(SHARK);

    //
    // island 1
    //
    islands[1]->addItem({-1, -1}, MONEY);
    islands[1]->addItem({-1, -1}, MONEY);
    islands[1]->addItem({-1, -1}, FOOD);
    islands[1]->addItem({-1, -1}, RANDOM_ITEM);
    islands[1]->addItem({-1, -1}, RANDOM_ITEM);
    islands[1]->addEarthling(CARTOGRAPHER);
    islands[1]->addEarthling(BOOKIE);
    islands[1]->addEarthling(WIZARD);

    //
    // island 2
    //
    islands[2]->addItem({-1, -1}, MONEY);
    islands[2]->addItem({-1, -1}, MONEY);
    islands[2]->addItem({-1, -1}, FOOD);
    islands[2]->addItem({-1, -1}, FOOD);
    islands[2]->addItem({-1, -1}, RANDOM_ITEM);
    islands[2]->addEarthling(CARTOGRAPHER);
    islands[2]->addEarthling(BOOKIE);
    islands[2]->addEarthling(WIZARD);
    islands[2]->addEarthling(SHARK);

    //
    // island 3
    //
    islands[3]->addItem({-1, -1}, MONEY);
    islands[3]->addItem({-1, -1}, MONEY);
    islands[3]->addItem({-1, -1}, FOOD);
    islands[3]->addItem({-1, -1}, FOOD);
    islands[3]->addItem({-1, -1}, RANDOM_ITEM);
    islands[3]->addItem({-1, -1}, RANDOM_ITEM);
    islands[3]->addEarthling(CARTOGRAPHER);
    islands[3]->addEarthling(CARTOGRAPHER);
    islands[3]->addEarthling(BOOKIE);


    //
    // island 4
    //
    islands[4]->addItem({-1, -1}, MONEY);
    islands[4]->addItem({-1, -1}, FOOD);
    islands[4]->addItem({-1, -1}, RANDOM_ITEM);
    islands[4]->addItem({-1, -1}, RANDOM_ITEM);
    islands[4]->addEarthling(CARTOGRAPHER);
    islands[4]->addEarthling(WIZARD);
//    islands[4]->addEarthling(SHARK);

    //
    // island 5
    //
    islands[5]->addItem({-1, -1}, MONEY);
    islands[5]->addItem({-1, -1}, MONEY);
    islands[5]->addItem({-1, -1}, MONEY);
    islands[5]->addItem({-1, -1}, FOOD);
    islands[5]->addItem({-1, -1}, RANDOM_ITEM);
    islands[5]->addItem({-1, -1}, ICARUS_WINGS);
    islands[5]->addItem({-1, -1}, ICARUS_WINGS);
    islands[5]->addEarthling(CARTOGRAPHER);
    islands[5]->addEarthling(CARTOGRAPHER);
    islands[5]->addEarthling(WIZARD);


    //
    // island 6
    //
    islands[6]->addItem({-1, -1}, MONEY);
    islands[6]->addItem({-1, -1}, MONEY);
    islands[6]->addItem({-1, -1}, FOOD);
    islands[6]->addItem({-1, -1}, RANDOM_ITEM);
    islands[6]->addItem({-1, -1}, RANDOM_ITEM);
    islands[6]->addItem({-1, -1}, ICARUS_WINGS);
    islands[6]->addEarthling(BOOKIE);

    //
    // island 7
    //
    islands[7]->addItem({-1, -1}, MONEY);
    islands[7]->addItem({-1, -1}, MONEY);
    islands[7]->addItem({-1, -1}, MONEY);
    islands[7]->addItem({-1, -1}, MONEY);
    islands[7]->addItem({-1, -1}, FOOD);
    islands[7]->addItem({-1, -1}, FOOD);
    islands[7]->addItem({-1, -1}, FOOD);
    islands[7]->addItem({-1, -1}, FOOD);
    islands[7]->addItem({-1, -1}, RANDOM_ITEM);
    islands[7]->addItem({-1, -1}, RANDOM_ITEM);
}


/**
 * @name play
 * @brief runs the game loop until either the user quits or the game finishes
 * @param none
 * @return void
 */
void Game::play() {
    string message;
    setupGame();
    introMessage();

    while (!gameOver) {
        printGame();

        // get user move
        int choice = fetchInput(playerOpts, "\nPlayer Controls: \n");

        // If either:
        //  A) the user chose to quit from the menu OR
        //  B) the player was no longer alive at the end of the processing
        //  ...then the game is over
        if (choice == static_cast<int>(playerOpts.size())) {

            gameOver = true;
            message = inColor(string("\n**************************   GAME OVER   **************************\n") +
                              "**                                                               **\n" +
                              "**                        Come back soon!                        **\n" +
                              "**                                                               **\n" +
                              "*******************************************************************\n", WHITE);

        } else if (!processInput(choice)) {

            gameOver = true;
            message = inColor(string("\n**************************   GAME OVER   **************************\n") +
                              "**                                                               **\n" +
                              "**                    You ran out of energy.                     **\n" +
                              "**          It\'s a tough world out there for an alien,           **\n" +
                              "**           but I\'ve got a special feeling about you.           **\n" +
                              "**                                                               **\n" +
                              "*******************************************************************\n", RED);
        }
    }

    cout << message << endl;
}


/**
 * @name introMessage
 * @brief shows the initial game information to the user
 * @param none
 * @return void
 */
void Game::introMessage() {
    string comment;

    player->makeComment(showHeading("ALERT"), false, RED, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);

    comment = "This is Intergallactia J15 speaking:";
    comment += "\nUhhh...Something\'s gone terribly wrong my Alien friend!";
    comment += "\nIt looks like you\'ve crash landed your spaceship on planet Earth.";
    comment += "\n\n\nPress [Enter] to continue...";

    player->makeComment(comment, true, RED, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

    comment = "The only way for you to get back home is to find each of the ship pieces scattered on";
    comment += "\nthese Earthly islands. All of us back home believe in you, but please hurry back!";
    comment += "\n\n\nPress [Enter] to continue...";

    player->makeComment(comment, true, RED);

    comment = "Here are some quick tips before I lose total communication!";
    comment += "\n\n1) As you move around, you\'ll reveal the spaces on the map.";
    comment += "\n2) Use the elevators to move up to the next island.";
    comment += "\n3) Collect money, food, and presents. You can use them for energy or to buy more items.";
    comment += "\n4) Watch out for the Earthlings! Some of them are good, some of...a.hg.e.f.rghh...dd.......";
    comment += "\n\n\nPress [Enter] to continue...";

    player->makeComment(comment, true, BLUE);
}


/**
 * @name showHelp
 * @brief Shows the help information to the player
 * @param none
 * @return void
 */
void Game::showHelp() {
    string comment;

    clearScreen();

    comment = "\n*The goal of the game is to find all the ship pieces on the islands";
    comment += "\n in order to put the spaceship back together again and fly home.";
    comment += "\n\n* There is one ship piece on each island.";
    comment += "\n\n* You can use the elevator to move up to the next island";

    player->makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, true);

    if (getValidBool("\nMore?")) {
        clearScreen();
        comment = "\nWhile an island is undiscovered, each of it\'s spaces will appear";
        comment += "\nas question marks on the map, but as you move around,";
        comment += "\nyou\'ll uncover the spaces and reveal what they contain";

        player->makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, true);
    } else {
        return;
    }


    if (getValidBool("\nMore?")) {
        clearScreen();
        comment = "\nYou can collect money, eat food, and collect items along the way.";
        comment += "\n*Money increases your cash. You can use this to purchase items or interact with some Earthlings";
        comment += "\n*Food will usually increase your energy, but some rotten food will decrease it.";
        comment += "\n*Different items will help you complete the game succesfully.";

        player->makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, true);
    } else {
        return;
    }


    if (getValidBool("\nMore?")) {
        clearScreen();
        comment = "\nFor instance, you want want to use an Inner Tube in water or Icarus Wings to fly in outer space";
        comment += "\nTake note, however, that these items don\'t last forever. You can monitor all the important";
        comment += "\ninformation about the game with the stats at the top of the terminal";

        player->makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, true);
    } else {
        return;
    }

    if (getValidBool("\nMore?")) {
        clearScreen();
        comment = "\nHere are some final tips for you:";
        comment += "\n1) Falling off the edge of an island will drop you to the island below";
        comment += "\n2) Look out for sharks in the water!";
        comment += "\n3) Interactions with other Earthlings are typically helpful (but may cost you)";
        comment += "\n4) Whenever you find all the ship pieces, the spaceship will appear somewhere on";
        comment += "\n   that island. Just find it and you\'ll fly home to victory!";

        player->makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, true);
        player->makeComment("\n\nGood luck out there!", GREEN);
    } else {
        return;
    }

}


/**
 * @name fetchInput
 * @brief fetches the user's input from the list of input options
 * @param optionList
 * @param prompt
 * @return int - the selected menu option
 */
int Game::fetchInput(vector<string> optionList, string prompt) {
    const unsigned int MIN_OPTION = 0;
    const unsigned int MAX_OPTION = static_cast<int>(optionList.size());

    return getValidInt(MIN_OPTION, MAX_OPTION, getMenu(optionList, true, prompt));
}


/**
 * @name processInput
 * @brief processes the user input. which triggers the various game processes for a single series of moves
 * @param input - the user's input
 * @return bool - true if the player is still alive at the end of the function, false if not
 */
bool Game::processInput(int input) {
    const int PLAYER_MENU_OPTION = 5;
    const int HELP_OPTION = 6;

    if (input >= 1 && input <= 4) {
        auto dir = static_cast<Direction>(input - 1);
        player->move(dir);
        printGame();

    } else if (input == PLAYER_MENU_OPTION) {
        player->showMenu();

    } else if (input == HELP_OPTION) {
        showHelp();
    }

    if (player->getSpace()->spaceType() != HOME_LAND) {
        // handle the earthling actions & movements
        processEarthlings();
    }

    // finally, check if the game is over as a result of the player variables
    return player->isAlive();
}


/**
 * @name printGame
 * @brief prints the state of the game in the terminal
 * @param none
 * @return void
 */
void Game::printGame() {
    clearScreen();
    player->printStats(true);
    printIsland(player->getSpace()->getIsland(), false);
    cout << endl;
}


/**
 * @name printIsland
 * @brief prints a specified island's state. if no island is provided,
 *  it prints the island that the player is currently on.
 * @param level - the island number to print
 * @param peek - if true, all covered spaces will be revealed
 * @return void
 */
void Game::printIsland(int level, bool peek) {
    if (level < 0) {
        level = player->getSpace()->getLevel();
    }
    islands[level]->print(peek);
}


/**
 * @name printIsland
 * @brief prints a specified island's state. if no island is provided,
 *  it prints the island that the player is currently on.
 * @param island - a pointer to the island to print
 * @param peek - if true, all covered spaces will be revealed
 * @return void
 */
void Game::printIsland(Island* island, bool peek) {
    if (island == nullptr) {
        player->getSpace()->getIsland()->print(peek);
    } else {
        island->print(peek);
    }
}


/**
 * @name movePlayerToIsland
 * @brief moves the player to a specified island, and optionally to a specified location on that island
 * @param island - a pointer to the island to move it
 * @param x - the x-coordinate on the island to move to
 * @param y - the y-coordinate on the island to move to
 * @return void
 */
void Game::movePlayerToIsland(Island* island, int x, int y) {
    Space* next = nullptr;

    // if the coords are specified, move the player to the specified coords on the specified island
    if ((x > -1 && y > -1) && island->spaceExists(x, y)) {
        next = island->getSpace(x, y);
    } else {
        next = island->randomAvailableGrassSpace();
    }

    player->move(next);

    getEnter("Now on Island " + to_string(player->getSpace()->getIsland()->getLevel()));

    if (player->getSpace()->getIsland() == islands[TOTAL_ISLANDS - 1]) {
        getEnter("Congratulations! You Win!!!\nYou've flown back to your homeland safely. Enjoy your time back home.");
    }
}


/**
 * @name linkAdjacentIslandSpaces
 * @brief links all the adjacent above & below pointers for all the island spaces
 * @param none
 * @return void
 */
void Game::linkAdjacentIslandSpaces() {
    Space* curr = nullptr;
    Space*** spaces = nullptr;
    Island* island = nullptr;

    for (int i = 0; i < TOTAL_ISLANDS; i++) {
        island = islands[i];
        int xSize = island->getSize().x;
        int ySize = island->getSize().y;
        spaces = island->getSpaces();

        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < ySize; y++) {
                curr = spaces[x][y];

                // link the adjacent top space
                if (curr->getTop() == nullptr && island->spaceExists(x - 1, y)) {
                    curr->setTop(spaces[x - 1][y]);
                }

                // link the adjacent bottom space
                if (curr->getBottom() == nullptr && island->spaceExists(x + 1, y)) {
                    curr->setBottom(spaces[x + 1][y]);
                }

                // link the adjacent left space
                if (curr->getLeft() == nullptr && island->spaceExists(x, y - 1)) {
                    curr->setLeft(spaces[x][y - 1]);
                }

                // link the adjacent right space
                if (curr->getRight() == nullptr && island->spaceExists(x, y + 1)) {
                    curr->setRight(spaces[x][y + 1]);
                }

                // link to a random GRASS space above
                if (island->getLevel() < TOTAL_ISLANDS) {
                    curr->setAbove(islands[i + 1]->randomAvailableGrassSpace());
                }

                // link to a random GRASS space below
                if (island->getLevel() > 0) {
                    curr->setBelow(islands[i - 1]->randomAvailableGrassSpace());
                }
            }
        }


    }
}


/**
 * @name getTotalIsland
 * @brief returns the value of TOTAL_ISLANDS
 * @return
 */
int Game::getTotalIslands() {
    return TOTAL_ISLANDS;
}


/**
 * @name showPlayerMenu
 * @brief shows the player's menu
 * @param none
 * @return void
 */
void Game::showPlayerMenu() {

}


/**
 * @name setupSpaceship
 * @brief sets up the aliens spaceship by creating all the required ship pieces, then
 *  randomizing their order within a vector so that they're not always on the same island
 *  each game.
 *  @param none
 *  @return void
 */
void Game::setupSpaceship() {
    // first initialize the spaceship vector w/ all the ship piece components.
    // There are 6 in all, one for each (non-homeland) island.
    spaceship.push_back(new ShipPiece(CABIN));
    spaceship.push_back(new ShipPiece(LEFT_BOOSTER));
    spaceship.push_back(new ShipPiece(RIGHT_BOOSTER));
    spaceship.push_back(new ShipPiece(CONTROL_BOARD));
    spaceship.push_back(new ShipPiece(LANDING_RODS));
    spaceship.push_back(new ShipPiece(PROPELLER));
    spaceship.push_back(new ShipPiece(ENGINE));

    random_device rd;
    auto rng = default_random_engine {rd()};
    shuffle(begin(spaceship), end(spaceship), rng);

    // places a ship piece on each island (besides the last one - AKA the homeland),
    //  because we want to assemble the spaceship in order to fly to the homeland.
    for (int i = 0; i < TOTAL_ISLANDS - 1; i++) {
        islands[i]->addShipPiece(spaceship[i], {-1, -1});
    }
}


/**
 * @name processEarthlings
 * @brief process/move all the earthlings on the island
 * @param none
 * @return void
 */
void Game::processEarthlings() {
    Island* island = player->getSpace()->getIsland();
    Space* space = nullptr;
    Earthling* earthling = nullptr;
    Element* element = nullptr;

    // reset the [turnComplete] value for each earthling on the island so that
    //  they can move during this turn.
    resetEarthlingsTurnComplete();

    Size size = island->getSize();

    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            space = island->getSpace(x, y);

            if (space != nullptr) {
                element = space->getElement();

                if (element != nullptr && element->getElementType() == EARTHLING) {
                    earthling = dynamic_cast<Earthling*>(element);
                    // only move each Earthling once in a given turn
                    if (!earthling->isTurnComplete()) {
                        earthling->move();
                        earthling->setTurnComplete(true);
                    }
                }
            }
        }
    }
}


/**
 * @name resetEarthlingsTurnComplete
 * @brief resets the [turnComplete] value for each of the Earthlings at the beginning of each process step
 * @param none
 * @return void
 */
void Game::resetEarthlingsTurnComplete() {
    Island* curr = currentIsland();
    Size size = curr->getSize();
    Space* space = nullptr;
    Element* element = nullptr;

    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            space = curr->getSpace(x, y);

            if (space != nullptr) {
                element = space->getElement();

                if (element != nullptr && element->getElementType() == EARTHLING) {
                    dynamic_cast<Earthling*>(element)->setTurnComplete(false);
                }
            }
        }
    }
}


/**
 * @name currentIsland
 * @brief returns a pointer to the Island that the player is currently on
 * @param none
 * @return Island*
 */
Island* Game::currentIsland() {
    Island* curr = nullptr;

    if (player != nullptr) {
        curr = player->getSpace()->getIsland();
    }

    return curr;
}


/**
 * @name getPlayer
 * @brief getter function that returns a pointer to the game's player
 * @param none
 * @return Alien* - a pointer to the player
 */
Alien* Game::getPlayer() {
    return player;
}


/**
 * @name getGameOver
 * @brief getter
 * @return bool
 */
bool Game::getGameOver() const {
    return gameOver;
}


/**
 * @name setGameOver
 * @brief setter
 * @param gameOver
 * @return void
 */
void Game::setGameOver(bool gameOver) {
    this->gameOver = gameOver;
}
