/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Slider.cpp is the class implementation
**  file for the Slider class. This file contains
**  definitions for the member functions of the Slider class.
**********************************************************/

#include "Slider.hpp"
#include "Island.hpp"
#include "Alien.hpp"

/**
 * @name Slider
 * @brief Slider class constructor
 * @param none
 * @return none
 */
Slider::Slider() {
    init();

    /* TODO: make a function that will update the symbol for the slider
     *  based on the direction it slides in
     */
}



/**
 * @name Slider
 * @brief Slide class constructor that allows for specifying the Slider direction,
 *  which changes the symbol for the Slider
 * @param direction
 * @return none
 */
Slider::Slider(Direction slideDirection) {
    this->slideDirection = slideDirection;
}



/**
 * @name init
 * @brief Slider initializer
 * @param none
 * @return void
 */
void Slider::init() {
    this->name = "Slider";
    this->backColor = GREY;
    this->color = BLACK;

    // determine the symbol based on the slide direction
    if (slideDirection == UP) {
        this->symbol = "^";
    } else if (slideDirection == DOWN) {
        this->symbol = "v";
    } else if (slideDirection == LEFT) {
        this->symbol = "<";
    } else if (slideDirection == RIGHT) {
        this->symbol = ">";
    } else {
        this->symbol = "¿";
    }
}



/**
 * @name ~Slider
 * @brief Slider class destructor
 * @param none
 * @return none
 */
Slider::~Slider() = default;



/**
 * @brief
 * @return
 */
Direction Slider::getSlideDirection() const {
    return slideDirection;
}



/**
 * @brief
 * @param slideDirection
 */
void Slider::setSlideDirection(Direction slideDirection) {
    this->slideDirection = slideDirection;
}



/**
 * @name spaceType
 * @brief returns this Space's SpaceType
 * @param none
 * @return SLIDER
 */
SpaceType Slider::spaceType() {
    return SLIDER;
}



/**
 * @name experience
 * @brief slides the experiencer in the direction that the Slider points.
 * @details Note that Items may sit on Slider spaces w/o moving, but any Earthling
 *  or Alien that moves on the the Slider will have the Slider experience.
 *      Also Note that the slider doesn't slide above or below, it's only intended
 *      to do 2d slides.
 * @param experiencer - a pointer to the Element that is experiencing the Slider
 * @return void
 */
void Slider::experience(Element* experiencer) {
    Space* next = nullptr;

    if (experiencer != nullptr) {

        // move the EARTHLING or ALIEN along the slider
        if (experiencer->getElementType() != ITEM) {
            next = getDirection(slideDirection);

            // set the experiencer's orientation to match the slide direction
            experiencer->setOrientation(slideDirection);

            if (next != nullptr) {
                // the space to slide to exists on the island
                experiencer->move(next);

                // have the experiencer experience the next space,
                //  which should keep them moving if it's another slider
                experiencer->getSpace()->experience(experiencer);
            }
        }
    }
}


