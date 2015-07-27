//
//  Move.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include <stdio.h>
#include "Move.h"
#include <string>

using namespace std;

Move::Move(bool Check, string Origin, string Destination, string Captures, bool Captured): Check(Check), Origin(Origin), Destination(Destination), Captures(Captures), Captured(Captured) {}
//Too fucking long, TODO
