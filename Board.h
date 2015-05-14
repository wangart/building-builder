//
//  Board.h
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Board__
#define __bb3k__Board__
#define MAXPLAYER  6
#define MAXCUPS 4


#include <stdio.h>
#include "Square.h"
#include "printBoard.h"
#include <string>
class Player;

class Board{
    int playerTurn;
    int numPlayers;
    Player* thePlayers[MAXPLAYER];
    Player* theCups [MAXCUPS];
    int diceVal1;
    int diceVal2;
    Square *theBoard [40];
    char availableChar[8];
    int numCup;
    
public:
    printBoard pB;
    Board();
    char getWinner();
    void addHuman(char c);
    void addPC();
    void removePlayer(int index);
    int getPlayerTurn();
    int getNumPlayer();
    Player* getPlayer(int index);
    int roll(bool test);
    bool doubleRoll();
    void nextPlayer();
    Square* squareAt(int index);
    bool hasCup(Player *p);
    void updateCup (Player *p);
    void printAvailableChar();
    int getNumCups();
    void updateCups(Player *p);
    void save (std::string filename);
    void transferAssets(Player* from, Player* to);
    Player* playerFind(char c);
    void load(std::string file);
    
    ~Board();
};

#endif /* defined(__bb3k__Board__) */
