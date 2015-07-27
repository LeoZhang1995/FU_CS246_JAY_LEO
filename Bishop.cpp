//
//  Bishop.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Bishop.h"
#include <string>
#include <stdio.h>
using namespace std;

Bishop::Bishop(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Alias = (side == "White") ? 'B' : 'b';
}

Move** Bishop::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[15];
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos;
    char newVer;
    char newHor;
    string captures;
    for (int a = 0; a < 15; ++a)
    {
        available[a] = NULL;
    }
    for (int i = 1; i < 8; ++i)
    {
    	if ((ver + i > 7) || (hor + i > 7)) {
    		break;
    	}
        if ((b->GetBoard()[ver + i][hor + i]->Alias == ' ') || (b->GetBoard()[ver + i][hor + i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + (ver + i);
            newHor = 'a' + (hor + i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, "", captured);
            curIndex++;
        } else if (b->GetBoard()[ver + i][hor + i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver + i][hor + i]->Alias == 'Q') || (b->GetBoard()[ver + i][hor + i]->Alias == 'q')) {
                captures = newPos + "Q";
            } else if ((b->GetBoard()[ver + i][hor + i]->Alias == 'R') || (b->GetBoard()[ver + i][hor + i]->Alias == 'r')) {
                captures = newPos + "R";
            } else if ((b->GetBoard()[ver + i][hor + i]->Alias == 'B') || (b->GetBoard()[ver + i][hor + i]->Alias == 'b')) {
                captures = newPos + "B";
            } else if ((b->GetBoard()[ver + i][hor + i]->Alias == 'N') || (b->GetBoard()[ver + i][hor + i]->Alias == 'n')) {
                captures = newPos + "K";
            } else if ((b->GetBoard()[ver + i][hor + i]->Alias == 'P') || (b->GetBoard()[ver + i][hor + i]->Alias == 'p')) {
                captures = newPos + "P";
            }
            newVer = '1' + (ver + i);
            newHor = 'a' + (hor + i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = 1; i < 8; ++i)
    {
    	if ((ver + i > 7) || (hor - i < 0)) {
    		break;
    	}
        if ((b->GetBoard()[ver + i][hor - i]->Alias == ' ') || (b->GetBoard()[ver + i][hor - i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + (ver + i);
            newHor = 'a' + (hor - i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, "", captured);
            curIndex++;
        } else if (b->GetBoard()[ver + i][hor - i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver + i][hor - i]->Alias == 'Q') || (b->GetBoard()[ver + i][hor - i]->Alias == 'q')) {
                captures = newPos + "Q";
            } else if ((b->GetBoard()[ver + i][hor - i]->Alias == 'R') || (b->GetBoard()[ver + i][hor - i]->Alias == 'r')) {
                captures = newPos + "R";
            } else if ((b->GetBoard()[ver + i][hor - i]->Alias == 'B') || (b->GetBoard()[ver + i][hor - i]->Alias == 'b')) {
                captures = newPos + "B";
            } else if ((b->GetBoard()[ver + i][hor - i]->Alias == 'N') || (b->GetBoard()[ver + i][hor - i]->Alias == 'n')) {
                captures = newPos + "N";
            } else if ((b->GetBoard()[ver + i][hor - i]->Alias == 'P') || (b->GetBoard()[ver + i][hor - i]->Alias == 'p')) {
                captures = newPos + "P";
            }
            newVer = '1' + (ver + i);
            newHor = 'a' + (hor - i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = 1; i < 8; ++i)
    {
    	if ((ver - i < 0) || (hor + i > 7)) {
    		break;
    	}
        if ((b->GetBoard()[ver - i][hor + i]->Alias == ' ') || (b->GetBoard()[ver - i][hor + i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + (ver - i);
            newHor = 'a' + (hor + i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, "", captured);
            curIndex++;
        } else if (b->GetBoard()[ver - i][hor + i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver - i][hor + i]->Alias == 'Q') || (b->GetBoard()[ver - i][hor + i]->Alias == 'q')) {
                captures = newPos + "Q";
            } else if ((b->GetBoard()[ver - i][hor + i]->Alias == 'R') || (b->GetBoard()[ver - i][hor + i]->Alias == 'r')) {
                captures = newPos + "R";
            } else if ((b->GetBoard()[ver - i][hor + i]->Alias == 'B') || (b->GetBoard()[ver - i][hor + i]->Alias == 'b')) {
                captures = newPos + "B";
            } else if ((b->GetBoard()[ver - i][hor + i]->Alias == 'N') || (b->GetBoard()[ver - i][hor + i]->Alias == 'n')) {
                captures = newPos + "N";
            } else if ((b->GetBoard()[ver - i][hor + i]->Alias == 'P') || (b->GetBoard()[ver - i][hor + i]->Alias == 'p')) {
                captures = newPos + "P";
            }
            newVer = '1' + (ver - i);
            newHor = 'a' + (hor + i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = 1; i < 8; ++i)
    {
    	if ((ver - i < 0) || (hor - i < 0)) {
    		break;
    	}
        if ((b->GetBoard()[ver - i][hor - i]->Alias == ' ') || (b->GetBoard()[ver - i][hor - i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + (ver - i);
            newHor = 'a' + (hor - i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, "", captured);
            curIndex++;
        } else if (b->GetBoard()[ver - i][hor - i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver - i][hor - i]->Alias == 'Q') || (b->GetBoard()[ver - i][hor - i]->Alias == 'q')) {
                captures = newPos + "Q";
            } else if ((b->GetBoard()[ver - i][hor - i]->Alias == 'R') || (b->GetBoard()[ver - i][hor - i]->Alias == 'r')) {
                captures = newPos + "R";
            } else if ((b->GetBoard()[ver - i][hor - i]->Alias == 'B') || (b->GetBoard()[ver - i][hor - i]->Alias == 'b')) {
                captures = newPos + "B";
            } else if ((b->GetBoard()[ver - i][hor - i]->Alias == 'N') || (b->GetBoard()[ver - i][hor - i]->Alias == 'n')) {
                captures = newPos + "N";
            } else if ((b->GetBoard()[ver - i][hor - i]->Alias == 'P') || (b->GetBoard()[ver - i][hor - i]->Alias == 'p')) {
                captures = newPos + "P";
            }
            newVer = '1' + (ver - i);
            newHor = 'a' + (hor - i);
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    return available;
}

void Bishop::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
