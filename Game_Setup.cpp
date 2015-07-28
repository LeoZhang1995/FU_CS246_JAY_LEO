//
//  Game_Setup.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Game_Setup.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

Game_Setup::Game_Setup() {
    b = new Board(NULL);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            b->GetBoard()[i][j]->SetBoard(b);
        }
    }
    this->r = NULL;
    this->p1 = NULL;
    this->p2 = NULL;
}

void Game_Setup::Start_Game() {
    b->v->Print(b->GetBoard(), "");
}

void Game_Setup::Restart_Game() {
	b->Restart_Game();
    this->Start_Game();
}

void Game_Setup::End_Game() {
	if (b->GetTurn() == 'b') {
		p2->IncreaseScore();
	} else if (b->GetTurn() == 'w') {
		p1->IncreaseScore();
	}
	this->Restart_Game();
}

Board* Game_Setup::GetBoard() {
    return b;
}

void Game_Setup::SetP1(Player *p1) {
    this->p1 = p1;
}

void Game_Setup::SetP2(Player *p2) {
    this->p2 = p2;
}

Player* Game_Setup::GetP1() {
    return p1;
}

Player* Game_Setup::GetP2() {
    return p2;
}

Game_Setup::~Game_Setup() {
	if (b != NULL) {
		delete b;
	}
	if (r != NULL) {
		delete r;
	}
	if (p1 != NULL) {
		delete p1;
	}
	if (p2 != NULL) {
		delete p2;
	}
}
