//
//  main.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include <iostream>
#include "Game_Controller.h"
#include "AI_Four.h"
#include "Game_Controller.h"
#include "Pawn.h"
#include "AI_One.h"
#include "Game_Setup.h"
#include "Player.h"
#include "AI_Three.h"
#include "Game_View.h"
#include "Queen.h"
#include "AI_Two.h"
#include "Graphical_Display.h"
#include "Rook.h"
#include "Bishop.h"
#include "Human.h"
#include "Text_Display.h"
#include "Black_Block.h"
#include "King.h"
#include "White_Block.h"
#include "Board.h"
#include "Knight.h"
#include "Chess.h"
#include "Move.h"

int main() {
    Game_Controller *c = new Game_Controller();
    Game_View *v = new Text_Display(c);
    Game_Setup *s = new Game_Setup();
    c->Setup(s);
    s->GetBoard()->SetView(v);
    v->Read_Command();
    delete c;
}
