//
//  Board.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Board.h"
#include <string>
#include <stdio.h>
using namespace std;

Board::Board(Game_View *v) {
    this->v = v;
    char newHor;
    Game_Board = new Chess*[8][8];
    Game_Board[0][0] = new Rook("White", "a1");
    Game_Board[0][1] = new Knight("White", "b1");
    Game_Board[0][2] = new Bishop("White", "c1");
    Game_Board[0][3] = new Queen("White", "d1");
    Game_Board[0][4] = new King("White", "e1");
    Game_Board[0][5] = new Bishop("White", "f1");
    Game_Board[0][6] = new Knight("White", "g1");
    Game_Board[0][7] = new Rook("White", "h1");
    for (int i = 0; i < 8; ++i)
    {
    	newHor = 'a' + i;
    	Game_Board[1][i] = new Pawn("White", newHor + '2');
    	Game_Board[6][i] = new Pawn("Black", newHor + '7');
    }
    for (int i = 0; i < 8; ++i)
    {
    	newHor = 'a' + i;
    	if ((i + 2) & 1 == 1) {
    		Game_Board[2][i] = new White_Block(NULL, newHor + '3');
    		Game_Board[3][i] = new Black_Block(NULL, newHor + '3');
    		Game_Board[4][i] = new White_Block(NULL, newHor + '3');
    		Game_Board[5][i] = new Black_Block(NULL, newHor + '3');
    	} else {
    		Game_Board[2][i] = new Black_Block(NULL, newHor + '3');
    		Game_Board[3][i] = new White_Block(NULL, newHor + '3');
    		Game_Board[4][i] = new Black_Block(NULL, newHor + '3');
    		Game_Board[5][i] = new White_Block(NULL, newHor + '3');
    	}
    	Game_Board[1][i] = new Pawn(NULL, newHor + '3');
    }
    Game_Board[7][0] = new Rook("Black", "a8");
    Game_Board[7][1] = new Knight("Black", "b8");
    Game_Board[7][2] = new Bishop("Black", "c8");
    Game_Board[7][3] = new Queen("Black", "d8");
    Game_Board[7][4] = new King("Black", "e8");
    Game_Board[7][5] = new Bishop("Black", "f8");
    Game_Board[7][6] = new Knight("Black", "g8");
    Game_Board[7][7] = new Rook("Black", "h8");
    Turn = 'w';
}

void Board::Make_Move(Move* A_Move) {
	string origin = A_Move->Origin;
	string destination = A_Move->Destination;
	int oldVer, oldHor, newVer, newHor;
	oldVer = origin[1] - '1';
	oldHor = origin[0] - 'a';
	newVer = destination[1] - '1';
	newHor = destination[0] - 'a';
	delete Game_Board[newVer][newHor];
	Game_Board[newVer][newHor] = Game_Board[oldVer][oldHor];
	Game_Board[oldVer][oldHor] = ((oldVer + oldHor) & 1 == 1) ? new White_Block(NULL, origin) : new Black_Block(NULL, origin);
	delete A_Move;
	//TODO: checkmate, stalemate
	v->Print(Game_Board);
	if (Turn == 'w') {
		Turn = 'b';
	} else {
		Turn = 'w';
	}
}

Board::~Board() {
	delete v;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			delete Game_Board[i][j];
		}
	}
}
