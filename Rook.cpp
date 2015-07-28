//
//  Rook.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Rook.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

Rook::Rook(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Moved = false;
    this->Alias = (side == "White") ? 'R' : 'r';
}

Chess* Rook::CopyChess() {
    Chess *chess = new Rook(Side, Position);
    ((Rook*)(chess))->Moved = Moved;
    return chess;
}

Move** Rook::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[15];
    Move* test;
    int testResult;
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
    for (int i = hor + 1; i < 8; ++i)
    {
        if ((b->GetBoard()[ver][i]->Alias == ' ') || (b->GetBoard()[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                continue;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        } else if (b->GetBoard()[ver][i]->Side == Side) {
            break;
        } else {
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            captures = newPos;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                break;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        }
    }
    for (int i = hor - 1; i >= 0; --i)
    {
        if ((b->GetBoard()[ver][i]->Alias == ' ') || (b->GetBoard()[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                continue;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        } else if (b->GetBoard()[ver][i]->Side == Side) {
            break;
        } else {
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            captures = newPos;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                break;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        }
    }
    for (int i = ver + 1; i < 8; ++i)
    {
        if ((b->GetBoard()[i][hor]->Alias == ' ') || (b->GetBoard()[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                continue;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        } else if (b->GetBoard()[i][hor]->Side == Side) {
            break;
        } else {
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            captures = newPos;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                break;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        }
    }
    for (int i = ver - 1; i >= 0; --i)
    {
        if ((b->GetBoard()[i][hor]->Alias == ' ') || (b->GetBoard()[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            test = new Move(check, Position, newPos, "", captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                continue;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
                available[curIndex] = test;
                curIndex++;
            }
        } else if (b->GetBoard()[i][hor]->Side == Side) {
            break;
        } else {
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = "";
            newPos += newHor;
            newPos += newVer;
            captures = newPos;
            test = new Move(check, Position, newPos, captures, captured);
            testResult = b->SimulateCheck(test);
            if (testResult == 0) {
                break;
            } else if (testResult == 1) {
                test->Check = true;
                available[curIndex] = test;
                curIndex++;
            } else {
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

void Rook::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
