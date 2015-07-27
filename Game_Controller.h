//
//  Game_Controller.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Game_Controller__
#define __Chess_Project__Game_Controller__

#include <stdio.h>
#include "Game_Setup.h"
#include <string>

class Game_Setup;

class Game_Controller{
protected:
    Game_Setup *s;
public:
    void Interpreter(std::string A_String, std::string B_String, std::string C_String, std::string D_String);
    void Setup(Game_Setup *s);
    Game_Controller();
    ~Game_Controller();
};

#endif /* defined(__Chess_Project__Game_Controller__) */
