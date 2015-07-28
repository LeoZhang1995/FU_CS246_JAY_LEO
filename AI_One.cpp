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

void AI_One::Make_move(Move *A_Move){
    Move** available = Available_Move(A_Move->Origin);
    int length = 0;
    while (available[length]!=NULL) {
        length++;
    }
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

AI_One::AI_One(std::string side, Board *b): Side(side), b(b), Score(0) {}

void AI_One::Suggest_move(){}

Move** AI_One::Available_Move(std::string position) {
    int ver = position[1] - '1';
    int hor = position[0] - 'a';
    return b->GetBoard()[ver][hor]->Available_Move();
}
