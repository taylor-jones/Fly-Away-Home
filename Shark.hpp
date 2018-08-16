/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Shark.hpp is the Shark class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Shark class.
**********************************************************/

#ifndef SHARK_HPP
#define SHARK_HPP


#include <stack>
#include "Earthling.hpp"
#include "Alien.hpp"


class Shark: public Earthling {
  private:
    Alien* player = nullptr;
    std::vector<Space*>sharkWater;

    bool inSharkWater(Space* checkSpace);
    void setReachableWaters();
    void moveTowardElement(Element* actor);

  public:
    Shark();
    ~Shark() override;

    void init(Alien* player);
    void interact(Element* actor) override;
    bool move(Space* space) override;
    bool move() override;
};


#endif //SHARK_HPP
