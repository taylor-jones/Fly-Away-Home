/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: SpeedSkates.hpp is the SpeedSkates class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the SpeedSkates class.
**********************************************************/


#ifndef SPEED_SKATES_HPP
#define SPEED_SKATES_HPP


#include "Item.hpp"

class SpeedSkates: public Item {
  public:
    SpeedSkates();
    ~SpeedSkates() override;

    void interact(Element* actor) override;
};


#endif //SPEED_SKATES_HPP
