/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Slider.hpp is the Slider class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Slider class.
**********************************************************/

#ifndef SLIDER_HPP
#define SLIDER_HPP


#include "Space.hpp"
#include "Element.hpp"

class Slider: public Space {
  private:
    Direction slideDirection = RIGHT;

    void init() override;


  public:
    Slider();
    explicit Slider(Direction slideDirection);
    ~Slider() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;

    Direction getSlideDirection() const;

    void setSlideDirection(Direction slideDirection);
};


#endif //SLIDER_HPP
