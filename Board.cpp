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

void Board::Restart_Game() {
	for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            delete Game_Board[i][j];
        }
    }
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
	bool checked = A_Move->Check;
	bool checkmated = false;
	bool up = false;
	int oldVer, oldHor, newVer, newHor, oldVer_2, oldHor_2, newVer_2, newHor_2;
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
	    if ((A_Move->Captures != "") && (A_Move->Destination != A_Move->Captures)) {
	    	oldVer_2 = A_Move->Captures[1] - '1';
	    	oldHor_2 = A_Move->Captures[0] - 'a';
	    	delete Game_Board[oldVer_2][oldHor_2];
	    	if (((oldVer_2 + oldHor_2) & 1) == 1) {
		        Game_Board[oldVer_2][oldHor_2] =  new White_Block("", A_Move->Captures);
		    } else {
		        Game_Board[oldVer_2][oldHor_2] =  new Black_Block("", A_Move->Captures);
		    }
	    }
	    if (((Game_Board[newVer][newHor]->Alias == 'P') && (newVer == 7)) ||
			((Game_Board[newVer][newHor]->Alias == 'p') && (newVer == 0))) {
	    	if (v != NULL) {
		    	v->Read_One_Command();
		    	up = true;
		    }
	    }
	    if ((Game_Board[newVer][newHor]->Alias == 'K') ||
			(Game_Board[newVer][newHor]->Alias == 'k')) {
	    	if (A_Move->Other == "Castling") {
	    		if (oldVer == newVer) {
	    			oldVer_2 = oldVer;
	    			oldHor_2 = (newHor > oldHor) ? 7 : 0;
	    			newVer_2 = newVer;
	    			newHor_2 = (oldHor + newHor) / 2;
	    		} else if (oldHor == newHor) {
	    			oldHor_2 = oldHor;
	    			oldVer_2 = (newVer > oldVer) ? 7 : 0;
	    			newHor_2 = newHor;
	    			newVer_2 = (oldVer + newVer) / 2;
	    		}
	    		delete Game_Board[newVer_2][newHor_2];
				Game_Board[newVer_2][newHor_2] = Game_Board[oldVer_2][oldHor_2];
				Game_Board[newVer_2][newHor_2]->Position = destination;
			    if (((oldVer + oldHor) & 1) == 1) {
			        Game_Board[oldVer_2][oldHor_2] =  new White_Block("", origin);
			    } else {
			        Game_Board[oldVer_2][oldHor_2] =  new Black_Block("", origin);
			    }
	    	}
	    }
		//TODO: checkmate, stalemate
		string otherMessage;
		if (Turn == 'w') {
			if (up) {
				checked = Check('k');
			}
			if (checked) {
				checkmated = Checkmate();
				if (checkmated) {
					if (v != NULL) {
						v->Print(Game_Board, otherMessage);
						v->Checkmate("White");
					}
				} else {
					otherMessage = "Black is in checked.";
				}
			}
			if (!checkmated) {
				if (v != NULL) {
					v->Print(Game_Board, otherMessage);
				}
				Turn = 'b';
			}
		} else {
			if (up) {
				checked = Check('K');
			}
			if (checked) {
				checkmated = Checkmate();
				if (checkmated) {
					if (v != NULL) {
						v->Print(Game_Board, otherMessage);
						v->Checkmate("Black");
					}
				} else {
					otherMessage = "White is in checked.";
				}
			}
			if (!checkmated) {
				if (v != NULL) {
					v->Print(Game_Board, otherMessage);
				}
				Turn = 'w';
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if ((Game_Board[i][j]->Alias == 'P') ||
					(Game_Board[i][j]->Alias == 'p')) {
					if (((Pawn*)(Game_Board[i][j]))->MovingStatus == 2) {
						((Pawn*)(Game_Board[i][j]))->MovingStatus = 1;
					}
				}
			}
		}
		if ((Game_Board[newVer][newHor]->Alias == 'K') ||
			(Game_Board[newVer][newHor]->Alias == 'k')) {
			((King*)(Game_Board[newVer][newHor]))->Moved = true;
			if (A_Move->Other == "Castling") {
				((Rook*)(Game_Board[newVer_2][newHor_2]))->Moved = true;
			}
		} else if ((Game_Board[newVer][newHor]->Alias == 'R') ||
			(Game_Board[newVer][newHor]->Alias == 'r')) {
			((Rook*)(Game_Board[newVer][newHor]))->Moved = true;
		} else if ((Game_Board[newVer][newHor]->Alias == 'P') ||
			(Game_Board[newVer][newHor]->Alias == 'p')) {
			if ((newVer - oldVer == 2) || (oldVer - newVer == 2)) {
				((Pawn*)(Game_Board[newVer][newHor]))->MovingStatus = 2;
			} else {
				((Pawn*)(Game_Board[newVer][newHor]))->MovingStatus = 1;
			}
		}
	}
	delete A_Move;
}

Chess*** Board::GetBoard() {
    return Game_Board;
}

char Board::GetTurn() {
    return Turn;
}

void Board::SetTurn(char turn) {
	Turn = turn;
}

void Board::SetView(Game_View *v) {
    if (this->v == NULL) {
        this->v = v;
    }
}

void Board::Illegal_Move() {
	if (v != NULL) {
		v->Print(Game_Board, "Move is illegal, please try again");
	}
}

bool Board::Check(char alias) {
	int kingVer, kingHor, attackVer, attackHor;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Game_Board[i][j]->Alias == alias) {
				kingVer = i;
				kingHor = j;
				break;
			}
		}
	}
	if (alias == 'K') {
		attackVer = kingVer + 1;
		attackHor = kingHor + 1;
		if ((attackVer < 8) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'p')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor - 1;
		if ((attackVer < 8) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'p')) {
			return true;
		}
		attackVer = kingVer + 2;
		attackHor = kingHor + 1;
		if ((attackVer < 8) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor + 2;
		if ((attackVer < 8) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor + 2;
		if ((attackVer >= 0) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer - 2;
		attackHor = kingHor + 1;
		if ((attackVer >= 0) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor - 2;
		if ((attackVer < 8) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer + 2;
		attackHor = kingHor - 1;
		if ((attackVer < 8) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor - 2;
		if ((attackVer >= 0) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer - 2;
		attackHor = kingHor - 1;
		if ((attackVer >= 0) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'n')) {
			return true;
		}
		attackVer = kingVer;
		attackHor = kingHor - 1;
		if ((attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'k')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor;
		if ((attackVer >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'k')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor;
		if ((attackVer < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'k')) {
			return true;
		}
		attackVer = kingVer;
		attackHor = kingHor + 1;
		if ((attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'k')) {
			return true;
		}
		for (int i = kingHor + 1; i < 8; ++i)
		{
			if ((Game_Board[kingVer][i]->Alias == 'r') ||
				(Game_Board[kingVer][i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer][i]->Alias == ' ') ||
				(Game_Board[kingVer][i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingHor - 1; i >= 0; --i)
		{
			if ((Game_Board[kingVer][i]->Alias == 'r') ||
				(Game_Board[kingVer][i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer][i]->Alias == ' ') ||
				(Game_Board[kingVer][i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingVer + 1; i < 8; ++i)
		{
			if ((Game_Board[i][kingHor]->Alias == 'r') ||
				(Game_Board[i][kingHor]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[i][kingHor]->Alias == ' ') ||
				(Game_Board[i][kingHor]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingVer - 1; i >= 0; --i)
		{
			if ((Game_Board[i][kingHor]->Alias == 'r') ||
				(Game_Board[i][kingHor]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[i][kingHor]->Alias == ' ') ||
				(Game_Board[i][kingHor]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer + i > 7) || (kingHor + i > 7)) {
				break;
			}
			if ((Game_Board[kingVer + i][kingHor + i]->Alias == 'b') ||
				(Game_Board[kingVer + i][kingHor + i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer + i][kingHor + i]->Alias == ' ') ||
				(Game_Board[kingVer + i][kingHor + i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer - i < 0) || (kingHor - i < 0)) {
				break;
			}
			if ((Game_Board[kingVer - i][kingHor - i]->Alias == 'b') ||
				(Game_Board[kingVer - i][kingHor - i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer - i][kingHor - i]->Alias == ' ') ||
				(Game_Board[kingVer - i][kingHor - i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer + i > 7) || (kingHor - i < 0)) {
				break;
			}
			if ((Game_Board[kingVer + i][kingHor - i]->Alias == 'b') ||
				(Game_Board[kingVer + i][kingHor - i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer + i][kingHor - i]->Alias == ' ') ||
				(Game_Board[kingVer + i][kingHor - i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer - i < 0) || (kingHor + i > 7)) {
				break;
			}
			if ((Game_Board[kingVer - i][kingHor + i]->Alias == 'b') ||
				(Game_Board[kingVer - i][kingHor + i]->Alias == 'q')) {
				return true;
			} else if ((Game_Board[kingVer - i][kingHor + i]->Alias == ' ') ||
				(Game_Board[kingVer - i][kingHor + i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
	} else if (alias == 'k') {
		attackVer = kingVer - 1;
		attackHor = kingHor - 1;
		if ((attackVer >= 0) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'P')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor + 1;
		if ((attackVer >= 0) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'P')) {
			return true;
		}
		attackVer = kingVer + 2;
		attackHor = kingHor + 1;
		if ((attackVer < 8) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor + 2;
		if ((attackVer < 8) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor + 2;
		if ((attackVer >= 0) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer - 2;
		attackHor = kingHor + 1;
		if ((attackVer >= 0) && (attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor - 2;
		if ((attackVer < 8) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer + 2;
		attackHor = kingHor - 1;
		if ((attackVer < 8) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor - 2;
		if ((attackVer >= 0) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer - 2;
		attackHor = kingHor - 1;
		if ((attackVer >= 0) && (attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'N')) {
			return true;
		}
		attackVer = kingVer;
		attackHor = kingHor - 1;
		if ((attackHor >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'K')) {
			return true;
		}
		attackVer = kingVer - 1;
		attackHor = kingHor;
		if ((attackVer >= 0) &&
			(Game_Board[attackVer][attackHor]->Alias == 'K')) {
			return true;
		}
		attackVer = kingVer + 1;
		attackHor = kingHor;
		if ((attackVer < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'K')) {
			return true;
		}
		attackVer = kingVer;
		attackHor = kingHor + 1;
		if ((attackHor < 8) &&
			(Game_Board[attackVer][attackHor]->Alias == 'K')) {
			return true;
		}
		for (int i = kingHor + 1; i < 8; ++i)
		{
			if ((Game_Board[kingVer][i]->Alias == 'R') ||
				(Game_Board[kingVer][i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer][i]->Alias == ' ') ||
				(Game_Board[kingVer][i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingHor - 1; i >= 0; --i)
		{
			if ((Game_Board[kingVer][i]->Alias == 'R') ||
				(Game_Board[kingVer][i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer][i]->Alias == ' ') ||
				(Game_Board[kingVer][i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingVer + 1; i < 8; ++i)
		{
			if ((Game_Board[i][kingHor]->Alias == 'R') ||
				(Game_Board[i][kingHor]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[i][kingHor]->Alias == ' ') ||
				(Game_Board[i][kingHor]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = kingVer - 1; i >= 0; --i)
		{
			if ((Game_Board[i][kingHor]->Alias == 'R') ||
				(Game_Board[i][kingHor]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[i][kingHor]->Alias == ' ') ||
				(Game_Board[i][kingHor]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer + i > 7) || (kingHor + i > 7)) {
				break;
			}
			if ((Game_Board[kingVer + i][kingHor + i]->Alias == 'B') ||
				(Game_Board[kingVer + i][kingHor + i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer + i][kingHor + i]->Alias == ' ') ||
				(Game_Board[kingVer + i][kingHor + i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer - i < 0) || (kingHor - i < 0)) {
				break;
			}
			if ((Game_Board[kingVer - i][kingHor - i]->Alias == 'B') ||
				(Game_Board[kingVer - i][kingHor - i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer - i][kingHor - i]->Alias == ' ') ||
				(Game_Board[kingVer - i][kingHor - i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer + i > 7) || (kingHor - i < 0)) {
				break;
			}
			if ((Game_Board[kingVer + i][kingHor - i]->Alias == 'B') ||
				(Game_Board[kingVer + i][kingHor - i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer + i][kingHor - i]->Alias == ' ') ||
				(Game_Board[kingVer + i][kingHor - i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if ((kingVer - i < 0) || (kingHor + i > 7)) {
				break;
			}
			if ((Game_Board[kingVer - i][kingHor + i]->Alias == 'B') ||
				(Game_Board[kingVer - i][kingHor + i]->Alias == 'Q')) {
				return true;
			} else if ((Game_Board[kingVer - i][kingHor + i]->Alias == ' ') ||
				(Game_Board[kingVer - i][kingHor + i]->Alias == '_')) {
				continue;
			} else {
				break;
			}
		}
	}
	return false;
}

void Board::SetBoard(Chess*** nb) {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Game_Board[i][j] != NULL) {
				delete Game_Board[i][j];
				Game_Board[i][j] = nb[i][j]->CopyChess();
			}
		}
	}
}

int Board::SimulateCheck(Move* A_Move) {
	Board *nb = new Board(NULL);
	nb->SetTurn(Turn);
	nb->SetBoard(Game_Board);
	for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            nb->GetBoard()[i][j]->SetBoard(nb);
        }
    }
	Move* test = new Move(false, A_Move->Origin, A_Move->Destination, A_Move->Captures, A_Move->Captured);
	nb->Make_Move(test);
	if (Turn == 'w') {
		if (nb->Check('K')) {
			delete nb;
			return 0;
		} else if (nb->Check('k')) {
			delete nb;
			return 1;
		}
	} else {
		if (nb->Check('k')) {
			delete nb;
			return 0;
		} else if (nb->Check('K')) {
			delete nb;
			return 1;
		}
	}
	delete nb;
	return 2;
}

void Board::UpdatePawn(string updateTo) {
	char ver, hor;
	string pos = "";
	if (Turn == 'w') {
		for (int i = 0; i < 8; ++i)
		{
			if (Game_Board[7][i]->Alias == 'P') {
				ver = '8';
				hor = 'a' + i;
				pos += hor;
				pos += ver;
				if (updateTo == "Q") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Queen("White", pos);
				} else if (updateTo == "R") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Rook("White", pos);
				} else if (updateTo == "N") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Knight("White", pos);
				} else if (updateTo == "B") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Bishop("White", pos);
				}
			}
		}
	} else if (Turn == 'b') {
		for (int i = 0; i < 8; ++i)
		{
			if (Game_Board[0][i]->Alias == 'P') {
				ver = '1';
				hor = 'a' + i;
				pos += hor;
				pos += ver;
				if (updateTo == "Q") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Queen("Black", pos);
				} else if (updateTo == "R") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Rook("Black", pos);
				} else if (updateTo == "N") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Knight("Black", pos);
				} else if (updateTo == "B") {
					delete Game_Board[7][i];
					Game_Board[7][i] = new Bishop("Black", pos);
				}
			}
		}
	}
}

bool Board::Checkmate() {
	Move** available;
	if (Turn == 'w') {
		Turn = 'b';
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (Game_Board[i][j]->Side == "Black") {
					available = Game_Board[i][j]->Available_Move();
					if (available != NULL) {
						delete available;
						return false;
					} else {
						delete available;
					}
				}
			}
		}
		Turn = 'w';
	} else {
		Turn = 'w';
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (Game_Board[i][j]->Side == "White") {
					available = Game_Board[i][j]->Available_Move();
					if (available != NULL) {
						delete available;
						return false;
					} else {
						delete available;
					}
				}
			}
		}
		Turn = 'b';
	}
	return true;
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
