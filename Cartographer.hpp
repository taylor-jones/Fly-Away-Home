/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Cartographer.hpp is the Cartographer class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Cartographer class.
**********************************************************/

#ifndef CARTOGRAPHER_HPP
#define CARTOGRAPHER_HPP


#include "Earthling.hpp"

class Cartographer: public Earthling {
  private:
    bool canMap(Direction direction);

  public:
    Cartographer();
    ~Cartographer() override;

    void interact(Element* actor) override;
    bool move() override;
};


#endif //CARTOGRAPHER_HPP
