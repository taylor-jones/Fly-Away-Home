/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Road.cpp is the class implementation
**  file for the Road class. This file contains
**  definitions for the member functions of the Road class.
**********************************************************/

#include "Road.hpp"
#include "Element.hpp"
#include "Alien.hpp"

/**
 * @name Road
 * @brief Road class constructor
 * @param none
 * @return none
 */
Road::Road() {
    this->name = "Road";
    this->backColor = BLACK;
}



/**
 * @name ~Road
 * @brief Road class destructor
 * @param none
 * @return none
 */
Road::~Road() = default;



/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return ROAD
 */
SpaceType Road::spaceType() {
    return ROAD;
}



/**
 * @name experience
 * @brief Any Element that moves on a road moves twice as fast, so two spaces per move
 * @param experiencer - a pointer to the Element doing the experiencing
 * @return void
 */
void Road::experience(Element* experiencer) {
    Alien* alien = nullptr;
    Item* item = nullptr;
    Space* peekSpace = nullptr;


    if (experiencer != nullptr) {
        if (experiencer->getElementType() == EARTHLING) {
            // the Earthling moves @ twice the regular speed
            experiencer->move(experiencer->getOrientation());

        } else if (experiencer->getElementType() == ALIEN) {
            // the experience depends on the Alien's activeItem
            alien = dynamic_cast<Alien*>(experiencer);
            item = alien->getActiveItem();


            // If the Alien is wearing speed skates, it moves @ 3x speed and no energy is taken
            if (item != nullptr && item->getItemType() == SPEED_SKATES) {
                // between moves, check if the move lands the alien on a non-road Space, in which case
                //  that space would take over the experience (since the Alien would no longer be on a road)
                peekSpace = alien->peek(alien->getOrientation());

                if (peekSpace != nullptr) {
                    alien->move(peekSpace);

                    if (peekSpace->spaceType() != ROAD) {
                        alien->experienceSpace();
                    } else {
                        peekSpace = alien->peek(alien->getOrientation());

                        if (peekSpace != nullptr) {
                            alien->move(peekSpace);

                            if (peekSpace->spaceType() != ROAD) {
                                alien->experienceSpace();
                            }
                        }
                    }

                }

            } else {
                // Otherwise, it moves @ 2x speed & 1 energy is taken
                peekSpace = alien->peek(alien->getOrientation());

                if (peekSpace != nullptr) {
                    alien->move(peekSpace);
                }

                if (alien->getSpace()->spaceType() != ROAD) {
                    alien->experienceSpace();
                }

                alien->adjustEnergy(-1);
            }
        }
    }
}



/**
 * @name init
 * @brief initialize common ROAD variables
 * @param none
 * @return void
 */
void Road::init() {
    // no necessary initialization
}
