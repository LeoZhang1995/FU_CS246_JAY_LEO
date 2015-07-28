//
//  Text_Display.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Text_Display__
#define __Chess_Project__Text_Display__

#include <stdio.h>
#include <string.h>
#include "Game_Controller.h"
#include "Game_View.h"
#include "Chess.h"

class Text_Display:public Game_View{
protected:
    Game_Controller *c;
    std::string Type1;
    std::string Type2;
public:
    void Read_Command();
    void Read_One_Command();
    void Read_Setup();
    void Setup_Done();
    void Print(Chess*** Game_Board, std::string otherMessage);
    void Checkmate(std::string side);
    Text_Display(Game_Controller *c);
};

#endif /* defined(__Chess_Project__Text_Display__) */
