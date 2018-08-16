/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Mailbox.cpp is the class implementation
**  file for the Mailbox class. This file contains
**  definitions for the member functions of the Mailbox class.
**********************************************************/

#include <vector>

#include "Mailbox.hpp"
#include "SpeedSkates.hpp"
#include "Innertube.hpp"
#include "IcarusWings.hpp"
#include "Binoculars.hpp"
#include "Decoy.hpp"
#include "Doorway.hpp"
#include "Food.hpp"


using std::cout;
using std::endl;

/**
 * @name Mailbox
 * @brief Mailbox class constructor
 * @param none
 * @return none
 */
Mailbox::Mailbox() {
    init();
}

Mailbox::Mailbox(int boxSize) {
    this->boxSize = boxSize;
    init();
}


/**
 * @name ~Mailbox
 * @brief Mailbox class destructor
 * @param none
 * @return none
 */
Mailbox::~Mailbox() {
    delete box;
}


/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return MAILBOX
 */
SpaceType Mailbox::spaceType() {
    return MAILBOX;
}



/**
 * @name checkBuyItem
 * @brief checks if the Alien wants to buy an item from the mailbox
 * @param alien - a pointer to the Alien at the mailbox
 * @return void
 */
void Mailbox::checkBuyItem(Alien* alien) {
    std::vector<string>boxItems = box->itemList(true);
    int startingItemCount = box->getItemCount();
    Item* itemSelected = nullptr;
    int choice = -1;

    // add a "back" option to the menu
    boxItems.insert(boxItems.begin(), "<<< Back\n");
    auto MAX_ITEM_SELECTION = static_cast<int>(boxItems.size() - 1);

    // keep showing the menu until either the Alien decides to "go back" or purchases an item
    while (choice != 0 && box->getItemCount() == startingItemCount) {
        reload();
        cout << endl;

        // let the user select a menu item
        choice = getValidInt(0, MAX_ITEM_SELECTION, getMenu(boxItems, 0, showHeading("Available Items", BLUE)));
        itemSelected = box->getItem(choice - 1);

        // process the user's selection
        if (choice != 0 && itemSelected != nullptr) {
            if (itemSelected->getPrice() > alien->getCash()) {
                // the item is too expensive
                alien->makeComment("Bummer. That\'s too expensive", true, RED);

            } else if (!alien->getBag()->hasSpace()) {
                // there's no available bag space
                alien->makeComment("Bummer. My bag is already full", true, RED);

                if (getValidBool("Would you like to drop an item from your bag and pick this up instead?\n")) {
                    alien->checkDropBagItem(itemSelected);
                } else {
                    choice = 0;
                }

            } else {
                // the item is affordable & bag space exists
                alien->getBag()->addItem(box->getItem(choice - 1, true));
                alien->makeComment("Awesome! Added " + itemSelected->getName() + " to my bag.", true, GREEN);
            }
        }
    }
}







/**
 * @name experience
 * @brief prompts the player about buying an item from the mailbox
 * @param experiencer - a pointer to the Element experiencing the mailbox
 * @return void
 */
void Mailbox::experience(Element* experiencer) {
    // only Aliens can experience the mailbox
    if (experiencer != nullptr && experiencer->getElementType() == ALIEN) {
        auto* alien = dynamic_cast<Alien*>(experiencer);

        cout << endl;

        // see if the Alien wants to buy something
        if (getValidBool(showHeading("Mail Order?", BLUE), "Yup", "Nope")) {
            checkBuyItem(alien);
        }
    }
}




/**
 * @name init
 * @brief Mailbox initializer function that sets common variable values
 * @param none
 * @return void
 */
void Mailbox::init() {
    Item* present = nullptr;

    const int PRESENT_MIN = 1;
    const int PRESENT_MAX = 7;
    const int VALUE_MIN = 3;
    const int VALUE_MAX = 3;

    this->name = "Mailbox";
    this->backColor = WHITE;
    this->color = BLUE;
    this->symbol = "M";


    box = new Bag(boxSize);

    // fill the box w/ random presents
    for (int i = 0; i < boxSize; i++) {
        // create the present
        present = presentFromRandomNumber(randInt(PRESENT_MIN, PRESENT_MAX));

        // set a (sort of) random price for each present
        present->setValue(randInt(VALUE_MIN, VALUE_MAX));

        // add the present to the mailbox
        box->addItem(present);
    }
}



/**
 * @name presentFromRandomNumber
 * @brief given a random number (in a specified range), maps the number to an ItemType
 *  (which is associated) w/ a present type, creates & returns the present of that type
 * @param number
 * @return Item* - a pointer to a present
 */
Item* Mailbox::presentFromRandomNumber(int number) {
    Item* present = nullptr;

    if (number == 1) {
        // speed skates
        present = new SpeedSkates();
    } else if (number == 2) {
        // innertube
        present = new Innertube();
    } else if (number == 3) {
        // icarus wings
        present = new IcarusWings();
    } else if (number == 4) {
        // binoculars
        present = new Binoculars();
    } else if (number == 5) {
        // decoy
        present = new Decoy();
    } else if (number == 6) {
        // doorway?
        present = new Doorway();
    } else if (number == 7) {
        // food
        present = new Food();
    }

    return present;
}





