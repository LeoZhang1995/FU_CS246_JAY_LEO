//
//  White_Block.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__White_Block__
#define __Chess_Project__White_Block__

#include <stdio.h>
#include "Board.h"
#include <string>

class White_Block:public Chess{
protected:
    Board *b;
    std::string Side;
    char Alias;
public:
    Move Available_Move();
    White_Block();
};

#endif /* defined(__Chess_Project__White_Block__) */
