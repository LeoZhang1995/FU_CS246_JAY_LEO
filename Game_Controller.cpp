//
//  Game_Controller.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Game_Controller.h"
#include <string>
#include <stdio.h>
using namespace std;

Game_Controller::Game_Controller() {
    this->s = NULL;
}

void Game_Controller::Interpreter(string A_String, string B_String, string C_String, string D_String) {
	if (A_String == "game") {
		s = new Game_Setup();
		s->Start_Game();
		if (B_String == "human") {
			s->p1 = new Human("White", s->b);
		} else if (B_String == "computer1") {
			s->p1 = new AI_One("White", s->b)
		}
		if (C_String == "human") {
			s->p2 = new Human("Black", s->b);
		} else if (B_String == "computer1") {
			s->p2 = new AI_One("Black", s->b)
		}
		//TODO: Other levels of AI
	} else if (A_String == "move") {
		if (s->b->Turn == 'w') {
			s->p1->Make_Move(new Move(false, B_String, C_String, NULL, false));
		} else {
			s->p2->Make_Move(new Move(false, B_String, C_String, NULL, false));
		}
	}
}
