//
//  Player.cpp
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Player.h"
#include "Square.h"
#include "Board.h"
#include <iostream>
#include <cstring>
#include "Ownable.h"
using namespace std;


Player::Player(char c, Board * myBoard, int index){
    name = c;
    hasRolled = false;
    doubleCount = 0;
    theBoard = myBoard;
    timRound = -1 ;
    numCups = 0;
    lastRolled = 0;
    wallet = 1500;
    memset(property, 0, sizeof(property));
    numProperty = 0;
    loc = 0;    // at collect OSAP square
    myIndex = index;
    theBoard->pB.setBoard(name, 0, 0);
}

int Player::resNum(){
    int resTotal = 0;
    for(int c = 5; c <= 35 ; c += 10){
        if (property[c] == 1){
            resTotal += 1;
        }
    }
    return resTotal;
}

int Player::gymNum(){
    int gymTotal = 0;
    if (property[12] == 1){
        gymTotal+=1;
    }
    if (property[28] ==1){
        gymTotal+=1;
    }
    if (gymTotal == 1){
        return 4;
    } else {
        return 10;
    }
}

int Player::getTimRound(){
    return timRound;
}

void Player::notifyMoney(int amount){
    if (-amount > wallet ){
        noMoney = true;
    } else {
        noMoney = false;
        wallet += amount;
    }
}



void Player::setTimRound(int x){
    timRound = x;
}



int Player::getLastRolled(){
    return lastRolled;
}

void Player::setLastRolled(int x){
    lastRolled = x;
    
}

int Player::getDoubleCount(){
    return doubleCount;
}

void Player::setDoubleCount(int x){
    doubleCount = x;
}

int Player::getLoc(){
    return loc;
}

void Player::toTims(){
    theBoard->pB.setBoard(name, 10, loc);
    loc = 10;
    cout << "you are sent to DC Tims Line" << endl;
    
}

char Player::getName(){
    return name;
}

void Player::notifyLoc(int move){
   
    if ((loc + move) <= 39){
        theBoard->pB.setBoard(name, loc + move, loc);
        loc += move;
        
    }
    else{
        
        theBoard->pB.setBoard(name, loc + move - 40, loc);
        loc = (loc + move - 40);
        cout << "You collected an OSAP of $200!!!" << endl;
        wallet += 200;
    }
    
    theBoard->pB.print();
}

void Player::useCup(){
    theBoard->updateCup(this);
    numCups --;
}

void Player::collectOsap(){
    loc = 0;
    theBoard->squareAt(0)->landOn(this);
}

int Player::tenPercent(){
    int worth = 0;
    for (int c = 0; c < 40; c++){
        if (property[c] == 1){
            worth += dynamic_cast <Ownable*> (theBoard->squareAt(c))->getWorth();
        }
    }
    return 0.1 * (this->wallet + worth);
    
}

void Player::declareBankcrupt(){
    
    Ownable* temp = dynamic_cast <Ownable* > (theBoard->squareAt(loc));
    if (temp)
        theBoard->transferAssets(this, temp->owner);
    else {
        for (int i = 0; i < 40 ; i++){
            if (property[i] == 1){
                dynamic_cast <Ownable *> (theBoard->squareAt(i))->reset();
                
            }
        }
    }
    if (numCups > 0)
        useCup();
    theBoard->removePlayer(myIndex);
        
    
}

void Player::printAssets(){
    cout << "You have the following property" << endl;
    for (int i = 0 ;i < 40; i++){
        if (property[i] == 1){
            cout << theBoard->squareAt(i)->getName()<< endl;
        }
    }
    cout << "You have " << getWallet() << " dollars in your wallet" << endl;
}



void Player::notifyAddProperty(int propertyNum){
    this->property[propertyNum] = 1;
    dynamic_cast <Ownable*> (theBoard->squareAt(propertyNum))->changeOwner(this);
}

void Player::notifyRemoveProperty(int propertyNum){
    this->property[propertyNum] = 0;
}

void Player::getCup(){
    theBoard->updateCup(this);
}

bool Player::canGetCup(){
    if (theBoard->getNumCups() < 4)
        return true;
    else
        return false;
}
void Player::updateIndex(int i){
    myIndex = i;
}

int Player::getWallet(){
    return wallet;
}

int Player::nameToIndex(string bname){
    int index = -1;
    if (bname == "garbage"){
        return -1;
    }else {
    for (int c = 0; c < 40; c++){
        if (theBoard->squareAt(c)->getName() == bname){
            index = c;
        }
    }
    }
    return index;
}

void Player::trade(Player *play, std::string gbuild,int gcash, std::string rbuild, int rcash){
    int gbuildindex = nameToIndex(gbuild);
    int rbuildindex = nameToIndex(rbuild);
    if (gbuildindex == -1){
        if (play->decideTrade(gbuildindex,gcash,rbuildindex, rcash)){
            this->notifyMoney(-gcash);
            this->notifyMoney(rcash);
            if (rbuild != "garbage"){
                this->notifyAddProperty(rbuildindex);
            }
        } else {
            cout  << "Trade was not agreed to" << endl;
        }
    }else if (property[gbuildindex] == 0){
        cout << "You cannot trade property you don't own!!!";
    } else {
        if (play->decideTrade(gbuildindex,gcash,rbuildindex, rcash)){
            this->notifyMoney(-gcash);
            if (gbuild != ""){
                this->notifyRemoveProperty(gbuildindex);
            }
            this->notifyMoney(rcash);
            if (rbuild != ""){
                this->notifyAddProperty(rbuildindex);
            }
        } else {
            cout << "Trade was not agreed to" << endl;
        }
    }
}

bool Player::hasPropertyi (int i){
    if (property[i] == 1)
        return true;
    else
        return false;
}

void Player::setLoc(int i){
    theBoard->pB.setBoard(name, i, loc);
    loc = i;
}

Player::~Player(){
    
}
