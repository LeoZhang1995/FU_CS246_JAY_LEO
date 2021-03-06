//
//  AI_One.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "AI_Three.h"
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <stdio.h>
using namespace std;

void AI_Three::Make_Move(Move *A_Move){
    Move** available = new Move* [137];
    for (int i = 0; i < 137; ++i)
    {
    	available[i] = NULL;
    }
    int curIndex = 0;
    int singleIndex = 0;
    Move** singleAvailable;
    int length = 0;
    int numChess = 0;
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		if (b->GetBoard()[i][j]->Side == Side) {
    			singleIndex = 0;
    			++numChess;
    			singleAvailable = b->GetBoard()[i][j]->Available_Move();
    			if (singleAvailable == NULL) {
					continue;
				}
    			while (singleAvailable[singleIndex] != NULL) {
    				available[curIndex] = new Move(singleAvailable[singleIndex]->Check, singleAvailable[singleIndex]->Origin, singleAvailable[singleIndex]->Destination, singleAvailable[singleIndex]->Captures, singleAvailable[singleIndex]->Captured);
    				delete singleAvailable[singleIndex];
    				curIndex++;
    				singleIndex++;
    			}
    			delete [] singleAvailable;
    		}
    	}
    }
    length = curIndex;
    srand(time(NULL));                                   // initialize random seed
    int random_number = rand() % length;
    Move* moveChosen = new Move(available[random_number]->Check, available[random_number]->Origin, available[random_number]->Destination, available[random_number]->Captures, available[random_number]->Captured);
    for (int i = 0; i < length; ++i)
    {
    	delete available[i];
    }
    delete [] available;
    b->Make_Move(moveChosen);
}

AI_Three::AI_Three(std::string side, Board *b): Side(side), b(b), Score(0) {}

Move** AI_Three::Available_Move(std::string position) { return NULL; }

void AI_Three::IncreaseScore(float point) {
	Score += point;
}

float AI_Three::GetScore() {
	return Score;
}

string AI_Three::GetSide() {
	return Side;
}
