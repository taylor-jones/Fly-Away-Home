/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: ShipPiece.hpp is the ShipPiece class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the ShipPiece class.
**********************************************************/


#ifndef SHIP_PIECE_HPP
#define SHIP_PIECE_HPP

enum ShipPieceType { CABIN,  LEFT_BOOSTER, RIGHT_BOOSTER, CONTROL_BOARD, LANDING_RODS, PROPELLER, ENGINE, NO_PIECE};

#include "Item.hpp"

class ShipPiece: public Item {
  private:
    ShipPieceType shipPieceType = NO_PIECE;

    void init();

  public:
    ShipPiece();
    explicit ShipPiece(ShipPieceType shipPieceType);
    ~ShipPiece() override;

    ShipPieceType getShipPieceType() const;
    void setShipPieceType(ShipPieceType shipPieceType);
    void interact(Element* actor) override;
};


#endif //SHIP_PIECE_HPP
