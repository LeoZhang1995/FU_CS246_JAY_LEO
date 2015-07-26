//
//  Human.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Human.h"
#include <string>
#include <stdio.h>
using namespace std;

Human::Human(std::string side, Board *b): Side(side), b(b), Score(0) {}

void Human::Make_move(Move A_Move) {
	b->Make_Move(A_Move);
}
