/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Game.hpp is the Game class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Game class.
**********************************************************/

#ifndef FINAL2_GAME_HPP
#define FINAL2_GAME_HPP

#include <string>
#include <vector>

#include "Island.hpp"
#include "Alien.hpp"
#include "ShipPiece.hpp"

using namespace std;

class Game {
  private:
    //
    //  member variables
    //
    static const int TOTAL_ISLANDS = 8;
    bool gameOver = false;

    Island* islands[TOTAL_ISLANDS];
    Alien* player = nullptr;

    vector<string>gameOpts;
    vector<string>playerOpts;
    vector<string>boolOpts;
    vector<ShipPiece*>spaceship;



    //
    // member functions
    //

    Island* currentIsland();
    void introMessage();
    void setupGame();
    void setupPlayer();
    void setupIslands();
    void setupSpaceship();
    void linkAdjacentIslandSpaces();
    void showPlayerMenu();
    void printIsland(int level = 0, bool peek = false);
    void printIsland(Island* island = nullptr, bool peek = false);
    void movePlayerToIsland(Island* island, int x = -1, int y = -1);
    bool processInput(int input);
    void resetEarthlingsTurnComplete();
    void processEarthlings();
    int fetchInput(vector<string> optionList, string prompt);


  public:
    Game();
    ~Game();

    // getters
    static int getTotalIslands();
    bool getGameOver() const;
    Alien* getPlayer();


    // setters
    void setGameOver(bool isGameOver);


    // activity
    void play();
    void showHelp();
    void printGame();
};


#endif //FINAL2_GAME_HPP
