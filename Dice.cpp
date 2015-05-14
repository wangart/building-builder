//
//  Dice.cpp
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Dice.h"
#include <stdlib.h>

Dice::Dice(){
    faceVal1 = 0;
    faceVal2 = 0;
    
}

int Dice::roll(){
    faceVal1 = rand()% 6 + 1;
    faceVal2 = rand()% 6 + 1;
    return (faceVal1 + faceVal2);
}

bool Dice::doubleRoll(){
    return (faceVal1 == faceVal2);
}