/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: HomeLand.hpp is the HomeLand class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the HomeLand class.
**********************************************************/

#ifndef HOME_LAND_HPP
#define HOME_LAND_HPP


#include "Space.hpp"

class HomeLand: public Space {

  public:
    HomeLand();
    ~HomeLand () override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
    void init() override;
};


#endif //HOME_LAND_HPP