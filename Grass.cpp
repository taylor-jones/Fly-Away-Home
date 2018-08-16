/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Grass.cpp is the class implementation
**  file for the Grass class. This file contains
**  definitions for the member functions of the Grass class.
**********************************************************/

#include "Grass.hpp"
#include "Alien.hpp"


/**
 * @name Grass
 * @brief Grass class constructor
 * @param none
 * @return none
 */
Grass::Grass() {
    this->backColor = GREEN;
    this->name = "Grass";
}


/**
 * @name ~Grass
 * @brief Grass class destructor
 * @param none
 * @return none
 */
Grass::~Grass() = default;


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return GRASS
 */
SpaceType Grass::spaceType() {
    return GRASS;
}


/**
 * @brief engage the land
 */
void Grass::experience(Element* experiencer) {
    // decrease the ALIEN'S health by 1
    if (experiencer->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(experiencer)->adjustEnergy(-1);
    }
}


/**
 * @name init
 * @brief Grass space initializer function
 * @param none
 * @return void
 */
void Grass::init() {

}
