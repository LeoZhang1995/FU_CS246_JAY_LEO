//
//  AI_One.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "AI_One.h"
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <stdio.h>
using namespace std;

void AI_One::Make_Move(Move *A_Move){
    Move** available = new Move* [137];
    for (int i = 0; i < 137; ++i)
    {
    	available[i] = NULL;
    }
    cout << "FUCK" << endl;
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

AI_One::AI_One(std::string side, Board *b): Side(side), b(b), Score(0) {}

Move** AI_One::Available_Move(std::string position) { return NULL; }

void AI_One::IncreaseScore() {
	Score++;
}

int AI_One::GetScore() {
	return Score;
}

string AI_One::GetSide() {
	return Side;
}
