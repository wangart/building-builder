//
//  Ownable.cpp
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Ownable.h"
#include "Player.h"
#include <string>
using namespace std;

void Ownable::landOn(Player* p){
    
    
}

void Ownable::updateMortage(){
    if (mortgage == true)
        mortgage = false;
    else
        mortgage = true;
}

void Ownable::changeOwner (Player *p){
    owner = p;
}

bool Ownable::getMonopoly(){
    return monopoly;
}

string Ownable::getOwner(){
    if (owner == 0){
        return "BANK";
    }
    else
        return string(1, owner->getName());
}

Player *Ownable::getOwnerp(){
    return owner;
}

string Ownable::getName(){
    return name;
}


bool Ownable::getMortgage(){
    return mortgage;
}