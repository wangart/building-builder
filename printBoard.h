//
//  printBoard.h
//  bb7000
//
//  Created by Arthur Wang on 2014-11-20.
//
//

#ifndef __bb7000__printBoard__
#define __bb7000__printBoard__
#include<iostream>

class printBoard{
    
public:
    char **board;
    printBoard();
    ~printBoard();
    void print();
    void setBoard(char piece, int loc, int oldloc);
    void addHouse(int loc);
    void removeHouse(int loc);
    
};

#endif /* defined(__bb7000__printBoard__) */
