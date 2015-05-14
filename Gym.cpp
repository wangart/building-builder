//
//  Gym.cpp
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Gym.h"
#include <string>
#include "Dice.h"
#include <stdlib.h>
#include <iostream>

void Gym::landOn(Player *p){
    if (owner == NULL){
        if(p->decideBuy(cost)){
            owner = p;
            p->notifyMoney(-cost);
            p->notifyAddProperty(myIndex);
        }
    }
    else {
        if (p != this->owner){
            std::cout << p->getName() << " must pay " << getPay() << std::endl;
            p->notifyMoney(-getPay());
            owner->notifyMoney(getPay());
        }
    }
}

void Gym::ownableMortage(Player *p){
    p->notifyMoney(cost/2);
}


int  Gym::getWorth(){
    return cost;
}

int  Gym::getPay(){
    int faceVal1 = rand()% 6 + 1;
    int faceVal2 = rand()% 6 + 1;
    return (faceVal1 + faceVal2)*(owner->gymNum());
}

void Gym:: mortgageBuild(){
    owner->notifyMoney(cost/2);
    mortgage = true;
}
void  Gym::unmortgageBuild(){
    owner->notifyMoney(-(cost/2)*1.1);
    mortgage = false;
}

int Gym::getNumImp(){
    return 0;
}

Gym::Gym(std::string name, int index){
    cost = 150;
    owner = 0;
    mortgage = false;
    this->myIndex = index;
    this->name = name;
    monopoly = false;
}

void Gym::reset(){
    owner = 0;
    mortgage = false;
}