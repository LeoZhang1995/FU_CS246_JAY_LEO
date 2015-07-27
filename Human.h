//
//  Human.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Human__
#define __Chess_Project__Human__

#include <stdio.h>
#include "Move.h"
#include "Board.h"

class Human:public Player{
protected:
    std::string Side;
    int Score;
    Board *b;
public:
    void Make_Move(Move* A_Move);
    Move** Available_Move(std::string position);
    Human(std::string side, Board *b);
};

#endif /* defined(__Chess_Project__Human__) */
