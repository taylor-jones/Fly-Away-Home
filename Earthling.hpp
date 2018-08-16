/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Earthling.hpp is the Earthling class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Earthling class.
**********************************************************/

#ifndef EARTHLING_HPP
#define EARTHLING_HPP


#include "Element.hpp"

enum EarthlingType { WIZARD, CARTOGRAPHER, SHARK, BOOKIE, NO_EARTHLING_TYPE };

class Earthling: public Element {
  protected:
    int interactionCount = 0;
    EarthlingType earthlingType = NO_EARTHLING_TYPE;
    bool turnComplete = false;

  public:
    Earthling();
    ~Earthling() override;

    bool isTurnComplete() const;
    void setTurnComplete(bool turnComplete);

    bool move(Space* next) override;
    bool move() override = 0;
    void interact(Element* actor) override = 0;
};


#endif //EARTHLING_HPP
