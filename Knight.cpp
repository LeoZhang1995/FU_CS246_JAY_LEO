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
using namespace std;

Knight::Knight(Board *b, string side, string position) {
    this->b = b;
    this->Side = side;
    this->Position = position;
    this->Alias = (side == "White") ? 'N' : 'n';
}

Move* Rook::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move *available = new Move[8];
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
    newHorIndex = hor + 2;
    if ((newVerIndex < 8) && (newHorIndex < 8) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver + 2;
    newHorIndex = hor + 1;
    if ((newVerIndex < 8) && (newHorIndex < 8) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver - 1;
    newHorIndex = hor - 2;
    if ((newVerIndex >= 0) && (newHorIndex >= 0) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver - 2;
    newHorIndex = hor - 1;
    if ((newVerIndex >= 0) && (newHorIndex >= 0) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver + 1;
    newHorIndex = hor - 2;
    if ((newVerIndex < 8) && (newHorIndex >= 0) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver + 2;
    newHorIndex = hor - 1;
    if ((newVerIndex < 8) && (newHorIndex >= 0) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver - 1;
    newHorIndex = hor + 2;
    if ((newVerIndex >= 0) && (newHorIndex < 8) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    newVerIndex = ver - 2;
    newHorIndex = hor + 1;
    if ((newVerIndex >= 0) && (newHorIndex < 8) && (b->Game_Board[newVerIndex][newHorIndex]->Side != Side)) {
        if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == ' ') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == '_')) {
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, NULL, captured);
            curIndex++;
        } else {
            if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'Q') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'q')) {
                captures = "Queen";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'R') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'r')) {
                captures = "Rook";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'B') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'b')) {
                captures = "Bishop";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'N') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'n')) {
                captures = "Knight";
            } else if ((b->Game_Board[newVerIndex][newHorIndex]->Alias == 'P') || (b->Game_Board[newVerIndex][newHorIndex]->Alias == 'p')) {
                captures = "Pawn";
            }
            newVer = '1' + newVerIndex;
            newHor = 'a' + newHorIndex;
            newPos = newHor + newVer;
            available[curIndex] = Move(check, Position, newPos, captures, captured);
            curIndex++;
        }
    }
    return available;
}
