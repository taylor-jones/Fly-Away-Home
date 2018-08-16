/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Island.hpp is the Island class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Island class.
**********************************************************/

#ifndef ISLAND_HPP
#define ISLAND_HPP


#include "Element.hpp"
#include "Space.hpp"
#include "Structures.hpp"
#include "Item.hpp"
#include "Earthling.hpp"

class Game;

class Island {
  private:
    //
    // member variables
    //
    int level = -1;
    int xSize = 30;
    int ySize = 30;

    Space*** island;
    Island* above = nullptr;
    Island* below = nullptr;
    Game* game = nullptr;



    //
    // member functions
    //
    void allocateSpaces();
    void addOuterSpaceBorder(int depth = 1);
    void fillRemainingSpacesWithSpaceType(SpaceType spaceType);
    int spaceTypeTotal(SpaceType spaceType = NO_SPACE, OccupiedState occupiedState = NO_OCCUPIED_STATE);
    std::vector<Space*>spacesOfTypeAndState(SpaceType spaceType = NO_SPACE, OccupiedState occupiedState = NO_OCCUPIED_STATE);
    Space* makeSpaceFromSpaceType(SpaceType spaceType);
    Item* makeItemFromItemType(ItemType itemType);
    Earthling* makeEarthlingFromEarthlingType(EarthlingType earthlingType);


  public:
    explicit Island(int level, int x = 30, int y = 30);
    ~Island();

    // getters
    int getLevel();
    bool spaceExists(int x, int y);

    Island* getAbove();
    Island* getBelow();
    Size getSize();
    Space*** getSpaces();
    Space* getSpace(int x, int y);
    Space* randomAvailableGrassSpace();
    Space* randomAvailableHomelandSpace();
    Space* randomUnoccupiedSpaceOfSpaceType(SpaceType spaceType);
    Game* getGame() const;


    // setters
    void addSpaces(Coordinates loc, SpaceType spaceType, Size size, bool allowToOverride = false);
    void addSlider(Coordinates loc, Direction direction, int length);
    void addShipPiece(Item* piece, Coordinates loc);

    void addEarthling(EarthlingType earthlingType);
    void addItem(Coordinates loc, ItemType itemType, bool allowOverride = false);
    void setAbove(Island* island);
    void setBelow(Island* island);
    void setLevel(int level);
    void setSize(int x, int y);
    void setGame(Game* game);


    // activity
    void complete(int elevatorCount = 1, int mailboxCount = 1, int spaceDepth = 1);
    void ensureHasSpaceType(SpaceType spaceType, int count);
    void print(bool peek = true);
    void uncoverEntireIsland();

};


#endif //ISLAND_HPP
