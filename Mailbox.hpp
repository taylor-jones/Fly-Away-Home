/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Mailbox.hpp is the Mailbox class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Mailbox class.
**********************************************************/

#ifndef MAILBOX_HPP
#define MAILBOX_HPP


#include "Space.hpp"
#include "Bag.hpp"
#include "Alien.hpp"

class Mailbox: public Space {
  private:
    int boxSize = 3;
    Bag* box = nullptr;
    Item* presentFromRandomNumber(int number);

    void checkBuyItem(Alien* alien);

  public:
    Mailbox();
    explicit Mailbox(int boxSize);
    ~Mailbox() override;

    SpaceType spaceType() override;
    void experience(Element* experiencer) override;
    void init() override;
};


#endif //MAILBOX_HPP
