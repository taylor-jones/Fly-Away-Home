/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: IcarusWings.cpp is the class implementation
**  file for the IcarusWings class. This file contains
**  definitions for the member functions of the IcarusWings class.
**********************************************************/


#include "IcarusWings.hpp"
#include "Alien.hpp"


/**
 * @name IcarusWings
 * @brief IcarusWings class constructor
 * @param none
 * @return none
 */
IcarusWings::IcarusWings() {
    this->itemType = ICARUS_WINGS;
    this->name = "Icarus Wings";
    this->price = randInt(3, 5);
    this->lifeSpan = 30;
}


/**
 * @name ~IcarusWings
 * @brief IcarusWings class destructor
 * @param none
 * @return none
 */
IcarusWings::~IcarusWings() {}



/**
 * @name interact
 * @brief interacts w/ the icarus wings by prompting the alien to add them to its bag
 * @details Only Aliens may interact w/ icarus wings
 * @param actor - the Element interacting w/ the icarus wings
 * @return void
 */
void IcarusWings::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->checkPickupBagItem(this);
    }
}
