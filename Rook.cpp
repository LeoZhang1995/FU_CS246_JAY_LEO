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
using namespace std;

Rook::Rook(string side, string position) {
    this->b = NULL;
    this->Side = side;
    this->Position = position;
    this->Moved = false;
    this->Alias = (side == "White") ? 'R' : 'r';
}

Move** Rook::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move** available = new Move*[14];
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos;
    char newVer;
    char newHor;
    string captures;
    for (int a = 0; a < 14; ++a)
    {
        available[a] = NULL;
    }
    for (int i = hor + 1; i < 8; ++i)
    {
        if ((b->GetBoard()[ver][i]->Alias == ' ') || (b->GetBoard()[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->GetBoard()[ver][i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver][i]->Alias == 'Q') || (b->GetBoard()[ver][i]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[ver][i]->Alias == 'B') || (b->GetBoard()[ver][i]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[ver][i]->Alias == 'N') || (b->GetBoard()[ver][i]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[ver][i]->Alias == 'P') || (b->GetBoard()[ver][i]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = hor - 1; i >= 0; --i)
    {
        if ((b->GetBoard()[ver][i]->Alias == ' ') || (b->GetBoard()[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->GetBoard()[ver][i]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[ver][i]->Alias == 'Q') || (b->GetBoard()[ver][i]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[ver][i]->Alias == 'R') || (b->GetBoard()[ver][i]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[ver][i]->Alias == 'B') || (b->GetBoard()[ver][i]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[ver][i]->Alias == 'N') || (b->GetBoard()[ver][i]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[ver][i]->Alias == 'P') || (b->GetBoard()[ver][i]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = ver + 1; i < 8; ++i)
    {
        if ((b->GetBoard()[i][hor]->Alias == ' ') || (b->GetBoard()[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->GetBoard()[i][hor]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[i][hor]->Alias == 'Q') || (b->GetBoard()[i][hor]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[i][hor]->Alias == 'R') || (b->GetBoard()[i][hor]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[i][hor]->Alias == 'B') || (b->GetBoard()[i][hor]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[i][hor]->Alias == 'N') || (b->GetBoard()[i][hor]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[i][hor]->Alias == 'P') || (b->GetBoard()[i][hor]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = ver - 1; i >= 0; --i)
    {
        if ((b->GetBoard()[i][hor]->Alias == ' ') || (b->GetBoard()[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->GetBoard()[i][hor]->Side == Side) {
            break;
        } else {
            if ((b->GetBoard()[i][hor]->Alias == 'Q') || (b->GetBoard()[i][hor]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->GetBoard()[i][hor]->Alias == 'R') || (b->GetBoard()[i][hor]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->GetBoard()[i][hor]->Alias == 'B') || (b->GetBoard()[i][hor]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->GetBoard()[i][hor]->Alias == 'N') || (b->GetBoard()[i][hor]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->GetBoard()[i][hor]->Alias == 'P') || (b->GetBoard()[i][hor]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = new Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    return available;
}

void Rook::SetBoard(Board *b) {
    if (this->b == NULL) {
        this->b = b;
    }
}
