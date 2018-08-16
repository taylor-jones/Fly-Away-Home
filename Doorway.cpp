/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Doorway.cpp is the class implementation
**  file for the Doorway class. This file contains
**  definitions for the member functions of the Doorway class.
**********************************************************/


#include "Doorway.hpp"
#include "Alien.hpp"
#include "Island.hpp"


/**
 * @name Doorway
 * @brief Doorway class constructor
 * @param none
 * @return none
 */
Doorway::Doorway() {
    this->lifeSpan = 0;
    this->itemType = DOORWAY;
    this->name = "Doorway";
    this->price = randInt(1, 2);
}


/**
 * @name ~Doorway
 * @brief Doorway class destructor
 * @param none
 * @return none
 */
Doorway::~Doorway() {}



/**
 * @name interact
 * @brief interacts w/ the doorway by moving the Element to another random location on the island
 * @param actor - the Element interacting w/ the doorway
 * @return void
 */
void Doorway::interact(Element* actor) {
    if (actor->getElementType() != ITEM) {
        Space* comebackSpace = getSpace();
        Space* space = getSpace()->getIsland()->randomUnoccupiedSpaceOfSpaceType(GRASS);

        actor->move(space);
        comebackSpace->setElement(this);
    }
}



/**
 * @name use
 * @brief uses the doorway, which creates an element that looks like an Alien next to the
 *  Alien, and any Earthlings that are up to trouble will be drawn to the doorway just like
 *  they would be drawn to the Alien.
 * @details Only Aliens can use the doorway
 * @param actor - the Element using the doorway
 * @return void
 */
void Doorway::use(Element* actor) {
    this->symbol = "∩";
    this->color = RED;
    this->backColor = INVISIBLE;

    if (actor->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(actor);
        Space* doorwaySpace = nullptr;
        Space* space = alien->getSpace();

        if (space->getRight() != nullptr && space->getRight()->getOccupiedState() == UNOCCUPIED) {
            doorwaySpace = space->getRight();
        } else if (space->getLeft() != nullptr && space->getLeft()->getOccupiedState() == UNOCCUPIED) {
            doorwaySpace = space->getLeft();
        } else if (space->getTop() != nullptr && space->getTop()->getOccupiedState() == UNOCCUPIED) {
            doorwaySpace = space->getTop();
        } else if (space->getBottom() != nullptr && space->getBottom()->getOccupiedState() == UNOCCUPIED) {
            doorwaySpace = space->getBottom();
        }

        if (doorwaySpace != nullptr) {
            setSpace(doorwaySpace);
            doorwaySpace->setElement(this);
        }
    }
}
