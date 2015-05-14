//
//  Slc.cpp
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Slc.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

void Slc::landOn(Player* p){
    int num = rand() % 24 + 1;
    cout << "You landed on SLC" << endl;
    
    if (p->canGetCup()){
        int cupNum = rand()%100 + 1;
        
        if (cupNum == 1){
            p->getCup();
            cout << "You get a roll-up-the-rum cup!" << endl;
            return;
        }
    }
    
    if (num == 1){      //Advance to collect OSAP
        cout << "Wow you are advnaced to collect OSAP" << endl;
        p->collectOsap();
    }
    
    else if (num == 2){     //Go to DC Tim Line
        cout << "Sorry you are sent to DC Tim Line" << endl;
        p->toTims();
        p->setTimRound(1);
    }
    
    else if (num >= 3 && num <= 5){     // Back 3
        cout << "You move back 3 steps" << endl;
        p->notifyLoc(-3);
    }
    
    else if (num >= 6 && num <= 9){     // Back 2
        cout << "You move back 2 steps" << endl;
        p->notifyLoc(-2);
    }
    
    else if (num >= 10 && num <= 13){   // Back 1
        cout << "You move back 1 step" << endl;
        p->notifyLoc(-1);
    }
    
    else if (num >= 14 && num <= 16){   //Forward 1
        cout << "You move forward 1 step" << endl;
        p->notifyLoc(1);
    }
    
    else if (num >= 17 && num <= 20){   //Forward 2
        cout << "You move forward 2 steps" << endl;
        p->notifyLoc(2);
    }
    
    else if (num >= 21 && num <= 24){   //Forward 3
        cout << "You move forward 3 steps" << endl;
        p->notifyLoc(3);
    }
}

std::string Slc::getOwner(){
    return "";
}

string Slc::getName(){
    return "" ;
}
int Slc::getNumImp(){
    return 0;
}