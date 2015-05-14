//
//  DCTimsLine.cpp
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "DCTimsLine.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"
using namespace std;



void DCTimsLine::landOn(Player* p){
    cout << "You are at DC Tims Line" << endl;
    
    if (p->getTimRound() == -1){
        return;
    }
    
    else if (p->getTimRound() < 2){
        cout << "You have been stuck here for " << p->getTimRound() << " round" << endl;
        
        int decision = p->decideTims();
        
        if (decision == 1){     //pay to leave Tims line
            p->notifyMoney(-50);
            p->setTimRound(-1);
        }
        else if (decision == 2){    //roll dice
            int d1 = rand() % 6 + 1;
            int d2 = rand() % 6 + 1;
            
            if(d1 == d2){
                cout << "You rolled a double, you can get out of DC Tims Line now" << endl;
                p->setTimRound(-1);
            }
            else{
                cout << "You are still stuck at Tims." << endl;
                p->setLastRolled (d1 + d2);
                p->setTimRound (p->getTimRound() + 1);
            }
        }
        else if (decision == 3){    // use cup
            p->useCup();
            p->setTimRound(-1);
        }
        
    }
    
    else if (p->getTimRound() >= 2){
        int decision = p->decideTims2();
        
        if (decision == 1){     //pay to leave Tims line
            p->notifyMoney(-50);
            p->setTimRound(-1);
            p->notifyLoc(p->getLastRolled());
        }
        else if (decision == 2){    // use cup
            p->useCup();
            p->setTimRound(-1);
            p->notifyLoc(p->getLastRolled());
        }
        
    }
}
std::string DCTimsLine::getOwner(){
    return "";
}

std::string DCTimsLine::getName(){
    return "";
}

int DCTimsLine::getNumImp(){
    return 0;
}