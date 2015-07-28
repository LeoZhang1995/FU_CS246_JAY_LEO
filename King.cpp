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
#include <iostream>
using namespace std;

King::King(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Moved = false;
    this->Alias = (side == "White") ? 'K' : 'k';
}

Chess* King::CopyChess() {
	Chess *chess = new King(Side, Position);
	((King*)(chess))->Moved = Moved;
	return chess;
}

Move** King::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[8];
    Move* test;
    int testResult;
    for (int a = 0; a < 8; ++a)
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
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        } else {
            captures = newPos;
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        }
    }
    newVerIndex = ver;
    newHorIndex = hor + 1;
    if ((newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        } else {
            captures = newPos;
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        }
    }
    newVerIndex = ver - 1;
    newHorIndex = hor;
    if ((newVerIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        } else {
            captures = newPos;
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        }
    }
    newVerIndex = ver;
    newHorIndex = hor - 1;
    if ((newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') || (b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        } else {
            captures = newPos;
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 1) {
            	test->Check = true;
            	available[curIndex] = test;
	            curIndex++;
            } else if (testResult == 2) {
	            available[curIndex] = test;
	            curIndex++;
	        }
        }
    }
    if (!Moved & !b->Check(Alias)) {
    	for (int i = hor + 1; i < 8; ++i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + (hor + 2);
		            newPos = "";
		            newPos += newHor;
		            newPos += newVer;
		            test = new Move(check, Position, newPos, "", captured);
		            testResult = b->SimulateCheck(test);
		            if (testResult == 0) {
		            	break;
		            } else if (testResult == 1) {
		            	test->Check = true;
		            	test->Other = "Castling";
		            	available[curIndex] = test;
			            curIndex++;
		            } else {
		            	test->Other = "Castling";
			            available[curIndex] = test;
			            curIndex++;
			        }
		        }
	        } else {
	        	newVer = '1' + ver;
	            newHor = 'a' + (hor + 1);
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            test = new Move(check, Position, newPos, "", captured);
	            testResult = b->SimulateCheck(test);
	            if (testResult == 0) {
	            	break;
	            }
	        }
	    }
	    for (int i = hor - 1; i >= 0; --i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + ver;
		            newHor = 'a' + (hor - 2);
		            newPos = "";
		            newPos += newHor;
		            newPos += newVer;
		            test = new Move(check, Position, newPos, "", captured);
		            testResult = b->SimulateCheck(test);
		            if (testResult == 0) {
		            	break;
		            } else if (testResult == 1) {
		            	test->Check = true;
		            	test->Other = "Castling";
		            	available[curIndex] = test;
			            curIndex++;
		            } else {
		            	test->Other = "Castling";
			            available[curIndex] = test;
			            curIndex++;
			        }
		        }
	        } else {
	        	newVer = '1' + ver;
	            newHor = 'a' + (hor - 1);
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            test = new Move(check, Position, newPos, "", captured);
	            testResult = b->SimulateCheck(test);
	            if (testResult == 0) {
	            	break;
	            }
	        }
	    }
	    for (int i = ver + 1; i < 8; ++i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + (ver + 2);
		            newHor = 'a' + hor;
		            newPos = "";
		            newPos += newHor;
		            newPos += newVer;
		            test = new Move(check, Position, newPos, "", captured);
		            testResult = b->SimulateCheck(test);
		            if (testResult == 0) {
		            	break;
		            } else if (testResult == 1) {
		            	test->Check = true;
		            	test->Other = "Castling";
		            	available[curIndex] = test;
			            curIndex++;
		            } else {
		            	test->Other = "Castling";
			            available[curIndex] = test;
			            curIndex++;
			        }
		        }
	        } else {
	        	newVer = '1' + (ver + 1);
	            newHor = 'a' + hor;
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            test = new Move(check, Position, newPos, "", captured);
	            testResult = b->SimulateCheck(test);
	            if (testResult == 0) {
	            	break;
	            }
	        }
	    }
	    for (int i = ver - 1; i >= 0; --i)
	    {
	        if ((b->GetBoard()[ver][i]->Alias != 'R') && (b->GetBoard()[ver][i]->Alias != 'r') &&
	        	(b->GetBoard()[ver][i]->Alias != ' ') && (b->GetBoard()[ver][i]->Alias != '_')) {
	            break;
	        } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
	            if (((Rook*)(b->GetBoard()[ver][i]))->Moved || (b->GetBoard()[ver][i]->Side != Side)) {
	                break;
	            } else {
	            	//TODO: get the real positions of king-rook switch
		            newVer = '1' + (ver -2);
		            newHor = 'a' + hor;
		            newPos = "";
		            newPos += newHor;
		            newPos += newVer;
		            test = new Move(check, Position, newPos, "", captured);
		            testResult = b->SimulateCheck(test);
		            if (testResult == 0) {
		            	break;
		            } else if (testResult == 1) {
		            	test->Check = true;
		            	test->Other = "Castling";
		            	available[curIndex] = test;
			            curIndex++;
		            } else {
		            	test->Other = "Castling";
			            available[curIndex] = test;
			            curIndex++;
			        }
		        }
	        } else {
	        	newVer = '1' + (ver - 1);
	            newHor = 'a' + hor;
	            newPos = "";
	            newPos += newHor;
	            newPos += newVer;
	            test = new Move(check, Position, newPos, "", captured);
	            testResult = b->SimulateCheck(test);
	            if (testResult == 0) {
	            	break;
	            }
	        }
	    }
    }
    if (curIndex == 0) {
    	return NULL;
    } else {
    	return available;
    }
}

void King::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
