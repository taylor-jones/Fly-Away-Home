/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Grass.hpp is the Grass class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Grass class.
**********************************************************/

#ifndef GRASS_HPP
#define GRASS_HPP


#include "Space.hpp"

class Grass: public Space {

  public:
    Grass();
    ~Grass () override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
    void init() override;
};


#endif //GRASS_HPP