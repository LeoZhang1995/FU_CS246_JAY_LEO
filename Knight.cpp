//
//  Knight.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Knight.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

Knight::Knight(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Alias = (side == "White") ? 'N' : 'n';
}

Chess* Knight::CopyChess() {
    Chess *chess = new Knight(Side, Position);
    return chess;
}

Move** Knight::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[9];
    Move* test;
    int testResult;
    for (int a = 0; a < 9; ++a)
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
    newHorIndex = hor + 2;
    if ((newVerIndex < 8) && (newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newVerIndex = ver + 2;
    newHorIndex = hor + 1;
    if ((newVerIndex < 8) && (newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newHorIndex = hor - 2;
    if ((newVerIndex >= 0) && (newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newVerIndex = ver - 2;
    newHorIndex = hor - 1;
    if ((newVerIndex >= 0) && (newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newVerIndex = ver + 1;
    newHorIndex = hor - 2;
    if ((newVerIndex < 8) && (newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newVerIndex = ver + 2;
    newHorIndex = hor - 1;
    if ((newVerIndex < 8) && (newHorIndex >= 0) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newHorIndex = hor + 2;
    if ((newVerIndex >= 0) && (newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    newVerIndex = ver - 2;
    newHorIndex = hor + 1;
    if ((newVerIndex >= 0) && (newHorIndex < 8) && (b->GetBoard()[newVerIndex][newHorIndex]->Side != Side)) {
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
    if (curIndex == 0) {
        return NULL;
    } else {
        return available;
    }
}

void Knight::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
