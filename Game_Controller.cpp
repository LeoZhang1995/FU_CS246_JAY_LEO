//
//  Game_Controller.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Game_Controller.h"
#include "Human.h"
#include <string>
#include <stdio.h>
using namespace std;

Game_Controller::Game_Controller() {
    this->s = NULL;
}

void Game_Controller::Interpreter(string A_String, string B_String, string C_String, string D_String) {
	if (A_String == "game") {
		s->Start_Game();
		if (B_String == "human") {
            Player *p1 = new Human("White", s->GetBoard());
			s->SetP1(p1);
		}
		if (C_String == "human") {
            Player *p2 = new Human("Black", s->GetBoard());
            s->SetP2(p2);
		}
		//TODO: Other levels of AI
	} else if (A_String == "move") {
		if (s->GetBoard()->GetTurn() == 'w') {
            Move *newMove = new Move(false, B_String, C_String, "", false);
			s->GetP1()->Make_Move(newMove);
		} else {
            Move *newMove = new Move(false, B_String, C_String, "", false);
			s->GetP2()->Make_Move(newMove);
		}
	} else if ((A_String == "Q") || (A_String == "R") ||
		(A_String == "N") || (A_String == "B")) {
		s->GetBoard()->UpdatePawn(A_String);
	}
}

void Game_Controller::Setup(Game_Setup *s) {
    this->s = s;
}

void Game_Controller::End_Game() {
    s->End_Game();
}

Game_Setup* Game_Controller::GetSetup() {
	return s;
}
