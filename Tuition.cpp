//
//  Tuition.cpp
//  bb3k
//
//  Created by Doris Wong on 23/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Tuition.h"
#include "Player.h"
#include <string>


void Tuition::landOn(Player* p){
    int decision = p->decideTuition();
    if (decision == 1){     //pay 300
        p->notifyMoney(-300);
    }
    else if (decision == 2){    //pay 10% of total worth
        p->notifyMoney (p->tenPercent());
    }
}

std::string Tuition::getName(){
    return "";
}

int Tuition::getNumImp(){
    return 0;
}

std::string Tuition::getOwner(){
    return "";
}