/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: HomeLand.cpp is the class implementation
**  file for the HomeLand class. This file contains
**  definitions for the member functions of the HomeLand class.
**********************************************************/

#include "HomeLand.hpp"
#include "Alien.hpp"


/**
 * @name HomeLand
 * @brief HomeLand class constructor
 * @param none
 * @return none
 */
HomeLand::HomeLand() {
    this->name = "Homeland";
    this->color = BLUE;
    this->backColor = MAGENTA;
}


/**
 * @name ~HomeLand
 * @brief HomeLand class destructor
 * @param none
 * @return none
 */
HomeLand::~HomeLand() = default;


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return LAND
 */
SpaceType HomeLand::spaceType() {
    return HOME_LAND;
}



/**
 * @name experience
 * @brief engage the HomeLand. This is only done by the Alien. Whenever an Alien walks
 *  around on its HomeLand, it actually gains energy with each step rather than losing energy.
 *  @param none
 *  @return void
 */
void HomeLand::experience(Element* experiencer) {
    if (experiencer != nullptr && experiencer->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(experiencer)->adjustEnergy(1, true);
    }
}



/**
 * @name init
 * @brief needed only to fulfill virtual void function requirement
 * @param none
 * @return none
 */
void HomeLand::init() {}
