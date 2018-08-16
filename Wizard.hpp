/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Wizard.hpp is the Wizard class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Wizard class.
**********************************************************/

#ifndef FINAL2_WIZARD_HPP
#define FINAL2_WIZARD_HPP


#include "Earthling.hpp"

class Wizard: public Earthling {
  private:
    void flipOrientation();

  public:
    Wizard();
    ~Wizard() override;

    void interact(Element* actor) override;
    bool move() override;
};


#endif //FINAL2_WIZARD_HPP
