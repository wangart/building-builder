//
//  Res.cpp
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Res.h"
#include <iostream>

void Res::landOn(Player* p){
    if (owner == NULL){
        if(p->decideBuy(cost)){
            owner = p;
            p->notifyMoney(-cost);
            p->notifyAddProperty(myIndex);
        }
    } else if(mortgage == true){
        std::cout << "Current Property is Mortgaged" << std::endl;
    } else {
        if (p != this->owner){
            std::cout << p->getName() << " must pay " << getPay() << std::endl;
            p->notifyMoney(-getPay());
            owner->notifyMoney(getPay());
        }
    }
}

void Res::ownableMortage(Player *p){
    p->notifyMoney(cost/2);
    mortgage = true;
}

int  Res::getWorth(){
    return cost;
}

int  Res::getPay(){
    int temp = 25;
    for (int i = 1; i < owner->resNum(); i++){
        temp = temp * 2;
    }
    return temp;
}

void Res:: mortgageBuild(){
    owner->notifyMoney(cost/2);
    mortgage = true;
}
void  Res::unmortgageBuild(){
    owner->notifyMoney(-(cost/2)*1.1);
    mortgage = false;
}

int Res::getNumImp(){
    return 0;
}

Res::Res(std::string name, int index){
    cost = 200;
    owner = 0;
    mortgage = false;
    this->myIndex = index;
    this->name = name;
    monopoly = false;
}


void Res::reset(){
    owner = 0;
    mortgage = false;
}