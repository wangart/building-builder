//
//  Gym.h
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Gym__
#define __bb3k__Gym__

#include <stdio.h>
#include "Ownable.h"
#include "Player.h"

class Gym : public Ownable{
    int cost;
public:
    void landOn(Player* p);
    Gym(std::string name, int index);
    void ownableMortage(Player *p);
    int  getWorth();
    int  getPay();
    void  mortgageBuild();
    void  unmortgageBuild();
    int getNumImp();
    void reset();


    
};
#endif /* defined(__bb3k__Gym__) */
