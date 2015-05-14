//
//  printBoard.cpp
//  bb7000
//
//  Created by Arthur Wang on 2014-11-20.
//
//

#include "printBoard.h"
#include <iostream>
#include <fstream>
using namespace std;

printBoard::printBoard(){
    ifstream is("board.txt");
    board = new char *[56];
    for(int r = 0; r < 56 ; r++){
        board[r] = new char[90];
        for(int c = 0; c < 90; c++){
            is.get(board[r][c]);
        }
    }
}

void printBoard::addHouse(int loc){
    int d = 0;
    if(loc <= 10 && loc >= 0){
        while(board[51][81 + d - 8 * loc] == 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[51][81 + d - 8 * loc] = 'I';
    } else if (loc <= 20 && loc >= 11){
        while(board[51 - 5 * (loc-10)][1 + d] == 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[51 - 5 * (loc-10)][1 + d] = 'I';
    } else if (loc <= 30 && loc >= 21){
        while (board[1][1 + d + 8 * (loc-20)] == 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[1][1 + d + 8 * (loc-20)] = 'I';
    } else {
        while (board[1 + 5 * (loc-30)][81 + d] == 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[1 + 5 * (loc-30)][81 + d] ='I';
    }
}

void printBoard::removeHouse(int loc){
    int d = 0;
    if(loc <= 10 && loc >= 0){
        while(board[51][85 - d - 8 * loc] != 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[51][85 - d - 8 * loc] = ' ';
    } else if (loc <= 20 && loc >= 11){
        while(board[51 - 5 * (loc-10)][5 - d] != 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[51 - 5 * (loc-10)][5 - d] = ' ';
    } else if (loc <= 30 && loc >= 21){
        while (board[1][5 - d + 8 * (loc-20)] != 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[1][5 - d + 8 * (loc-20)] = ' ';
    } else {
        while (board[1 + 5 * (loc-30)][85 - d] != 'I'){
            if(d > 4){
                break;
            }
            d++;
        }
        board[1 + 5 * (loc-30)][85 - d] = ' ';
    }
}

void printBoard::setBoard(char piece, int loc, int oldloc){
    int d = 0;
    if(oldloc <= 10 && oldloc >= 0){
        while(board[54][81 + d - 8 * oldloc] != piece){
            if(d > 4){
                break;
            }
            d++;
        }
        board[54][81 + d - 8 * oldloc] = ' ';
    } else if (oldloc <= 20 && oldloc >= 11){
        while(board[54 - 5 * (oldloc-10)][1 + d] != piece){
            if(d > 4){
                break;
            }
            d++;
        }
        board[54 - 5 * (oldloc-10)][1 + d] = ' ';
    } else if (oldloc <= 30 && oldloc >= 21){
        while (board[4][1 + d + 8 * (oldloc-20)] != piece){
            if(d > 4){
                break;
            }
            d++;
        }
        board[4][1 + d + 8 * (oldloc-20)] = ' ';
    } else {
        while (board[4 + 5 * (oldloc-30)][81 + d] != piece){
            if(d > 4){
                break;
            }
            d++;
        }
        board[4 + 5 * (oldloc-30)][81 + d] =' ';
    }
    d = 0;
    if(loc <= 10 && loc >= 0){
        while(board[54][81+d - 8 * loc] != ' '){
            d++;
        }
        board[54][81 + d - 8 * loc] = piece;
    } else if (loc <= 20 && loc >= 11){
        while(board[54 - 5 * (loc-10)][1 + d] != ' '){
            d++;
        }
        board[54 - 5 * (loc-10)][1 + d] = piece;
    } else if (loc <= 30 && loc >= 21){
        while (board[4][1 + d + 8 * (loc-20)] != ' '){
            d++;
        }
        board[4][1 + d + 8 * (loc-20)] = piece;
    } else {
        while (board[4 + 5 * (loc-30)][81 + d] != ' '){
            d++;
        }
        board[4 + 5 * (loc-30)][81 + d] = piece;
    }
}



void printBoard::print(){
    for(int r = 0; r < 56 ; r++){
        for(int c = 0; c < 90; c++){
            cout << board[r][c];
        }
    }
}

printBoard::~printBoard(){
    for (int x=0;x<56;x++){
        delete [] board[x];
    }
    delete [] board;
    board = NULL;
}