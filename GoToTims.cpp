//
//  GoToTims.cpp
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "GoToTims.h"
#include <iostream>
using namespace std;
#include "Player.h"

void GoToTims::landOn(Player* p){
    p->toTims();
    p->setTimRound(1);
}

std::string GoToTims::getOwner(){
    return "";
}

int GoToTims::getNumImp(){
    return 0;
}

string GoToTims::getName(){
    return "";
}