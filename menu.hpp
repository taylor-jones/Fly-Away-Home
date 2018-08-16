/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: menu.hpp is the menu function
**      specification file. This file contains specifications
**      for menu functions used within the program.
**********************************************************/

#include <vector>
#include <string>

//using std::vector;
using std::string;

#ifndef MENU_HPP
#define MENU_HPP

void showMenu(std::vector<string> &optionList, bool autoNumber);
void showMenu(std::vector<string> &optionList, bool autoNumber, string prompt);
void showMenu(std::vector<string> &optionList, int numberFrom, string prompt);

string getMenu(std::vector<string> &optionList, bool autoNumber);
string getMenu(std::vector<string> &optionList, bool autoNumber, string prompt);
string getMenu(std::vector<string> &optionList, int numberFrom = -1, string prompt = "");


#endif

