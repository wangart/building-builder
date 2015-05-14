//
//  Goose.h
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Goose__
#define __bb3k__Goose__

#include <stdio.h>
#include "Square.h"
#include "Player.h"
#include <string>

class Goose : public Square{
public:
    void landOn(Player* p);
    std::string getOwner();
    std::string getName();
    int getNumImp();

};


#endif /* defined(__bb3k__Goose__) */
