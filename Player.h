//
//  Player.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Player__
#define __Chess_Project__Player__

#include <stdio.h>
#include <string>
#include "Board.h"

class Player{
protected:
    std::string Side;
    int Score;
    Board *b;
public:
    virtual void Make_Move(Move* A_Move) = 0;
    virtual void IncreaseScore() = 0;
    virtual int GetScore() = 0;
    void Undo();
    void Surrender();
    virtual Move** Available_Move(std::string position) = 0;
};

#endif /* defined(__Chess_Project__Player__) */
