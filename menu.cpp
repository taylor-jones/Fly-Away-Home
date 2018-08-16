/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description:
**      menu.cpp is the function implementation file for
**      the menu functions declared in menu.hpp.
**********************************************************/

#include <iostream>
#include <vector>

#include "menu.hpp"
#include "util.hpp"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;


/**
 * @name showMenu
 * @brief displays a vector of strings as individual menu
 *      options in the terminal
 * @param optionList - a vector of strings that represent
 *      the menu options.
 * @param autoNumber - a boolean indicator as to whether
 *      or not the function should generate numbers before
 *      each of the menu options
 * @return void
 */
void showMenu(vector<string> &optionList, bool autoNumber) {
    // display each of the options in the optionList on its own line
    for (unsigned int i = 0; i < optionList.size(); i++) {
        if (autoNumber) {
            // automatically number the options, starting with #1
            cout << i + 1 << ". " << optionList[i] << endl;
        } else {
            // just display the option text
            cout << optionList[i] << endl;
        }
    }

    // place a newline at the end of the menu
    cout << endl;
}



/**
 * @name showMenu
 * @brief  Overloaded version of showMenu that additionally allows
 *      for specifying a prompt string to display above the menu.
 * @param optionList - a vector of strings that represent the menu options
 * @param autoNumber - a boolean indicator as to whether or not the
 *      function should generate numbers before each of the menu options.
 * @param prompt - a string to display above the menu.
 * @return void
 */
void showMenu(vector<string> &optionList, bool autoNumber, string prompt) {
    // display the prompt
    cout << prompt << endl;

    // display each of the options in the optionList on its own line
    for (unsigned int i = 0; i < optionList.size(); i++) {
        if (autoNumber) {
            // automatically number the options, starting with #1
            cout << i + 1 << ". " << optionList[i] << endl;
        } else {
            // just display the option text
            cout << optionList[i] << endl;
        }
    }

    // place a newline at the end of the menu
    cout << endl;
}



/**
 * @brief overloaded version of showMenu that allows for specifying a specific number
 *  to being auto-numbering at
 * @param optionList - a vector of strings that represent the menu options
 * @param numberFrom - the number at which to being auto-numberiong (or -1 for no autonumber)
 * @param prompt - a string to display above the menu.
 * @return void
 */
void showMenu(std::vector<string> &optionList, int numberFrom, string prompt) {
    cout << prompt << endl;

    for (int i = 0; i < static_cast<int>(optionList.size()); i++) {
        if (numberFrom > -1) {
            cout << i + numberFrom << ". " << optionList[i] << endl;
        } else {
            cout << optionList[i] << endl;
        }
    }

    cout << endl;
}




/**
 * @name getMenu
 * @brief Alternative version of showMenu that returns a string,
 *      allowing its return value to be used where strings are required.
 * @param optionList - a vector of strings that represent the menu options
 * @param autoNumber - a boolean indicator as to whether or not the
 *      function should generate numbers before each of the menu options.
 * @return string
 */
string getMenu(std::vector<string> &optionList, bool autoNumber) {
    showMenu(optionList, autoNumber);
    return "";
}



/**
 * @name getMenu
 * @brief  Overloaded version of getMenu that additionally allows
 *      for specifying a prompt string to display above the menu.
 * @param optionList - a vector of strings that represent the menu options
 * @param autoNumber - a boolean indicator as to whether or not the
 *      function should generate numbers before each of the menu options.
 * @param prompt - a string to display above the menu.
 * @return string
 */
string getMenu(std::vector<string> &optionList, bool autoNumber, string prompt) {
    showMenu(optionList, autoNumber, prompt);
    return "";
}


/**
 * @brief overloaded version of getMenu that allows for specifying a certain value
 *  to begin auto-numberg where: -1 = no auto-number
 * @param optionList - a vector of strings that represent the menu options
 * @param numberFrom - the number to begin auto-numbering from (or -1 for no auto-numbering
 * @param prompt - a string to display above the menu
 * @return string
 */
string getMenu(std::vector<string> &optionList, int numberFrom, string prompt) {
    showMenu(optionList, numberFrom, prompt);
    return "";
}



