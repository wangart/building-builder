//
//  PC.cpp
//  bb3k
//
//  Created by Doris Wong on 27/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "PC.h"
#include <cstring>
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Ownable.h"
using namespace std;


PC::PC(char c, Board * myBoard, int index): Player(c, myBoard, index){
    noMoney = false;
}

bool PC::decideBuy(int cost ){
   if (wallet > cost + 100)
       return true;
    else
        return false;
}


int PC::decideTims(){
    if (wallet > 300)
        return 1;   //pay to leave
    
    else if(theBoard->hasCup(this))
        return 3;   //use cup
    
    else
        return 2;   //roll dice
}

int PC::decideBuild(int cost ){
    if (wallet > cost)
        return 1;
    else
        return 0;
}


int PC::decideTims2(){
    if(theBoard->hasCup(this))
        return 2;   //use cup
    
    else 
        return 1;   //pay to leave
    

}

int PC::decideTuition(){
    
    if (tenPercent() > 300)
        return 2;       //pay 10%
    else
        return 1;       //pay $300 
}

bool PC::decidePay(){
    char answer;
    cout << "Do you want to pay?" << endl;
    cout << "Enter 'y' for yes, 'n' for no." << endl;
    cin >> answer;
    
    if (answer == 'y')
        return true;
    else
        return false;
}

void PC::decideNoMoney(){
    declareBankcrupt();
}

void PC::decideMortage(){
    bool hasProperty = false;
    int answer = 0;
    for (int i = 0; i < 40; i++){
        if (property[i] == 1){
            hasProperty = true;
            answer = i;
            break;
        }
    }
        
    if (hasProperty)
        dynamic_cast <Ownable *> (theBoard->squareAt(answer))->mortgageBuild();
    
    else
        declareBankcrupt();
}


bool PC::decideTrade(int rbuild, int rcash, int gbuild, int gcash){
    return false;
}

void PC::decideMove(bool test){
    int steps = 0;
    
    while (getDoubleCount() < 3){
        
        steps = theBoard->roll(false);
        if (getTimRound() != -1){
            theBoard->squareAt(10)->landOn(this);
        }
        
        else{
            
            
            if (getDoubleCount() == 2 && theBoard->doubleRoll()){
                toTims();
                break;
            }
            
            else{
                cout << "Player " << getName() << ":" << endl;
                cout << "You rolled " << steps << endl;
                
                
                notifyLoc(steps);
                theBoard->squareAt(getLoc())->landOn(this);
                if (!theBoard->doubleRoll())
                    break;
                
                
            }
            
            if (theBoard->doubleRoll())
                setDoubleCount(getDoubleCount() + 1);
            
            else
                break;
        }
    }
    
    setDoubleCount(0);
    setLastRolled(steps);
    if (noMoney == true){
        declareBankcrupt();
    } else {
        theBoard->nextPlayer();
    }
}

int PC::decideSell (int index){
    return 0;
}


