/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Sand.cpp is the class implementation
**  file for the Sand class. This file contains
**  definitions for the member functions of the Sand class.
**********************************************************/

#include "Sand.hpp"
#include "Element.hpp"
#include "Alien.hpp"

/**
 * @name Sand
 * @brief Sand class constructor
 * @param none
 * @return none
 */
Sand::Sand() {
    this->name = "Sand";
    this->backColor = YELLOW;
}


/**
 * @name ~Sand
 * @brief Sand class destructor
 * @param none
 * @return none
 */
Sand::~Sand() = default;


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return SAND
 */
SpaceType Sand::spaceType() {
    return SAND;
}


/**
 * @name experience
 * @brief while experiencing Sand, there's a 1/3 chance that the experiencer
 *  is not able to move
 * @param experiencer - a pointer to the Element experiencing the sand
 * @return void
 */
void Sand::experience(Element* experiencer) {
    if (experiencer != nullptr && experiencer->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(experiencer);

        if (randInt(1, 2) == 2) {
            alien->move(alien->getPrevSpace());
            alien->experienceSpace();
        }
        alien->adjustEnergy(-1);
    }
}



/**
 * @name init
 * @brief Sand class initializer (not needed)
 * @param none
 * @return void
 */
void Sand::init() {}
