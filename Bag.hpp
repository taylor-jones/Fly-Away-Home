/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Bag.hpp is the Bag class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Bag class.
**********************************************************/

#ifndef FINAL2_BAG_HPP
#define FINAL2_BAG_HPP


#include "Item.hpp"
#include <vector>

class Bag {
  private:
    int capacity = 10;
    int itemCount;
    Item** items;

    void shiftItems(int index);
    void init();


  public:
    Bag();
    explicit Bag(int capacity);
    ~Bag();

    // getters
    int getCapacity() const;
    int getItemCount() const;
    Item* getItem(int index, bool remove = false);

    bool hasSpace();

    // activity
    bool addItem(Item* item);
    void removeItem(int index);
    std::vector<string>itemList(bool showPrice = false);
};


#endif //FINAL2_BAG_HPP
