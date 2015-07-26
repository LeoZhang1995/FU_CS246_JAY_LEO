//
//  Chess.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Chess__
#define __Chess_Project__Chess__

#include <stdio.h>
#include "Move.h"
//#include "Board.h"

class Board;

class Chess{
protected:
    Board *b;
public:
    std::string Side;
    char Alias;
    virtual Move* Available_Move() = 0;
    std::string Position;
    Chess(std::string side, std::string position);
    void SetBoard(Board *b);
};
#endif /* defined(__Chess_Project__Chess__) */
