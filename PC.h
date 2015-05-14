//
//  PC.h
//  bb3k
//
//  Created by Doris Wong on 27/11/14.
//  Copyright (c) 2014 Doris Wong. All rights reserved.
//

#ifndef __bb3k__PC__
#define __bb3k__PC__

#include <stdio.h>
#include "Player.h"
#include <string>


class PC : public Player {
public:
    PC(char, Board*, int);
    bool  decideBuy(int) ;
    int  decideBuild(int);
    bool  decidePay() ;
    int  decideTims() ;     // return 1 if pay to leave
                            // return 2 if roll dice
                            // return 3 if use cup
    
    int  decideTims2() ;    // return 1 if pay to leave
                            // return 2 if use cup
    
    int decideTuition();    //return 1 if pay $300
                            // return 2 if pay 10% of total worth
    void decideNoMoney();
    void decideMortage();
    void decideMove(bool test);
    bool decideTrade(int, int, int, int);
    int decideSell (int);
    
};
#endif /* defined(__bb3k__PC__) */
