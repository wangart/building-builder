//
//  DCTimsLine.h
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__DCTimsLine__
#define __bb3k__DCTimsLine__

#include <stdio.h>
#include "Square.h"
#include "Player.h"
#include <string>

class DCTimsLine : public Square{
public:
    void landOn(Player* p);
    //DCTimsLine();
    std::string getOwner();
    std::string getName();
    int getNumImp();

};

#endif /* defined(__bb3k__DCTimsLine__) */
