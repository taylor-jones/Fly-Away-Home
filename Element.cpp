/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Element.cpp is the class implementation
**  file for the Element class. This file contains
**  definitions for the member functions of the Element class.
**********************************************************/

#include <iostream>
#include "Element.hpp"
#include "Island.hpp"
#include "Game.hpp"

using std::cout;
using std::endl;

/**
 * @name Element
 * @brief Element class constructor
 * @param none
 * @return none
 */
Element::Element() = default;


/**
 * @name Element
 * @brief Element class destructor
 * @param none
 * @return none
 */
Element::~Element() = default;


/**
 * @name getColor
 * @brief getter
 * @param none
 * @return Color
 */
Color Element::getColor() {
    return color;
}


/**
 * @name getBackColor
 * @brief getter
 * @param none
 * @return Color
 */
Color Element::getBackColor() {
    return backColor;
}


/**
 * @name getSymbol
 * @brief getter
 * @param none
 * @return string
 */
string Element::getSymbol() {
    return symbol;
}


/**
 * @name getName
 * @brief getter
 * @param none
 * @return string
 */
string Element::getName() {
    return name;
}


/**
 * @name getElementType
 * @brief getter
 * @param none
 * @return ElementType
 */
ElementType Element::getElementType() {
    return elementType;
}


/**
 * @name getOrientation
 * @brief getter
 * @param none
 * @return Direction
 */
Direction Element::getOrientation() {
    return orientation;
}


/**
 * @name getSpace
 * @brief getter
 * @param none
 * @return Space*
 */
Space* Element::getSpace() {
    return space;
}


/**
 * @name setColor
 * @brief setter
 * @param Color
 * @return void
 */
void Element::setColor(Color color) {
    this->color = color;
}

/**
 * @name setBackColor
 * @brief setter
 * @param Color
 * @return void
 */
void Element::setBackColor(Color backColor) {
    this->backColor = backColor;
}

/**
 * @name setSymbol
 * @brief setter
 * @param string
 * @return void
 */
void Element::setSymbol(string symbol){
    this->symbol = symbol;
}


/**
 * @name setName
 * @brief setter
 * @param string
 * @return void
 */
void Element::setName(string name){
    this->name = name;
}


/**
 * @name setOrientation
 * @brief setter
 * @param Direction
 * @return void
 */
void Element::setOrientation(Direction orientation) {
    this->orientation = orientation;
}


/**
 * @name setSpace
 * @brief setter
 * @param Space*
 * @return void
 */
 void Element::setSpace(Space* space) {
    this->space = space;
}


/**
 * @name setElementType
 * @brief setter
 * @param ElementType
 * @return void
 */
void Element::setElementType(ElementType elementType) {
    this->elementType = elementType;
}



/**
 * @name move
 * @brief moves an Element to a specified Space
 * @param next - a pointer to the Space to move to
 * @return bool - maybe change this to void?
 */
bool Element::move(Space* next) {
    Space* prev = space;
    bool moveMade = false;

    if (next != nullptr && next->getOccupiedState() != INACCESSIBLE && next != prev) {
        // this element will now occupy the new space. If this element is an item,
        // it will render the space ACCESSIBLE, meaning the player can still move this space,
        // but any other creature cannot.
        if (this->elementType == ITEM) {
            space->setOccupiedState(ACCESSIBLE);
        } else if (this->elementType == EARTHLING) {
            // if the element occupying the space is a EARTHLING, it will render
            //  the space INACCESSIBLE, meaning even the player cannot occupy this space.
            space->setOccupiedState(INACCESSIBLE);
        } else {
            getEnter("A move was made by an element w/ no valid ElementType");
        }

        // make the move to the next Space
        space = next;
        space->setElement(this);

        if (prev != nullptr) {
            prev->setOccupiedState(UNOCCUPIED);
            prev->setElement(nullptr);
        }

        moveMade = true;
    }

    return moveMade;
}




/**
 * @name move
 * @brief moves the element in a specified direction relative to it's current Space
 * @param direction - the Direction to move
 * @return bool (true if the move was made, false if not)
 */
bool Element::move(Direction direction) {
    Space* peekSpace = peek(direction);
    Space* prev = space;
    bool moveMade = false;

    if (peekSpace != nullptr && peekSpace->getOccupiedState() == UNOCCUPIED) {
        // a general element can only occupy a space that is unoccupied
        if (direction == UP) {
            space = space->getTop();
        } else if (direction == DOWN) {
            space = space->getBottom();
        } else if (direction == LEFT) {
            space = space->getLeft();
        } else if (direction == RIGHT) {
            space = space->getRight();
        } else if (direction == ABOVE) {
            space = space->getAbove();
        } else if (direction == BELOW) {
            space = space->getBelow();
        }
    }

    // update the occupied state of both the previous and current spaces, but only if a move was actually made
    if (space != prev) {
        // this element will now occupy the new space. If this element is an item,
        // it will render the space ACCESSIBLE, meaning the player can still move this space,
        // but any other creature cannot.
        if (this->elementType == ITEM) {
            space->setOccupiedState(ACCESSIBLE);
        } else if (this->elementType == EARTHLING) {
            // if the element occupying the space is a EARTHLING, it will render
            //  the space INACCESSIBLE, meaning even the player cannot occupy this space.
            space->setOccupiedState(INACCESSIBLE);
        } else {
            cout << "A move was made by an element w/ no valid ElementType" << endl;
            getEnter();
        }

        // remove the element pointer from the previous space and update it for the new space
        prev->setOccupiedState(UNOCCUPIED);
        prev->setElement(nullptr);
        space->setElement(this);
        moveMade = true;
    }

    // whether the move was made or not,
    // update the Element's orientation to match the direction
    orientation = direction;

    return moveMade;
}



/**
 * @brief
 * @param direction
 * @return
 */
Space* Element::peek(Direction direction) {
    if (direction == UP) {
        return space->getTop();
    } else if (direction == DOWN) {
        return space->getBottom();
    } else if (direction == LEFT) {
        return space->getLeft();
    } else if (direction == RIGHT) {
        return space->getRight();
    } else if (direction == ABOVE) {
        return space->getAbove();
    } else if (direction == BELOW) {
        return space->getBelow();
    } else if (direction == NO_DIRECTION) {
        return space;
    } else {
        return nullptr;
    }
}



/**
 * @name reload
 * @brief reloads the game in the terminal
 * @param none
 * @return void
 */
void Element::reload() {
    Space* space = nullptr;
    Island* island = nullptr;
    Game* game = nullptr;

    if (this->getSpace() != nullptr) {
        space = this->getSpace();

        if (space->getIsland() != nullptr) {
            island = space->getIsland();

            if (island->getGame() != nullptr) {
                game = island->getGame();
                game->printGame();
            }
        }
    }
}



/**
 * @name makeComment
 * @brief outputs a comment from the Element to the terminal
 * @param comment - the comment to output
 * @param interrupt - boolean indicator as to whether the comment should interrupt
 *  gameplay & require the user to press [Enter] or not
 */
void Element::makeComment(string comment, bool interrupt, Color color, Color backColor, ColorFormat format, bool reloadBefore, bool reloadAfter) {
    if (reloadBefore) {
        reload();
    }

    comment = inColor(comment, color, backColor, format);

    if (interrupt) {
        getEnter(comment);
    } else {
        cout << comment << endl;
    }

    if (reloadAfter) {
        reload();
    }
}



/**
 * @name move
 * @brief generic move function w/ no arguments does only moves the element if
 *  the more specified class has specified AI movements for the element type
 * @param none
 * @return true
 */
bool Element::move() {
    // does nothing if not overriden
    return true;
}

