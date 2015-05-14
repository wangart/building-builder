//
//  Tuition.h
//  bb3k
//
//  Created by Doris Wong on 23/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Tuition__
#define __bb3k__Tuition__

#include <stdio.h>
#include "Square.h"
#include "Player.h"
#include <string>

class Tuition : public Square{
public:
    void landOn(Player* p);
    //Tuition();
    std::string getOwner();
    std::string getName();
    int getNumImp();

};

#endif /* defined(__bb3k__Tuition__) */
