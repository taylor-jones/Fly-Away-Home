/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Elevator.hpp is the Elevator class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Elevator class.
**********************************************************/

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include "Space.hpp"

class Elevator: public Space {
  private:
    std::vector<string>elevatorOpts;

  public:
    Elevator();
    ~Elevator() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
    void init() override;
};


#endif //ELEVATOR_HPP
