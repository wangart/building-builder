//
//  Player.h
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Player__
#define __bb3k__Player__

#include <stdio.h>
#include "Square.h"
#include <string>
class Board;

class Player{
protected:
    bool hasRolled;
    char name;
    int doubleCount;
    Board * theBoard;
    int timRound;               // counts the # of round the player has been in Tims Line,
                                // =-1 if the player only pass by Tims,
    int numCups;
    int lastRolled;
    int wallet;
    int property [40];
    int numProperty;
    int loc;
    int myIndex;
    bool noMoney;
public:
    Player(char c, Board * myBoard, int index);
    void notifyLoc(int);
    void notifyMoney(int);
    int getWallet();
    void notifyAddProperty(int);
    void notifyRemoveProperty(int);
    int resNum();
    int gymNum();
    bool virtual decideBuy(int) = 0;
    int virtual decideBuild(int) = 0;
    int virtual decideSell(int) = 0;
    bool virtual decidePay() = 0;
    int virtual decideTims() = 0;       // return 1 if pay to leave
                                        // return 2 if roll dice
                                        // return 3 if use cup
    
    int virtual decideTims2() = 0;      // return 1 if pay to leave
                                        // return 2 if use cup
    
    int virtual decideTuition() = 0;    //return 1 if pay $300
                                        // return 2 if pay 10% of total worth
    
    int tenPercent();                   //return 10% of the players total worth (including savings,
                                        //printed prices of all buildings you own, and costs of each improvement)
    
    void toTims();                      // set location to DCTimsLine
    
    void collectOsap();                 // set location to OSAP and collect $
    
    void useCup();
    int getLastRolled();
    int getTimRound();
    void setTimRound(int);
    void setLastRolled(int);
    int getLoc();
    void setDoubleCount(int);
    int getDoubleCount();
    char getName();
    void virtual decideMortage() = 0;
    void virtual decideNoMoney() = 0;   //not enough money to pay
                                        // decide bankrupt or try to mortage
    bool virtual decideTrade(int, int, int, int) = 0;
    void declareBankcrupt();
    
    void trade (Player* , std::string, int, std::string, int);
    
    void printAssets();
    
    void virtual decideMove(bool) = 0;
    
    void canBuild();
    int nameToIndex(std::string);
    void getCup();
    
    bool canGetCup();
    
    void updateIndex(int);
    
    bool hasPropertyi(int);
    
    void setLoc(int);
    
    virtual ~Player();
    
    
};

#endif /* defined(__bb3k__Player__) */
