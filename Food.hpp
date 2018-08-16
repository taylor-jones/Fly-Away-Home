/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Food.hpp is the Food class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Food class.
**********************************************************/

#ifndef FINAL2_FOOD_HPP
#define FINAL2_FOOD_HPP


#include "Item.hpp"

class Food: public Item {
  private:
    void init();
    std::vector<std::vector<string>>foodPossibilities {
        {"Beer", "2"},
        {"Salad", "6"},
        {"Fries", "2"},
        {"Milkshake", "3"},
        {"Fresh Fruit", "4"},
        {"Fresh Veggies", "8"},
        {"Banana", "5"},
        {"Pizza", "10"},
        {"Cream Cheese", "5"},
        {"Avocados", "4"},
        {"Avocados from Mexico", "12"},
        {"Eggs", "7"},
        {"Rice", "1"},
        {"Chicken Wings", "8"},
        {"Ice Cream", "15"},
        {"Moldy Cheese", "-5"},
        {"Junk Food", "-10"},
        {"Rotten Tomatoes", "-15"},
        {"Meatloaf", "-25"}
    };

  public:
    Food();
    explicit Food(int value, string name);
    ~Food() override;

    void interact(Element* actor) override;
};


#endif //FINAL2_FOOD_HPP
