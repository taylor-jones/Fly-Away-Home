/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Wizard.cpp is the class implementation
**  file for the Wizard class. This file contains
**  definitions for the member functions of the Wizard class.
**********************************************************/

#include "Wizard.hpp"
#include "Alien.hpp"


/**
 * @name Wizard
 * @brief Wizard class constructor
 * @param none
 * @return none
 */
Wizard::Wizard() {
    this->symbol = "W";
    this->earthlingType = WIZARD;
    this->name = "Wizard";

    if (randInt(1, 2) == 1) {
        this->orientation = LEFT;
    } else {
        this->orientation = RIGHT;
    }
}



/**
 * @name ~Wizard
 * @brief Wizard class destructor
 * @param none
 * @return none
 */
Wizard::~Wizard() {}



/**
 * @brief interacts with the wizard
 * @param actor - the Element interacting w/ the wizard
 * @note only Aliens can interact w/ the wizard
 * @return void
 */
void Wizard::interact(Element* actor) {
    // if you pay the wizard $1, he'll recharge your energy back to it's max.
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        interactionCount += 1;

        auto* alien = dynamic_cast<Alien*>(actor);
        string comment;

        makeComment(showHeading("Wizard", BLUE), false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);

        if (interactionCount == 1) {
            comment = "You have come to the right place dear traveler. No matter your condition,";
        } else {
            comment = "Back for more, eh? That\'s great, but you should know that I charge";
            comment += "\na little bit more each time. Energy doesn\'t grow on trees you know!";
        }


        comment += "\nI will restore your energy to full strength for only $" + std::to_string(interactionCount);

        makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

        if (alien->checkRestoreEnergy(interactionCount)) {
            makeComment("Bless you my child. Safe travels, now!", BLUE);
        } else {
            makeComment("Suit yourself. I\'ll be around if you need me.");
        }
    }
}



/**
 * @name move
 * @brief moves the wizard
 * @return bool - true
 */
bool Wizard::move() {
    // the wizard only moves horizontally.
    Space* prev = space;
    Space* next = space->getDirection(orientation);

    if (next != nullptr && next->getOccupiedState() == UNOCCUPIED) {
        space = next;
        space->setElement(this);
        space->setOccupiedState(INACCESSIBLE);
        prev->setOccupiedState(UNOCCUPIED);
        prev->setElement(nullptr);
    } else {
        flipOrientation();
    }

    return true;
}


/**
 * @name flipOrientation
 * @brief flips the Wizards orientation to face the opposite direction
 * @param none
 * @return void
 */
void Wizard::flipOrientation() {
    if (orientation == LEFT) {
        orientation = RIGHT;
    } else if (orientation == RIGHT) {
        orientation = LEFT;
    }
}
