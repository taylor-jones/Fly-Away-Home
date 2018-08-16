/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: IcarusWings.hpp is the IcarusWings class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the IcarusWings class.
**********************************************************/


#ifndef ICARUS_WINGS_HPP
#define ICARUS_WINGS_HPP


#include "Item.hpp"

class IcarusWings: public Item {
  public:
    IcarusWings();
    ~IcarusWings() override;

    void interact(Element* actor) override;
};


#endif //ICARUS_WINGS_HPP
