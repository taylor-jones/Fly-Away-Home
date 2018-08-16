/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Sand.hpp is the Sand class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Sand class.
**********************************************************/

#ifndef SAND_HPP
#define SAND_HPP


#include "Space.hpp"

class Sand: public Space {
  private:
    void init() override;


  public:
    Sand();
    ~Sand() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
};


#endif //SAND_HPP
