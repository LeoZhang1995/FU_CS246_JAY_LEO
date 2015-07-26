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

Rook::Rook(Board *b, string side, string position) {
    this->b = b;
    this->Side = side;
    this->Position = position;
    this->Moved = false;
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
    string captures;
    for (int a = 0; a < 14; ++a)
    {
        available[a] = NULL;
    }
    for (int i = hor + 1; i < 8; ++i)
    {
        if ((b->Game_Board[ver][i]->Alias == ' ') || (b->Game_Board[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->Game_Board[ver][i]->Side == Side) {
            break;
        } else {
            if ((b->Game_Board[ver][i]->Alias == 'Q') || (b->Game_Board[ver][i]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[ver][i]->Alias == 'R') || (b->Game_Board[ver][i]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[ver][i]->Alias == 'B') || (b->Game_Board[ver][i]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[ver][i]->Alias == 'N') || (b->Game_Board[ver][i]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[ver][i]->Alias == 'P') || (b->Game_Board[ver][i]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = hor - 1; i >= 0; --i)
    {
        if ((b->Game_Board[ver][i]->Alias == ' ') || (b->Game_Board[ver][i]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->Game_Board[ver][i]->Side == Side) {
            break;
        } else {
            if ((b->Game_Board[ver][i]->Alias == 'Q') || (b->Game_Board[ver][i]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[ver][i]->Alias == 'R') || (b->Game_Board[ver][i]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[ver][i]->Alias == 'B') || (b->Game_Board[ver][i]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[ver][i]->Alias == 'N') || (b->Game_Board[ver][i]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[ver][i]->Alias == 'P') || (b->Game_Board[ver][i]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + ver;
            newHor = 'a' + i;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = ver + 1; i < 8; ++i)
    {
        if ((b->Game_Board[i][hor]->Alias == ' ') || (b->Game_Board[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->Game_Board[i][hor]->Side == Side) {
            break;
        } else {
            if ((b->Game_Board[i][hor]->Alias == 'Q') || (b->Game_Board[i][hor]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[i][hor]->Alias == 'R') || (b->Game_Board[i][hor]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[i][hor]->Alias == 'B') || (b->Game_Board[i][hor]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[i][hor]->Alias == 'N') || (b->Game_Board[i][hor]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[i][hor]->Alias == 'P') || (b->Game_Board[i][hor]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    for (int i = ver - 1; i >= 0; --i)
    {
        if ((b->Game_Board[i][hor]->Alias == ' ') || (b->Game_Board[i][hor]->Alias == '_')) {
            //TODO: checkmate, captured, invalid
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else if (b->Game_Board[i][hor]->Side == Side) {
            break;
        } else {
            if ((b->Game_Board[i][hor]->Alias == 'Q') || (b->Game_Board[i][hor]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[i][hor]->Alias == 'R') || (b->Game_Board[i][hor]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[i][hor]->Alias == 'B') || (b->Game_Board[i][hor]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[i][hor]->Alias == 'N') || (b->Game_Board[i][hor]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[i][hor]->Alias == 'P') || (b->Game_Board[i][hor]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + i;
            newHor = 'a' + hor;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    return available;
}
