/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Food.cpp is the class implementation
**  file for the Food class. This file contains
**  definitions for the member functions of the Food class.
**********************************************************/

#include "Food.hpp"
#include "Alien.hpp"

/**
 * @name Food
 * @brief Food class constructor that generates a random food type
 * @param none
 * @return none
 */
Food::Food() {
    int randLoc = randInt(0, foodPossibilities.size() - 1);
    std::vector<string>match = foodPossibilities.at(randLoc);
    this->name = match[0];
    this->value = stoi(match[1]);
    init();
}


/**
 * @name Food
 * @brief default Food class constructor
 * @param none
 * @return none
 */
Food::Food(int value, string name) {
    this->value = value;
    this->name = name;
    init();
}


/**
 * @name init
 * @brief initializes common Food values
 * @param none
 * @return void
 */
void Food::init() {
    this->itemType = FOOD;
    this->symbol = "=";
    this->color = BLACK;
    this->backColor = INVISIBLE;
    this->price = randInt(1, 5);
}


/**
 * @name ~Food
 * @brief Food class destructor
 * @param none
 * @return none
 */
Food::~Food() {}



/**
 * @name interact
 * @brief Modifies the Alien's health based on the food they ate
 * @param actor - the Element interacting w/ the Food
 * @return void
 */
void Food::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        dynamic_cast<Alien*>(actor)->eatFood(this);
    }
}


