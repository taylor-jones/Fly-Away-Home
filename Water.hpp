/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Water.hpp is the Water class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Water class.
**********************************************************/

#ifndef WATER_HPP
#define WATER_HPP


#include "Space.hpp"

class Water: public Space {
  private:
    void init() override;

  public:
    Water();
    ~Water() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
};


#endif //WATER_HPP
