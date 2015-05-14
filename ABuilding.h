//
//  ABuilding.h
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__ABuilding__
#define __bb3k__ABuilding__

#include <stdio.h>
#include "Ownable.h"
#include "Player.h"
#include "Board.h"

class ABuilding : public Ownable{
    int pCost;
    bool monopoly;
    int buildings;
    int tuition0;
    int tuition1;
    int tuition2;
    int tuition3;
    int tuition4;
    int tuition5;
    Board *theBoard;
    ABuilding *neighbour1;
    ABuilding *neighbour2;
public:
    int iCost;
    void landOn(Player* p);
    int getPay();
    int getWorth();
    void mortgageBuild();
    void unmortgageBuild();
    void improve(int n);
    void addBuilding(int n);
    void getBuildings();
    ABuilding(std::string name, int index, int iCost, int pCost, int izero, int ione, int itwo, int ithree, int ifour, int ifive,Board *bord);
    std::string getName();
    int getNumImp();
    void reset();
    int getICost();
};
#endif /* defined(__bb3k__ABuilding__) */
