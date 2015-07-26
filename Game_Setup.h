//
//  Game_Setup.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Game_Setup__
#define __Chess_Project__Game_Setup__

#include <stdio.h>
#include "Record.h"
#include "Player.h"

class Board;
class Record;
class Player;

class Game_Setup{
protected:
    Board *b;
    Record *r;
    Player *p1;
    Player *p2;
public:
    void Start_Game();
    void End_Game();
    void Restart_Game();
    Game_Setup();
    ~Game_Setup();
};

#endif /* defined(__Chess_Project__Game_Setup__) */
