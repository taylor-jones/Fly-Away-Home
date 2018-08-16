/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Structures.hpp is the Structures specification file.
**  This file contains common helper structs that are use in various
**  locations throughout the game.
**********************************************************/

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP


enum Direction { LEFT, DOWN, UP, RIGHT, ABOVE, BELOW, NO_DIRECTION };


struct Range {
    int min;
    int max;

//    Range() {
//        min = 0;
//        max = 0;
//    }
};


struct Size {
    int x;
    int y;

    Size() {
        x = 0;
        y = 0;
    }

    Size(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


struct Coordinates {
    int x = 0;
    int y = 0;
    int z = 0;

    Coordinates(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Coordinates(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};


#endif //STRUCTURES_HPP
