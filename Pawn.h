//
//  Pawn.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Pawn__
#define __Chess_Project__Pawn__

#include <stdio.h>
#include "Board.h"
#include <string>

class Pawn:public Chess{
protected:
    Board *b;
    std::string Side;
    char Alias;
    std::string Position;
public:
    Move Available_Move();
    Pawn(Board *b,std::string side);
};

#endif /* defined(__Chess_Project__Pawn__) */
