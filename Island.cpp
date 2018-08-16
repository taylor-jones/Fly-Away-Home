/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Island.cpp is the class implementation
**  file for the Island class. This file contains
**  definitions for the member functions of the Island class.
**********************************************************/

#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include "Island.hpp"
#include "Grass.hpp"
#include "Water.hpp"
#include "Road.hpp"
#include "Sand.hpp"
#include "OuterSpace.hpp"
#include "Elevator.hpp"
#include "Mailbox.hpp"
#include "Money.hpp"
#include "Food.hpp"
#include "Game.hpp"
#include "HomeLand.hpp"
#include "Slider.hpp"
#include "Spaceship.hpp"
#include "Innertube.hpp"
#include "SpeedSkates.hpp"
#include "IcarusWings.hpp"
#include "Decoy.hpp"
#include "Doorway.hpp"
#include "Binoculars.hpp"
#include "Wizard.hpp"
#include "Bookie.hpp"
#include "Cartographer.hpp"
#include "Shark.hpp"


using std::cout;
using std::endl;
using std::string;
using std::setw;


/**
 * @name Island
 * @brief Island class constructor
 * @param none
 * @return none
 */
Island::Island(int level, int x, int y) {
    this->level = level;
    this->xSize = x;
    this->ySize = y;
    allocateSpaces();
}



/**
 * @name ~Island
 * @brief Island class destructor
 * @param none
 * @return none
 */
Island::~Island() {
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            delete island[x][y];
        }
        delete island[x];
    }
    delete island;
}


/**
 * @name getAbove
 * @brief getter function that gets a pointer to the Island Above
 * @param none
 * @return Island*
 */
Island* Island::getAbove() {
    return above;
}


/**
 * @name getBelow
 * @brief getter function that gets a pointer to the Island below
 * @param none
 * @return Island*
 */
Island* Island::getBelow() {
    return below;
}

/**
 * @name setAbove
 * @brief setter function that sets a pointer to the Island Above
 * @param island - a pointer to an island
 * @return void
 */
void Island::setAbove(Island* island) {
    this->above = island;
}

/**
 * @name setBelow
 * @brief setter function that sets a pointer to the Island below
 * @param island - a pointer to an island
 * @return void
 */
void Island::setBelow(Island* island) {
    this->below = island;
}



/**
 * @name setGame
 * @brief getter function that returns a pointer to the Game
 * @param game - a pointer to a Game
 * @return void
 */
Game* Island::getGame() const {
    return game;
}


/**
 * @name setGame
 * @brief setter function that sets a pointer to the Game
 * @param game - a pointer to a Game
 * @return void
 */
void Island::setGame(Game* game) {
    this->game = game;
}




/**
 * @name spaceExists
 * @brief checks if a specified location exists on the island
 * @param x - the x coordinate to check
 * @param y - the y coordinate to check
 * @return bool (true if the location exists, false if not)
 */
bool Island::spaceExists(int x, int y) {
    return !(x < 0 || x >= xSize || y < 0 || y >= ySize);
}



/**
 * @name allocateSpaces
 * @brief allocates the spaces on the island
 * @param none
 * @return void
 */
void Island::allocateSpaces() {
    island = new Space**[xSize];

    for (int x = 0; x < xSize; x++) {
        island[x] = new Space*[ySize];

        for (int y = 0; y < ySize; y++) {
            island[x][y] = nullptr;
        }
    }
}



/**
 * @name makeSpaceFromSpaceType
 * @brief creates and returns a pointer to a new Space of a specified SpaceType
 * @param spaceType - the type of Space to make
 * @return Space* - a pointer to a newly created Space
 */
Space* Island::makeSpaceFromSpaceType(SpaceType spaceType) {
    Space* space = nullptr;

    if (spaceType == GRASS) {
        space = new Grass;
    } else if (spaceType == HOME_LAND) {
        space = new HomeLand;
    } else if (spaceType == WATER) {
        space = new Water;
    } else if (spaceType == ROAD) {
        space = new Road;
    } else if (spaceType == SAND) {
        space = new Sand;
    } else if (spaceType == SLIDER) {
        space = new Slider;
    } else if (spaceType == OUTER_SPACE) {
        space = new OuterSpace;
    } else if (spaceType == ELEVATOR) {
        space = new Elevator;
        space->setOccupiedState(INACCESSIBLE);
    } else if (spaceType == MAILBOX) {
        space = new Mailbox;
        space->setOccupiedState(INACCESSIBLE);
    }

    if (space != nullptr) {
        space->setLevel(level);
        space->setIsland(this);
        space->init();
    }

    return space;
}



/**
 * @name makeItemFromItemType
 * @brief creates and returns a pointer to a new Item of a specified ItemType
 * @param itemType - the type of Item to make
 * @return Item* - a pointer to a newly created Item
 */
Item* Island::makeItemFromItemType(ItemType itemType) {
    Item* item = nullptr;

    if (itemType == MONEY) {
        item = new Money();
    } else if (itemType == FOOD) {
        item = new Food();
    } else if (itemType == SPACESHIP) {
        item = new Spaceship();
    } else if (itemType == INNERTUBE) {
        item = new Innertube();
    } else if (itemType == SPEED_SKATES) {
        item = new SpeedSkates();
    } else if (itemType == ICARUS_WINGS) {
        item = new IcarusWings();
    } else if (itemType == DECOY) {
        item = new Decoy();
    } else if (itemType == DOORWAY) {
        item = new Doorway();
    } else if (itemType == BINOCULARS) {
        item = new Binoculars();
    }

    return item;
}



/**
 * @name makeEarthlingFromEarthlingType
 * @brief creates and returns a pointer to a new Earthling of a specified EarthlingType
 * @param earthlingType - the type of Earthling to make
 * @return Earthling* - a pointer to a newly created Earthling
 */
Earthling* Island::makeEarthlingFromEarthlingType(EarthlingType earthlingType) {
    Earthling* earthling = nullptr;

    if (earthlingType == WIZARD) {
        earthling = new Wizard();
    } else if (earthlingType == BOOKIE) {
        earthling = new Bookie();
    } else if (earthlingType == CARTOGRAPHER) {
        earthling = new Cartographer();
    } else if (earthlingType == SHARK) {
        earthling = new Shark();
    }

    return earthling;
}



/**
 * @name fillRemainingSpacesWithSpaceType
 * @brief fills any remaining island spaces with a specified spaceType
 * @param spaceType - the space type to fill the island with
 * @return void
 */
void Island::fillRemainingSpacesWithSpaceType(SpaceType spaceType) {
    // if the spaceType happens to be NO_SPACE, default to GRASS
    if (spaceType == NO_SPACE) {
        spaceType = GRASS;
    }

    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            if (island[x][y] == nullptr) {
                island[x][y] = makeSpaceFromSpaceType(spaceType);
                island[x][y]->setLocation({x, y});
            }
        }
    }
}



/**
 * @name addOuterSpaceBorder
 * @brief adds a border of OuterSpace spaces to the island
 * @param none
 * @return void
 */
void Island::addOuterSpaceBorder(int depth) {
    for (int x = 0; x < depth; x++) {
        for (int y = 0; y < ySize; y++) {
            if (spaceExists(x, y)) {
                if (island[x][y] != nullptr && island[x][y]->spaceType() != OUTER_SPACE) {
                    delete island[x][y];
                }

                island[x][y] = makeSpaceFromSpaceType(OUTER_SPACE);
                island[x][y]->setLocation({x, y});
            }
        }
    }

    for (int x = xSize - depth; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            if (spaceExists(x, y)) {
                if (island[x][y] != nullptr && island[x][y]->spaceType() != OUTER_SPACE) {
                    delete island[x][y];
                }

                island[x][y] = makeSpaceFromSpaceType(OUTER_SPACE);
                island[x][y]->setLocation({x, y});
            }
        }
    }

    for (int y = 0; y < depth; y++) {
        for (int x = 0; x < ySize; x++) {
            if (spaceExists(x, y)) {
                if (island[x][y] != nullptr && island[x][y]->spaceType() != OUTER_SPACE) {
                    delete island[x][y];
                }

                island[x][y] = makeSpaceFromSpaceType(OUTER_SPACE);
                island[x][y]->setLocation({x, y});
            }
        }
    }

    for (int y = ySize - depth; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            if (spaceExists(x, y)) {
                if (island[x][y] != nullptr && island[x][y]->spaceType() != OUTER_SPACE) {
                    delete island[x][y];
                }

                island[x][y] = makeSpaceFromSpaceType(OUTER_SPACE);
                island[x][y]->setLocation({x, y});
            }
        }
    }
}



/**
 * @name setLevel
 * @brief setter function that sets the island's level
 * @param level - the island level
 * @return void
 */
void Island::setLevel(int level) {
    this->level = level;
}



/**
 * @name setSize
 * @brief setter function that sets the island's size
 * @param x - the island's xSize
 * @param y - the island's ySize
 * @return void
 */
void Island::setSize(int x, int y) {
    this->xSize = x;
    this->ySize = y;
}



/**
 * @name getSize
 * @brief getter function that returns the size of the island as a Size struct
 * @param none
 * @return Size - a Size struct containing the island's size
 */
Size Island::getSize() {
    return { xSize, ySize };
}



/**
 * @name getSpaces
 * @brief gets a pointer to the spaces on the island
 * @param none
 * @return Space*** - a pointer to the spaces on the island
 */
Space*** Island::getSpaces() {
    return island;
}



/**
 * @name getSpace
 * @brief gets a pointer to the Space at a specified location on the island
 * @param x - the x-coord of the location
 * @param y - the y-coord of the location
 * @return Space* - a pointer to the space at the location (if it exists).
 *  If it doesn't exist, returns nullptr
 */
Space* Island::getSpace(int x, int y) {
    if (spaceExists(x, y)) {
        return island[x][y];
    }
    return nullptr;
}



/**
 * @name randomUnoccupiedSpaceOfSpaceType
 * @brief returns a pointer to a randomly selected Space of a specified SpaceType on this island
 * @param spaceType - the SpaceType to find a random selection of
 * @return Space* - a pointer to the randomly selected space (or nullptr if none is found)
 */
Space* Island::randomUnoccupiedSpaceOfSpaceType(SpaceType spaceType) {
    Space* result = nullptr;
    Space* tracer = nullptr;

    int totalUnoccupiedSpacesOfSpaceType = spaceTypeTotal(spaceType, UNOCCUPIED);

    if (totalUnoccupiedSpacesOfSpaceType > 0) {
        while (result == nullptr) {
            int x = randInt(0, xSize - 1);
            int y = randInt(0, ySize - 1);

            if (spaceExists(x, y)) {
                tracer = island[x][y];

                if (tracer->spaceType() == spaceType && tracer->getOccupiedState() == UNOCCUPIED) {
                    result = tracer;
                }
            }
        }
    }

    return result;
}



/**
 * @name randomAvailableHomelandSpace
 * @brief returns a pointer to a randomly selected Space on the island of type HOMELAND
 * @param none
 * @return Space* - a pointer to the HOMELAND space
 */
Space* Island::randomAvailableHomelandSpace() {
    Space* homelandSpace = nullptr;
    Space* tracer = nullptr;

    int totalUnoccupiedHomelandSpace = spaceTypeTotal(HOME_LAND, UNOCCUPIED);

    if (totalUnoccupiedHomelandSpace > 0) {
        while (homelandSpace == nullptr) {
            int x = randInt(0, xSize - 1);
            int y = randInt(0, ySize - 1);

            if (spaceExists(x, y)) {
                tracer = island[x][y];

                if (tracer->spaceType() == HOME_LAND && tracer->getOccupiedState() == UNOCCUPIED) {
                    homelandSpace = tracer;
                }
            }
        }
    }

    return homelandSpace;
}



/**
 * @name randomAvailableGrassSpace
 * @brief returns a pointer to a randomly selected Space on the island of type GRASS
 * @param none
 * @return Space* - a pointer to the GRASS space
 */
Space* Island::randomAvailableGrassSpace() {
//    Space* space = nullptr;
    Space* grassSpace = nullptr;
    Space* tracer = nullptr;

    int totalUnoccupiedGrassSpaces = spaceTypeTotal(GRASS, UNOCCUPIED);

    if (totalUnoccupiedGrassSpaces > 0) {
        while (grassSpace == nullptr) {
            int x = randInt(0, xSize - 1);
            int y = randInt(0, ySize - 1);

            if (spaceExists(x, y)) {
                tracer = island[x][y];

                if (tracer->spaceType() == GRASS && tracer->getOccupiedState() == UNOCCUPIED) {
                    grassSpace = tracer;
                }
            }
        }
    }

    return grassSpace;
}



/**
 * @name getLevel
 * @brief getter function that returns the island's level
 * @param none
 * @return int - the island's level
 */
int Island::getLevel() {
    return level;
}



/**
 * @name complete
 * @brief complete the setup of the island
 * @param elevatorCount - the total # of elevators that should be on the island
 * @param mailboxCount - the total # of mailboxes that should be on the island
 * @param spaceDepth - the depth of the surrounding outer space for the island
 * @return void
 */
void Island::complete(int elevatorCount, int mailboxCount, int spaceDepth) {
    if (level < game->getTotalIslands() - 1) {
        addOuterSpaceBorder(spaceDepth);
        fillRemainingSpacesWithSpaceType(GRASS);

        // these 'ensure' methods need to be executed at the end
        if (level < game->getTotalIslands() - 2) {
            ensureHasSpaceType(ELEVATOR, elevatorCount);
        }

        ensureHasSpaceType(MAILBOX, mailboxCount);

    } else {
        // it's the HomeLand level
        fillRemainingSpacesWithSpaceType(HOME_LAND);
    }
}



/**
 * @note addSpaces
 * @brief adds a specified type of space(s) to the island
 * @param loc - the coordinate location where the space type should start. If the location
 *  is not within the bounds of the island, the space won't be added.
 * @param spaceType - the type of space to add
 * @param size - the width (x) and length (y) of the added space(s)
 * @return void
 * @note at any point, if a space that would be added by this function does not exist on the map,
 *  it won't be added.
 */
void Island::addSpaces(Coordinates loc, SpaceType spaceType, Size size, bool allowToOverride) {
    int bufferX = 0, bufferY = 0;

    if (loc.x == 0) {
        bufferX = 1;
    }

    if (loc.y == 0) {
        bufferY = 1;
    }

    for (int x = loc.x; x < loc.x + size.x + bufferX; x++) {
        for (int y = loc.y; y < loc.y + size.y + bufferY; y++) {
            if (spaceExists(x, y)) {
                if (island[x][y] == nullptr) {
                    island[x][y] = makeSpaceFromSpaceType(spaceType);
                    island[x][y]->setLocation({x, y});

                } else if (allowToOverride) {
                    delete island[x][y];
                    island[x][y] = makeSpaceFromSpaceType(spaceType);
                    island[x][y]->setLocation({x, y});
                }
            }
        }
    }
}



/**
 * @name addSlider
 * @brief adds a Slider (or multiple Slider) Space to the island
 * @param loc - the starting coordinates of the slider
 * @param direction - the direction that the Slider will slide
 * @param length - the number of sliders that will be placed in succession
 */
void Island::addSlider(Coordinates loc, Direction direction, int length) {
    int x = loc.x, y = loc.y;
    int total = 0;
    Space* curr = nullptr;
    Space* temp = nullptr;

    while (spaceExists(x, y) && total < length) {
        curr = getSpace(x, y);

        if (curr != nullptr) {
            temp = curr;
        }

        island[x][y] = new Slider(direction);
        curr = island[x][y];
        curr->setLevel(level);
        curr->setIsland(this);
        curr->init();

        total += 1;

        if (direction == UP) {
            x -= 1;
        } else if (direction == DOWN) {
            x += 1;
        } else if (direction == LEFT) {
            y -= 1;
        } else if (direction == RIGHT) {
            y += 1;
        }
    }

    delete temp;
}



/**
 * @name addItem
 * @brief adds an item of a specified itemType to the island
 * @param loc - the location on the island to place the item
 * @param itemType - the ItemType
 * @param allowOverride - should this item be allowed to replace an existing item at the location?
 * @return - void
 */
void Island::addItem(Coordinates loc, ItemType itemType, bool allowOverride) {
    Space* space = nullptr;
    Item* item = nullptr;

    int attempts = 0;
    bool itemPlaced = false;

    if (itemType == RANDOM_ITEM) {
        itemType = static_cast<ItemType>(randInt(0, 7));
    }


    // if the coordinates are -1, -1, then that's an indicator that the item should
    //  be randomly placed on an appropriate space
    if (loc.x == -1 && loc.y == -1) {
        while (!itemPlaced && attempts < xSize * ySize * xSize) {
            int x = randInt(0, xSize - 1);
            int y = randInt(0, ySize - 1);

            space = island[x][y];

            // items can't go in: OUTER_SPACE, MAILBOX, or ELEVATOR
            // items can go in: GRASS, WATER, SAND, and ROAD
            if (space != nullptr &&
                space->getOccupiedState() == UNOCCUPIED &&
                (space->spaceType() == GRASS ||
                space->spaceType() == WATER ||
                space->spaceType() == SAND ||
                space->spaceType() == ROAD ||
                space->spaceType() == HOME_LAND)) {

                item = makeItemFromItemType(itemType);
                item->setSpace(space);
                item->getSpace()->setOccupiedState(ACCESSIBLE);
                item->getSpace()->setIsland(this);
                item->getSpace()->setElement(item);
                itemPlaced = true;
            }

            attempts += 1;
        }

    } else if (island[loc.x][loc.y] != nullptr &&
        island[loc.x][loc.y]->getOccupiedState() == UNOCCUPIED &&
        (island[loc.x][loc.y]->spaceType() == GRASS ||
         island[loc.x][loc.y]->spaceType() == WATER ||
         island[loc.x][loc.y]->spaceType() == SAND ||
         island[loc.x][loc.y]->spaceType() == ROAD ||
         island[loc.x][loc.y]->spaceType() == HOME_LAND)) {

        item = makeItemFromItemType(itemType);
        item->setSpace(island[loc.x][loc.y]);
        item->getSpace()->setOccupiedState(ACCESSIBLE);
        item->getSpace()->setIsland(this);
        item->getSpace()->setElement(item);
    }

}



/**
 * @name addEarthling
 * @brief adds an Earthling of a specified type to the island at a random (but appropriate) locatino
 * @param earthlingType - the type of earthling to add
 * @return void
 * @note If there aren't any appropriate locations on the island for the specified earthlingType, then
 *  this function will result in an infinite loop, so be cautious of that.
 */
void Island::addEarthling(EarthlingType earthlingType) {
    Space* space = nullptr;
    Earthling* earthling = nullptr;
    SpaceType spaceType = NO_SPACE;
    OccupiedState occupiedState = NO_OCCUPIED_STATE;
    bool spaceFound = false;


    while (!spaceFound) {
        int x = randInt(0, xSize - 1);
        int y = randInt(0, ySize - 1);

        space = island[x][y];

        if (space != nullptr) {
            // EarthlingType placement rules:
            //  - No earthling can be placed in OUTER_SPACE, HOMELAND, MAILBOX, or ELEVATOR spaces
            //  - Sharks can only be placed in Water spaces
            //  - Non-Sharks can only be placed in non-water spaces
            spaceType = space->spaceType();
            occupiedState = space->getOccupiedState();

            if (earthlingType == SHARK && occupiedState == UNOCCUPIED && spaceType == WATER) { // this space works for a shark
                spaceFound = true;
            } else if (earthlingType != SHARK && occupiedState == UNOCCUPIED &&
                (spaceType == GRASS || spaceType == ROAD || spaceType == SAND)) { // this space works for a non-shark earthling
                spaceFound = true;
            }
        }
    }


    // once the loop breaks, that means an appropriate space has been found to place this earthling
    earthling = makeEarthlingFromEarthlingType(earthlingType);
    earthling->setSpace(space);
    space->setOccupiedState(INACCESSIBLE);
    /* TODO: what to do here about the earthling's occupied state? I think if it's INACESSIBLE then the alien wont
     *  be able to interact w/ it (the way the code is right now), but if it's ACCESSIBLE, the alien will take it's place
     *  as if it's an item (the way the code is right now). I'll need to refactor one way or another i think.
     * */
    space->setIsland(this);
    space->setElement(earthling);

    if (earthlingType == SHARK) {
        dynamic_cast<Shark*>(earthling)->init(game->getPlayer());
    }
}



/**
 * @name print
 * @brief prints the state of the island
 * @param peek - should covered spaces be revealed?
 * @return void
 * @note The code for thi function wes inspired by a similar function in the example project
 *  code from Long Le.
 */
void Island::print(bool peek) {
    Space* space = nullptr;
    Element* element = nullptr;
    string symbol;
    Color color = DEFAULT_COLOR;
    Color backColor = DEFAULT_COLOR;


    // print the island indicator
    if (level < game->getTotalIslands() - 1) {
        cout << "Island: " << level << endl << endl;
    } else {
        cout << "Welcome Home!" << endl;
    }


    // draw the top border
//    cout << " " << string(static_cast<unsigned long>(ySize * 2), '-') << endl;
    cout << "┌" << repeat("─", ySize * 2) <<  "┐" << endl;

    // draw the island
    for (int x = 0; x < xSize; x++) {
//        cout << "|"; // left border
        cout << "│"; // left border

        for (int y = 0; y < ySize; y++) {
            space = island[x][y];   // pointer to the space on the island
            element = space->getElement();  // pointer to the element in the space


            if (space->getCovered() && !peek) {
                // display the space as hidden
                color = BLACK;
                cout << setw(2) << inColor(" " + space->getVisual(false), GREY, DEFAULT_COLOR);
            } else {
                if (element != nullptr) {
                    // display the colors associated w/ the element
                    symbol = " " + element->getSymbol();
                    color = element->getColor();

                    if (element->getBackColor() == INVISIBLE) {
                        backColor = space->getBackColor();
                    } else {
                        backColor = element->getBackColor();
                    }
                } else {
                    // display the colors associated w/ the space
                    symbol = " " + space->getSymbol();
                    color = space->getColor();
                    backColor = space->getBackColor();
                }

                cout << setw(2) << inColor(symbol, color, backColor, BOLD);
            }
        }

//        cout << inColor("", color, backColor) << "|" << endl; // right border
        cout << inColor("", color, backColor) << "│" << endl; // right borderÍ

    }

    // draw the bottom border
//    cout << " " << string(static_cast<unsigned long>(ySize * 2), '-') << endl;
    cout << "└" << repeat("─", ySize * 2) << "┘" << endl;
}



/**
 * @name ensureHasSpaceType
 * @brief ensure the island has at least the specified count of a particular SpaceType
 * @param spaceType - the SpaceType to ensure
 * @param count - the number of Spaces of that SpaceType to ensure
 */
void Island::ensureHasSpaceType(SpaceType spaceType, int count) {
    Space* temp = nullptr;

    int total = spaceTypeTotal(spaceType);
    int attempts = 0;

    while (total < count && attempts < xSize * ySize) {
        int x = randInt(0, xSize - 1);
        int y = randInt(0, ySize - 1);

        temp = island[x][y];

        if (temp != nullptr && (temp->spaceType() == GRASS || temp->spaceType() == HOME_LAND)) {
            island[x][y] = makeSpaceFromSpaceType(spaceType);
            island[x][y]->setLocation({x, y});
            delete temp;
            total += 1;
        }

        attempts += 1;
    }
}




/**
 * @name spaceTypeTotal
 * @brief returns the total # of a specified spaceType on the island
 * @param spaceType - the spaceType to count
 * @param occupiedState - (optional) if != NO_OCCUPIED_STATE, then only return the count
 *  of spaces also scoped to the specified occupiedState.
 * @return int - the total # of spaces of that spaceType (and occupiedState, if applicable)
 */
int Island::spaceTypeTotal(SpaceType spaceType, OccupiedState occupiedState) {
    Space* space = nullptr;
    int total = 0;

    // based on the arguments, the results can be scoped to either:
    //  A) the space type
    //  B) the occupied state
    //  C) or both
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            space = island[x][y];

            if (space->isSpaceTypeAndOccupiedState(spaceType, occupiedState)) {
                total += 1;
            }
        }
    }

    return total;
}



/**
 * @note spacesOfTypeAndState
 * @brief builds and returns a vector of pointers to Spaces on the island
 *  of a specified SpaceType and/or Occupied State
 * @param spaceType - the SpaceType that the space must match
 *  (or if the spaceType == NO_SPACE, then any SpaceType matches)
 * @param occupiedState - the OccupiedState that the space must match
 *  (or if the occupiedState == NO_OCCUPIED_STATE, then any OccupiedState matches)
 * @return - vector<Space*> - a vector of pointers to the Spaces on the island that match
 */
std::vector<Space*> Island::spacesOfTypeAndState(SpaceType spaceType, OccupiedState occupiedState) {
    Space* space = nullptr;
    vector<Space*>matches;

    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            space = island[x][y];

            if (space->isSpaceTypeAndOccupiedState(spaceType, occupiedState)) {
                matches.push_back(space);
            }
        }
    }

    return matches;
}



/**
 * @name addShipPiece
 * @brief place the ship piece from the spaceship somewhere on the island
 * @param piece - a pointer to the ship piece item to place
 * @param loc - a specified location to place the ship piece
 * @return void
 */
void Island::addShipPiece(Item* piece, Coordinates loc) {
    Space* space = nullptr;
    bool spaceFound = false;

    if (piece != nullptr) {
        if (loc.x > -1 && loc.y > -1) {
            if (spaceExists(loc.x, loc.y)) {
                space = island[loc.x][loc.y];

                if (space->isSpaceTypeAndOccupiedState(GRASS, UNOCCUPIED)) {
                    // we'll use the specified space
                    spaceFound = true;
                }
            }
        }

        if (!spaceFound) {
            // we'll use a random GRASS space
            space = randomAvailableGrassSpace();
        }

        // place the ship piece at the determined space
        space->setElement(piece);
        space->setOccupiedState(ACCESSIBLE);
        piece->setSpace(space);

    } else {
        getEnter("Passed NULL ship piece to island " + to_string(level) + " (Island::addShipPiece)");
    }
}


/**
 * @name uncoverEntireIsland
 * @brief uncovers all the spaces on the island
 * @param none
 * @return void
 */
void Island::uncoverEntireIsland() {
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            island[x][y]->setCovered(false);
        }
    }
}



