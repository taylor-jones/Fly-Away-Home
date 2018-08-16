/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Road.hpp is the Road class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Road class.
**********************************************************/

#ifndef ROAD_HPP
#define ROAD_HPP


#include "Space.hpp"

class Road: public Space {
  private:
    void init() override;

  public:
    Road();
    ~Road() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
};


#endif //ROAD_HPP
