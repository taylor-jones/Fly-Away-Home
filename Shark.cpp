/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Shark.cpp is the class implementation
**  file for the Shark class. This file contains
**  definitions for the member functions of the Shark class.
**********************************************************/

#include <algorithm>
#include <queue>
#include "Shark.hpp"


/**
 * @name Shark
 * @brief Shark class constructor
 * @param none
 * @return none
 */
Shark::Shark() {
    this->symbol = "^";
    this->earthlingType = SHARK;
    this->name = "Shark";
    this->color = GREY;
    this->backColor = BLUE;
}


/**
 * @name init
 * @brief shark initialization function that sets the player points and all the reachable
 *  shark waters
 * @param player - A pointer to the player (Alien)
 * @return void
 */
void Shark::init(Alien* player) {
    this->player = player;

    // add to the sharkWater vector all the spaces that are part of the water that the shark is in.
    setReachableWaters();
}




/**
 * @name ~Shark
 * @brief Shark class destructor
 * @param none
 * @return none
 */
Shark::~Shark() {

}



/**
 * @brief interacts with the shark
 * @param actor - the Element interacting w/ the shark
 * @note only Aliens can interact w/ the shark
 * @return void
 */
void Shark::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(actor);

        // make sure the Alien isn't wearing icarus wings, which would negate the interaction
        Item* active = alien->getActiveItem();
        if (active == nullptr || active->getItemType() != ICARUS_WINGS) {
            alien->getBittenByShark();
        }
    }
}



/**
 * @name move
 * @brief moves the shark
 * @param (not implemented here, expects nullptr)
 * @return bool - true
 */
bool Shark::move() {
    Space* prevSpace = space;
    Space* playerSpace = player->getSpace();
    Item* playerItem = player->getActiveItem();

    Space* top = space->getTop();
    Space* bottom = space->getBottom();
    Space* left = space->getLeft();
    Space* right = space->getRight();

    Element* tracer = nullptr;
    Element* target = player;

    // if the alien is in the water but has the icarus wings, the shark should not detect the alien,
    //  because the alien would be technically flying above the water.
    if (inSharkWater(playerSpace) && (playerItem == nullptr || playerItem->getItemType() != ICARUS_WINGS)) {
        for (auto &water: sharkWater) {
            tracer = water->getElement();

            if (tracer != nullptr && tracer->getElementType() == ITEM) {
                if (dynamic_cast<Item*>(tracer)->getItemType() == DECOY) {
                    target = tracer;
                }
            }
        }


        moveTowardElement(target);

        bool doStrike = false;

        top = space->getTop();
        bottom = space->getBottom();
        left = space->getLeft();
        right = space->getRight();

        // if the player is right next to the shark, then interact w/ the player
        if (top != nullptr && inSharkWater(top) && top == playerSpace) {
            orientation = UP;
            doStrike = true;
        } else if (bottom != nullptr && inSharkWater(top) && bottom == playerSpace) {
            orientation = DOWN;
            doStrike = true;
        } else if (left != nullptr && inSharkWater(top) && left == playerSpace) {
            orientation = LEFT;
            doStrike = true;
        } else if (right != nullptr && inSharkWater(top) && right == playerSpace) {
            orientation = RIGHT;
            doStrike = true;
        }

        if (doStrike && orientation != player->getOrientation()) {
            interact(player);
        }


    } else {
        // if the Alien isn't in the water, the shark just moves randomly & lazily around
        if (randInt(1, 3) > 2) {
            int moveDir = randInt(1,4);

            if (moveDir == 1 && inSharkWater(top) && top->getOccupiedState() == UNOCCUPIED) {
                space = space->getTop();
            } else if (moveDir == 2 && inSharkWater(bottom) && bottom->getOccupiedState() == UNOCCUPIED) {
                space = space->getBottom();
            } else if (moveDir == 3 && inSharkWater(left) && left->getOccupiedState() == UNOCCUPIED) {
                space = space->getLeft();
            } else if (moveDir == 4 && inSharkWater(right) && right->getOccupiedState() == UNOCCUPIED) {
                space = space->getRight();
            }

            if (space != prevSpace) {
                space->setElement(this);
                space->setOccupiedState(INACCESSIBLE);
                prevSpace->setOccupiedState(UNOCCUPIED);
                prevSpace->setElement(nullptr);
            }
        }
    }

    return true;
}



/**
 * @name setReachableWaters
 * @brief populates the sharkWater vector with pointers to all the water spaces that are reachable from this shark
 * @param none
 * @return void
 */
void Shark::setReachableWaters() {
    Space* w = nullptr;
    std::queue<Space*>waters;

    waters.push(space);

    while (!waters.empty()) {
        w = waters.front();

        // add the water space to the sharkWaters
        sharkWater.push_back(w);

        Space* top = w->getTop();
        Space* bottom = w->getBottom();
        Space* left = w->getLeft();
        Space* right = w->getRight();

        // add any adjacent WATER spaces to the queue
        if (top != nullptr && top->spaceType() == WATER && !inSharkWater(top)) {
            waters.push(top);
        }

        if (bottom != nullptr && bottom->spaceType() == WATER && !inSharkWater(bottom)) {
            waters.push(bottom);
        }

        if (left != nullptr && left->spaceType() == WATER && !inSharkWater(left)) {
            waters.push(left);
        }

        if (right != nullptr && right->spaceType() == WATER && !inSharkWater(right)) {
            waters.push(right);
        }

        waters.pop();
    }
}



/**
 * @name inSharkWater
 * @brief checks if a specified space is already in the shark waters
 * @param checkSpace - a pointer to the space to check on
 * @return bool - true if it's already included, false if not
 */
bool Shark::inSharkWater(Space* checkSpace) {
    if (checkSpace == nullptr) {
        return false;
    }

    return (std::find(sharkWater.begin(), sharkWater.end(), checkSpace) != sharkWater.end());
}




/**
 * @name move
 * @brief call the parent Element move
 * @param space - a pointer to the Space to move to
 * @return bool - true
 */
bool Shark::move(Space* space) {
    return Element::move(space);
}



/**
 * @name moveTowardElement
 * @brief moves the shark toward a decoy item
 * @param actor - a pointer to a Decoy Element
 * @return void
 */
void Shark::moveTowardElement(Element* actor) {
    if (actor != nullptr) {
        if (actor->getSpace() != nullptr) {
            Coordinates actorLoc = actor->getSpace()->getLocation();
            Space* next = nullptr;

            int actorX = actorLoc.x;
            int actorY = actorLoc.y;

            int sharkX = space->getLocation().x;
            int sharkY = space->getLocation().y;

            Space* top = space->getTop();
            Space* bottom = space->getBottom();
            Space* left = space->getLeft();
            Space* right = space->getRight();

            std::vector<Space*>moveOrder;
            bool moveFound = false;

            // make a move in the direction of the player's location
            if (actorX < sharkX) {
                if (actorY < sharkY) { // nw
                    if (randInt(1, 2) == 1) {
                        moveOrder = { left, top, right, bottom };
                    } else {
                        moveOrder = { top, left, right, bottom };
                    }
                } else if (actorY > sharkY) { // ne
                    if (randInt(1, 2) == 1) {
                        moveOrder = { right, top, left, bottom };
                    } else {
                        moveOrder = { top, right, left, bottom };
                    }
                } else if (actorY == sharkY) { // n
                    moveOrder = { top, left, right, bottom };
                }

            } else if (actorX > sharkX) {
                if (actorY < sharkY) { // sw
                    if (randInt(1, 2) == 1) {
                        moveOrder = { left, bottom, right, top};
                    } else {
                        moveOrder = { bottom, left, right, top};
                    }
                } else if (actorY > sharkY) { // se
                    if (randInt(1, 2) == 1) {
                        moveOrder = { right, bottom, left, top};
                    } else {
                        moveOrder = { bottom, right, left, top};
                    }
                } else if (actorY == sharkY) { // s
                    moveOrder = { bottom, left, right, top};
                }
            } else if (actorX == sharkX) {
                if (actorY < sharkY) { // w
                    if (randInt(1, 2) == 1) {
                        moveOrder = { left, top, bottom, right};
                    } else {
                        moveOrder = { left, bottom, top, right};
                    }
                } else if (actorY > sharkY) { // e
                    if (randInt(1, 2) == 1) {
                        moveOrder = { right, top, bottom, left};
                    } else {
                        moveOrder = { right, bottom, top, left};
                    }
                }
            }


            int i = 0;

            while (i < static_cast<int>(moveOrder.size()) && !moveFound) {
                if (moveOrder[i] != nullptr && inSharkWater(moveOrder[i])) {
                    moveFound = true;
                    next = moveOrder[i];
                } else {
                    i += 1;
                }
            }

            if (next != nullptr) {
                move(next);
            }
        }
    }
}



