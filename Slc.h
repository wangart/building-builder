//
//  Slc.h
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Slc__
#define __bb3k__Slc__

#include <stdio.h>
#include "Square.h"
#include "Player.h"

class Slc : public Square{
public:
    void landOn(Player* p);
    std::string getOwner();
    std::string getName();
    int getNumImp();

};

#endif /* defined(__bb3k__Slc__) */
