/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Bookie.hpp is the Bookie class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Bookie class.
**********************************************************/

#ifndef BOOKIE_HPP
#define BOOKIE_HPP


#include "Earthling.hpp"

enum BargainOutcome { PLAYER_WINS, BOOKIE_WINS, TIE, NO_OUTCOME };

class Bookie: public Earthling {
  private:

    void bargain1(Element* actor);
    void bargain2(Element* actor);
    void bargain3(Element* actor);

    bool guessNumber(int target);

  public:
    Bookie();
    ~Bookie() override;

    void interact(Element* actor) override;
    bool move() override;
};


#endif //BOOKIE_HPP
