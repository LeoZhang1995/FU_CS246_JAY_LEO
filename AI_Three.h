//
//  AI_Three.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__AI_Three__
#define __Chess_Project__AI_Three__

#include <stdio.h>
#include "Move.h"
#include "Player.h"

class AI_Three:public Player{
public:
    void Make_move(Move A_Move);
    void Suggest_move();
    AI_Three();
};

#endif /* defined(__Chess_Project__AI_Three__) */
