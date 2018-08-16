/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: util.hpp is the utility function
**      specification file. This file contains specifications
**      for utility functions used within the program.
**********************************************************/


#include <string>

#ifndef UTIL_HPP
#define UTIL_HPP


using std::istream;
using std::string;

/* inout validation */

//
// general
//

bool isValidInput(istream& input, string& value);
bool isValidInput(istream& input, string& value, unsigned int minLength);
bool isValidInput(istream& input, string& value, unsigned int minLength, unsigned int maxLength);

string getValidInput(string prompt, string errMessage);


//
// numbers
//


// general
string showPos(int value, string append = "", bool showColored = false);
string showPos(double value, string append = "", bool showColored = false);


// doubles
bool isDouble(istream& input, double& value);
bool isValidDouble(istream& input, double& value, double min);
bool isValidDouble(istream& input, double& value, double min, double max);

double getValidDouble(double min);
double getValidDouble(double min, double max);
double getValidDouble(double min, double max, string prompt);


// integers
bool isInt(double value);
bool isInt(istream& input, int& value);
bool isInt(istream& input, int& value, int number);

bool isValidInt(istream& input, int& value, int min);
bool isValidInt(istream& input, int& value, int min, int max);

int getValidInt(int min);
int getValidInt(int min, int max);
int getValidInt(int min, int max, string prompt);


bool getValidBool(string prompt = "", string yesListing = "Yes", string noListing = "No");




/* random integer generation */

int randInt(int min, int max);


/* misc utility */

//
// io
//

void getEnter();
void getEnter(string prompt);

string randomLineFromFile(string fileName);


//
// screen
//

void clearScreen(string content = "");



//
// strings
//

string pluralize(string word);
string pluralizeIf(string word, int count);
string capitalize(string word);
string repeat(string content, int times);


enum Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, GREY, DEFAULT_COLOR, INVISIBLE };
enum ColorFormat { DEFAULT_FORMAT, BOLD, DIM, UNDERLINED, BLINK, REVERSE, HIDDEN };
string inColor(string content = "", Color foreGround = DEFAULT_COLOR, Color backGround = DEFAULT_COLOR, ColorFormat format = DEFAULT_FORMAT);


string wrap(string content, string wrapper, size_t padding = 0);
string showHeading(string content, Color color = DEFAULT_COLOR);

#endif
