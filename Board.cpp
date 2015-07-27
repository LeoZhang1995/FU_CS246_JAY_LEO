//
//  Board.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "White_Block.h"
#include "Black_Block.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

Board::Board(Game_View *v) {
    this->v = v;
    char newHor;
    string position;
    Chess*** Chess_Array = new Chess**[8];
    for (int i = 0; i < 8; i++) {
        Chess_Array[i] = new Chess*[8];
    }
    Game_Board = Chess_Array;
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
        position = "";
        position += newHor;
        position += '2';
    	Game_Board[1][i] = new Pawn("White", position);
    	position = "";
        position += newHor;
        position += '7';
    	Game_Board[6][i] = new Pawn("Black", position);
    }
    for (int i = 0; i < 8; ++i)
    {
    	newHor = 'a' + i;
        position = "";
        position += newHor;
        position += '3';
    	if (((i + 2) & 1) == 1) {
    		Game_Board[2][i] = new White_Block("", position);
    		Game_Board[3][i] = new Black_Block("", position);
    		Game_Board[4][i] = new White_Block("", position);
    		Game_Board[5][i] = new Black_Block("", position);
    	} else {
    		Game_Board[2][i] = new Black_Block("", position);
    		Game_Board[3][i] = new White_Block("", position);
    		Game_Board[4][i] = new Black_Block("", position);
    		Game_Board[5][i] = new White_Block("", position);
    	}
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
	string curSide;
	if (Turn == 'w') {
		curSide = "White";
	} else {
		curSide = "Black";
	}
	if (Game_Board[oldVer][oldHor]->Side != curSide) {
		cout << Game_Board[oldVer][oldHor]->Side << endl;
		this->Illegal_Move();
	} else {
		delete Game_Board[newVer][newHor];
		Game_Board[newVer][newHor] = Game_Board[oldVer][oldHor];
		Game_Board[newVer][newHor]->Position = destination;
	    if (((oldVer + oldHor) & 1) == 1) {
	        Game_Board[oldVer][oldHor] =  new White_Block("", origin);
	    } else {
	        Game_Board[oldVer][oldHor] =  new Black_Block("", origin);
	    }
		delete A_Move;
		//TODO: checkmate, stalemate
		if (Turn == 'w') {
			v->Print(Game_Board, "Player1 Moved: " + origin + " " + destination);
			Turn = 'b';
		} else {
			v->Print(Game_Board, "Player2 Moved: " + origin + " " + destination);
			Turn = 'w';
		}
	}
}

Chess*** Board::GetBoard() {
    return Game_Board;
}

char Board::GetTurn() {
    return Turn;
}

void Board::SetView(Game_View *v) {
    if (this->v == NULL) {
        this->v = v;
    }
}

void Board::Illegal_Move() {
	v->Print(Game_Board, "Move is illegal, please try again");
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
    delete [] Game_Board;
}
