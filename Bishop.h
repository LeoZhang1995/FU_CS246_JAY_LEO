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
public:
    Move Available_Move();
    Bishop();
};

#endif /* defined(__Chess_Project__Bishop__) */
