/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Spaceship.hpp is the Spaceship class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Spaceship class.
**********************************************************/


#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "Item.hpp"

class Spaceship: public Item {
  private:

  public:
    Spaceship();
    ~Spaceship() override;

    void interact(Element* actor) override;
};


#endif //SPACESHIP_HPP
