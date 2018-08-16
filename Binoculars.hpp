/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Binoculars.hpp is the Binoculars class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Binoculars class.
**********************************************************/


#ifndef BINOCULARS_HPP
#define BINOCULARS_HPP


#include "Item.hpp"

class Binoculars: public Item {
  private:
    std::vector<string>directionOpts = { "Up", "Down", "Left", "Right" };

  public:
    Binoculars();
    ~Binoculars() override;

    void interact(Element* actor) override;
    void use(Element* actor) override;
};


#endif //BINOCULARS_HPP
