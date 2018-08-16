/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Bookie.cpp is the class implementation
**  file for the Bookie class. This file contains
**  definitions for the member functions of the Bookie class.
**********************************************************/

#include "Bookie.hpp"
#include "Alien.hpp"
#include "Island.hpp"
#include "Game.hpp"

using std::to_string;
using std::cout;
using std::endl;


/**
 * @name Bookie
 * @brief Bookie class constructor
 * @param none
 * @return none
 */
Bookie::Bookie() {
    this->symbol = "B";
    this->earthlingType = BOOKIE;
    this->name = "Bookie";
    this->color = BLACK;
    this->backColor = WHITE;
}



/**
 * @name ~Bookie
 * @brief Bookie class destructor
 * @param none
 * @return none
 */
Bookie::~Bookie() {

}



/**
 * @brief interacts with the bookie
 * @param actor - the Element interacting w/ the bookie
 * @note only Aliens can interact w/ the bookie
 * @return void
 */
void Bookie::interact(Element* actor) {
    // the bookie tries to get you to gamble your money OR
    //   if you have no money, your health

    // health bets require more riskiness than money
    if (actor != nullptr && actor->getElementType() == ALIEN) {
        string comment;

        makeComment(showHeading("Bookie", BLUE), false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);

        if (interactionCount == 0) {
            comment = "Hey! Hey! Hey! You wanna get rich?";
            comment += "\nThink about how fast you could get off this island.";

        } else {
            comment = "Boy am I glad to see you again!";
        }

        comment += "\n\nI\'ll make you a deal...";



        makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);


        bargain1(actor);

//        int bargain = randInt(1, 3);
//
//        // randomly select a bargain for the bookie to offer
//        if (bargain == 1) {
//            bargain1(actor);
//        } else if (bargain == 2) {
//            bargain2(actor);
//        } else {
//            bargain3(actor);
//        }


        interactionCount += 1;
    }
}



/**
 * @name move
 * @brief moves the bookie
 * @param (not implemented here, expects nullptr)
 * @return bool - true
 */
bool Bookie::move() {
    Space* prevSpace = space;

    // the bookie moves randomly around w/ no particular purpose. In fact, often he doesn't move at all.
    if (randInt(1, 3) > 2) {
        int moveDir = randInt(1,4);

        if (moveDir == 1 && space->getTop() != nullptr && space->getTop()->getOccupiedState() == UNOCCUPIED) {
            space = space->getTop();
        } else if (moveDir == 2 && space->getBottom() != nullptr && space->getBottom()->getOccupiedState() == UNOCCUPIED) {
            space = space->getBottom();
        } else if (moveDir == 3 && space->getLeft() != nullptr && space->getLeft()->getOccupiedState() == UNOCCUPIED) {
            space = space->getLeft();
        } else if (moveDir == 4 && space->getRight() != nullptr && space->getRight()->getOccupiedState() == UNOCCUPIED) {
            space = space->getRight();
        }

        if (space != prevSpace) {
            space->setElement(this);
            space->setOccupiedState(INACCESSIBLE);
            prevSpace->setOccupiedState(UNOCCUPIED);
            prevSpace->setElement(nullptr);
        }
    }

    return true;
}




/**
 * @name bargain1
 * @brief one of the bargains that the bookie tries to make with you
 * @param none
 * @return void
 */
void Bookie::bargain1(Element* actor) {
    // rock-paper-scissors
    auto* alien = dynamic_cast<Alien*>(actor);
    int cost = randInt(2, 4);
    int payout = cost * 2;
    BargainOutcome outcome = NO_OUTCOME;

    string comment;
    std::vector<string>opts = {"Rock", "Paper", "Scissors"};

    comment = "What do you say we play a game of rock-paper-scissors?";
    comment += "\nIt\'ll only cost you $" + to_string(cost) + ", ";
    comment += "but if you win, I\'ll pay you $" + to_string(payout) + ".";

    makeComment(comment, true, BLUE);

    if (getValidBool("Play Rock-Paper-Scissors for $" + to_string(cost) + "?\n", "Yup", "Nope")) {
        if (alien->getCash() >= cost) {
            alien->adjustCash(0 - cost);

            int choice = getValidInt(1, 3, getMenu(opts, true, "Which do you choose?\n"));
            int bookieChoice = randInt(1, 3);

            comment = "Your choice:    " + opts[choice - 1];
            comment += "\nBookie\'s choice: " + opts[bookieChoice - 1];

            makeComment(comment, true, BLUE);


            if (choice == bookieChoice) {
                outcome = TIE;
            } else if ((choice == 1 && bookieChoice == 2) || (choice == 2 && bookieChoice == 3) || (choice == 3 && bookieChoice == 1)) {
                outcome = BOOKIE_WINS;
            } else {
                outcome = PLAYER_WINS;
            }

            if (outcome == TIE) {
                comment = "Hmmm...looks like we tied. Well, I said I'd pay you if you won.";
                comment += "\nI guess that\'s $" + to_string(cost) + " more in my pocket";
            } else if (outcome == BOOKIE_WINS) {
                comment = "Nice try! Feel free to play again anytime!";
            } else if (outcome == PLAYER_WINS) {
                comment = "What?! I can\'t believe it. Fine, here\'s your money";
                alien->adjustCash(payout);
            }

            makeComment(comment, true, BLUE);

        } else {
            comment = "Don\'t have enough cash? Well, that\'s no worry.";
            makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);
            bargain2(actor);
        }
    } else {
        comment = "Ok, fine.";
        makeComment(comment, false, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);
        bargain2(actor);
    }
}



/**
 * @name bargain2
 * @brief one of the bargains that the bookie tries to make with you
 * @param none
 * @return void
 */
void Bookie::bargain2(Element* actor) {
    auto* alien = dynamic_cast<Alien*>(actor);
    int maxEnergy = alien->getMaxEnergy();

    BargainOutcome outcome = NO_OUTCOME;

    string comment;

    comment += "\nHow about we play a different game for some energy?";
    comment += "\nI\'ll think of a number from 1-10, and you\'ll get 3 chances to guess it.";
    comment += "\nI\'m so nice I\'ll even tell you whether to guess higher or lower after each guess.";

    makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

    comment = "\nHere\'s the thing - if you guess the number, \nI\'ll reward you with an extra life, ";
    comment += "\nbut if you don\'t, I\'ll take one away...";

    makeComment(comment, true, BLUE);


    if (getValidBool("Play the number guessing game?\n", "Yup", "Nope")) {
        int bookieNumber = randInt(1, 10);

        int guesses = 0;

        while (outcome == NO_OUTCOME) {
            if (guessNumber(bookieNumber)) {
                outcome = PLAYER_WINS;
            } else {
                guesses += 1;
            }

            if (guesses >= 3) {
                outcome = BOOKIE_WINS;
            }
        }

        int lives = alien->getLivesRemaining();

        if (outcome == BOOKIE_WINS) {
            if (lives == 0) {
                comment = "Welp. It looks like that one really cost you. It was nice knowing you.";
            } else {
                comment = "Hot dog! Thanks for the energy";
            }

            makeComment(comment, true, BLUE);
            alien->adjustEnergy(0 - maxEnergy);

        } else if (outcome == PLAYER_WINS) {
            comment = "How in the world? Are you some sort of mind reader?";
            comment += "\nWell, I wasn\'t expecting that, but I\'m a man of my word.";
            comment += "\nEnjoy the extra life...and get outta here would ya...";

            makeComment(comment, true, BLUE );
            alien->setLivesRemaining(lives + 1);
        }

    } else if (space->getIsland()->getLevel() == 2 && interactionCount > 0){

        bargain3(actor);

    } else {
        comment = "Well it looks like you\'re not in the market for my services,";
        comment += "\nbut when you change your mind, you know where to find me.";
        makeComment(comment, true, BLUE);
    }
}



/**
 * @name bargain3
 * @brief one of the bargains that the bookie tries to make with you
 * @param none
 * @return void
 */
void Bookie::bargain3(Element* actor) {
    string comment;

    comment = "Alright, listen - I didn\'t wanna tell you this the first time around,";
    comment += "\nbecause I wasn\'t sure if you are you you say you are, but I\'m gonna make you";
    comment += "\nthe offer of a lifetime.";

    makeComment(comment, true, BLUE);

    comment = "I know a guy who knows a guy...long story short - I can get you your ship pieces.";
    comment += "\nBut I\'m still a gambling man, so here\'s the deal - we\'ll flip for it";
    comment += "\nYou call heads or tails while the coin is in the air.";

    makeComment(comment, true, BLUE);

    comment = "If you win, I\'ll give you all your ship pieces right here - right now.";
    comment += "\nBut, if you lose, your ship will get destoroyed and you\'ll be stuck on earth forever.";
    comment += "\nWhad\'ya say?";

    makeComment(comment, true, BLUE);

    if (getValidBool("Flip for the ship?\n", "Yup", "Nope")) {
        int result = randInt(1, 2);
        std::vector<string>opts = { "Heads", "Tails" };

        reload();
        int choice = getValidInt(1, 2, getMenu(opts, true, "\nWhat\'s the call?\n"));

        comment = "Your choice: " + opts[choice - 1];
        comment += "\nResult:      " + opts[result - 1];

        makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, true, false);

        if (choice == result) {
            comment = "\nOh my goodness! You\'ve done it. Wow, I\'m actually pretty proud of you.";
            comment += "\nWell, like I said, you won so we\'ve put your ship back together.";
            comment += "\nIt should be somewhere on this island";
            makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

            getSpace()->getIsland()->addItem({ -1, -1}, SPACESHIP, true);
            reload();

        } else {
            comment = "\nWell, my friend - I hope you like Earth, because you\'re gonna have";
            comment += "\nto get used to it. You can kiss that ship goodbye.";
            makeComment(comment, true, BLUE, DEFAULT_COLOR, DEFAULT_FORMAT, false, true);

            // game over
            getSpace()->getIsland()->getGame()->setGameOver(true);
        }
    }
}



/**
 * @name guessNumber
 * @brief prompts the player to guess the bookie's number
 * @param target - the target number to guess
 * @return bool - true if the number was guessed, false if not
 */
bool Bookie::guessNumber(int target) {
    bool correct = false;

    int guess = getValidInt(1, 10, "\nWhat\'s your guess?\n");

    if (guess < target) {
        cout << "Higher" << endl;
    } else if (guess > target) {
        cout << "Lower" << endl;
    } else {
        cout << "Bingo!" << endl;
        correct = true;
    }

    return correct;
}
