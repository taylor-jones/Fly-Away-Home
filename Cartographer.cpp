/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Cartographer.cpp is the class implementation
**  file for the Cartographer class. This file contains
**  definitions for the member functions of the Cartographer class.
**********************************************************/

#include <algorithm>
#include "Cartographer.hpp"
#include "Island.hpp"
#include "Alien.hpp"

using std::min;
using std::to_string;
using std::cout;
using std::endl;


/**
 * @name Cartographer
 * @brief Cartographer class constructor
 * @param none
 * @return none
 */
Cartographer::Cartographer() {
    this->symbol = "C";
    this->earthlingType = CARTOGRAPHER;
    this->name = "Cartographer";

    if (randInt(1, 2) == 1) {
        this->orientation = LEFT;
    } else {
        this->orientation = RIGHT;
    }
}


/**
 * @name ~Cartographer
 * @brief Cartographer class destructor
 * @param none
 * @return none
 */
Cartographer::~Cartographer() {

}



/**
 * @brief interacts with the cartographer
 * @param actor - the Element interacting w/ the cartographer
 * @note only Aliens can interact w/ the cartographer
 * @return void
 */
void Cartographer::interact(Element* actor) {
    // cartographer will uncover the entire island for you.
    // However, there's a 50/50 chance the cartographer will charge you $20 for his map.
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(actor);
        int revealCharge = 0;
        string comment;

        // The cartographer will charge to reveal the spaces
        Island* curr = getSpace()->getIsland();
        Size size = curr->getSize();
        int totalSpaces = size.x * size.y;
        int coveredSpaces = 0;
        double coveredRatio = 0;

        for (int x = 0; x < size.x; x++) {
            for (int y = 0; y < size.y; y++) {
                if (curr->getSpace(x, y)->getCovered()) {
                    coveredSpaces += 1;
                }
            }
        }

        coveredRatio = (static_cast<double>(coveredSpaces) / totalSpaces);


        // There's a 50/50 chance cartographer will try to charge based on the amount of covered spaces.
        if (randInt(1, 2) == 1) {
            // for every 5% of covered land, the cartographer charges $1.
            revealCharge = static_cast<int>(coveredRatio * 20);
        }


         makeComment(showHeading("Cartographer", BLUE), false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);


        // Determine the cartographers comments

        if (interactionCount == 0) {
            comment = "Oh, uh. Hi, I didn\'t see you there. You see I\'m always busy exploring the new world!";
        } else {
            comment += "Oh you again? Still wandering around this island, huh?";
        }

        if (coveredRatio != 0) {
            comment += "\nY\'know, I can share my maps with you. It might make your travels a lot easier.";

            if (revealCharge > 0) {
                comment += "\nBut it\'s gonna cost you. For $" + to_string(revealCharge) + " bucks I\'ll uncover the entire island.";
            } else {
                comment += "\nIn fact, I\'m feeling generous. Go ahead and use my maps to uncover the entire island.";
            }
        } else {
            comment += "\nBut it doesn\'t look like you need my help. Nice work!";
        }


        makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

        if (coveredRatio > 0) {
            if (alien->checkBuyMaps(revealCharge)) {
                comment = "Wonderful! Good luck with making it home!";
            } else {
                comment = "Alright, then. Maybe I\'ll see ya around.";
            }

            makeComment(comment, true, BLUE);
        }


        interactionCount += 1;
    }
}



/**
 * @name move
 * @brief moves the cartographer
 * @details once the cartographer makes it to an edge position, he will move clockwise
 * @param (not implemented here, expects nullptr)
 * @return bool - true
 */
bool Cartographer::move() {
    // The cartographer will typically hang out at the edges of the island, trying to discover new land,
    //  but occasionally, his path gets interrupted and he will change course and head towards a different edge.

    Space* prev = space;
    Space* next = nullptr;
    Direction prevOrientation = orientation;
    bool stayPut = false;

    if (orientation == UP) {
        if (canMap(LEFT)) {
            orientation = LEFT;
        } else if (canMap(UP)) {
            orientation = UP;
        } else if (canMap(RIGHT)) {
            orientation = RIGHT;
        } else if (canMap(DOWN)) {
            orientation = DOWN;
        } else {
            stayPut = true;
        }
    } else if (orientation == RIGHT) {
        if (canMap(UP)) {
            orientation = UP;
        } else if (canMap(RIGHT)) {
            orientation = RIGHT;
        } else if (canMap(DOWN)) {
            orientation = DOWN;
        } else if (canMap(LEFT)) {
            orientation = LEFT;
        } else {
            stayPut = true;
        }
    } else if (orientation == DOWN) {
        if (canMap(RIGHT)) {
            orientation = RIGHT;
        } else if (canMap(DOWN)) {
            orientation = DOWN;
        } else if (canMap(LEFT)) {
            orientation = LEFT;
        } else if (canMap(UP)) {
            orientation = UP;
        } else {
            stayPut = true;
        }
    } else if (orientation == LEFT) {
        if (canMap(DOWN)) {
            orientation = DOWN;
        } else if (canMap(LEFT)) {
            orientation = LEFT;
        } else if (canMap(UP)) {
            orientation = UP;
        } else if (canMap(RIGHT)) {
            orientation = RIGHT;
        } else {
            stayPut = true;
        }
    } else {
        // there's no current orientation
        orientation = LEFT;
        move();
    }


    if (canMap(orientation) && !stayPut) {
        next = space->getDirection(orientation);
        space = next;
        space->setElement(this);
        space->setOccupiedState(INACCESSIBLE);
        prev->setOccupiedState(UNOCCUPIED);
        prev->setElement(nullptr);

        if (canMap(orientation)) {
            orientation = prevOrientation;
        }
    }

    return true;
}



/**
 * @brief checks whether the Space in a particular direction relative to the cartographer is available for mapping
 * @details the cartographer can map any spaceType except the following:
 *  - MAILBOX, ELEVATOR, OUTER_SPACE, HOME_LAND
 * @param direction - the direction to check
 * @return
 */
bool Cartographer::canMap(Direction direction) {
    bool mappable = true;

    if (space != nullptr) {
        Space* peekSpace = space->getDirection(direction);

        if (peekSpace != nullptr) {
            SpaceType spaceType = peekSpace->spaceType();

            if (spaceType == MAILBOX || spaceType == ELEVATOR || spaceType == OUTER_SPACE || spaceType == HOME_LAND) {
                mappable = false;
            } else if (peekSpace->getOccupiedState() != UNOCCUPIED) {
                mappable = false;
            }

        } else {
            mappable = false;
        }

    } else {
        mappable = false;
    }

    return mappable;
}


