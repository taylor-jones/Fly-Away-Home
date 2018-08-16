/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Innertube.cpp is the class implementation
**  file for the Innertube class. This file contains
**  definitions for the member functions of the Innertube class.
**********************************************************/


#include "Innertube.hpp"
#include "Alien.hpp"


/**
 * @name Innertube
 * @brief Innertube class destructor
 * @param none
 * @return none
 */
Innertube::Innertube() {
    this->itemType = INNERTUBE;
    this->name = "Innertube";
    this->price = randInt(1, 3);
}



/**
 * @name ~Innertube
 * @brief Innertube class destructor
 * @param none
 * @return none
 */
Innertube::~Innertube() {}



/**
 * @name interact
 * @brief interacts w/ the innertube by prompting the alien to add them to its bag
 * @details Only Aliens may interact w/ innertube
 * @param actor - the Element interacting w/ the innertube
 * @return void
 */
void Innertube::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->checkPickupBagItem(this);
    }
}
