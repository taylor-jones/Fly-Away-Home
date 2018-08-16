/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Money.hpp is the Money class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Money class.
**********************************************************/

#ifndef FINAL2_MONEY_HPP
#define FINAL2_MONEY_HPP


#include "Item.hpp"

class Money: public Item {
  private:
    void init();
    std::vector<int>moneyPossibilities = {1, 1, 2, 2, 3, 5, 5, 10, 20, 100};

  public:
    Money();
    explicit Money(int value);
    ~Money() override;

    void interact(Element* actor) override;
};


#endif //FINAL2_MONEY_HPP
