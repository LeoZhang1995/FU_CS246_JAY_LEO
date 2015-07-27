//
//  Knight.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Knight__
#define __Chess_Project__Knight__

#include <stdio.h>
#include "Board.h"
#include <string>

class Knight:public Chess{
protected:
    Board *b;
public:
    Move** Available_Move();
    Knight(std::string side, std::string position);
    void SetBoard(Board *b);
};

#endif /* defined(__Chess_Project__Knight__) */
