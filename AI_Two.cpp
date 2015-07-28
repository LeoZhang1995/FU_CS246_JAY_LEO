//
//  AI_One.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "AI_Two.h"
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <stdio.h>
using namespace std;

void AI_Two::Make_Move(Move *A_Move){
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
    b->Make_Move(available[random_number]);
//        
//        
//        
// 	char chess_array[6]={'K','Q','B','R','N','P'};
//    srand(time(NULL));                                   // initialize random seed
//    int random_number = rand() % 6 + 1;
// 	char RandomChess = chess_array[random_number];
// 	if (RandomChess =='K')
// 	{
// 		/* code */
// 	}else if (RandomChess =='Q')
// 	{
// 		/* code */
// 	}else if (RandomChess =='B')
// 	{
// 		/* code */
// 	}else if (RandomChess =='R')
// 	{
// 		/* code */
// 	}else if (RandomChess =='N')
// 	{
// 		/* code */
// 	}else if (RandomChess =='P')
//    {
// 		/* code */
// 	}
}

AI_Two::AI_Two(std::string side, Board *b): Side(side), b(b), Score(0) {}

Move** AI_Two::Available_Move(std::string position) { return NULL; }

void AI_Two::IncreaseScore() {
	Score++;
}

int AI_Two::GetScore() {
	return Score;
}

string AI_Two::GetSide() {
	return Side;
}
