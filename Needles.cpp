//
//  Needles.cpp
//  bb3k
//
//  Created by Doris Wong on 20/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Needles.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Board.h"
#include <string>
using namespace std;




void Needles::landOn(Player* p){
    int num = rand() % 18 + 1;
    
    cout << "You have landed on Needles Hall" << endl;
    
    
    if (p->canGetCup()){
        int cupNum = rand()%100 + 1;
        
        if (cupNum == 1){
            p->getCup();
            cout << "You get a roll-up-the-rum cup!" << endl;
            return;
        }
    }
    
    if (num == 1){      // -200
        cout << "You are losing $200!" << endl;
        p->notifyMoney(-200);
    }
    
    else if (num >= 2 && num <= 3){     // -100
        cout << "You are losing $100!" << endl;
        p->notifyMoney(-100);
    }
    
    else if (num >= 4 && num <= 6){     // -50
        cout << "You are losing $50!" << endl;
        p->notifyMoney(-50);
    }
    
    else if (num >= 7 && num <= 12){     // +25
        cout << "You gained $25! Congradulations!" << endl;
        p->notifyMoney(25);
    }
    
    else if (num >= 13 && num <= 15){     // +50
        cout << "You gained $50! Congradulations!" << endl;
        p->notifyMoney(50);
    }
    
    else if (num >= 16 && num <= 17){     // +100
        cout << "You gained $100! Congradulations!" << endl;
        p->notifyMoney(100);
    }
    
    else if (num == 18){     // +200
        cout << "WOW! You gained $200! Congradulations!" << endl;
        p->notifyMoney(200);
    }
    
}

std::string Needles::getOwner(){
    return "";
}

std::string Needles::getName(){
    return "";
}

int Needles::getNumImp(){
    return 0;
}