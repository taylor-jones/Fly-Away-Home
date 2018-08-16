/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Space.hpp is the Space class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Space class.
**********************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <vector>
#include "Structures.hpp"
#include "util.hpp"
#include "menu.hpp"


enum SpaceType { GRASS, HOME_LAND, WATER, ROAD, SAND, SLIDER, OUTER_SPACE, ELEVATOR, MAILBOX, NO_SPACE };
enum OccupiedState { UNOCCUPIED, ACCESSIBLE, INACCESSIBLE, NO_OCCUPIED_STATE };

class Element;
class Island;

class Space {
  protected:
    static const int TOTAL_ISLANDS = 7;
    const string BLOCK_SYMBOL = "█";
    const string COVERED_SYMBOL = "?";

    Coordinates location = {-1, -1};
    Space* top = nullptr;
    Space* right = nullptr;
    Space* bottom = nullptr;
    Space* left = nullptr;
    Space* above = nullptr;
    Space* below = nullptr;

    int level = -1;
    string name = "None";

    bool covered = true; // is this space on the map still covered?
    OccupiedState occupiedState = UNOCCUPIED;

    Color color = DEFAULT_COLOR;
    Color backColor = DEFAULT_COLOR;
    string symbol = " ";
    Element* element = nullptr;
    Island* island = nullptr;


  public:
    Space();
    explicit Space(int level);
    explicit Space(Island* island);
    virtual ~Space();
    virtual void init() = 0;

    // getters
    virtual SpaceType spaceType() = 0;
    Space* getLeft();
    Space* getRight();
    Space* getTop();
    Space* getBottom();
    Space* getAbove();
    Space* getBelow();
    Space* getDirection(Direction direction);
    Space* nearestAvailableSpace();
    Element* getElement();
    Island* getIsland();
    OccupiedState getOccupiedState();
    const Coordinates &getLocation() const;

    int getLevel();
    bool getCovered();
    bool isSpaceTypeAndOccupiedState(SpaceType spaceType = NO_SPACE, OccupiedState occupiedState = NO_OCCUPIED_STATE);

    string getSymbol();
    string getName() const;
    string getVisual(bool peek = false);
    Color getColor();
    Color getBackColor();


    // setters
    void setLeft(Space* space = nullptr);
    void setRight(Space* space = nullptr);
    void setTop(Space* space = nullptr);
    void setBottom(Space* space = nullptr);
    void setAbove(Space* space = nullptr);
    void setBelow(Space* space = nullptr);
    void setElement(Element* element);
    void setIsland(Island* island);
    void setLevel(int level);
    void setLocation(const Coordinates &location);
    void setCovered(bool covered);
    void setOccupiedState(OccupiedState occupiedState);

    void setSymbol(string symbol);
    void setColor(Color color);
    void setBackColor(Color color);


    // activity
    virtual void experience(Element* experiencer) = 0;
    virtual void reload();
};


#endif //SPACE_HPP
