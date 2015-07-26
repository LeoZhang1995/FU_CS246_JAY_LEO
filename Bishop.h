//
//  Bishop.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Bishop__
#define __Chess_Project__Bishop__

#include <stdio.h>
#include "Board.h"
#include <string>

class Bishop:public Chess{
protected:
    Board *b;
    std::string Side;
    char Alias;
    std::string Position;
public:
    Move Available_Move();
    Bishop(Board *b, std::string side);
};

#endif /* defined(__Chess_Project__Bishop__) */
