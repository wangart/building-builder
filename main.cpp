//
//  main.cpp
//  bb3k
//
//  Created by Doris Wong on 19/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#include <stdio.h>
#include "Board.h"
#include "Player.h"
#include "printBoard.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){
    srand (time(NULL));
    bool test = false;
    Board *board = new Board();
    
    
    
   
    cout << "                                            " << endl;
    cout << "                                            " << endl;
    cout << "            *********************           " << endl;
    cout << "     **********************************     " << endl;
    cout << "********************************************" << endl;
    cout << "                                            " << endl;
    cout << "Welcome to the game of Building Builder 7000" << endl;
    cout << "                                            " << endl;
    cout << "********************************************" << endl;
    cout << "     **********************************     " << endl;
    cout << "            *********************           " << endl;
    cout << "                                            " << endl;
    cout << "                                            " << endl;
    
    
    if (argc == 2){
        std::string argcIn(argv[1]);
        if(argcIn == "-testing"){
            test = true;
        }
        
    }
    if (argc == 3){
        std::string argcIn(argv[1]);
        if (argcIn == "-load"){
            string fileName;
            fileName = argv[2];
            board->load(fileName);
        
            cout << "Saved game is loaded" << endl;
        }
        
    }
    if (argc ==4){
        std::string argcIn(argv[1]);
        std::string argcIn2(argv[2]);
        if (argcIn == "-testing" && argcIn2 == "-load"){
            string fileName;
            fileName = argv[3];
            board->load(fileName);
            test = true;
            cout << "Saved game is loaded" << endl;
        }
    }
    else {
    

        
        char c;
        cout << "Are you ready to start the game? " << endl;
        cout << "Enter 'y' for yes, 'n' for no." << endl;
        while (cin >> c){
            if (c == 'y'){
                cout << "                                            " << endl;
                cout << "What character do you want to represent player " << board->getNumPlayer() + 1 << "?" << endl;
                cout << "You can choose from:";
                board->printAvailableChar();
                cout << endl;
                cin >> c;
                board->addHuman(c);
                cout << "                                            " << endl;
                cout << "Do you want to add another human players? " << endl;
                cout << "Enter 'y' for yes, 'n' for no." << endl;
                
            }
            else
                break;
        }
        
        cout << "                                            " << endl;
        cout << "Do you want to add PC players? " << endl;
        cout << "Enter 'y' for yes, 'n' for no." << endl;
        while (cin >> c){
            cout << "                                            " << endl;
            if (c == 'y'){
                board->addPC();
                cout << "Do you want to add another PC players? " << endl;
                cout << "Enter 'y' for yes, 'n' for no." << endl;
                
            }
            else
                break;
        }
        
        while (board->getNumPlayer() < 2){
            cout << "                                            " << endl;
            cout << "You do not have enough players to start the game" << endl;
            cout << "Are you ready to start the game? " << endl;
            cout << "Enter 'y' for yes, 'n' for no." << endl;
            while (cin >> c){
                if (c == 'y'){
                    cout << "                                            " << endl;
                    cout << "What character do you want to represent player " << board->getNumPlayer() + 1 << "?" << endl;
                    cout << "You can choose from:";
                    board->printAvailableChar();
                    cout << endl;
                    cin >> c;
                    board->addHuman(c);
                    cout << "                                            " << endl;
                    cout << "Do you want to add another human players? " << endl;
                    cout << "Enter 'y' for yes, 'n' for no." << endl;
                    
                }
                else
                    break;
            }
            
            cout << "                                            " << endl;
            cout << "Do you want to add PC players? " << endl;
            cout << "Enter 'y' for yes, 'n' for no." << endl;
            while (cin >> c){
                cout << "                                            " << endl;
                if (c == 'y'){
                    board->addPC();
                    cout << "Do you want to add another PC players? " << endl;
                    cout << "Enter 'y' for yes, 'n' for no." << endl;
                    
                }
                else
                    break;
            }
        }
    }
    cout << "                                            " << endl;
    cout << "Game start" << endl;
    board->pB.print();
    
    while (true){
        if (board->getNumPlayer() == 1){
            cout << "Congrats to " << board->getWinner() << ", you are the Winner!" << endl;
        }
        //board->pB.print();
        int l_playerTurn = board->getPlayerTurn();
        Player* l_player = board->getPlayer(l_playerTurn);
        
        cout << "Player " <<l_player->getName() << " it is your turn" << endl;
        l_player->decideMove(test);
        
        }
    }
