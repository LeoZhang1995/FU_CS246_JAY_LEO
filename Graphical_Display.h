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

class Graphical_Display:public Game_View{
public:
    void Read_Command();
    void Print(std::string A_String);
    Graphical_Display();
    ~Graphical_Display();
};

#endif /* defined(__Chess_Project__Graphical_Display__) */
