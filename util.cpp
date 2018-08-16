/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description:
**      util.cpp is the function implementation file for
**      the utility functions declared in util.hpp.
**********************************************************/


#include <iostream>
#include <climits>
#include <fstream>
#include <cmath>
#include <cfloat>
#include <vector>
#include "util.hpp"
#include "menu.hpp"



//
// general
//


/**
 * @name isValidInput
 * @brief Reads an input stream to determine if it's contents
 *      represent a input of any substance
 * @param input - a reference to an input stream
 * @param value - a reference to an string, which will hold
 *       the input value, if valid.
 * @return bool (true if the input value is valid, false if not)
 */
bool isValidInput(istream& input, string& value) {
    return !(!getline(input, value) || value.empty() || (value.find_first_not_of(' ') == string::npos));
}



/**
 * @name isValidInput
 * @brief overloaded version of isValidInput that additionally
 *      allows for specifying a minimum length for validity.
 * @param input  - a reference to an input stream
 * @param value - a reference to a string, which will hold the
 *      input value, if valid.
 * @param minLength - the minimum length allowed
 * @return - bool (true if the input is valid, false if not)
 */
bool isValidInput(istream& input, string& value, unsigned int minLength) {
    return isValidInput(input, value) && (value.length() >= minLength);
}



/**
 * @name isValidInput
 * @brief overloaded version of isValidInput that additionally
 *      allows for specifying a minimum input length for validity
 *      and a maximum input length for validity.
 * @param input  - a reference to an input stream
 * @param value - a reference to a string, which will hold the
 *      input value, if valid.
 * @param minLength - the minimum length allowed
 * @param maxLength - the maximum length allowed
 * @return - bool (true if the input is valid, false if not)
 */
bool isValidInput(istream& input, string& value, unsigned int minLength, unsigned int maxLength) {
    return isValidInput(input, value, minLength) && (value.length() <= maxLength);
}




/**
 * @name getValidInput
 * @brief prompts a user to provide some kind of input, and
 *      continues to display a provided error message until a
 *      valid input is provided.
 * @param prompt - the prompt to display to the user before receiving input
 * @param errMessage - the message to display to the user when no valid input is received
 * @return string - the input value (once valid)
 */
string getValidInput(string prompt, string errMessage) {
    string value;

    std::cout << prompt;

    while (!isValidInput(std::cin, value)) {
        std::cout << errMessage << ": ";
    }

    return value;
}





//
// doubles
//



/**
 * @name isDouble
 * @brief determines if a input stream represents a double
 * @param input - the input stream
 * @param value - the value that will be assigned the resulting
 *      double if the stream contains a double
 * @return bool - true if the stream represents a double, false if not.
 */
bool isDouble(istream& input, double& value) {
    bool result;
    string line;

    // If there's no valid input stream, or the resulting string is empty,
    //  then it's not an integer.
    if (!getline(input, line) || line.empty()) {
        result = false;
    } else {
        char* nonDbl;
        // convert the line to a double
        value = strtod(line.c_str(), &nonDbl);

        // If it's a valid double, nothing out of range will be found
        result = (*nonDbl == 0);
    }

    return result;
}



/**
 * @name isValidDouble
 * @brief determines if an input value represents a double that
 *      additionally is greater than a specified minimum;
 * @param input - the input stream
 * @param value - the value that will be assigned the double, if valid
 * @param min - the minimum double value allowed
 * @return bool - true if the stream represents a valid double
 *      >= min, false if not
 */
bool isValidDouble(istream& input, double& value, double min) {
    return (isDouble(input, value)) && (value >= min);
}



/**
 * @name isValidDouble
 * @brief overloaded version of isValidDouble that additionally
 *      allows for specifying a maximum value allowed for validity.
 * @param input - the input stream
 * @param value - the value that will be assigned the double, if valid
 * @param min - the minimum double value allowed
 * @param max - the maximum double value allowed
 * @return bool - true if the stream represents a valid double
 *      >= min and <= max, false if not.
 */
bool isValidDouble(istream& input, double& value, double min, double max) {
    return (isDouble(input, value)) && (value >= min) && (value <= max);
}



/**
 * @name getValidDouble
 * @brief Retrieves a user's input and, if the response is
 *      a valid double (>= [min] and <= DBL_MAX, the double
 *      is returned. If not, the function continues to prompt
 *      the user until a satisfying double is provided.
 * @param min - the lowest valid double allowed
 * @return double (once a valid double is provided)
 */
double getValidDouble(double min) {
    double choice;

    // use input validation to ensure the value is within range
    while (!isValidDouble(std::cin, choice, min, DBL_MAX)) {
        std::cout << "Please choose a number from " << min << " through " << DBL_MAX << ": ";
    }

    return choice;
}



/**
 * @name getValidDouble
 * @brief overloaded version of getValidDouble that additionally
 *      allows for specifying a max allowed value.
 * @param min - the lowest valid double allowed
 * @param max - the highest valid double allowed
 * @return double (once a valid double is provided)
 */
double getValidDouble(double min, double max) {
    double choice;

    // use input validation to ensure the value is within range
    while (!isValidDouble(std::cin, choice, min, max)) {
        std::cout << "Please choose a number from " << min << " through " << max << ": ";
    }

    return choice;
}



/**
 * @name getValidDouble
 * @brief overloaded version of getValidDouble that additionally
 *      allows for specifying a max allowed value as well as a
 *      prompt to display to the user before accepting input.
 * @param min - the lowest valid double allowed
 * @param max - the highest valid double allowed
 * @param prompt - a string to print to the console before input
 * @return double (once a valid double is provided)
 */
double getValidDouble(double min, double max, string prompt) {
    double choice;

    std::cout << prompt;

    // use input validation to ensure the value is within range
    while (!isValidDouble(std::cin, choice, min, max)) {
        std::cout << "Please choose a number from " << min << " through " << max << ": ";
    }

    return choice;
}



//
// integers
//


/**
 * @note isInt
 * @brief determines if a number (double) is an integer
 * @param value - a double
 * @return bool - true if it is an integer, false if not
 */
bool isInt(double value) {
    return (round(value) == value);
}



/**
 * @name isInt
 * @brief reads in input stream to determine if its contents
 *      represent an integer value
 * @param input - a reference to an input stream
 * @param value - a reference to an integer that will store:
 *          - the integer value from the input stream (if it was a valid int) OR
 *          - 0, if the input stream was not a valid integer.
 * @return bool (true if the input stream value is an integer, false if not)
 * @note The design of this function was inspired by a similar example found at:
 *      https://stackoverflow.com/questions/3403632/check-if-user-input-a-float-to-a-int-var
 */
bool isInt(istream& input, int& value) {
    bool result;
    string line;

    // If there's no valid input stream, or the resulting string is empty,
    //  then it's not an integer.
    if (!getline(input, line) || line.empty()) {
        result = false;
    } else {
        // Extract the characters from the input stream and store them
        //  in [line]. Then, inspect [line] for anything that isn't an integer.
        // If anything is found, we'll know that the input isn't an integer.
        char* nonInt;
        value = strtol(line.c_str(), &nonInt, 10);

        // If only integer(s) are found, it's an integer.
        result = (*nonInt == 0);
    }

    return result;
}



/**
 * @note isInt
 * @brief overloaded version of isInt that additionally allows
 *      for specifying the exact integer expected
 * @param input - a reference to an input stream
 * @param value - a reference to an integer that will store:
 *          - the integer value from the input stream (if it was a valid int) OR
 *          - 0, if the input stream was not a valid integer.
 * @param number - the exact number expected
 * @return bool (true if the input stream value is an integer, false if not)
 */
bool isInt(istream& input, int& value, int number) {
    return isInt(input, value) && value == number;
}



/**
 * @name isValidInt
 * @brief reads an input stream to determine if its contents
 *      represent an integer value >= a specified minimum value.
 * @param input - a reference to an input stream
 * @param value - a reference to an integer that will store:
 *          - the integer value from the input stream (if it was a valid int) OR
 *          - 0, if the input stream was not a valid integer.
 * @param min - the minimum value allowed in order to be valid
 * @return bool (true if the input stream value is an integer, false if not)
 */
bool isValidInt(istream& input, int& value, int min) {
    return (isInt(input, value)) && (value >= min);
}




/**
 * @name isValidInt
 * @brief overloaded version of isValidInt that additionally allows
 *      for specifying a maximum value allowed
 * @param input - a reference to an input stream
 * @param value - a reference to an integer that will store:
 *          - the integer value from the input stream (if it was a valid int) OR
 *          - 0, if the input stream was not a valid integer.
 * @param min - the minimum value allowed in order to be valid
 * @param max - the maximum value allowed in order to be valid
 * @return bool (true if the input stream value is an integer, false if not)
 */
bool isValidInt(istream& input, int& value, int min, int max) {
    return (isInt(input, value)) && (value >= min) && (value <= max);
}



/**
 * @name getValidInt
 * @brief Retrieves user's input and, if the response is a
 *      valid integer ( >= [min] and <= INT_MAX, the integer is returned.
 * @param min - the minimum value allowed in order to be valid
 * @param max - the maximum value allowed in order to be valid
 * @return int (once valid input is provided)
 */
int getValidInt(int min) {
    int choice;

    // use input validation to ensure the value is within range
    while (!isValidInt(std::cin, choice, min, INT_MAX)) {
        std::cout << "Please choose a number from " << min << " through " << INT_MAX << ": ";
    }

    return choice;
}



/**
 * @name getValidInt
 * @brief overloaded version of getValidInt that additionally allows
 *      for specifying a maximum value allowed
 * @param min - the minimum value allowed in order to be valid
 * @param max - the maximum value allowed in order to be valid
 * @return int (once valid input is provided)
 */
int getValidInt(int min, int max) {
    int choice;

    // use input validation to ensure the value is within range
    while (!isValidInt(std::cin, choice, min, max)) {
        std::cout << "Please choose a number from " << min << " through " << max << ": ";
    }

    return choice;
}



/**
 * @name getValidInt
 * @brief overloaded version of getValidInt that additionally allows
 *      for specifying a prompt to display before retrieving input
 * @param min - the minimum value allowed in order to be valid
 * @param max - the maximum value allowed in order to be valid
 * @param prompt - the prompt to display to the user
 * @return int (once valid input is provided)
 */
int getValidInt(int min, int max, string prompt) {
    int choice;

    std::cout << prompt;

    // use input validation to ensure the value is within range
    while (!isValidInt(std::cin, choice, min, max)) {
        std::cout << "Please choose a number from " << min << " through " << max << ": ";
    }

    return choice;
}




/**
 * @brief (optionally) presents a prompt to the user and a simple boolean
 *  option menu and return the boolean value associated w/ the user's response.
 * @param prompt
 * @return
 */
bool getValidBool(string prompt, string yesListing, string noListing) {
    int choice = 0;
    std::vector<string>boolOptions = {yesListing, noListing};

    choice = getValidInt(1, 2, getMenu(boolOptions, true, prompt));

    return (choice == 1);
}




/**
 * @name randInt
 * @brief returns a random integer within a specified range
 * @param min - the lowest number that the random number could be
 * @param max - the highest number that the random number could be
 * @return - int (a random integer such that min <= randInt <= max)
 * @note this function expects srand to have previously been seeded
 */
int randInt(int min, int max) {
    if (max > min) {
        return min + (rand() % static_cast<int>(max - min + 1));
    }

    return min;
}



/**
 * @name getEnter
 * @brief requires the user to press enter before continuing
 * @return void
 */
void getEnter() {
    std::cout << "\nPress [Enter] to continue...";
    std::cin.ignore(1000, '\n');
}



/**
 * @name getEnter
 * @brief overloaded version of getEnter that additionally
 *      allows for specifying a prompt to display to the user
 *      before requiring the user to press [enter]
 * @param prompt
 * @return void
 */
void getEnter(string prompt) {
    std::cout << prompt;
    std::cin.ignore(1000, '\n');
}



/**
 * @name clearScreen
 * @brief clears the console screen
 * @note This bit of code was taken from the instructor's
 *      response to a quiestion on Piazza at:
 *      https://piazza.com/class/jc25x89fowe5q4?cid=51
 * @param none
 * @return void
 */
void clearScreen(string content) {
    std::cout << "\033[2J\033[1;1H";

    if (!content.empty()) {
        std::cout << content << std::endl;
    }
}



/**
 * @name pluralize
 * @brief returns the pluralized version of a word, without
 *      modifying the original word.
 * @note this function doesn't cover every single word in the english
 *      language, but it does cover most of them, and protection for
 *      edge cases can be added as needed.
 * @param word - the word to pluralize.
 * @return string - the pluralized version of the word.
 */
std::string pluralize(std::string word) {
    string pluralWord;
    unsigned long long int len = word.length();

    char c1 = word[len - 1];    // the last char in the word
    char c2 = word[len - 2];    // the 2nd-to-last char in the word
    char c3 = word[len - 3];    // the 3rd-to-last char in the word

    if (c1 == 'y' && c2 != 'e') {
        // word ends in y (and not ey) - remove last letter and add ies to end
        pluralWord = word.substr(0, len - 1) + "ies";
    } else if ((c2 == 's' && (c1 == 's' || c1 == 'h')) || (c1 == 's' && c2 == 'c') || (c1 == 's' || c1 == 'x' || c1 == 'z')) {
        // word ends in: ss, sh, ch, s, x, or z - add es to the end
        if (word == "ox") {
            pluralWord = "oxen";
        } else {
            pluralWord = word + "es";
        }
    } else if (c1 == 'f') {
        // word ends in f - remove last letter and add "ves" to end
        pluralWord = word.substr(0, len - 1) + "ves";
    } else if (c1 == 'e' && c2 == 'f' && c3 != 'f') {
        // word ends in fe - remove the last 2 letters and add "ves" to end
        pluralWord = word.substr(0, len - 2) + "ves";
    } else {
        // word doesn't meed any of the above criteria - add s to end
        pluralWord = word + "s";
    }

    return pluralWord;
}



/**
 * @name pluralizeIf
 * @brief pluralizes a word, if the count > 1
 * @param word - a string to pluralize (potentially)
 * @param count - the number of items to consider
 * @return string:
 *      if count = 0, an empty string
 *      if count = 1, the singular word
 *      if count > 1, the pluralized word
 */
string pluralizeIf(string word, int count) {
    if (count != 1) {
        return pluralize(word);
    }

    return word;
}



/**
 * @name capitalize
 * @brief capitalizes the first letter of a word
 * @param word - the word to capitalize
 * @return the word with a capital first letter
 */
string capitalize(string word) {
    string capWord = word;
    capWord[0] = toupper(capWord[0]);
    return capWord;
}



/**
 * @name randomLineFromFile
 * @brief reads through a file (if possible), and
 *      retrieves a random line from that file.
 * @param fileName
 * @return string - a line from the file.
 */
string randomLineFromFile(string fileName) {
    std::ifstream in;
    string line;
    std::vector<string>lines;
    int randLine = 0;

    in.open(fileName);

    if (in.good()) {
        while(getline(in, line)) {
            lines.push_back(line);

            randLine = randInt(0, lines.size() - 1);
        }
    }

    return lines.at(randLine);
}



/**
 * @name inColor
 * @brief returns a string formatted to be displayed in a particular color & style in the terminal
 * @param content - the original string to format
 * @param foreGround - the foreground color to display the string in
 * @param backGround - the background color to display the string in
 * @param format - the format attribute to modify
 * @return string - the formatted (colored) string
 * @note The inspiration to create this function came from the following source:
 *  https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
 */
string inColor(const string content, Color foreGround, Color backGround, ColorFormat format) {
    string fgColor, bgColor, formatSet, formatReset;

    // get the foreground ansi color code
    switch (foreGround) {
        case DEFAULT_COLOR:
            fgColor = "39";
            break;
        case BLACK:
            fgColor = "30";
            break;
        case RED:
            fgColor = "31";
            break;
        case GREEN:
            fgColor = "32";
            break;
        case YELLOW:
            fgColor = "33";
            break;
        case BLUE:
            fgColor = "34";
            break;
        case MAGENTA:
            fgColor = "35";
            break;
        case CYAN:
            fgColor = "36";
            break;
        case WHITE:
            fgColor = "97";
            break;
        case GREY:
            fgColor = "37";
            break;
        case INVISIBLE:
            fgColor = "";
            break;
    }

    // get the background ansi color code
    switch (backGround) {
        case DEFAULT_COLOR:
            bgColor = "49";
            break;
        case BLACK:
            bgColor = "40";
            break;
        case RED:
            bgColor = "41";
            break;
        case GREEN:
            bgColor = "42";
            break;
        case YELLOW:
            bgColor = "43";
            break;
        case BLUE:
            bgColor = "44";
            break;
        case MAGENTA:
            bgColor = "45";
            break;
        case CYAN:
            bgColor = "46";
            break;
        case WHITE:
            bgColor = "107";
            break;
        case GREY:
            bgColor = "47";
            break;
        case INVISIBLE:
            bgColor = "";
            break;
    }

    // get the formatting style
    switch (format) {
        case DEFAULT_FORMAT:
            formatSet = "0";
            formatReset = "0";
            break;
        case BOLD:
            formatSet = "1";
            formatReset = "21";
            break;
        case DIM:
            formatSet = "2";
            formatReset = "22";
            break;
        case UNDERLINED:
            formatSet = "3";
            formatReset = "24";
            break;
        case BLINK:
            formatSet = "5";
            formatReset = "25";
            break;
        case REVERSE:
            formatSet = "7";
            formatReset = "27";
            break;
        case HIDDEN:
            formatSet = "8";
            formatReset = "28";
            break;
    }

    // wrap the content in the ansi color declaration and return the wrapped content
//    return "\033[" + formatSet + ";" + fgColor + ";" + bgColor + "m" + content + "\033[" + formatReset + "m";
    return "\033[" + formatSet + ";" + fgColor + ";" + bgColor + "m" + content + "\033[0m";
}


/**
 * @name showPos
 * @brief similar to showPos, but instead of affecting output stream, it returns a string prepended w/ a
 *  positive or negative (unless the value is 0)
 * @param value - the value to prepend the sign to
 * @param showColored - boolean indicator as to whether to string should be returned in a colored format
 * @return string
 */
string showPos(int value, string append, bool showColored) {
    string sign = (value > 0) ? "+" : "";
    sign += std::to_string(value) + append;

    if (showColored) {
        if (value > 0) {
            sign = inColor(sign, GREEN);
        } else if (value < 0) {
            sign = inColor(sign, RED);
        }
    }

    return sign;
}



/**
 * @name showPos
 * @brief similar to showPos, but instead of affecting output stream, it returns a string prepended w/ a
 *  positive or negative (unless the value is 0)
 * @param value - the value to prepend the sign to
 * @param showColored - boolean indicator as to whether to string should be returned in a colored format
 * @return string
 */
string showPos(double value, string append, bool showColored) {
    string sign = (value > 0) ? "+" : "";
    sign += std::to_string(value) + append;

    if (showColored) {
        if (value > 0) {
            sign = inColor(sign, GREEN);
        } else if (value < 0) {
            sign = inColor(sign, RED);
        }
    }

    return sign;
}


/**
 * @name wrap
 * @brief wraps a string in another string
 * @param content - the string to wrap
 * @param wrapper - the wrapper string
 * @param padding - the space padding between the wrapper & the content
 * @return string - the resulting string
 */
string wrap(string content, string wrapper, size_t padding) {
    string padder = string(padding, ' ');
    return wrapper + padder + content + padder + wrapper;
}


/**
 * @name showHeading
 * @brief common wrapper for headings
 * @param content - the string to display as a header
 * @return string - a header style string
 */
string showHeading(string content, Color color) {
    return inColor(wrap(content, "-----", 3) + "\n", color, DEFAULT_COLOR, BOLD);
}


/**
 * @brief repeat
 * @param content - the string to repeat
 * @param times - the number of times to repeat the string
 * @return string - the resulting string
 */
string repeat(string content, int times) {
    string result;

    for (int i = 0; i < times; i++) {
        result += content;
    }

    return result;
}

