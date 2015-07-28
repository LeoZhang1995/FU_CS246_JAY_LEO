//
//  Pawn.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Pawn.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

Pawn::Pawn(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->MovingStatus = 0;
    this->Alias = (side == "White") ? 'P' : 'p';
}

Chess* Pawn::CopyChess() {
	Chess *chess = new Pawn(Side, Position);
	((Pawn*)(chess))->MovingStatus = MovingStatus;
	return chess;
}

Move** Pawn::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[5];
    Move* test;
    int testResult;
    for (int a = 0; a < 5; ++a)
    {
        available[a] = NULL;
    }
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos, newPos_2;
    int newVerIndex, newHorIndex;
    char newVer, newHor, newVer_2, newHor_2;
    string captures;
    if (Side == "White") {
    	if (ver == 4) {
    		newVerIndex = ver;
	    	newHorIndex = hor + 1;
    		if ((newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p') &&
    			(((Pawn*)(b->GetBoard()[newVerIndex][newHorIndex]))->MovingStatus == 2)) {
    			newVer = '1' + newVerIndex + 1;
		        newHor = 'a' + newHorIndex;
		        newVer_2 = '1' + newVerIndex;
		        newHor_2 = 'a' + newHorIndex;
		        newPos = "";
		        newPos_2 = "";
	            newPos += newHor;
	            newPos += newVer;
	            newPos_2 += newHor_2;
	            newPos_2 += newVer_2;
    			test = new Move(check, Position, newPos, newPos_2, captured);
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
    		newVerIndex = ver;
	    	newHorIndex = hor - 1;
    		if ((newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'p') &&
    			(((Pawn*)(b->GetBoard()[newVerIndex][newHorIndex]))->MovingStatus == 2)) {
    			newVer = '1' + newVerIndex + 1;
		        newHor = 'a' + newHorIndex;
		        newVer_2 = '1' + newVerIndex;
		        newHor_2 = 'a' + newHorIndex;
		        newPos = "";
		        newPos_2 = "";
	            newPos += newHor;
	            newPos += newVer;
	            newPos_2 += newHor_2;
	            newPos_2 += newVer_2;
    			test = new Move(check, Position, newPos, newPos_2, captured);
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
	        captures = newPos;
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
	        captures = newPos;
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
	} else {
		if (ver == 3) {
    		newVerIndex = ver;
	    	newHorIndex = hor + 1;
    		if ((newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') &&
    			(((Pawn*)(b->GetBoard()[newVerIndex][newHorIndex]))->MovingStatus == 2)) {
    			newVer = '1' + newVerIndex - 1;
		        newHor = 'a' + newHorIndex;
		        newVer_2 = '1' + newVerIndex;
		        newHor_2 = 'a' + newHorIndex;
		        newPos = "";
		        newPos_2 = "";
	            newPos += newHor;
	            newPos += newVer;
	            newPos_2 += newHor_2;
	            newPos_2 += newVer_2;
    			test = new Move(check, Position, newPos, newPos_2, captured);
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
    		newVerIndex = ver;
	    	newHorIndex = hor - 1;
    		if ((newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Alias == 'P') &&
    			(((Pawn*)(b->GetBoard()[newVerIndex][newHorIndex]))->MovingStatus == 2)) {
    			newVer = '1' + newVerIndex - 1;
		        newHor = 'a' + newHorIndex;
		        newVer_2 = '1' + newVerIndex;
		        newHor_2 = 'a' + newHorIndex;
		        newPos = "";
		        newPos_2 = "";
	            newPos += newHor;
	            newPos += newVer;
	            newPos_2 += newHor_2;
	            newPos_2 += newVer_2;
    			test = new Move(check, Position, newPos, newPos_2, captured);
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
	    if ((newVerIndex >= 0) && 
	    	((b->GetBoard()[newVerIndex][newHorIndex]->Alias == ' ') ||
	    		(b->GetBoard()[newVerIndex][newHorIndex]->Alias == '_'))) {
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
	        captures = newPos;
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
	        captures = newPos;
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
    if (curIndex == 0) {
    	return NULL;
    } else {
    	return available;
    }
}

void Pawn::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
