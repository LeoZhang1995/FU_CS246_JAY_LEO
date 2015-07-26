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
using namespace std;

Game_Setup::Game_Setup() {
    this->b = NULL;
    this->r = NULL;
    this->p1 = NULL;
    this->p2 = NULL;
}

Game_Setup::Start_Game() {
	b = new Board();
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			b->Game_Board[i][j]->SetBoard(b);
		}
	}
}

Game_Setup::Restart_Game() {
	delete b;
	this->Start_Game();
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
