//
//  AI_Four.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__AI_Four__
#define __Chess_Project__AI_Four__

#include <stdio.h>
#include "Move.h"

class AI_Four{
public:
    void Make_move(Move A_Move);
    void Suggest_move();
    AI_Four();
};

#endif /* defined(__Chess_Project__AI_Four__) */
