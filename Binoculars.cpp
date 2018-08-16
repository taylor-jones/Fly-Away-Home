/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Binoculars.cpp is the class implementation
**  file for the Binoculars class. This file contains
**  definitions for the member functions of the Binoculars class.
**********************************************************/


#include "Binoculars.hpp"
#include "Alien.hpp"


/**
 * @name Binoculars
 * @brief Binoculars class constructor
 * @param none
 * @return none
 */
Binoculars::Binoculars() {
    this->itemType = BINOCULARS;
    this->name = "Binoculars";
    this->price = randInt(2, 3);
    this->lifeSpan = 0;
}


/**
 * @name ~Binoculars
 * @brief Binoculars class destructor
 * @param none
 * @return none
 */
Binoculars::~Binoculars() {}



/**
 * @name interact
 * @brief interacts w/ the binoculars by prompting the alien to add them to its bag
 * @details Only Aliens may interact w/ binoculars
 * @param actor - the Element interacting w/ the binoculars
 * @return void
 */
void Binoculars::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->checkPickupBagItem(this);
    }
}



/**
 * @name use
 * @brief uses the binoculars by prompting the user to select which direction to clear
 * @details Only Aliens may use the binoculars
 * @param actor - the Element using the binoculars
 * @return void
 */
void Binoculars::use(Element* actor) {
    if (actor->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(actor);

        reload();
        int choice = getValidInt(1, directionOpts.size(), getMenu(directionOpts, true, "\nWhich direction would you like to reveal?\n"));
        Space* space = alien->getSpace();

        if (choice == 1) { // Up
            while (space != nullptr) {
                space->setCovered(false);

                if (space->getLeft() != nullptr) {
                    space->getLeft()->setCovered(false);
                }

                if (space->getRight() != nullptr) {
                    space->getRight()->setCovered(false);
                }

                space = space->getTop();
            }

        } else if (choice == 2) { // Down
            while (space != nullptr) {
                space->setCovered(false);

                if (space->getLeft() != nullptr) {
                    space->getLeft()->setCovered(false);
                }

                if (space->getRight() != nullptr) {
                    space->getRight()->setCovered(false);
                }

                space = space->getBottom();
            }

        } else if (choice == 3) { // Left
            while (space != nullptr) {
                space->setCovered(false);

                if (space->getTop() != nullptr) {
                    space->getTop()->setCovered(false);
                }

                if (space->getBottom() != nullptr) {
                    space->getBottom()->setCovered(false);
                }

                space = space->getLeft();
            }

        } else if (choice == 4) { // Right
            while (space != nullptr) {
                space->setCovered(false);

                if (space->getTop() != nullptr) {
                    space->getTop()->setCovered(false);
                }

                if (space->getBottom() != nullptr) {
                    space->getBottom()->setCovered(false);
                }

                space = space->getRight();
            }
        }
    }
}
