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

Knight::Knight(Board *b, string side, string Position) {
    this->b = b;
    this->Side = side;
    this->Position = Position;
    this->Alias = (side == "White") ? 'K' : 'k';
}

Move* Rook::Available_Move() {
    int ver = Position[1] - '1';
    int hor = Position[0] - 'a';
    Move *available = new Move[8];
    for (int a = 0; a < 8; ++a)
    {
        available[a] = Null;
    }
    int curIndex = 0;
    bool check = false;
    bool captured = false;
    string newPos;
    char newVer;
    char newHor;
    int rating = 0;
    string captures;
}