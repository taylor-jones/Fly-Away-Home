/**********************************************************
** Program Name: final project
** Author: Taylor Jones
** Date: 3/6/2018
** Description: Alien.hpp is the Alien class
**  specification file. This file contains declarations
**  for the member variables and member functions of
**  the Alien class.
**********************************************************/

#ifndef ALIEN_HPP
#define ALIEN_HPP


#include "Element.hpp"
#include "Bag.hpp"
#include "Earthling.hpp"

class Alien: public Element {
  private:
    //
    // member variables
    //
    bool backHome = false;
    int homeLevel = -1;

    int cash = 0;
    int points = 0;
    int rank = 1;
    string rankName = "Weiner";

    int maxEnergy = 100;
    int energy = 100;
    int energyMarker = 100;
    int livesRemaining = 3;
    int activeItemStepsRemaining = 0;

  private:

    std::vector<string>menuOpts;

    Bag* bag = nullptr;
    Bag* shipPieces = nullptr;
    Item* activeItem = nullptr;
    Item* nonBagItem = nullptr;
    Space* prevSpace = nullptr;
    Island* homeland = nullptr;


    //
    // member functions
    //

    int nextRankPoints();
    void depleteActiveItem();
    void checkForwardExperiences();


  public:
    // object handling
    Alien();
    explicit Alien(int homeLevel);
    ~Alien() override;
    void init();


    // getters
    int getCash() const;
    int getPoints() const;
    int getRank() const;
    int getEnergy() const;
    int getEnergyMarker() const;
    int getLivesRemaining() const;
    int getHomeLevel() const;
    int getActiveItemStepsRemaining() const;
    int getMaxEnergy() const;

    bool isAlive();
    const string &getRankName() const;
    string getOrientationString() const;
    Item* getActiveItem() const;
    Item* getNonBagItem() const;
    Space* getPrevSpace() const;
    Bag* getBag() const;
    Bag* getShipPieces() const;
    Island* getHomeland() const;



    // setters
    void setCash(int cash);
    void setPoints(int points);
    void setRank(int rankNumber);
    void setRankName(const string &rankName);
    void setBag(Bag* bag);
    void setLivesRemaining(int livesRemaining);
    void setActiveItem(Item* currentItem);
    void setEnergy(int energy);
    void setHomeLevel(int homeLevel);
    void setEnergyMarker();
    void setPrevSpace(Space* prevSpace);
    void setHomeland(Island* homeland);
    void setNonBagItem(Item* nonBagItem);
    void setMaxEnergy(int maxEnergy);

    void adjustPoints(int amount);
    void adjustCash(int amount);
    void adjustEnergy(int amount, bool bypassMax = false);
    void setActiveItemStepsRemaining(int activeItemStepsRemaining);



    // activity
    void interact(Element* actor) override;

    void experienceSpace(Direction direction = NO_DIRECTION);
    void interactWithElements(Direction direction = NO_DIRECTION);
    void interactWithEarthling(Earthling* earthling);
    void checkDropBagItem(Item* replaceWithItem = nullptr);
    void checkPickupBagItem(Item* newItem = nullptr);
    void checkUseBagItem();
    bool checkBuyMaps(int price);

    bool move(Direction direction) override;
    bool move(Space* space) override;

    void checkIfBackHome();
    void checkRestoreEnergy();
    bool checkRestoreEnergy(int price);
    void getBittenByShark();
    void eatFood(Item* food);
    bool findShipPiece(Item* piece);
    void flyHome(Item* spaceship);
    void pickupMoney(Item* money);
    void restoreEnergy();

    void printStats(bool showSurroundings = true);
    void showMenu();
    void uncoverAdjacentSpaces();

};


#endif //ALIEN_HPP
