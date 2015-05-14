//
//  Dice.h
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__Dice__
#define __bb3k__Dice__

#include <stdio.h>


class Dice{
public:
    int faceVal1;
    int faceVal2;
    
public:
    int roll();
    bool doubleRoll();
    Dice();
    
};



#endif /* defined(__bb3k__Dice__) */
