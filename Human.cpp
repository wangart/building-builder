//
//  Human.cpp
//  bb3k
//
//  Created by Doris Wong on 27/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Human.h"
#include <cstring>
#include <iostream>
#include "Board.h"
#include "Ownable.h"
#include "ABuilding.h"
using namespace std;

Human::Human(char c, Board * myBoard, int index): Player(c, myBoard, index){
    noMoney = false;
}

bool  Human::decideBuy(int cost){
    char answer;
    cout << "Do you want to buy this property for $" << cost << "?" << endl;
    cout << "Enter 'y' for yes, 'n' for no." << endl;
    cin >> answer;
    if (answer == 'y' && wallet > cost)
        return true;
    else if (answer == 'y'){
        cout << "You don't have enough money" << endl;
        return false;
    }
    else
        return false;
}

int Human::decideTims(){
    int answer;
    cout << "You are at DC Tims line now" << endl;
    cout << "Enter '1' if you want to pay to leave" << endl;
    cout << "Enter '2' if you want to roll dice to leave" << endl;
    cout << "Enter '3' if you want to use Roll-Up the rim cup to leave" << endl;
    cin >> answer;
    return answer;
}

bool Human::checkMonopoly(int index){
    switch (index) {
        case 1:
            if (property[3] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 3:
            if (property[1] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 6:
            if (property[8] == 1 && property[9] == 1 ){
                return true;
            } else {
                return false;
            }
            break;
        case 8:
            if (property[6] == 1 && property[9] == 1 ){
                return true;
            } else {
                return false;
            }
            break;
        case 9:
            if (property[6] == 1 && property[8] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 11:
            if (property[13] == 1 && property[14] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 13:
            if (property[11] == 1 && property[14] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 14:
            if (property[11] == 1 && property[13] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 16:
            if (property[18] == 1 && property[19] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 18:
            if (property[16] == 1 && property[19] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 19:
            if (property[18] == 1 && property[16] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 21:
            if (property[23] == 1 && property[24] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 23:
            if (property[21] == 1 && property[24] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 24:
            if (property[21] == 1 && property[23] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 26:
            if (property[27] == 1 && property[29] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 27:
            if (property[26] == 1 && property[29] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 29:
            if (property[26] == 1 && property[27] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 31:
            if (property[32] == 1 && property[34] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 32:
            if (property[31] == 1 && property[34] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 34:
            if (property[31] == 1 && property[32] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 39:
            if (property[37] == 1){
                return true;
            } else {
                return false;
            }
            break;
        case 37:
            if (property[39] == 1){
                return true;
            } else {
                return false;
            }
            break;
        default:
            return false;
            break;
    }
}

int Human::decideBuild(int index){
    if (property[index] != 1){
        cout << "You do NOT own this property!!! You cannot upgrade it!" << endl;
        return 0;
    } else if (!(this->checkMonopoly(index))){
        cout << "You do not have a monopoly of this property yet!" << endl;
        return 0;
    } else{
        int choice;
        cout << "Would you like to upgrade this property? State how many:" << endl; // make this better later
        while (cin >> choice){
            int max = (5- dynamic_cast <ABuilding *> (theBoard->squareAt(index))->getNumImp());
            if (choice <= max){
                if (choice * (dynamic_cast <ABuilding *> (theBoard->squareAt(index))->getICost()) <= wallet){
                    cout << "You have successfully purchased the upgrades" << endl;
                    this->notifyMoney(-choice*(dynamic_cast <ABuilding *> (theBoard->squareAt(index))->getICost()));
                    return choice;
                } else {
                    cout << "You do not have enough to construct so many houses"<< endl;
                    return 0;
                }
            } else {
                cout << "You can only construct a maximum of " << max << " properties" << endl;
                return 0;
            }
        }
    }
    return 0;
}

int Human::decideTims2(){
    int answer;
    cout << "You are at DC Tims line for the 3rd round" << endl;
    cout << "Enter '1' if you want to pay to leave" << endl;
    cout << "Enter '2' if you want to use Roll-Up the rim cup to leave" << endl;
    cin >> answer;
    
    return answer;
}
int Human::decideTuition(){
    int answer;
    cout << "You have to pay tuition" << endl;
    cout << "Enter '1' if you want to pay $300" << endl;
    cout << "Enter '2' if you want to pay 10% of your assets" << endl;
    cout << "10% of your assets is: $" << tenPercent() << endl;
    cin >> answer;
    
    return answer;
}

bool Human::decidePay(){
    char answer;
    cout << "Do you want to pay?" << endl;
    cout << "Enter 'y' for yes, 'n' for no." << endl;
    cin >> answer;
    
    if (answer == 'y')
        return true;
    else
        return false;
}

void Human::decideNoMoney(){
    noMoney = true;
}

void Human::decideMortage(){
    bool hasProperty = false;
    for (int i = 0; i < 40; i++){
        if (property[i] == 1){
            hasProperty = true;
            break;
        }
    }
    
    if(hasProperty){
        int answer;
        cout << "which property do you want to mortgage?" << endl;
        cout << "you have the following property" << endl;
        for (int i = 0 ;i < 40; i++){
            if (property[i] == 1){
                cout << "Property in square " << i << endl;
            }
        }
        
        cin >> answer;
        
        dynamic_cast <Ownable *> (theBoard->squareAt(answer)) -> mortgageBuild();
        
    }
    
    else {
        char answer;
        cout << "you have no property to mortage" << endl;
        cout << "Please enter 'y' to declare bankcrupt" << endl;
        cin >> answer ;
        if (answer == 'y')
            declareBankcrupt();
    }
}

bool Human::decideTrade(int rbuild,int rcash,int gbuild, int gcash){
    char choice;
    cout << "Player "<< getName()<< ", Would you like to make this trade? (y/n)" << endl;
    cin >> choice;
    if (gbuild == -1){
        if (choice == 'y'){
            if (rbuild != -1){
                notifyAddProperty(rbuild);
            }
            notifyMoney(rcash);
            notifyMoney(gcash);
            return true;
        } else {
            return false;
        }
    } else if (property[gbuild] == 0){
        cout << "You cannot trade property you do not own!";
        return false;
    }else {
        if (choice == 'y'){
            if (rbuild != -1){
                notifyAddProperty(rbuild);
                notifyRemoveProperty(gbuild);
            }
            notifyMoney(rcash);
            notifyMoney(gcash);
            return true;
        } else {
            return false;
        }
    }
}

void Human::decideMove(bool test){
    string command = "" ;
    int steps = 0;
    cout << "Enter 'help' for instructions" << endl;
    
    cin >> command;
    if ( command == "help"){
        cout << "roll: rolls the dice" << endl
        << "next: end your turn" << endl
        << "trade <name> <give> <receive>: trade another player using his character for property or money" << endl
        << "improve <property> buy/sell: attempt to buy or sell a improve for property" << endl
        << "mortgage <property>: attempts to mortgage property" << endl
        << "unmortgage <property>: attempts to unmortgage property" << endl
        << "bankrupt: player declares bankruptcy. This command is only available when a player must pay more money then they current have" << endl
        << "assets: displays the assets of the current player. Does not work if the player is deciding how to pay Tuition" << endl
        << "save <filename>: saves the current state of the game" << endl
        << "cup: use a tims cup to get out of the tims line" << endl
        << "pay: pay $50 to get out of the tims line" << endl;
        
    }
    else if (command ==  "roll"){
        if (!hasRolled){
            while (getDoubleCount() < 3){
                steps = theBoard->roll(test);
                if (getTimRound() != -1){
                    theBoard->squareAt(10)->landOn(this);
                    
                }
                else {
                    if (getDoubleCount() == 2 && theBoard->doubleRoll()){
                        toTims();
                        hasRolled =true;
                        break;
                    }
                    else{
                        cout << "You rolled " << steps << endl;
                        
                        notifyLoc(steps);
                        theBoard->squareAt(getLoc())->landOn(this);
                        
                        setLastRolled(steps);
                        hasRolled = true;
                        if (theBoard->doubleRoll()){
                            cout << "You rolled a double! You can use roll again!" << endl;
                            setDoubleCount(getDoubleCount() + 1);
                            hasRolled = false;
                            break;
                        }
                        break;
                    }
                }
                
                break;
            }
            
            setLastRolled(steps);
        } else {
            cout << "You already rolled! You cannot use this command again!" << endl;
        }
        
    }
    else if (command == "trade"){
        char name;
        cin >> name;
        string bgive = "garbage";
        int cgive = 0;
        string breceive = "garbage";
        int creceive = 0;
        char tester;
        cin.get(tester);
        if (cin.peek() > '9'){
            cin >> bgive;
        } else {
            cin >> cgive;
        }
        cin.get(tester);
        if (cin.peek() > '9'){
            cin >> breceive;
        } else {
            cin >> creceive;
        }
        Player *tradee = NULL;
        for (int c = 0 ; c < theBoard->getNumPlayer(); c++){
            if (theBoard->getPlayer(c)->getName() == name){
                tradee = theBoard->getPlayer(c);
            }
        }
        if (wallet < cgive){
            cout << "You do not have enough cash to make this trade" << endl;
        } else if (tradee == NULL){
            cout << "This player does not exist" << endl;
        } else {
            trade(tradee,bgive,cgive,breceive,creceive);
        }
    }
    else if (command == "improve"){
        string dec;
        cin >> dec;
        if (dec == "buy"){
            cout << "Enter the name of the property you would like to buy buildings" << endl;
            string prop;
            cin >> prop;
            dynamic_cast <ABuilding *> (theBoard->squareAt(nameToIndex(prop)))->addBuilding(this->decideBuild(nameToIndex(prop)));
        } else {
            cout << "Enter the name of the property you would like to sell buildings" << endl;
            string prop;
            cin >> prop;
            dynamic_cast <ABuilding *> (theBoard->squareAt(nameToIndex(prop)))->addBuilding(this->decideSell(nameToIndex(prop)));
        }
    }
                       
   else if (command == "mortgage"){
       string mort;
       cin >> mort;
       dynamic_cast <Ownable *> (theBoard->squareAt(nameToIndex(mort)))->mortgageBuild();
       
   }
   else if (command == "unmortgage"){
       string uMort;
       cin >> uMort;
       dynamic_cast <Ownable *> (theBoard->squareAt(nameToIndex(uMort)))->unmortgageBuild();
   }
   else if (command == "bankrupt"){
       cout << "Player " << getName() << " has declared Bankruptcy!" << endl;
       declareBankcrupt();
   }
   else if (command == "assets"){
       printAssets();
   }
   else if (command == "save"){
       string filename;
       cin >> filename;
       theBoard->save(filename);
       cout << "The game is saved to:" << filename << endl;
   }
   else if (command == "next"){
       if (hasRolled == false){
           cout << "You must roll before you end your turn!" << endl;
       }
       if (noMoney == false){
           setDoubleCount(0);
           theBoard->nextPlayer();
           hasRolled = false;
       } else {
           cout << "You have no money! You must either trade or mortgage property or declare bankruptcy!" << endl;
       }
   }
   else{
       cout << "Invalid Command: Please type \"help\" to see command list" << endl;
   }
   }

                       
                       
                       
int Human::decideSell(int index){
    if (property[index] != 1){
        cout << "You do NOT own this property!!! You cannot sell upgrades on this property!" << endl;
        return 0;
    }   else{
        int choice;
        cout << "Would you like to sell upgrades on this property? State how many:" << endl; // make this better later
        while (cin >> choice){
            int houses = dynamic_cast <ABuilding *> (theBoard->squareAt(index))->getNumImp();
            if (choice <= houses){
                cout << "You have successfully sold the upgrades" << endl;
                this->notifyMoney(0.5*choice*(dynamic_cast <ABuilding *> (theBoard->squareAt(index))->getICost()));
                return -choice;
            } else {
                cout << "You can only have " << houses << " upgrades" << endl;
                return 0;
            }
        }
    }
    return 0;
}
