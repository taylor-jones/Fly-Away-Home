/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Doorway.hpp is the Doorway class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Doorway class.
**********************************************************/


#ifndef DOORWAY_HPP
#define DOORWAY_HPP


#include "Item.hpp"

class Doorway: public Item {
  public:
    Doorway();
    ~Doorway() override;

    void use(Element* actor) override;
    void interact(Element* actor) override;
};


#endif //DOORWAY_HPP
