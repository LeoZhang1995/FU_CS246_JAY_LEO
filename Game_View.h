//
//  Game_View.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Game_View__
#define __Chess_Project__Game_View__

#include <stdio.h>
#include <string>
#include "Game_Controller.h"

class Game_Controller;

class Game_View{
protected:
    Game_Controller *c;
public:
    virtual void Read_Command() = 0;
    virtual void Read_One_Command() = 0;
    virtual void Read_Setup() = 0;
    virtual void Setup_Done() = 0;
    virtual void Print(Chess*** Game_Board, std::string otherMessage) = 0;
    virtual void Checkmate(std::string side) = 0;
    virtual void Stalemate() = 0;
};

#endif /* defined(__Chess_Project__Game_View__) */
