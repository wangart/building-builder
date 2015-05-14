//
//  Board.cpp
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include "Board.h"
#include "Slc.h"
#include "Money.h"
#include "Player.h"
#include "GoToTims.h"
#include "Goose.h"
#include "Needles.h"
#include "DCTimsLine.h"
#include "ABuilding.h"
#include "Tuition.h"
#include "Res.h"
#include "Gym.h"
#include "Human.h"
#include "PC.h"
#include <stdlib.h>
#include <cstring>
#include "iostream" 
#include <fstream>
using namespace std;



Board::Board(){
    playerTurn = 0;
    numPlayers = 0;
    memset(thePlayers, 0, sizeof(thePlayers));
    memset(theCups, 0, sizeof(theCups));
    diceVal1 = 0;
    diceVal2 = 0;
    
    
    theBoard[0] = new Money(200);
    theBoard[1] = new ABuilding("AL",1,40, 50, 2, 10, 30, 90, 160, 250,this);
    theBoard[2] = new Slc();
    theBoard[3] = new ABuilding("ML",3,60, 50, 4, 20, 60, 180, 320, 450,this); // ML
    theBoard[4] = new Tuition(); //tuition
    theBoard[5] = new Res("MKV", 5); // MKV
    theBoard[6] = new ABuilding("ECH",6,100, 50, 6, 30, 90, 270, 400, 550,this);  //ECH
    theBoard[7] = new Needles();
    theBoard[8] = new ABuilding("PAS",8,100, 50, 6, 30, 90, 270, 400, 550,this); //PAS
    theBoard[9] = new ABuilding("HH",9,120, 50, 8, 40, 100, 300, 450, 600,this);  //HH
    theBoard[10] = new DCTimsLine();
    theBoard[11] = new ABuilding("RCH",11,140, 100, 10, 50, 150, 450, 625,750,this); //RCH
    theBoard[12] = new Gym("PAC", 12);   //PAC
    theBoard[13] = new ABuilding("DWE",13,140, 100, 10, 50, 150, 450, 625,750,this); //DWE
    theBoard[14] = new ABuilding("CPH",14,160, 100, 12, 60, 180, 500, 700, 900,this); //CPH
    theBoard[15] = new Res("UWP", 15);   //UWP
    theBoard[16] = new ABuilding("LHI",16,180, 100, 14, 70, 200, 550, 750, 950,this); //LHI
    theBoard[17] = new Slc();
    theBoard[18] = new ABuilding("BMH",18,180, 100, 14, 70, 200, 550, 750, 950,this); //BMH
    theBoard[19] = new ABuilding("OPT",19,200, 100, 16, 80, 200, 600, 800, 1000,this);     //OPT
    theBoard[20] = new Goose();
    theBoard[21] = new ABuilding("EV1",21,220, 150, 18, 90, 250, 700, 875, 1050,this); //EV1
    theBoard[22] = new Needles();
    theBoard[23] = new ABuilding("EV2",23,220, 150, 18, 90, 250, 700, 875, 1050,this); //EV2;
    theBoard[24] = new ABuilding("EV3",24,240, 150, 20, 100, 300, 750, 925, 1100,this); //EV3
    theBoard[25] = new Res("V1", 25);   //V1
    theBoard[26] = new ABuilding("PHYS",26,260, 150, 22, 110, 330, 800, 975, 1150,this); //PHYS
    theBoard[27] = new ABuilding("B1",27,260, 150, 22, 110, 330, 800, 975, 1150,this); //B1
    theBoard[28] = new Gym("CIF", 28);   //CIF
    theBoard[29] = new ABuilding("B2",29,280, 150, 24, 120, 360, 850, 1025, 1200,this); //B2
    theBoard[30] = new GoToTims();
    theBoard[31] = new ABuilding("EIT",31,300, 200, 26, 130, 390, 900, 1100, 1275,this); //EIT
    theBoard[32] = new ABuilding("ESC",32,300, 200, 26, 130, 390, 900, 1100, 1275,this); //ESC
    theBoard[33] = new Slc();
    theBoard[34] = new ABuilding("C2",34,320, 200, 28, 150, 450, 1000, 1200, 1400,this); //C2
    theBoard[35] = new Res("REV", 35); //REV
    theBoard[36] = new Needles();
    theBoard[37] = new ABuilding("MC",37,350, 200, 35, 175, 500, 1100, 1300, 1500,this); //MC
    theBoard[38] = new Money(-150); //Coop fee
    theBoard[39] = new ABuilding("DC",39,400, 200, 50, 200, 600, 1400, 1700, 2000,this); //DC
    
    availableChar[0] = 'G';
    availableChar[1] = 'B';
    availableChar[2] = 'D';
    availableChar[3] = 'P';
    availableChar[4] = 'S';
    availableChar[5] = '$';
    availableChar[6] = 'L';
    availableChar[7] = 'T';
    
    
    
}


char Board::getWinner(){
    return thePlayers[0]->getName();
}

void Board::addHuman(char c){
    thePlayers[numPlayers] = new Human (c, this, numPlayers);
    for (int i = 0; i < 8; i++){
        if (availableChar[i] == c)
            availableChar[i] = '0';
    }
    numPlayers += 1;
}

void Board::addPC(){
    char c = 0;
    for (int i = 0; i < 8; i++){
        if (availableChar[i] != '0'){
            c = availableChar[i];
            break;
        }
    }
    
    thePlayers[numPlayers] = new PC (c, this, numPlayers);
    
    for (int i = 0; i < 8; i++){
        if (availableChar[i] == c)
            availableChar[i] = '0';
    }
    numPlayers += 1;
}


int Board::getPlayerTurn(){
    return playerTurn;
}

int Board::getNumPlayer(){
    return numPlayers;
}


Player* Board::getPlayer(int index){
    return thePlayers[index];
}


int Board::roll(bool test){
    if (test){
        cin >> diceVal1 >> diceVal2;
    } else {
        diceVal1 = rand()% 6 + 1;
        diceVal2 = rand()% 6 + 1;
    }
    return (diceVal1 + diceVal2);
}


bool Board::doubleRoll(){
    return (diceVal1 == diceVal2);
}

void Board::nextPlayer(){
    if (playerTurn == numPlayers - 1)
        playerTurn = 0;
    else
        playerTurn += 1;
}

void Board::removePlayer(int index){
    delete thePlayers[index];
    
    for (int i = index + 1; i < MAXPLAYER; i++){
        if (thePlayers[i] != 0)
            thePlayers[i]->updateIndex(i-1);
        thePlayers[i-1] = thePlayers[i];
    }
    thePlayers[MAXPLAYER-1] = 0;
    numPlayers -= 1;
}
Square* Board::squareAt(int index){
    return theBoard[index];
}

bool Board::hasCup(Player *p){
    for (int i = 0; i < 4; i++){
        if (theCups[i] == p)
            return true;
    }
    return false;
}

void Board::updateCup (Player *p){
    for (int i = 0; i < 4; i++){
        if (theCups[i] == p){
            theCups[i] = 0;
            return;
        }
    }
}


void Board::printAvailableChar(){
    for (int i = 0; i < 8; i++){
        if (availableChar[i] != '0')
            cout << availableChar[i] << " ";
    }
}

int Board::getNumCups(){
    return numCup;
}

void Board::updateCups(Player *p){
    for (int i = 0; i < 4; i++){
        if (theCups[i] != 0)
            theCups[i] = p;
    }
    numCup += 1;
}

void Board::save(string filename){
    
    ofstream myfile;
    myfile.open (filename.c_str());
    myfile << numPlayers << endl;

    
    for (int i = 0; i < numPlayers; i++){
        myfile << thePlayers[i]->getName() << " ";
        myfile << thePlayers[i]->getWallet() << " ";
        myfile << thePlayers[i]->getLoc() << endl;
    }
    
    
    
    myfile << theBoard[1]->getName() << " " << theBoard[1]->getOwner() << " " << theBoard[1]->getNumImp() << endl;
    myfile << theBoard[3]->getName() << " " << theBoard[3]->getOwner() << " " << theBoard[3]->getNumImp() << endl;
    myfile << theBoard[5]->getName() << " " << theBoard[5]->getOwner() << endl;
    myfile << theBoard[6]->getName() << " " << theBoard[6]->getOwner() << " " << theBoard[6]->getNumImp() << endl;
    myfile << theBoard[8]->getName() << " " << theBoard[8]->getOwner() << " " << theBoard[8]->getNumImp() << endl;
    myfile << theBoard[9]->getName() << " " << theBoard[9]->getOwner() << " " << theBoard[9]->getNumImp() << endl;
    myfile << theBoard[11]->getName() << " " << theBoard[11]->getOwner() << " " << theBoard[11]->getNumImp() << endl;
    myfile << theBoard[12]->getName() << " " << theBoard[12]->getOwner() << endl;
    myfile << theBoard[13]->getName() << " " << theBoard[13]->getOwner() << " " << theBoard[13]->getNumImp() << endl;
    myfile << theBoard[14]->getName() << " " << theBoard[14]->getOwner() << " " << theBoard[14]->getNumImp() << endl;
    myfile << theBoard[15]->getName() << " " << theBoard[15]->getOwner() << endl;
    myfile << theBoard[16]->getName() << " " << theBoard[16]->getOwner() << " " << theBoard[16]->getNumImp() << endl;
    myfile << theBoard[18]->getName() << " " << theBoard[18]->getOwner() << " " << theBoard[18]->getNumImp() << endl;
    myfile << theBoard[19]->getName() << " " << theBoard[19]->getOwner() << " " << theBoard[19]->getNumImp() << endl;
    myfile << theBoard[21]->getName() << " " << theBoard[21]->getOwner() << " " << theBoard[21]->getNumImp() << endl;
    myfile << theBoard[23]->getName() << " " << theBoard[23]->getOwner() << " " << theBoard[23]->getNumImp() << endl;
    myfile << theBoard[24]->getName() << " " << theBoard[24]->getOwner() << " " << theBoard[24]->getNumImp() << endl;
    myfile << theBoard[25]->getName() << " " << theBoard[25]->getOwner() << endl;
    myfile << theBoard[26]->getName() << " " << theBoard[26]->getOwner() << " " << theBoard[26]->getNumImp() << endl;
    myfile << theBoard[27]->getName() << " " << theBoard[27]->getOwner() << " " << theBoard[27]->getNumImp() << endl;
    myfile << theBoard[28]->getName() << " " << theBoard[28]->getOwner() << endl;
    myfile << theBoard[29]->getName() << " " << theBoard[29]->getOwner() << " " << theBoard[29]->getNumImp() << endl;
    myfile << theBoard[31]->getName() << " " << theBoard[31]->getOwner() << " " << theBoard[31]->getNumImp() << endl;
    myfile << theBoard[32]->getName() << " " << theBoard[32]->getOwner() << " " << theBoard[32]->getNumImp() << endl;
    myfile << theBoard[34]->getName() << " " << theBoard[34]->getOwner() << " " << theBoard[34]->getNumImp() << endl;
    myfile << theBoard[35]->getName() << " " << theBoard[35]->getOwner() << endl;
    myfile << theBoard[37]->getName() << " " << theBoard[37]->getOwner() << " " << theBoard[37]->getNumImp() << endl;
    myfile << theBoard[39]->getName() << " " << theBoard[39]->getOwner() << " " << theBoard[39]->getNumImp() << endl;
    
    
    
    //myfile.close();
}

void Board::transferAssets(Player *pfrom, Player *pto){
    
    
    pto->notifyMoney(pfrom->getWallet());
    for(int i = 0; i < 40; i++){
        
        if (pfrom->hasPropertyi(i)){
            
            if ((dynamic_cast<Ownable*> (theBoard[i]))->getMortgage()){
                int worth = (dynamic_cast<Ownable*> (theBoard[i]))->getWorth();
                cout << theBoard[i]->getName() << " is mortgaged." << endl;
                cout << "Do you want to pay $" << worth << " to own this building" << endl;
                cout << "Enter 'y' for yes, and 'n' for no." << endl;
                char answer;
                cin >> answer;
                if (answer == 'y'){
                    pto->notifyAddProperty(i);
                    pfrom->notifyMoney(- worth );
                    
                }
                else {
                    cout << "You decided not to pay" << endl;
                    cout << "This building is returned to the open market" << endl;
                    (dynamic_cast<Ownable*> (theBoard[i]))->reset();
                }
            }
            else{
                
                pto->notifyAddProperty(i);
            }
            
            
        }
        
    }
    
}


void Board::load(string file){
    
    ifstream save;
    save.open(file.c_str());
    
    save >> numPlayers;
    
    
    for (int c = 0; c < numPlayers; c++){
        
        char player;
        save >> player;
        
        
        int money;
        save >> money;
        
        
        int position;
        save >> position;
        int jail;
        thePlayers[c] = new Human(player,this,numPlayers);
        thePlayers[c]->updateIndex(c);
        thePlayers[c]->notifyMoney(-1500 + money);
        thePlayers[c]->setLoc(position);
        if (position == 10){
            save >> jail;
            if (jail == 1){
                save >> jail;
                thePlayers[c]->setTimRound(jail);
            }
        }
    }
    
    
    
    string prop;
    while (save >> prop){
        std::string owner;
        save >> owner;
        int houses;
        if (owner == "BANK"){
            if (!(prop == "MKV" || prop == "UWP" || prop == "V1" || prop == "REV" || prop == "PAC" || prop == "CIF")){
                save >> houses;
            }
        }
        else{
            int index = thePlayers[0]->nameToIndex(prop);
            playerFind(*owner.c_str())->notifyAddProperty(index);
            dynamic_cast <Ownable *> (theBoard[index])->changeOwner(playerFind(*owner.c_str()));
            if (!(prop == "MKV" || prop == "UWP" || prop == "V1" || prop == "REV" || prop == "PAC" || prop == "CIF")){
                save >> houses;
                dynamic_cast <ABuilding *> (theBoard[index])->addBuilding(houses);
            }
            
            
        }
    }
}


Player * Board::playerFind(char i){
    for (int c = 0; c < numPlayers; c++){
        if (thePlayers[c]->getName() == i){
            return thePlayers[c];
        }
    }
    return NULL;
}


Board::~Board(){
    for (int i = 0; i < 40; i++)
        delete theBoard[i];
    
    for (int i = 0; i < MAXPLAYER; i++)
        delete thePlayers[i];
}

