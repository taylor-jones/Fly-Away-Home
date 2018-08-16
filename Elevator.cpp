/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Elevator.cpp is the class implementation
**  file for the Elevator class. This file contains
**  definitions for the member functions of the Elevator class.
**********************************************************/

#include "Elevator.hpp"
#include "Element.hpp"
#include "Island.hpp"

using std::cout;
using std::endl;
using std::to_string;



/**
 * @name Elevator
 * @brief Elevator class constructor
 * @param none
 * @return none
 */
Elevator::Elevator() {
    this->backColor = RED;
    this->name = "Elevator";
    this->symbol = "↑";
}


/**
 * @name ~Elevator
 * @brief Elevator class destructor
 * @param none
 * @return none
 */
Elevator::~Elevator() = default;



/**
 * @name init
 * @brief initialize the Elevator space
 * @param none
 * @return void
 */
void Elevator::init() {
    // create the level list according to the level that this elevator is on
    elevatorOpts = {"Stay on island " + to_string(level), "Move up to island " + to_string(level + 1)};
}


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return ELEVATOR
 */
SpaceType Elevator::spaceType() {
    return ELEVATOR;
}


/**
 * @name experience
 * @brief The alien uses the elevator to move up to the next level OR - if it's the final level
 * @param experiencer - A pointer to an Element experiencing the Elevator
 * @return void
 */
void Elevator::experience(Element* experiencer) {
    cout << endl << showHeading("You\'ve found the elevator on island " + to_string(level) + "!", BLUE) << endl;

    int choice = getValidInt(0, elevatorOpts.size() - 1, getMenu(elevatorOpts, 0, "What would you like to do?\n"));
    if (choice == 1) {
        // move the experiencer to the next island up
        experiencer->move(ABOVE);
        experiencer->getSpace()->getIsland()->print(true);
        clearScreen();
    }
}





