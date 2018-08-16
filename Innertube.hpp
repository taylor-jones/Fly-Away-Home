/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Innertube.hpp is the Innertube class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Innertube class.
**********************************************************/


#ifndef INNERTUBE_HPP
#define INNERTUBE_HPP


#include "Item.hpp"

class Innertube: public Item {
  public:
    Innertube();
    ~Innertube() override;

    void interact(Element* actor) override;
};


#endif //INNERTUBE_HPP
