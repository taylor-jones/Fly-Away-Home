/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: OuterSpace.cpp is the class implementation
**  file for the OuterSpace class. This file contains
**  definitions for the member functions of the OuterSpace class.
**********************************************************/

#include "OuterSpace.hpp"
#include "Element.hpp"
#include "Alien.hpp"


/**
 * @name OuterSpace
 * @brief OuterSpace class constructor
 * @param none
 * @return none
 */
OuterSpace::OuterSpace() {
    this->name = "Outer Space";
    this->backColor = DEFAULT_COLOR;
    this->color = BLACK;
}


/**
 * @name ~OuterSpace
 * @brief OuterSpace class destructor
 * @param none
 * @return none
 */
OuterSpace::~OuterSpace() = default;


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return OUTER_SPACE
 */
SpaceType OuterSpace::spaceType() {
    return OUTER_SPACE;
}


/**
 * @name experience
 * @brief Unless an Alien has an ActiveItem that will allow it
 *  to suspend in outer space, it will drop to the Island below
 * @param none
 * @return void
 */
void OuterSpace::experience(Element* experiencer) {
    Alien* alien = nullptr;
    bool immunity = false;
    string message;

    if (experiencer->getElementType() == ALIEN) {
        alien = dynamic_cast<Alien*>(experiencer);

        if (alien->getActiveItem() != nullptr && alien->getActiveItem()->getItemType() == ICARUS_WINGS) {
            immunity = true;
        }

        if (!immunity) {
            // move to alien to the island below
            alien->move(BELOW);

            // ...and since falling hurts, drop the alien's energy by 50 pts
            alien->adjustEnergy(-25);

            message = inColor("\nOh no!", RED) + " You fell off the edge of Island " + std::to_string(level);
            message += " (" + inColor("-25 energy", RED) + ")\n";
            message += "\nPress [Enter] to continue...";

            alien->makeComment(inColor(message), true);

        }
    }
}


/**
 * @brief
 */
void OuterSpace::init() {

}
