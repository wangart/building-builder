//
//  Res.h
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Res__
#define __bb3k__Res__

#include <stdio.h>
#include "Ownable.h"
class Player;

class Res : public Ownable{
    int cost;
public:
    void landOn(Player* p);
    Res(std::string name, int index);
    void ownableMortage(Player *p);
    
    int  getWorth();
    int  getPay();
    void mortgageBuild();
    void unmortgageBuild();
    int getNumImp();
    void reset();

};
#endif /* defined(__bb3k__Res__) */
