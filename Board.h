//
//  Board.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Board__
#define __Chess_Project__Board__

#include <stdio.h>
#include "Chess.h"
#include "Game_View.h"

class Game_View;

class Board{
protected:
    Chess*** Game_Board;
    char Turn;
public:
    Game_View *v;
    void SetView(Game_View *v);
    bool Check(char alias);
    bool Checkmate();
    bool Stalemate();
    void Make_Move(Move* A_Move);
    void Illegal_Move();
    Chess*** GetBoard();
    void SetBoard(Chess*** nb);
    int SimulateCheck(Move* A_Move);
    char GetTurn();
    void SetTurn(char turn);
    void UpdatePawn(std::string updateTo);
    void Restart_Game();
    Board(Game_View *v);
    ~Board();
};
#endif /* defined(__Chess_Project__Board__) */
