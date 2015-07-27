//
//  King.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "King.h"
#include "Rook.h"
#include <string>
#include <stdio.h>
using namespace std;

King::King(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Moved = false;
    this->Alias = (side == "White") ? 'K' : 'k';
}

Move** King::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[7];
    for (int a = 0; a < 4; ++a)
    {
        available[a] = NULL;
    }
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos;
    int newVerIndex, newHorIndex;
    char newVer, newHor;
    string captures;
    newVerIndex = ver + 1;
    newHorIndex = hor;
    if ((newVerIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver;
    newHorIndex = hor + 1;
    if ((newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver - 1;
    newHorIndex = hor;
    if ((newVerIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver;
    newHorIndex = hor - 1;
    if ((newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    if (!Moved) {
    	for (int i = hor + 1; i < 8; ++i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        }
	        if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + i;
		            newPos = newHor + newVer;
		            available[curIndex] = new Move(check, Position, newPos, captures, captured);
		            curIndex++;
		        }
	        }
	    }
	    for (int i = hor - 1; i >= 0; --i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        }
	        if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + i;
		            newPos = newHor + newVer;
		            available[curIndex] = new Move(check, Position, newPos, captures, captured);
		            curIndex++;
		        }
	        }
	    }
	    for (int i = ver + 1; i < 8; ++i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        }
	        if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + i;
		            newPos = newHor + newVer;
		            available[curIndex] = new Move(check, Position, newPos, captures, captured);
		            curIndex++;
		        }
	        }
	    }
	    for (int i = ver - 1; i >= 0; --i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        }
	        if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + i;
		            newPos = newHor + newVer;
		            available[curIndex] = new Move(check, Position, newPos, captures, captured);
		            curIndex++;
		        }
	        }
	    }
    }
    return available;
}

void King::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
