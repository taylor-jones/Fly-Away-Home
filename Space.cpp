/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Space.cpp is the class implementation
**  file for the Space class. This file contains
**  definitions for the member functions of the Space class.
**********************************************************/

#include "Space.hpp"
#include "Game.hpp"


/**
 * @name Space
 * @brief Space class constructor
 * @return none
 */
Space::Space() {}


/**
 * @name Space
 * @brief Space class constructor that allows for specifying the level of the space
 * @param level
 * @return none
 */
Space::Space(int level) {
    this->level = level;
}


/**
 * @name Space
 * @brief Space class constructor that allows for specifying the Island that the space is on
 * @param island
 * @return none
 */
Space::Space(Island* island) {
    this->island = island;
}




/**
 * @name ~Space
 * @brief Space class destructor
 * @param none
 * @return none
 */
Space::~Space() {

}



/**
 * @name getSymbol
 * @brief getter function that retrieves the Space's symbol
 * @param none
 * @return string - the Space's symbol
 */
string Space::getSymbol() {
    return symbol;
}


/**
 * @name getCovered
 * @brief getter function to retrieve the value of covered
 * @return covered
 */
bool Space::getCovered() {
    return covered;
}




/**
 * @brief returns the "visible" symbol that should be displayed to the user
 * @param peek - boolean indicator as to whether the visible symbol should be
 *  seen - even if the space is still covered
 * @return - the symbol that will be visible to the user.
 */
string Space::getVisual(bool peek) {
    if (peek || !covered) {
        return symbol;
    }
    return COVERED_SYMBOL;
}



Space* Space::getLeft() {
    return this->left;
}


Space* Space::getRight() {
    return this->right;
}


Space* Space::getTop() {
    return this->top;
}


Space* Space::getBottom() {
    return this->bottom;
}


Space* Space::getAbove() {
    return this->above;
}


Space* Space::getBelow() {
    return this->below;
}


Color Space::getColor() {
    return this->color;
}


Color Space::getBackColor() {
    return this->backColor;
}


OccupiedState Space::getOccupiedState() {
    return this->occupiedState;
}


Element* Space::getElement() {
    return element;
}

Island* Space::getIsland() {
    return island;
}





void Space::setTop(Space* space) {
    delete this->top;
    this->top = space;
}


void Space::setBottom(Space* space) {
    delete this->bottom;
    this->bottom = space;
}


void Space::setLeft(Space* space) {
    delete this->left;
    this->left = space;
}


void Space::setRight(Space* space) {
    delete this->right;
    this->right = space;
}


void Space::setAbove(Space* space) {
    delete this->above;
    this->above = space;
}


void Space::setBelow(Space* space) {
    delete this->below;
    this->below = space;
}


void Space::setCovered(bool covered) {
    this->covered = covered;
}


void Space::setSymbol(string symbol) {
    this->symbol = symbol;
}


void Space::setColor(Color color) {
    this->color = color;
}


void Space::setBackColor(Color color) {
    this->backColor = color;
}


void Space::setOccupiedState(OccupiedState occupiedState) {
    this->occupiedState = occupiedState;
}


void Space::setElement(Element* element) {
    this->element = element;
}

void Space::setIsland(Island* island) {
    this->island = island;
}

void Space::setLevel(int level) {
    this->level = level;
}

int Space::getLevel() {
    return level;
}



const Coordinates &Space::getLocation() const {
    return location;
}

void Space::setLocation(const Coordinates &location) {
    this->location = location;
}




/**
 * @name getDirection
 * @brief gets a pointer to the neighboring Space in a specified direction
 * @param direction - the direction to look in
 * @return Space* - a pointer to the space in the specified direction
 */
Space* Space::getDirection(Direction direction) {
    Space* space = nullptr;

    if (direction == UP) {
        space = getTop();
    } else if (direction == DOWN) {
        space = getBottom();
    } else if (direction == LEFT) {
        space = getLeft();
    } else if (direction == RIGHT) {
        space = getRight();
    } else if (direction == ABOVE) {
        space = getAbove();
    } else if (direction == BELOW) {
        space = getBelow();
    }

    return space;
}



/**
 * @name getName
 * @brief getter function to get the Space's name
 * @param none
 * @return string - the Space's name
 */
string Space::getName() const {
    return name;
}



/**
 * @name reload
 * @brief reloads the game in the terminal
 * @param none
 * @return void
 */
void Space::reload() {
    Island* island = nullptr;
    Game* game = nullptr;

    if (this->getIsland() != nullptr) {
        island = this->getIsland();

        if (island->getGame() != nullptr) {
            game = island->getGame();
            game->printGame();
        }
    }
}



/**
 * @name nearestAvailableSpace
 * @brief gets the nearest available space to this Space
 * @param none
 * @return Space* - a pointer to the nearest available space
 */
Space* Space::nearestAvailableSpace() {

    int distanceFromLeftAvailable = -1;
    int distanceFromRightAvailable = -1;
    int distanceFromTopAvailable = -1;
    int distanceFromBottomAvailable = -1;

    Space* nearestRight = nullptr;
    Space* nearestLeft = nullptr;
    Space* nearestTop = nullptr;
    Space* nearestBottom = nullptr;

    if (getRight() != nullptr) {
        if (getRight()->getOccupiedState() == UNOCCUPIED) {
            distanceFromRightAvailable = 0;
        } else {
            while (getRight()->getOccupiedState() != UNOCCUPIED) {
                distanceFromRightAvailable += 1;
                if (getRight() != nullptr) {
                    nearestRight = getRight();
                } else {
                    distanceFromRightAvailable = -1;
                }
            }
        }
    }


    if (getLeft() != nullptr) {
        if (getLeft()->getOccupiedState() == UNOCCUPIED) {
            distanceFromLeftAvailable = 0;
        } else {
            while (getLeft()->getOccupiedState() != UNOCCUPIED) {
                distanceFromLeftAvailable += 1;
                if (getLeft() != nullptr) {
                    nearestLeft = getLeft();
                } else {
                    distanceFromLeftAvailable = -1;
                }
            }
        }
    }


    if (getTop() != nullptr) {
        if (getTop()->getOccupiedState() == UNOCCUPIED) {
            distanceFromTopAvailable = 0;
        } else {
            while (getTop()->getOccupiedState() != UNOCCUPIED) {
                distanceFromTopAvailable += 1;
                if (getTop() != nullptr) {
                    nearestTop = getTop();
                } else {
                    distanceFromTopAvailable = -1;
                }
            }
        }
    }


    if (getBottom() != nullptr) {
        if (getBottom()->getOccupiedState() == UNOCCUPIED) {
            distanceFromBottomAvailable = 0;
        } else {
            while (getBottom()->getOccupiedState() != UNOCCUPIED) {
                distanceFromBottomAvailable += 1;
                if (getBottom() != nullptr) {
                    nearestBottom = getBottom();
                } else {
                    distanceFromBottomAvailable = -1;
                }
            }
        }
    }


    vector<int>distances = { distanceFromBottomAvailable, distanceFromTopAvailable, distanceFromLeftAvailable, distanceFromRightAvailable };
    int tempMin = distanceFromBottomAvailable;

    for (int distance : distances) {
        if (distance < tempMin) {
            tempMin = distance;
        }
    }

    if (tempMin == distanceFromBottomAvailable) {
        return nearestBottom;
    } else if (tempMin == distanceFromTopAvailable) {
        return nearestTop;
    } else if (tempMin == distanceFromLeftAvailable) {
        return nearestLeft;
    } else if (tempMin == distanceFromRightAvailable) {
        return nearestRight;
    }

    return nullptr;
}


/**
 * @name isSpaceTypeAndOccupiedState
 * @brief checks if the Space is of a specified SpaceType &/OR OccupiedState
 * @param spaceType
 * @param occupiedState
 * @return bool - true if the space matches the specified space type & occupied state
 * @note - note that a spaceType of NO_SPACE and/or an occupiedState of NO_OCCUPIED_STATE
 *  are considered to be NULL arguments, meaning those components would not be required to match
 *  those specifications. For instance, an argument of (GRASS, NO_OCCUPIED_STATE) would mean
 *  the space only needs to be a GRASS space but could be of any occupied state to return true.
 *  Similarly, an argument of (NO_SPACE, UNOCCUPIED) would mean that a space of any SpaceType would
 *  only need to have an OccupiedState of UNOCCUPIED in order to return true.
 */
bool Space::isSpaceTypeAndOccupiedState(SpaceType spaceType, OccupiedState occupiedState) {
    // since both arguments are optional, the inspection could be checking to see if the space is
    // A) Only of a particular SpaceType
    // B) Only of a particular OccupiedState
    // C) Both
    // D) no SpaceType or OccupiedState requirements

    if (spaceType != NO_SPACE) {
        if (occupiedState != NO_OCCUPIED_STATE) {
            // C
            return (this->spaceType() == spaceType && this->occupiedState == occupiedState);
        } else {
            // A
            return (this->spaceType() == spaceType);
        }
    } else if (occupiedState != NO_OCCUPIED_STATE) {
        // B
        return (this->occupiedState == occupiedState);
    }

    // D
    return true;
}





