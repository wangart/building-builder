//
//  Ownable.h
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Ownable__
#define __bb3k__Ownable__

#include <stdio.h>
#include "Square.h"
#include "Player.h"
#include <string>

class Ownable : public Square{
protected:
    std::string name;
    bool mortgage;
    int myIndex;
    bool monopoly;
public:
    Player *owner;
    void virtual landOn(Player* p) = 0;
    int virtual getWorth() = 0;
    int virtual getPay() = 0;
    void virtual mortgageBuild() = 0;
    void virtual unmortgageBuild() = 0;
    void changeOwner(Player *);
    void updateMortage();
    std::string getOwner();
    std::string getName();
    int virtual getNumImp() = 0;
    void virtual reset() = 0;
    bool getMonopoly();
    int getMax();
    bool getMortgage();
    Player *getOwnerp();
};
#endif /* defined(__bb3k__Ownable__) */
