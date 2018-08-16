/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Water.cpp is the class implementation
**  file for the Water class. This file contains
**  definitions for the member functions of the Water class.
**********************************************************/

#include "Water.hpp"
#include "Alien.hpp"

/**
 * @name Water
 * @brief Water class constructor
 * @param none
 * @return none
 */
Water::Water() {
    this->name = "Water";
    this->backColor = BLUE;
}


/**
 * @name ~Water
 * @brief Water class destructor
 * @param none
 * @return none
 */
Water::~Water() = default;


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return WATER
 */
SpaceType Water::spaceType() {
    return WATER;
}


/**
 * @name experience
 * @brief engage the water space.
 * @details Whenever an Alien gets into the water, his energy level
 *  will decrease faster than usual (unless he's wearing an innertube).
 *  However, if he doesn't die while in the water, his energy will return
 *  to the level it was at prior to getting into the way (once he gets out).
 * @param experiencer - A pointer to an Element that experiences the water
 * @return void
 */
void Water::experience(Element* experiencer) {
    Alien* alien = nullptr;
    Item* item = nullptr;
    bool immunity = false;

    // decrease the ALIEN'S health by 1
    if (experiencer->getElementType() == ALIEN) {
        alien = dynamic_cast<Alien*>(experiencer);

        // if the Alien's previous space was NOT water, then set the energy marker
        // to reflect the Alien's energy at the time it entered the water
        if (alien->getPrevSpace() != nullptr && alien->getPrevSpace()->spaceType() != WATER) {
            alien->setEnergyMarker();
        }


        // if the Alien is using an Innertube or Icarus Wings, he's immune to the energy draining effects of the water.
        // Otherwise, the water drains the Alien's energy by 3 for each step taken.
        item = alien->getActiveItem();
        if (item != nullptr && (item->getItemType() == INNERTUBE || item->getItemType() == ICARUS_WINGS)) {
            immunity = true;
        }

        if (!immunity) {
            alien->adjustEnergy(-3);
        }
    }
}



/**
 * @brief
 */
void Water::init() {

}
