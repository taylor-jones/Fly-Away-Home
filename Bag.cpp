/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Bag.cpp is the class implementation
**  file for the Bag class. This file contains
**  definitions for the member functions of the Bag class.
**********************************************************/


#include "Bag.hpp"


/**
 * @name Bag
 * @brief Bag class constructor
 * @param none
 * @return none
 */
Bag::Bag() {
    init();
}


/**
 * @name Bag
 * @brief Bag class constructor that allows for specifying the bag size
 * @param capacity
 * @return none
 */
Bag::Bag(int capacity) {
    this->capacity = capacity;
    init();
}



/**
 * @name init
 * @brief common bag initializer function
 * @param none
 * @return void
 */
void Bag::init() {
    this->itemCount = 0;
    this->items = new Item*[capacity];

    // allocate the bag
    for (int i = 0; i < capacity; i++) {
        items[i] = nullptr;
    }
}


/**
 * @name ~Bag
 * @brief Bag class destructor
 * @param none
 * @return none
 */
Bag::~Bag() {
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }
    delete [] items;
}


/**
 * @brief
 * @param item
 * @return
 */
bool Bag::addItem(Item* item) {
    if (hasSpace()) {
        items[itemCount] = item;
        itemCount += 1;
        return true;
    }
    return false;
}


/**
 * @brief
 * @return
 */
bool Bag::hasSpace() {
    return (itemCount < capacity);
}


/**
 * @name shiftItems
 * @brief shifts all the items in the bag to make space for
 *  any new items to be added
 * @param idx - the index to start shifting items
 * @return void
 */
void Bag::shiftItems(int index) {
    for (int i = index; i < capacity; i++) {
        items[i] = items[i] + 1;
    }

    items[capacity - 1] = nullptr;
}


/**
 * @brief
 * @param index
 */
void Bag::removeItem(int index) {
    Item* item = items[index];
    shiftItems(index);
    itemCount -= 1;
    delete item;
}


/**
 * @brief
 * @param index
 * @return
 */
Item* Bag::getItem(int index, bool remove) {
    Item* item = items[index];

    // if remove, then remove the item from the bag. Otherwise just retrieve it
    if (remove) {
        shiftItems(index);
        itemCount -= 1;
    }

    return item;
}


/**
 * @name itemList
 * @brief returns a vector of the names of the items in the bag
 *  (in the order of their relative index within the bag)
 * @param none
 * @return vector
 */
std::vector<string> Bag::itemList(bool showPrice) {
    std::vector<string>list;
    string itemListing;

    list.reserve(itemCount);

    for (int i = 0; i < itemCount; i++) {
        itemListing = items[i]->getName();

        if (showPrice) {
            itemListing += " - " + inColor("$" + std::to_string(items[i]->getPrice()), GREEN);
        }

        list.push_back(itemListing);
    }

    return list;
}



int Bag::getCapacity() const {
    return capacity;
}

int Bag::getItemCount() const {
    return itemCount;
}


