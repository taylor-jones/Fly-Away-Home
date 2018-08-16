/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: SpeedSkates.cpp is the class implementation
**  file for the SpeedSkates class. This file contains
**  definitions for the member functions of the SpeedSkates class.
**********************************************************/


#include "SpeedSkates.hpp"
#include "Alien.hpp"


/**
 * @name SpeedSkates
 * @brief SpeedSkates class constructor
 * @param none
 * @return none
 */
SpeedSkates::SpeedSkates() {
    this->itemType = SPEED_SKATES;
    this->name = "Speed Skates";
    this->price = randInt(1, 3);
}



/**
 * @name ~SpeedSkates
 * @brief SpeedSkates class destructor
 * @param none
 * @return none
 */
SpeedSkates::~SpeedSkates() {}



/**
 * @name interact
 * @brief interacts w/ the speed skates by prompting the alien to add them to its bag
 * @details Only Aliens may interact w/ speed skates
 * @param actor - the Element interacting w/ the speed skates
 * @return void
 */
void SpeedSkates::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->checkPickupBagItem(this);
    }
}
