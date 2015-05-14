//
//  Square.h
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Square__
#define __bb3k__Square__

#include <stdio.h>
#include <string>
class Player;

class Square{
public:
    void virtual landOn(Player* p) = 0;
    virtual ~Square();
    std::string virtual getOwner() = 0;
    std::string virtual getName() = 0;
    int virtual getNumImp() = 0;
    
};
#endif /* defined(__bb3k__Square__) */
