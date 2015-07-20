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
    void Make_Move();
    void Undo();
    void Surrender();
    Move Available_Move(std::string Position);
    Player(std::string Side,Board *b);
    ~Player();
};

#endif /* defined(__Chess_Project__Player__) */
