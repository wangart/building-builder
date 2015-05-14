//
//  ABuilding.cpp
//  bb3k
//
//  Created by Doris Wong on 24/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "ABuilding.h"
#include <iostream>
#include "Board.h"
using namespace std;


void ABuilding::landOn(Player* p){
       if (owner == NULL){
        if(p->decideBuy(pCost)){
            owner = p;
            p->notifyMoney(-pCost);
            p->notifyAddProperty(myIndex);
        }
       }
       else if(mortgage == true){
        cout << "Current Property is Mortgaged" << endl;
       }
       else {
           if (p != this->owner){
            std::cout << p->getName() << " must pay " << owner->getName() << " " << getPay() << std::endl;
            p->notifyMoney(-getPay());
            owner->notifyMoney(getPay());
        }
    }
}

void ABuilding::addBuilding(int n){
    buildings += n;
    if (n>= 0){
        for (int j = 0;j < n; j++){
            theBoard->pB.addHouse(myIndex);
        }
    }else{
        for (int j = 0;j < -n; j++){
            theBoard->pB.removeHouse(myIndex);
        }
    }
}

int ABuilding::getICost(){
    return iCost;
}

int ABuilding::getWorth(){
    return pCost + buildings * iCost;
}

void ABuilding::improve(int n){
    if (n > buildings){
        cout << "You do not have that many buildings to improve" << endl;
    } else {
        buildings += n;
        owner->notifyMoney(-iCost*n);
    }
}

void ABuilding::mortgageBuild(){
    if (mortgage){
        cout << "Building is already mortgaged" << endl;
    }else{
        if (buildings != 0){
            cout << "There are still improvements on this property! You must sell them first" << endl;
        } else {
            cout << "You have successfully mortgaged the property" << endl;
            owner->notifyMoney(pCost / 2);
            mortgage = true;
        }
    }
}

void ABuilding::unmortgageBuild(){
    if (mortgage){
        cout << "You have successfully mortgaged the property" << endl;
        owner->notifyMoney(-(pCost/2*1.1));
    } else {
        cout << "This property is not mortgaged yet" << endl;
    }
}

int ABuilding::getPay(){
    switch (buildings) {
        case 0:
            return tuition0;
            break;
        case 1:
            return tuition1;
            break;
        case 2:
            return tuition2;
            break;
        case 3:
            return tuition3;
            break;
        case 4:
            return tuition4;
            break;
        default:
            return tuition5;
            break;
    }
}

string ABuilding::getName(){
    return name;
}

int ABuilding::getNumImp(){
    return buildings;
}

ABuilding::ABuilding(std::string name, int index, int pCost, int iCost, int izero, int ione, int itwo, int ithree, int ifour, int ifive, Board *bord){
    this->pCost = pCost;
    this->iCost = iCost;
    monopoly = false;
    buildings = 0;
    tuition0 = izero;
    tuition1 = ione;
    tuition2 = itwo;
    tuition3 = ithree;
    tuition4 = ifour;
    tuition5 = ifive;
    owner = 0;
    mortgage = false;
    myIndex = index;
    this->name = name;
    theBoard = bord;
}

void ABuilding::reset(){
    monopoly = false;
    buildings = 0;
    owner = 0;
    mortgage = false;
    
}
