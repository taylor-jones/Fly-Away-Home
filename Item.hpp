/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Item.hpp is the Item class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Item class.
**********************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP


#include "Element.hpp"

enum ItemType {
  MONEY,
  FOOD,
  BINOCULARS,
  INNERTUBE,
  ICARUS_WINGS,
  SPEED_SKATES,
  DECOY,
  DOORWAY,
  SHIP_PIECE,
  SPACESHIP,
  ROSE_BUSHES,
  BOOM_BOX,
  NO_ITEM,
  RANDOM_ITEM
};

class Item: public Element {
  protected:
    int value = 0;
    int price = 0;
    int impactTo = 0;
    int impactFrom = 0;
    int lifeSpan = -1;

    ItemType itemType = NO_ITEM;


  public:
    Item();
    ~Item() override;

    // getters
    int getValue() const;
    int getImpactTo() const;
    int getImpactFrom() const;
    int getLifeSpan() const;
    int getPrice() const;
    ItemType getItemType() const;


    // setters
    void setValue(int value = -1);
    void setImpactTo(int impactTo);
    void setImpactFrom(int impactFrom);
    void setLifeSpan(int lifeSpan);
    void setPrice(int price);
    void setItemType(ItemType itemType);

    // activity
    void interact(Element* actor) override = 0;
    virtual void use(Element* actor);
};


#endif //ITEM_HPP
