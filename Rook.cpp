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

Rook::Rook(Board *b, string side, string Position) {
    this->b = b;
    this->Side = side;
    this->Position = Position;
    this->Alias = (side == "White") ? 'R' : 'r';
}

Move* Rook::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move *available = new Move[14];
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos;
    char newVer;
    char newHor;
    int rating = 0;
    string captures;
    for (int a = 0; a < 14; ++a)
    {
        available[a] = Null;
    }
    for (int i = hor + 1; i < 8; ++i)
    {
        if ((b[ver][i]->Alias == ' ') || (b[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, Null, captured, rating);
            curIndex++;
            rating = 0;
        } else if (b[ver][i]->Side == Side) {
            break;
        } else {
            if ((b[ver][i]->Alias == 'Q') || (b[ver][i]->Alias == 'q')) {
                rating += 10;
                captures = "Queen";
            } else if ((b[ver][i]->Alias == 'R') || (b[ver][i]->Alias == 'r')) {
                rating += 6;
                captures = "Rook";
            } else if ((b[ver][i]->Alias == 'B') || (b[ver][i]->Alias == 'b')) {
                rating += 5;
                captures = "Bishop";
            } else if ((b[ver][i]->Alias == 'N') || (b[ver][i]->Alias == 'n')) {
                rating += 5;
                captures = "Knight";
            } else if ((b[ver][i]->Alias == 'P') || (b[ver][i]->Alias == 'p')) {
                rating += 1;
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, captures, captured, rating);
            curIndex++;
            rating = 0;
        }
    }
    for (int i = hor - 1; i >= 0; --i)
    {
        if ((b[ver][i]->Alias == ' ') || (b[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, Null, captured, rating);
            curIndex++;
            rating = 0;
        } else if (b[ver][i]->Side == Side) {
            break;
        } else {
            if ((b[ver][i]->Alias == 'Q') || (b[ver][i]->Alias == 'q')) {
                rating += 10;
                captures = "Queen";
            } else if ((b[ver][i]->Alias == 'R') || (b[ver][i]->Alias == 'r')) {
                rating += 6;
                captures = "Rook";
            } else if ((b[ver][i]->Alias == 'B') || (b[ver][i]->Alias == 'b')) {
                rating += 5;
                captures = "Bishop";
            } else if ((b[ver][i]->Alias == 'N') || (b[ver][i]->Alias == 'n')) {
                rating += 5;
                captures = "Knight";
            } else if ((b[ver][i]->Alias == 'P') || (b[ver][i]->Alias == 'p')) {
                rating += 1;
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, captures, captured, rating);
            curIndex++;
            rating = 0;
        }
    }
    for (int i = ver + 1; i < 8; ++i)
    {
        if ((b[i][hor]->Alias == ' ') || (b[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, Null, captured, rating);
            curIndex++;
            rating = 0;
        } else if (b[i][hor]->Side == Side) {
            break;
        } else {
            if ((b[i][hor]->Alias == 'Q') || (b[i][hor]->Alias == 'q')) {
                rating += 10;
                captures = "Queen";
            } else if ((b[i][hor]->Alias == 'R') || (b[i][hor]->Alias == 'r')) {
                rating += 6;
                captures = "Rook";
            } else if ((b[i][hor]->Alias == 'B') || (b[i][hor]->Alias == 'b')) {
                rating += 5;
                captures = "Bishop";
            } else if ((b[i][hor]->Alias == 'N') || (b[i][hor]->Alias == 'n')) {
                rating += 5;
                captures = "Knight";
            } else if ((b[i][hor]->Alias == 'P') || (b[i][hor]->Alias == 'p')) {
                rating += 1;
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, captures, captured, rating);
            curIndex++;
            rating = 0;
        }
    }
    for (int i = ver - 1; i >= 0; --i)
    {
        if ((b[i][hor]->Alias == ' ') || (b[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, Null, captured, rating);
            curIndex++;
            rating = 0;
        } else if (b[i][hor]->Side == Side) {
            break;
        } else {
            if ((b[i][hor]->Alias == 'Q') || (b[i][hor]->Alias == 'q')) {
                rating += 10;
                captures = "Queen";
            } else if ((b[i][hor]->Alias == 'R') || (b[i][hor]->Alias == 'r')) {
                rating += 6;
                captures = "Rook";
            } else if ((b[i][hor]->Alias == 'B') || (b[i][hor]->Alias == 'b')) {
                rating += 5;
                captures = "Bishop";
            } else if ((b[i][hor]->Alias == 'N') || (b[i][hor]->Alias == 'n')) {
                rating += 5;
                captures = "Knight";
            } else if ((b[i][hor]->Alias == 'P') || (b[i][hor]->Alias == 'p')) {
                rating += 1;
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            if (check) {
                rating += 20;
            }
            available[curIndex] = Move(check, Position, newPos, captures, captured, rating);
            curIndex++;
            rating = 0;
        }
    }
    return available;
}