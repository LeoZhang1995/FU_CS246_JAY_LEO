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

class Game_View{
protected:
    Game_Controller *c;
public:
    void Read_Command();
    void Print(std::string A_String);
    Game_View();
    ~Game_View();
};

#endif /* defined(__Chess_Project__Game_View__) */
