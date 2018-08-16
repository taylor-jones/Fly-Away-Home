/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Alien.cpp is the class implementation
**  file for the Alien class. This file contains
**  definitions for the member functions of the Alien class.
**********************************************************/

#include <iomanip>
#include <climits>
#include "Alien.hpp"
#include "Game.hpp"


using std::cout;
using std::endl;
using std::to_string;



/**
 * @name Alien
 * @brief default Alien class constructor
 * @param none
 * @return none
 */
Alien::Alien() {
    init();
}


/**
 * @name Alien
 * @brief Alien constructor that allows for specifying the homeLevel
 * @param homeLevel - the level that indicates winning the game
 * @return none
 */
Alien::Alien(int homeLevel) {
    this->homeLevel = homeLevel;
    init();
}


/**
 * @name init
 * @brief Alien class initialization function that sets the common object properties
 * @param none
 * @return void
 */
void Alien::init() {
    this->livesRemaining = 3;
    this->energy = 100;
    this->name = "ToeJam";
    this->elementType = ALIEN;
    this->color = MAGENTA;
    this->backColor = BLACK;
    this->symbol = "@";
    this->canMoveOverAccessibleSpaces = true;
    this->bag = new Bag(5);
    this->shipPieces = new Bag(6);


    menuOpts = { "<<< Resume Game", "Use Item", "Drop Item", "Check Ship Status" };
}



/**
 * @name ~Alien
 * @brief Alien class destructor
 * @param none
 * @return none
 */
Alien::~Alien() {
    delete bag;
}

/**
 * @name getCash
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getCash() const {
    return cash;
}

/**
 * @name setCash
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setCash(int cash) {
    this->cash = cash;
}

/**
 * @name getPoints
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getPoints() const {
    return points;
}

/**
 * @name setPoints
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setPoints(int points) {
    this->points = points;
}

/**
 * @name getRank
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getRank() const {
    return rank;
}

/**
 * @name setRank
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setRank(int rank) {
    this->rank = rank;
}

/**
 * @name getRankName
 * @brief getter
 * @param none
 * @return string
 */
const string &Alien::getRankName() const {
    return rankName;
}

/**
 * @name setRankName
 * @brief setter
 * @param string
 * @return void
 */
void Alien::setRankName(const string &rankName) {
    this->rankName = rankName;
}

/**
 * @name getBag
 * @brief getter
 * @param none
 * @return Bag*
 */
Bag* Alien::getBag() const {
    return bag;
}

/**
 * @name setBag
 * @brief setter
 * @param Bag*
 * @return void
 */
void Alien::setBag(Bag* bag) {
    this->bag = bag;
}

/**
 * @name getEnergy
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getEnergy() const {
    return energy;
}

/**
 * @name setEnergy
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setEnergy(int energy) {
    this->energy = energy;
}

/**
 * @name getLivesRemaining
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getLivesRemaining() const {
    return livesRemaining;
}

/**
 * @name setLivesRemaining
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setLivesRemaining(int livesRemaining) {
    this->livesRemaining = livesRemaining;
}

/**
 * @name getHomeLevel
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getHomeLevel() const {
    return homeLevel;
}

/**
 * @name setHomeLevel
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setHomeLevel(int homeLevel) {
    this->homeLevel = homeLevel;
}

/**
 * @name getActiveItem
 * @brief getter
 * @param none
 * @return Item*
 */
Item* Alien::getActiveItem() const {
    return activeItem;
}

/**
 * @name setActiveItem
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setActiveItem(Item* activeItem) {
    this->activeItem = activeItem;
}

/**
 * @name getEnergyMarker
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getEnergyMarker() const {
    return energyMarker;
}

/**
 * @name setEnergyMarker
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setEnergyMarker() {
    this->energyMarker = energy;
}

/**
 * @name getPrevSpace
 * @brief getter
 * @param none
 * @return Space*
 */
Space* Alien::getPrevSpace() const {
    return prevSpace;
}

/**
 * @name setPrevSpace
 * @brief setter
 * @param Space*
 * @return void
 */
void Alien::setPrevSpace(Space* prevSpace) {
    if (prevSpace != nullptr) {
        this->prevSpace = prevSpace;
    }
}

/**
 * @name getHomeland
 * @brief getter
 * @param none
 * @return Island*
 */
Island* Alien::getHomeland() const {
    return homeland;
}

/**
 * @name setHomeland
 * @brief setter
 * @param Island*
 * @return void
 */
void Alien::setHomeland(Island* homeland) {
    this->homeland = homeland;
}

/**
 * @name getNonBagItem
 * @brief getter
 * @param none
 * @return Item*
 */
Item* Alien::getNonBagItem() const {
    return nonBagItem;
}

/**
 * @name setNonBagItem
 * @brief setter
 * @param Item* nonBagItem
 * @return void
 */
void Alien::setNonBagItem(Item* nonBagItem) {
    this->nonBagItem = nonBagItem;
}

/**
 * @name getActiveItemStepsRemaining
 * @brief getter
 * @param none
 * @return int
 */
int Alien::getActiveItemStepsRemaining() const {
    return activeItemStepsRemaining;
}


/**
 * @name setActiveItemStepsRemaining
 * @brief setter
 * @param int
 * @return void
 */
void Alien::setActiveItemStepsRemaining(int activeItemStepsRemaining) {
    this->activeItemStepsRemaining = activeItemStepsRemaining;
}



/**
 * @name getShipPieces
 * @brief gets a pointer to the Alien's ship piece bag
 * @param none
 * @return void
 */
Bag* Alien::getShipPieces() const {
    return shipPieces;
}



/**
 * @name adjustPoints
 * @brief setter function to update the Alien's amount of points
 * @param amount - the amount of points to change by
 * @return void
 */
void Alien::adjustPoints(int amount) {
    points = std::max(0, points + amount);

    // check if the Alien's rank has changed based on the points
    switch(rank) {
        case 1:
            if (points >= 40) {
                rank = 2;
                rankName = "Dufus";
                points -= 40;
                maxEnergy += 10;
            }
            break;
        case 2:
            if (points >= 100) {
                rank = 3;
                rankName = "Poindexter";
                points -= 100;
                livesRemaining += 1;
                maxEnergy += 10;
            }
            break;
        case 3:
            if (points >= 180) {
                rank = 4;
                rankName = "Peanut";
                points -= 180;
                maxEnergy += 10;
            }
            break;
        case 4:
            if (points >= 280) {
                rank = 5;
                rankName = "Dude";
                points -= 280;
                maxEnergy += 10;
            }
            break;
        case 5:
            if (points >= 400) {
                rank = 6;
                rankName = "Bro";
                points -= 400;
                livesRemaining += 1;
                maxEnergy += 10;
            }
            break;
        case 6:
            if (points >= 540) {
                rank = 7;
                rankName = "Homey";
                points -= 540;
                maxEnergy += 10;
            }
            break;
        case 7:
            if (points >= 700) {
                rank = 8;
                rankName = "Rap Master";
                points -= 700;
                maxEnergy += 10;
            }
            break;
        case 8:
            if (points >= 880) {
                rank = 9;
                rankName = "Funk Lord";
                points -= 880;
                livesRemaining += 1;
                maxEnergy += 10;
            }
            break;
        default:
            rankName = "Wiener";
            rank = 1;
    }

}


/**
 * @name adjustCash
 * @brief setter function to update the Alien's amount of cash
 * @param amount - the amount of cash to change by
 * @return void
 */
void Alien::adjustCash(int amount) {
    cash = std::max(0, cash + amount);

    if (amount < 0) {
        cout << "Bummer" << endl;
    } else if (amount < 5) {
        cout << "Every penny helps" << endl;
    } else if (amount < 10) {
        cout << "Alright!" << endl;
    } else if (amount < 25) {
        cout << "I could get used to this!" << endl;
    } else {
        cout << "Happy Birthday to me!" << endl;
    }
}


/**
 * @adjustEnergy
 * @brief adjusts the Alien's energy level by a specified amount
 * @param amount - the level to adjust by
 * @bypassMax - boolean indicator as to whether the Alien's energy level should be
 *  allowed to go above the max level
 */
void Alien::adjustEnergy(int amount, bool bypassMax) {
    // make sure the amount doesn't go above the INT_MAX or below the INT_MIN
    long pendingEnergy = energy + amount;

    if (pendingEnergy > 0) {
        if (pendingEnergy > INT_MAX) {
            energy = INT_MAX;
        } else {
            energy = static_cast<int>(pendingEnergy);
        }
    } else if (livesRemaining > 0) {
        livesRemaining -= 1;
        energy = maxEnergy;
        energyMarker = energy;
    } else {
        energy = static_cast<int>(pendingEnergy);
    }

    // this only gets bypassed on the last level where the Alien gets to roan around and his
    //  energy just continues to rise from being back in his homeland.
    if (!bypassMax) {
        energy = std::min(energy, maxEnergy);
    }
}



/**
 * @name interact
 * @brief
 * @param none
 * @return void
 */
void Alien::interact(Element* actor) {
    cout << "interacting w/ alien" << endl;
}




/**
 * @name move
 * @brief moves an Alien to a specified Space and uncovers that space
 * @param next - a pointer to the Space to move to
 * @return bool - maybe change this to void?
 */
bool Alien::move(Space* next) {
    Space* prev = space;
    prevSpace = prev;

    if (next != nullptr && next->getOccupiedState() != INACCESSIBLE && next != prev) {
        prev->setOccupiedState(UNOCCUPIED);
        prev->setElement(nullptr);

        space = next;
        space->setElement(this);
        space->setOccupiedState(INACCESSIBLE);

        uncoverAdjacentSpaces();
    }

    orientation = NO_DIRECTION;

    depleteActiveItem();
    checkRestoreEnergy();
    checkIfBackHome();

    return true;
}





/**
 * @name move
 * @brief moves an Alien in a specified Direction and uncovers that space
 * @param next - a pointer to the Space to move to
 * @return bool - maybe change this to void?
 */
bool Alien::move(Direction direction) {
    Space* next = space->getDirection(direction);
    Space* prev = space;

    bool makeMove = false;

    if (next != nullptr && next != prev) {
        Element* element = next->getElement();
        ElementType elemType = NO_ELEMENT_TYPE;
        OccupiedState occupiedState = next->getOccupiedState();

        if (element != nullptr) {
            elemType = element->getElementType();
        }

        if (elemType == EARTHLING) {
            // don't move, but interact w/ the element
            element->interact(this);

        } else if (occupiedState == INACCESSIBLE) {
            // don't move, but experience the space
            next->experience(this);

        } else if (occupiedState == ACCESSIBLE) {
            // interact w/ the element then move to the space
            if (element != nullptr) {
                element->interact(this);
            }

            makeMove = true;

            if (elemType == ITEM) {
                if (dynamic_cast<Item*>(element)->getItemType() == SPACESHIP) {
                    makeMove = false;
                }
            }

        } else if (occupiedState == UNOCCUPIED) {
            // move
            makeMove = true;
        }




        // if a move should be made, handle all the steps involved
        if (makeMove) {
            prevSpace = prev;
            space = next;
            space->setOccupiedState(INACCESSIBLE);
            space->setElement(this);

            if (nonBagItem != nullptr) {
                prev->setOccupiedState(ACCESSIBLE);
                prev->setElement(nonBagItem);
                nonBagItem = nullptr;
            } else {
                prev->setOccupiedState(UNOCCUPIED);
                prev->setElement(nullptr);
            }

            uncoverAdjacentSpaces();
        }
    }


    orientation = direction;
    depleteActiveItem();
    checkRestoreEnergy();

    reload();

    checkForwardExperiences();
    checkIfBackHome();

    return true;
}




/**
 * @name uncoverAdjacentSpaces
 * @brief uncover the space that the Alien is on as well as all the adjacent spaces
 * @param none
 * @return void
 */
void Alien::uncoverAdjacentSpaces() {
    space->setCovered(false);

    if (space->getTop() != nullptr) {
        space->getTop()->setCovered(false);

        if (space->getTop()->getLeft() != nullptr) {
            space->getTop()->getLeft()->setCovered(false);
        }

        if (space->getTop()->getRight() != nullptr) {
            space->getTop()->getRight()->setCovered(false);
        }
    }

    if (space->getBottom() != nullptr) {
        space->getBottom()->setCovered(false);

        if (space->getBottom()->getLeft() != nullptr) {
            space->getBottom()->getLeft()->setCovered(false);
        }

        if (space->getBottom()->getRight() != nullptr) {
            space->getBottom()->getRight()->setCovered(false);
        }
    }

    if (space->getLeft() != nullptr) {
        space->getLeft()->setCovered(false);
    }

    if (space->getRight() != nullptr) {
        space->getRight()->setCovered(false);
    }
}



/**
 * @name experienceSpace
 * @brief experience a Space in a specified direction (relative to the Alien)
 *  or if no direction is specified, engage the Alien's current space.
 * @param direction - the relative direction in which to engage a Space
 * @return void
 */
void Alien::experienceSpace(Direction direction) {
    if (peek(direction) != nullptr) {
        peek(direction)->experience(this);
    }
}



/**
 * @name interactWithElements
 * @brief interaction w/ the elements in the Alien's current space
 * @param none
 * @return void
 */
void Alien::interactWithElements(Direction direction) {
    Space* interactionSpace = getSpace()->getDirection(direction);
    Element* element = nullptr;

    if (interactionSpace != nullptr) {
        element = interactionSpace->getElement();
    }

//    Element* element = getSpace()->getElement();

    if (element != nullptr) {
        getEnter("Interacting w/ " + element->getName());
        element->interact(this);
    }

}



/**
 * @name nextRankPoints
 * @brief returns the # of points needed to move up to the next rank
 * @param none
 * @return int
 */
int Alien::nextRankPoints() {
    // use a formula based on the current rank
    return ((rank + 3) * rank) * 10;
}



/**
 * @name getStats
 * @brief returns various Alien's current stats in the form of a string
 * @param none
 * @return string
 */
void Alien::printStats(bool showSurroundings) {
    Space* ahead = nullptr;
    Space* curr = nullptr;

    string itemActive;
    string itemStepsRemaining;
    string spaceAhead;
    string spaceCurr;
    string elemAhead;
    string elemCurr;


    if (showSurroundings) {
        // get information about the Alien's surroundings and print that as well
        curr = getSpace();
        ahead = peek(getOrientation());

        if (curr == nullptr) {
            spaceCurr += "Something is Wrong!";
        } else {
            spaceCurr += curr->getName();

            if (curr->getElement() != nullptr) {
                elemCurr += curr->getElement()->getName();
            } else {
                elemCurr += "None";
            }
        }

        if (ahead == nullptr) {
            spaceAhead += "Doesn\'t Exist";
            elemAhead += "N\\A";
        } else {
            spaceAhead += ahead->getName();

            if (ahead->getElement() != nullptr) {
                elemAhead += ahead->getElement()->getName();
            } else {
                elemAhead += "None";
            }
        }
    }



    if (activeItem != nullptr) {
        itemActive += activeItem->getName();
        itemStepsRemaining = " (" + to_string(activeItemStepsRemaining) + ")";
    } else {
        itemActive += "None";
        itemStepsRemaining = "";
    }


    cout << setw(27) << left << inColor("Name:", BLUE) << setw(15) << name
         << setw(34) << inColor("Orientation:", BLUE) << getOrientationString() << endl;

    cout << setw(27) << left << inColor("Rank:", BLUE) << setw(15) << rankName
         << setw(34) << inColor("Space (Current):", BLUE) << spaceCurr << endl;

    cout << setw(27) << left << inColor("Energy:", BLUE) << setw(15) << to_string(energy) + "/" + to_string(maxEnergy)
         << setw(34) << inColor("Element (Current):", BLUE) << elemCurr << endl;

    cout << setw(27) << left << inColor("Lives:", BLUE) << setw(15) << to_string(livesRemaining)
         << setw(34) << inColor("Space (Ahead):", BLUE) << spaceAhead << endl;

    cout << setw(27) << left << inColor("Points:", BLUE) << setw(15) << to_string(points) + "/" + to_string(nextRankPoints())
         << setw(34) << inColor("Element (Ahead):", BLUE) << elemAhead << endl;

    cout << setw(27) << left << inColor("Cash:", BLUE) << setw(15) << "$" + to_string(cash)
         << setw(34) << inColor("Energy Marker:", BLUE) << getEnergyMarker() << endl;

    cout << setw(27) << left << inColor("Bag:", BLUE) << setw(15) << to_string(bag->getItemCount()) + "/" + to_string(bag->getCapacity())
         << setw(34) << inColor("Active Item:", BLUE) << itemActive + itemStepsRemaining << endl;

    cout << setw(27) << left << inColor("Ship Pieces:", BLUE) << setw(15) << to_string(shipPieces->getItemCount()) + "/" + to_string(shipPieces->getCapacity()) << endl;

    cout << endl << endl;

}



/**
 * @name eatFood
 * @brief consumes a food item which adjust the alien's point value
 *  and removes the food item from it's space
 * @param food - a pointer to a Food Item
 * @return void
 */
void Alien::eatFood(Item* food) {
    int value = food->getValue();
    string foodName = food->getName();
    string comment;

    // adjust the Alien's energy
    energy = std::min(energy + value, maxEnergy);


    // make a comment to indicate eating the food
    if (value < 0) {
        comment = "Yuck - " + foodName + "!";
    } else if (value < 10) {
        comment = "Yum - " + foodName + "!";
    } else {
        comment = "Delicious - " + foodName + "!";
    }

    comment += " (" +  showPos(value, " energy", true) + ")";
    makeComment(comment, true);


    // remove the food from the game
    delete food;
}



/**
 * @name pickupMoney
 * @brief adds the money's value to the Alien's cash and then removes the Money Item from the game
 * @param money - a pointer to the Money Item that the Alien picks up
 * @return void
 */
void Alien::pickupMoney(Item* money) {
    int value = money->getValue();
    string comment;

    // adjust the Alien's cash based on the money value
    cash = std::max(0, cash + value);


    // indicate that the Alien picked up some money
    if (value < 5) {
        comment =  "Every penny helps";
    } else if (value < 10) {
        comment =  "Alright!";
    } else if (value < 25) {
        comment =  "I could get used to this!";
    } else {
        comment =  "Happy Birthday to me!";
    }

    comment += " (" + inColor("+" + to_string(value) + " " + pluralizeIf("buck", value) + "!", GREEN) + ")";
    makeComment(comment, true);


    // remove the money from the game
    delete money;
}



/**
 * @name getOrientationString
 * @brief gets a string representation of the Alien's orientation
 * @param none
 * @return string
 */
string Alien::getOrientationString() const {
    string result;

    if (orientation == UP) {
        result = "^ UP";
    } else if (orientation == DOWN) {
        result = "v DOWN";
    } else if (orientation == LEFT) {
        result = "< LEFT";
    } else if (orientation == RIGHT) {
        result = "> RIGHT";
    } else if (orientation == ABOVE) {
        result = "? ABOVE";
    } else if (orientation == BELOW) {
        result = "¿ BELOW";
    } else if (orientation == NO_DIRECTION) {
        result = "NONE";
    } else {
        result = "SOMETHING IS WRONG";
    }

    return result;
}



/**
 * @name isAlive
 * @brief checks if the Alien is still alive or not
 * @param none
 * @return bool - true if still alive, false if not
 */
bool Alien::isAlive() {
    return !(energy <= 0 && livesRemaining <= 0);
}



/**
 * @note restoreEnergy
 * @brief returns the Alien's energy to whatever the energyMarker value is
 * @param none
 * @return void
 */
void Alien::restoreEnergy() {
    getEnter("Restoring Energy!");
    this->energy = this->energyMarker;
}



/**
 * @name checkIfBackHome
 * @brief checks if the Alien has completed the game & arrived back to its homeland
 * @param none
 * @return void
 */
void Alien::checkIfBackHome() {
    // check if the player has moved to the "Home Grass" island, which would mean the player has won the game.
    if (!backHome && getSpace()->getIsland()->getLevel() == homeLevel) {
        string winMessage =  string("***************************   YOU WIN   ***************************\n")
             + "**                                                               **\n"
             + "**   Congratulations! You made it back to your homeland safely.  **\n"
             + "**                  Enjoy your time back home                    **\n"
             + "**               (where only good things happen)                 **\n"
             + "**                                                                     **\n"
             + "*******************************************************************\n";

        string continueMessage = "\nFeel free to roam around you homeland or quit whenever you\'re ready.\nPress [Enter] to continue...";

        makeComment(winMessage, false, GREEN, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);
        makeComment(continueMessage, true, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);
        backHome = true;
    }
}



/**
 * @name checkRestoreEnergy
 * @brief check if the Alien's energy should be restored to the energy marker
 * @details this would be caused by the alien having gotten out of the water
 * @param none
 * @return void
 */
void Alien::checkRestoreEnergy() {
    if (prevSpace != nullptr && prevSpace->spaceType() == WATER && getSpace()->spaceType() != WATER) {
        if (energyMarker != 0) {
            energy = energyMarker;
        }
    }
}



/**
 * @name checkRestoreEnergy
 * @brief overloaded version of checkRestoreEnergy that involves buying back energy from the Wizard
 * @param price - the price required to restore the energy
 * @return void
 */
bool Alien::checkRestoreEnergy(int price) {
    bool doRestore = false;

    if (getValidBool("Restore energy for $" + std::to_string(price))) {
        if (cash < price) {
            makeComment("Rats. You don\'t have enough money", true, RED);

        } else {
            energy = maxEnergy;
            energyMarker = maxEnergy;
            makeComment("I can feel it already!", true, GREEN);
            doRestore = true;
        }
    }

    return doRestore;
}



/**
 * @name showMenu
 * @brief shows the Alien's menu
 * @param none
 * @return void
 */
void Alien::showMenu() {
    reload();
    int choice = getValidInt(0, menuOpts.size() - 1, getMenu(menuOpts, 0, showHeading("Paused", BLUE)));

    if (choice == 1) {
        checkUseBagItem();
    } else if (choice == 2) {
        checkDropBagItem();
    } else if (choice == 3) {
        // TODO: look @ the space ship status
    }

}



/**
 * @name checkDropBagItem
 * @brief checks if the Alien wants to buy an item from the mailbox
 * @param Item - a pointer to the item that would replace the dropped item (optional)
 * @return void
 */
void Alien::checkDropBagItem(Item* replaceWithItem) {
    std::vector<string>bagItems = bag->itemList();
    Item* itemSelected = nullptr;
    int choice = -1;
    bool dropComplete = false;
    bagItems.insert(bagItems.begin(), "<<< Back");
    auto MAX_ITEM_SELECTION = static_cast<int>(bagItems.size() - 1);

    reload();

    // keep showing the menu until either the Alien decides to "go back" or drop and item
    while (!dropComplete) {
        choice = getValidInt(0, MAX_ITEM_SELECTION, getMenu(bagItems, 0, showHeading("Drop Item", BLUE)));

        if (choice != 0) {
            itemSelected = bag->getItem(choice - 1);

            if (itemSelected != nullptr) {
                // drop the item
                bag->removeItem(choice - 1);

                // if a replacement item was argued, add that item to the bag
                if (replaceWithItem != nullptr) {
                    bag->addItem(replaceWithItem);
                }
            }

            dropComplete = true;
        } else {
            dropComplete = true;
        }
    }
}



/**
 * @name checkUseBagItem
 * @brief displays the list of current bag items and allows the Alien
 *  to pick one of the bag items to use.
 * @param none
 * @return void
 */
void Alien::checkUseBagItem() {
    std::vector<string>bagItems = bag->itemList();
    int startingItemCount = bag->getItemCount();
    Item* itemSelected = nullptr;
    Item* currActiveItem = activeItem;
    int choice = -1;

    bagItems.insert(bagItems.begin(), "<<< Back\n");
    auto MAX_ITEM_SELECTION = static_cast<int>(bagItems.size() - 1);

    reload();

    // keep showing the menu until either the Alien decides to "go back" or drop and item
    while (choice != 0 && bag->getItemCount() == startingItemCount) {
        choice = getValidInt(0, MAX_ITEM_SELECTION, getMenu(bagItems, 0, showHeading("Use Item", BLUE)));

        if (choice != 0) {
            itemSelected = bag->getItem(choice - 1);

            if (itemSelected != nullptr) {
                // make it the active item
                activeItem = bag->getItem(choice - 1, true);
                activeItem->use(this);
                activeItemStepsRemaining = activeItem->getLifeSpan();
                delete currActiveItem;
            }
        }
    }
}



/**
 * @name findShipPiece
 * @brief finds a ship piece for the Alien and adds it the Alien's collection of ship pieces
 * @param piece - A pointer to the ship piece that was found
 * @return bool - true if all the ship pieces have been found, false if not
 */
bool Alien::findShipPiece(Item* piece) {
    shipPieces->addItem(piece);

    bool shipComplete = (shipPieces->getItemCount() == shipPieces->getCapacity());
    string comment = "Awesome! I found the " + piece->getName() + ".";

    // Make a comment about finding the ship piece
    if (shipComplete) {
        // if the Alien has found all the ship pieces, then the spaceship should appear
        //  on whatever island the alien is on.
        comment += "\nThat means all the ship pieces have been found and\nthe spaceship has been put back together.";
        makeComment(comment, true, GREEN, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);
        makeComment("All you need to do is find the spaceship on this island and then you can fly back home!", true, BLUE);

    } else {
         comment += "\nOnly " + std::to_string(shipPieces->getCapacity() - shipPieces->getItemCount()) + " more ship pieces to go!";
        makeComment(comment, true, GREEN, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);
    }

    return shipComplete;
}



/**
 * @name flyHome
 * @brief flies the Alien home by changing it's space to one on it's homeland
 * @param spaceship - a pointer to the Spaceship that is used to fly the alien home
 * @return void
 */
void Alien::flyHome(Item* spaceship) {
    // move the alien (and the spaceship) to the Alien's homeland island
    Space* alienSpace = nullptr;
    Space* shipSpace = nullptr;
    bool spacesFound = false;

    while (!spacesFound) {
        alienSpace = homeland->randomAvailableHomelandSpace();

        if (alienSpace->getLeft() != nullptr && alienSpace->getLeft()->getOccupiedState() == UNOCCUPIED) {
            shipSpace = alienSpace->getLeft();
            spacesFound = true;
        } else if (alienSpace->getRight() != nullptr && alienSpace->getRight()->getOccupiedState() == UNOCCUPIED) {
            shipSpace = alienSpace->getRight();
            spacesFound = true;
        } else if (alienSpace->getTop() != nullptr && alienSpace->getTop()->getOccupiedState() == UNOCCUPIED) {
            shipSpace = alienSpace->getTop();
            spacesFound = true;
        } else if (alienSpace->getBottom() != nullptr && alienSpace->getBottom()->getOccupiedState() == UNOCCUPIED) {
            shipSpace = alienSpace->getBottom();
            spacesFound = true;
        }
    }

    // once a location has been found, move the Alien & spaceship to the respective spaces
    spaceship->setSpace(shipSpace);
    spaceship->getSpace()->setElement(spaceship);
    spaceship->getSpace()->setOccupiedState(INACCESSIBLE);

    move(alienSpace);
}



/**
 * @name checkPickupItem
 * @brief checks if the Alien can/wants to add a new item to it's bag
 * @param newItem - the item that the Alien would add to its bag
 * @return void
 */
void Alien::checkPickupBagItem(Item* newItem) {
    // see if the Alien wants to pickup the item
    reload();

    if (getValidBool(showHeading("Add " + newItem->getName() + " to bag?", BLUE), "Yup", "Nope")) {
        if (bag->getItemCount() < bag->getCapacity()) {
            bag->addItem(newItem);
            newItem->setSpace(nullptr);
            makeComment("Awesome!", false, GREEN);
        } else {
            // there's no available bag space
            makeComment("Bummer. My bag is already full", true, RED);

            if (getValidBool("Would you like to drop an item from your bag and pick this up instead?\n")) {
                checkDropBagItem(newItem);
            }
        }
    } else {
        // the Alien did not choose to pick up the item. We'll set it as the nonBagItem so that
        //  we know to place that item back in the Space after the Alien's next move.
        nonBagItem = newItem;
    }
}



/**
 * @name depleteActiveItem
 * @brief decrements the lifespan of the activeItem. Once the active item
 *  has no steps remaining, it's removed.
 * @oaram none
 * @return void
 */
void Alien::depleteActiveItem() {
    Item* active = activeItem;

    if (active != nullptr && active->getItemType() == DOORWAY) {
        activeItemStepsRemaining = 0;
        activeItem = nullptr;

    } else if (active != nullptr) {
        activeItemStepsRemaining -= 1;

        if (activeItemStepsRemaining <= 0) {
            activeItemStepsRemaining = 0;

            if (activeItem->getSpace() != nullptr) {
                activeItem->getSpace()->setElement(nullptr);
            }

            activeItem = nullptr;
            delete active;
        }
    }
}



/**
 * @name getBittenByShark
 * @brief Has the Alien encounter a shark bite
 * @param none
 * @return void
 */
void Alien::getBittenByShark() {
    adjustEnergy(-25);
    energyMarker = max(energyMarker - 25, 0);
    makeComment("Ouch! Shark Bite! (-25 energy)", true, RED);
}



/**
 * @name interactWithEarthling
 * @brief direction interaction w/ an Earthling
 * @param earthling - a pointer to the Earthling to interact with
 * @return void
 */
void Alien::interactWithEarthling(Earthling* earthling) {
    if (earthling != nullptr) {
        earthling->interact(this);
    }
}



/**
 * @brief checks for forward experiences for the Alien depending on the
 *  space and/or elements ahead. This allows for the Alien to interact w/
 *  different parts of the game as he approches them
 */
void Alien::checkForwardExperiences() {
    Space* spaceAhead = space->getDirection(orientation);
    SpaceType spaceTypeAhead = NO_SPACE;
    Element* elementAhead = nullptr;
    ElementType elementTypeAhead = NO_ELEMENT_TYPE;

    if (spaceAhead!= nullptr) {
        spaceTypeAhead = spaceAhead->spaceType();
        elementAhead = spaceAhead->getElement();

        if (elementAhead != nullptr) {
            elementTypeAhead = elementAhead->getElementType();
        }
    }


    // Forward experience the ELEVATOR || MAILBOX
    if (spaceTypeAhead == ELEVATOR || spaceTypeAhead == MAILBOX) {
        experienceSpace(orientation);
    } else {
        experienceSpace();
    }

    // Forward experience interactions w/ Earthlings
    if (elementTypeAhead == EARTHLING) {
        interact(elementAhead);
    }

}



/**
 * @name checkBuyMaps
 * @brief checks if the Alien wants to buy maps from the cartographer
 * @param the price of the maps
 * @return bool - true if the maps are bought, false if not
 */
bool Alien::checkBuyMaps(int price) {
    bool doUncover = false;

    if (price > 0) {
        if(getValidBool("Buy the maps for $" + to_string(price) + " " + pluralizeIf("buck", price) + "?")) {
            if (cash < price) {
                makeComment("Bummer. You don\'t have enough money", true, RED);

            } else {
                makeComment("Awesome!", true, GREEN);
                doUncover = true;
            }
        }
    } else if(getValidBool("Take the maps?")) {
        doUncover = true;
    }

    if (doUncover) {
        getSpace()->getIsland()->uncoverEntireIsland();
    }

    return doUncover;
}




int Alien::getMaxEnergy() const {
    return maxEnergy;
}

void Alien::setMaxEnergy(int maxEnergy) {
    this->maxEnergy = maxEnergy;
}



