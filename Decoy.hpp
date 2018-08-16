/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Decoy.hpp is the Decoy class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Decoy class.
**********************************************************/


#ifndef DECOY_HPP
#define DECOY_HPP


#include "Item.hpp"

class Decoy: public Item {
  private:
    bool isPlaced = false;

  public:
    Decoy();
    ~Decoy() override;

    void use(Element* actor) override;
    void interact(Element* actor) override;
};


#endif //DECOY_HPP
