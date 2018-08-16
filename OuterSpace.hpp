/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: OuterSpace.hpp is the OuterSpace class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the OuterSpace class.
**********************************************************/

#ifndef OUTER_SPACE_HPP
#define OUTER_SPACE_HPP


#include "Space.hpp"

class OuterSpace: public Space {
  private:
    void init() override;

  public:
    OuterSpace();
    ~OuterSpace() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
};


#endif //OUTER_SPACE_HPP
