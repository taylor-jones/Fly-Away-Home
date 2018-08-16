/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: ShipPiece.cpp is the class implementation
**  file for the ShipPiece class. This file contains
**  definitions for the member functions of the ShipPiece class.
**********************************************************/


#include "ShipPiece.hpp"
#include "Alien.hpp"
#include "Island.hpp"


ShipPiece::ShipPiece() {
    init();
}

ShipPiece::ShipPiece(ShipPieceType shipPieceType) {
    this->shipPieceType = shipPieceType;
    init();
}


void ShipPiece::init() {
    this->itemType = SHIP_PIECE;
//    this->name = "Ship Piece";
    this->backColor = MAGENTA;
    this->color = YELLOW;
    this->symbol = "§";

    // match the name of the ship piece w/ the ship piece type
    if (shipPieceType == CABIN) {
        this->name = "Cabin";
    } else if (shipPieceType == LEFT_BOOSTER) {
        this->name = "Left Booster";
    } else if (shipPieceType == RIGHT_BOOSTER) {
        this->name = "Right Booster";
    } else if (shipPieceType == CONTROL_BOARD) {
        this->name = "Control Board";
    } else if (shipPieceType == LANDING_RODS) {
        this->name = "Landing Rods";
    } else if (shipPieceType == PROPELLER) {
        this->name = "Propeller";
    } else if (shipPieceType == ENGINE) {
        this->name = "Engine";
    }
}


ShipPiece::~ShipPiece() {}



/**
 * @name interact
 * @brief interaction method for a ship piece
 * @param actor - the Element interacting w/ the ship piece
 * @return void
 * @note Only Alien's can interact w/ ship pieces, so any other element
 *  type will provoke no action
 */
void ShipPiece::interact(Element* actor) {
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        bool shipComplete = false;

        reload();

        // indicate the finding of the ship piece
        std::cout << std::endl << showHeading("Ship Piece Found!", BLUE) << std::endl;

        // add the ship pieces to the Alien's collection
        shipComplete = dynamic_cast<Alien*>(actor)->findShipPiece(this);

        // if the ship is complete, the spaceship should be created on the current island
        if (shipComplete) {
            getSpace()->getIsland()->addItem({ -1, -1}, SPACESHIP, true);
            reload();
        }

        // remove the ship piece from it's space
        getSpace()->setElement(nullptr);
        setSpace(nullptr);
    }
}



ShipPieceType ShipPiece::getShipPieceType() const {
    return shipPieceType;
}


void ShipPiece::setShipPieceType(ShipPieceType shipPieceType) {
    this->shipPieceType = shipPieceType;
}





