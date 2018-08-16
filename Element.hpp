/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Element.hpp is the Element class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Element class.
**********************************************************/

#ifndef ELEMENT_HPP
#define ELEMENT_HPP


#include "Structures.hpp"
#include "Space.hpp"
#include "util.hpp"


enum ElementType { ITEM, EARTHLING, ALIEN, NO_ELEMENT_TYPE };


class Element {
  protected:
    //
    // member variables
    //
    Space* space = nullptr;
    ElementType elementType = NO_ELEMENT_TYPE;
    Direction orientation = NO_DIRECTION;

    Color color = DEFAULT_COLOR;
    Color backColor = INVISIBLE;

    string symbol = " ";
    string name = "";

    bool canMoveOverAccessibleSpaces = false;

    //
    // member functions
    //



  public:
    Element();
    virtual ~Element();

    // getters
    Space* getSpace();
    ElementType getElementType();
    Direction getOrientation();
    Color getColor();
    Color getBackColor();
    string getSymbol();
    string getName();


    // setters
    void setSpace(Space* space);
    void setElementType(ElementType elementType);
    void setOrientation(Direction orientation);
    void setColor(Color color);
    void setBackColor(Color color);
    void setSymbol(string symbol);
    void setName(string name);


    // activities
    virtual void interact(Element* actor) = 0;
    virtual void reload();

    virtual bool move();
    virtual bool move(Direction direction);
    virtual bool move(Space* space);

    Space* peek(Direction direction);
    void makeComment(string comment, bool interrupt = false, Color color = DEFAULT_COLOR, Color backColor = DEFAULT_COLOR, ColorFormat format = DEFAULT_FORMAT, bool reloadBefore = true, bool reloadAfter = true);
};


#endif //ELEMENT_HPP
