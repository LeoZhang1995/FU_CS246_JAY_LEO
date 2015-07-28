//
//  Graphical_Display.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Graphical_Display__
#define __Chess_Project__Graphical_Display__

#include <stdio.h>
#include "Game_Controller.h"
#include "Game_View.h"
#include "Chess.h"

class Graphical_Display:public Game_View{
protected:
    Game_Controller *c;
public:
    void Read_Command();
    void Read_Setup();
    void Setup_Done();
    void Read_One_Command();
    void Checkmate(std::string side);
    void Print(Chess*** Game_Board, std::string otherMessage);
    Graphical_Display(Game_Controller *c);
    ~Graphical_Display();
};

#endif /* defined(__Chess_Project__Graphical_Display__) */
