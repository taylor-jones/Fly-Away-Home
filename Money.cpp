/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Money.cpp is the class implementation
**  file for the Money class. This file contains
**  definitions for the member functions of the Money class.
**********************************************************/

#include "Money.hpp"
#include "Alien.hpp"

/**
 * @name Money
 * @brief default Money class constructor that picks a random
 *  money value from the possible list of values
 * @param none
 * @return none
 */
Money::Money() {
    int randLoc = randInt(0, moneyPossibilities.size() - 1);
    this->value = moneyPossibilities.at(randLoc);
    init();
}


/**
 * @name Money
 * @brief Money class constructor that allows for specifying the money value
 * @param none
 * @return none
 */
Money::Money(int value) {
    this->value = value;
    init();
}


/**
 * @name init
 * @brief initializes common money attributes
 * @param none
 * @return void
 */
void Money::init() {
    this->itemType = MONEY;
    this->symbol = "$";
    this->color = BLACK;
    this->backColor = INVISIBLE;
    this->name = std::to_string(this->value) + " " + pluralizeIf("buck", this->value);
}



/**
 * @name ~Money
 * @brief money class destructor
 * @param none
 * @return none
 */
Money::~Money() {}



/**
 * @name interact
 * @brief Adds the monetary value to the Player's cash
 * @param actor - the Element interacting w/ the Money
 * @return void
 */
void Money::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->pickupMoney(this);
    }
}


