/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Decoy.cpp is the class implementation
**  file for the Decoy class. This file contains
**  definitions for the member functions of the Decoy class.
**********************************************************/


#include "Decoy.hpp"
#include "Alien.hpp"


/**
 * @name Decoy
 * @brief Decoy class constructor
 * @param none
 * @return none
 */
Decoy::Decoy() {
    this->itemType = DECOY;
    this->name = "Decoy";
    this->price = randInt(1, 3);
    this->backColor = WHITE;
    this->color = BLACK;
    this->elementType = ITEM;
    this->symbol = "%";
}


/**
 * @name ~Decoy
 * @brief Decoy class destructor
 * @param none
 * @return none
 */
Decoy::~Decoy() {}



/**
 * @name interact
 * @brief interacts w/ the decoy by prompting the alien to add them to its bag
 * @details Only Aliens may interact w/ decoy
 * @param actor - the Element interacting w/ the decoy
 * @return void
 */
void Decoy::interact(Element* actor) {
    if (!isPlaced) {
        if (actor != nullptr && actor->getElementType() == ALIEN) {
            dynamic_cast<Alien*>(actor)->checkPickupBagItem(this);
        }
    }
}


/**
 * @name use
 * @brief uses the decoy, which creates an element that looks like an Alien next to the
 *  Alien, and any Earthlings that are up to trouble will be drawn to the decoy just like
 *  they would be drawn to the Alien.
 * @details Only Aliens can use the decoy
 * @param actor - the Element using the decoy
 * @return void
 */
void Decoy::use(Element* actor) {
    if (actor->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(actor);
        this->symbol = alien->getSymbol();

        Space* decoySpace = nullptr;
        Space* space = alien->getSpace();

        if (space->getRight() != nullptr && space->getRight()->getOccupiedState() == UNOCCUPIED) {
            decoySpace = space->getRight();
        } else if (space->getLeft() != nullptr && space->getLeft()->getOccupiedState() == UNOCCUPIED) {
            decoySpace = space->getLeft();
        } else if (space->getTop() != nullptr && space->getTop()->getOccupiedState() == UNOCCUPIED) {
            decoySpace = space->getTop();
        } else if (space->getBottom() != nullptr && space->getBottom()->getOccupiedState() == UNOCCUPIED) {
            decoySpace = space->getBottom();
        }

        if (decoySpace != nullptr) {
            setSpace(decoySpace);
            decoySpace->setElement(this);
            decoySpace->setOccupiedState(INACCESSIBLE);
            isPlaced = true;
        }
    }
}
