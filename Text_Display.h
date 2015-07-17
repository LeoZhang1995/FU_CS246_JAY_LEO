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
#include "Game_Controller.h"
#include "Game_View.h"

class Text_Display:public Game_View{
public:
    void Read_Command();
    void Print(std::string A_String);
    Text_Display();
    ~Text_Display();
};

#endif /* defined(__Chess_Project__Text_Display__) */
