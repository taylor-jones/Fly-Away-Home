/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Item.cpp is the class implementation
**  file for the Item class. This file contains
**  definitions for the member functions of the Item class.
**********************************************************/

#include "Item.hpp"

Item::Item() {
    this->symbol = "┼";
    this->color = MAGENTA;
    this->backColor = WHITE;
    this->lifeSpan = 25;
}

Item::~Item() {

}

int Item::getValue() const {
    return value;
}

void Item::setValue(int value) {
    this->value = value;
}

int Item::getImpactTo() const {
    return impactTo;
}

void Item::setImpactTo(int impactTo) {
    this->impactTo = impactTo;
}

int Item::getImpactFrom() const {
    return impactFrom;
}

void Item::setImpactFrom(int impactFrom) {
    this->impactFrom = impactFrom;
}

ItemType Item::getItemType() const {
    return itemType;
}

void Item::setItemType(ItemType itemType) {
    this->itemType = itemType;
}


int Item::getLifeSpan() const {
    return lifeSpan;
}

/**
 * @brief setter
 * @param lifeSpan
 */
void Item::setLifeSpan(int lifeSpan) {
    this->lifeSpan = lifeSpan;
}

/**
 * @brief getter
 * @return
 */
int Item::getPrice() const {
    return price;
}

/**
 * @brief setter
 * @param price
 */
void Item::setPrice(int price) {
    this->price = price;
}


/**
 * @name use
 * @brief default use function (does nothing)
 * @param actor
 */
void Item::use(Element* actor) {}


