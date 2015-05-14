//
//  Money.cpp
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Money.h"
#include "Player.h"


Money::Money(int Val): Val(Val){}
    

void Money::landOn(Player* p){
    p->notifyMoney(Val);
}

std::string Money::getOwner(){
    return "";
}

std::string Money::getName(){
    return "";
}

int Money::getNumImp(){
    return 0;
}