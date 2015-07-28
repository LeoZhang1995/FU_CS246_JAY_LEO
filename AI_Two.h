//
//  AI_Two.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__AI_Two__
#define __Chess_Project__AI_Two__

#include <stdio.h>
#include "Move.h"
#include "Player.h"

class AI_Two:public Player{
public:
    void Make_move(Move A_Move);
    void Suggest_move();
    AI_Two();
};

#endif /* defined(__Chess_Project__AI_Two__) */
