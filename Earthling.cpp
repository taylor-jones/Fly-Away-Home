/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Earthling.cpp is the class implementation
**  file for the Earthling class. This file contains
**  definitions for the member functions of the Earthling class.
**********************************************************/

#include "Earthling.hpp"


Earthling::Earthling() {
    this->elementType = EARTHLING;
    this->color = BLACK;
    this->backColor = WHITE;
    this->symbol = "#";
}


Earthling::~Earthling() {

}

bool Earthling::isTurnComplete() const {
    return turnComplete;
}

void Earthling::setTurnComplete(bool turnComplete) {
    this->turnComplete = turnComplete;
}


/**
 * @name move
 * @brief moves an Element to a specified Space
 * @param next - a pointer to the Space to move to
 * @return bool - true
 */
bool Earthling::move(Space* next) {
    Space* prev = space;

    if (next != nullptr && next != prev) {
        Element* element = next->getElement();

        if (next->getOccupiedState() == UNOCCUPIED) {
            space = next;
            space->setElement(this);
            space->setOccupiedState(INACCESSIBLE);
            prev->setOccupiedState(UNOCCUPIED);
            prev->setElement(nullptr);

        } else if (element != nullptr && element->getElementType() == ALIEN) {
            interact(element);
        }
    }

    return true;
}


