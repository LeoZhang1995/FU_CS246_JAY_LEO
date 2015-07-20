//
//  Rook.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Rook__
#define __Chess_Project__Rook__

#include <stdio.h>
#include "Board.h"
#include <string>

class Rook:public Chess{
protected:
    Board *b;
    std::string Side;
    char Alias;
    std::string Position;
public:
    Move Available_Move();
    Rook(Board *b,std::string side);
};

#endif /* defined(__Chess_Project__Rook__) */
