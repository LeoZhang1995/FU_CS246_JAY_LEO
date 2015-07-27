//
//  Human.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Human.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

Human::Human(std::string side, Board *b): Side(side), b(b), Score(0) {}

void Human::Make_Move(Move* A_Move) {
	Move** available = Available_Move(A_Move->Origin);
	int i = 0;
	bool legal = true;
	while (true) {
		if (available[i] == NULL) {
			legal = false;
			break;
		} else if ((available[i]->Origin == A_Move->Origin) && (available[i]->Destination == A_Move->Destination)) {
			delete A_Move;
			Move* A_Move = new Move(available[i]->Check, available[i]->Origin, available[i]->Destination, available[i]->Captures, available[i]->Captured);
			A_Move->Other = available[i]->Other;
			legal = true;
			break;
		}
		i++;
	}
	i = 0;
	while (available[i] != NULL) {
		i++;
		delete available[i];
	}
	delete [] available;
	if (legal) {
		b->Make_Move(A_Move);
	} else {
		delete A_Move;
		b->Illegal_Move();
	}
}

Move** Human::Available_Move(std::string position) {
    int ver = position[1] - '1';
    int hor = position[0] - 'a';
    return b->GetBoard()[ver][hor]->Available_Move();
}
