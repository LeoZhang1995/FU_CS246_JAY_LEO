//
//  AI_One.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__AI_One__
#define __Chess_Project__AI_One__

#include <stdio.h>
#include "Move.h"
#include "Board.h"

class AI_One:public Player{
protected:
    std::string Side;
    float Score;
    Board *b;
public:
    void Make_Move(Move *A_Move);
    void IncreaseScore(float point);
    float GetScore();
    std::string GetSide();
    Move** Available_Move(std::string position);
    AI_One(std::string side, Board *b);
};

#endif /* defined(__Chess_Project__AI_One__) */
