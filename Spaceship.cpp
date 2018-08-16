/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Spaceship.cpp is the class implementation
**  file for the Spaceship class. This file contains
**  definitions for the member functions of the Spaceship class.
**********************************************************/


#include "Spaceship.hpp"
#include "Alien.hpp"

using std::cout;
using std::endl;


Spaceship::Spaceship() {
    this->elementType = ITEM;
    this->itemType = SPACESHIP;
    this->name = "Spaceship";
    this->symbol = "☼";
    this->color = MAGENTA;
    this->backColor = GREY;
}


Spaceship::~Spaceship() {}


/**
 * @name interact
 * @brief use the spaceship to fly back home from earth
 * @details only Aliens can interact w/ the spaceship.
 * @param actor - the Element interacting w/ the spaceship
 * @return void
 */
void Spaceship::interact(Element* actor) {
    bool alreadyHome = (getSpace() == nullptr || getSpace()->spaceType() == HOME_LAND);

    if (actor != nullptr && actor->getElementType() == ALIEN) {
        if (!alreadyHome) {
            auto* alien = dynamic_cast<Alien*>(actor);

            reload();

            cout << endl << showHeading("Spaceship Found!!!", BLUE) << endl;

            if (getValidBool("Are you ready to fly home?", "Yup", "Nope")) {
                alien->flyHome(this);
            } else {
                alien->setNonBagItem(this);
            }

        } else {
            makeComment("You\'re already back home!", RED);
        }
    }
}

