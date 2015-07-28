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
#include <iostream>
#include <stdio.h>
#include "AI_One.h"
#include "AI_Two.h"
#include "AI_Three.h"
#include "AI_Four.h"
using namespace std;

Game_Controller::Game_Controller() {
    this->s = NULL;
}

void Game_Controller::Interpreter(string A_String, string B_String, string C_String, string D_String) {
	if (A_String == "game") {
		s->Start_Game();
		if (B_String == "human")  {
            Player *p1 = new Human("White", s->GetBoard());
			s->SetP1(p1);
		} else if (B_String == "computer1") {
			Player *p1 = new AI_One("White", s->GetBoard());
			s->SetP1(p1);
		} else if (B_String == "computer2") {
			Player *p1 = new AI_Two("White", s->GetBoard());
			s->SetP1(p1);
		} else if (B_String == "computer3") {
			Player *p1 = new AI_Three("White", s->GetBoard());
			s->SetP1(p1);
		} else if (B_String == "computer4") {
			Player *p1 = new AI_Four("White", s->GetBoard());
			s->SetP1(p1);
		}
		if (C_String == "human")  {
            Player *p2 = new Human("Black", s->GetBoard());
			s->SetP2(p2);
		} else if (B_String == "computer1") {
			Player *p2 = new AI_One("Black", s->GetBoard());
			s->SetP2(p2);
		} else if (B_String == "computer2") {
			Player *p2 = new AI_Two("Black", s->GetBoard());
			s->SetP2(p2);
		} else if (B_String == "computer3") {
			Player *p2 = new AI_Three("Black", s->GetBoard());
			s->SetP2(p2);
		} else if (B_String == "computer4") {
			Player *p2 = new AI_Four("Black", s->GetBoard());
			s->SetP2(p2);
		}
    } else if (A_String == "move") {
        if (s->GetBoard()->GetTurn() == 'w') {
        	if ((B_String != "") && (C_String != "")) {
	            Move *newMove = new Move(false, B_String, C_String, "", false);
	            s->GetP1()->Make_Move(newMove);
	        } else {
	        	s->GetP1()->Make_Move(NULL);
	        }
        } else {
            if ((B_String != "") && (C_String != "")) {
	            Move *newMove = new Move(false, B_String, C_String, "", false);
	            s->GetP2()->Make_Move(newMove);
	        } else {
	        	s->GetP2()->Make_Move(NULL);
	        }
		}
	} else if ((A_String == "Q") || (A_String == "R") ||
		(A_String == "N") || (A_String == "B")) {
		s->GetBoard()->UpdatePawn(A_String);
	} else if (A_String == "resign") {
		s->Surrender();
	} else if (A_String == "setup") {
		s->Board_Setup();
	} else if ((A_String == "+") || (A_String == "-") ||
		(A_String == "=") || (A_String == "done")) {
		s->ModifyBoard(A_String, B_String, C_String, D_String);
	}
}

void Game_Controller::Setup(Game_Setup *s) {
    this->s = s;
}

void Game_Controller::End_Game() {
    s->End_Game();
}

void Game_Controller::Stalemate() {
	s->Stalemate();
}

void Game_Controller::Setup_Done() {
	s->Setup_Done();
}

Game_Setup* Game_Controller::GetSetup() {
	return s;
}

Game_Controller::~Game_Controller() {
    if (s != NULL) {
    	delete s;
    }
}
