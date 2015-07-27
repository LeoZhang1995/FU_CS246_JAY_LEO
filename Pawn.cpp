//
//  Pawn.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Pawn.h"
#include <string>
#include <stdio.h>
using namespace std;

Pawn::Pawn(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->MovingStatus = 0;
    this->Alias = (side == "White") ? 'P' : 'p';
}

Move** Pawn::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[5];
    for (int a = 0; a < 5; ++a)
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
    if (Side == "White") {
	    newVerIndex = ver + 1;
	    newHorIndex = hor;
	    if ((newVerIndex < 8) && 
	    	((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') ||
	    		(b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_'))) {
	        newVer = '1' + newVerIndex;
	        newHor = 'a' + newHorIndex;
	        newPos = "";
            newPos += newHor;
            newPos += newVer;
	        available[curIndex] = new Move(check, Position, newPos, "", captured);
	        curIndex++;
	    }
	    if (MovingStatus == 0) {
		    newVerIndex = ver + 2;
		    newHorIndex = hor;
		    if ((newVerIndex < 8) && 
		    	((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') ||
		    		(b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) &&
		    	((b->GetBoard()[newVerIndex - 1][newHorIndex]->Alias == ' ') ||
		    		(b->GetBoard()[newVerIndex - 1][newHorIndex]->Alias == '_'))) {
		        newVer = '1' + newVerIndex;
	            newHor = 'a' + newHorIndex;
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            available[curIndex] = new Move(check, Position, newPos, "", captured);
	            curIndex++;
		    }
		}
	    newVerIndex = ver + 1;
	    newHorIndex = hor + 1;
	    newVer = '1' + newVerIndex;
        newHor = 'a' + newHorIndex;
        newPos = "";
        newPos += newHor;
        newPos += newVer;
	    if ((newVerIndex < 8) && (newHorIndex < 8) &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != "") &&
            (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
	        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
	            captures = newPos + "Q";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
	            captures = newPos + "R";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
	            captures = newPos + "B";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
	            captures = newPos + "N";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
	            captures = newPos + "P";
	        }
	        available[curIndex] = new Move(check, Position, newPos, captures, captured);
	        curIndex++;
	    }
	    //TODO: capture en passant
	    newVerIndex = ver + 1;
	    newHorIndex = hor - 1;
        newVer = '1' + newVerIndex;
	    newHor = 'a' + newHorIndex;
	    newPos = "";
        newPos += newHor;
        newPos += newVer;
	    if ((newVerIndex < 8) && (newHorIndex >= 0) &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != "") &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
	        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
	            captures = newPos + "Q";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
	            captures = newPos + "R";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
	            captures = newPos + "B";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
	            captures = newPos + "N";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
	            captures = newPos + "P";
	        }
	        available[curIndex] = new Move(check, Position, newPos, captures, captured);
	        curIndex++;
	    }
	} else {
		newVerIndex = ver - 1;
	    newHorIndex = hor;
	    if ((newVerIndex >= 0) && 
	    	((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') ||
	    		(b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_'))) {
	        newVer = '1' + newVerIndex;
	        newHor = 'a' + newHorIndex;
	        newPos = "";
            newPos += newHor;
            newPos += newVer;
	        available[curIndex] = new Move(check, Position, newPos, "", captured);
	        curIndex++;
	    }
	    if (MovingStatus == 0) {
		    newVerIndex = ver - 2;
		    newHorIndex = hor;
		    if ((newVerIndex >= 0) && 
		    	((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') ||
		    		(b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) &&
		    	((b->GetBoard()[newVerIndex + 1][newHorIndex]->Alias == ' ') ||
		    		(b->GetBoard()[newVerIndex + 1][newHorIndex]->Alias == '_'))) {
		        newVer = '1' + newVerIndex;
	            newHor = 'a' + newHorIndex;
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            available[curIndex] = new Move(check, Position, newPos, "", captured);
	            curIndex++;
		    }
		}
	    newVerIndex = ver - 1;
	    newHorIndex = hor + 1;
	    newVer = '1' + newVerIndex;
        newHor = 'a' + newHorIndex;
        newPos = "";
        newPos += newHor;
        newPos += newVer;
	    if ((newVerIndex >= 0) && (newHorIndex < 8) &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != "") &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
	        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
	            captures = newPos + "Q";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
	            captures = newPos + "R";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
	            captures = newPos + "B";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
	            captures = newPos + "N";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
	            captures = newPos + "P";
	        }
	        available[curIndex] = new Move(check, Position, newPos, captures, captured);
	        curIndex++;
	    }
	    newVerIndex = ver - 1;
	    newHorIndex = hor - 1;
	    newVer = '1' + newVerIndex;
        newHor = 'a' + newHorIndex;
        newPos = "";
        newPos += newHor;
        newPos += newVer;
	    if ((newVerIndex >= 0) && (newHorIndex >= 0) &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != "") &&
	    	(b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
	        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'Q') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'q')) {
	            captures = newPos + "Q";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'R') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'r')) {
	            captures = newPos + "R";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'B') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'b')) {
	            captures = newPos + "B";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'N') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'n')) {
	            captures = newPos + "N";
	        } else if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p')) {
	            captures = newPos + "P";
	        }
	        available[curIndex] = new Move(check, Position, newPos, captures, captured);
	        curIndex++;
	    }
	}
    return available;
}

void Pawn::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
