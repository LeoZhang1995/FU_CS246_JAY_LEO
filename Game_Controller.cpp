//
//  Game_Controller.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Game_Controller.h"
#include "Human.h"
#include <string>
#include <stdio.h>
#include "AI_One.h"
#include "AI_Two.h"
#include "AI_Three.h"
#include "AI_Four.h"
using namespace std;

Game_Controller::Game_Controller() {
    this->s = NULL;
}

void Game_Controller::Interpreter(string A_String, string B_String, string C_String, string D_String) {
	if (A_String == "game") {
		s->Start_Game();
		if ((B_String == "human")&&(C_String == "human"))  {                // human VS human
            Player *p1 = new Human("White", s->GetBoard());
			s->SetP1(p1);
            Player *p2 = new Human("Black", s->GetBoard());
            s->SetP2(p2);
//        }else if ((B_String == "human")&&(C_String == "computer1"))  {      // human VS computer1
//            Player *p1 = new Human("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_One("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "human")&&(C_String == "computer2"))  {      // human VS computer2
//            Player *p1 = new Human("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Two("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "human")&&(C_String == "computer3"))  {      // human VS computer3
//            Player *p1 = new Human("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Three("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "human")&&(C_String == "computer4"))  {      // human VS computer4
//            Player *p1 = new Human("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Four("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer1")&&(C_String == "human"))  {      // computer1 VS human
//            Player *p1 = new AI_One("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new Human("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer2")&&(C_String == "human"))  {      // computer2 VS human
//            Player *p1 = new AI_Two("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new Human("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer3")&&(C_String == "human"))  {      // computer3 VS human
//            Player *p1 = new AI_Three("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new Human("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer4")&&(C_String == "human"))  {      // computer4 VS human
//            Player *p1 = new AI_Four("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new Human("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer1")&&(C_String == "computer1"))  {  // computer1 VS computer1
//            Player *p1 = new AI_One("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_One("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer1")&&(C_String == "computer2"))  {  // computer1 VS computer2
//            Player *p1 = new AI_One("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Two("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer1")&&(C_String == "computer3"))  {  // computer1 VS computer3
//            Player *p1 = new AI_One("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Three("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer1")&&(C_String == "computer4"))  {  // computer1 VS computer4
//            Player *p1 = new AI_One("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Four("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer2")&&(C_String == "computer1"))  {  // computer2 VS computer1
//            Player *p1 = new AI_Two("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_One("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer2")&&(C_String == "computer2"))  {  // computer2 VS computer2
//            Player *p1 = new AI_Two("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Two("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer2")&&(C_String == "computer3"))  {  // computer2 VS computer3
//            Player *p1 = new AI_Two("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Three("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer2")&&(C_String == "computer4"))  {  // computer2 VS computer4
//            Player *p1 = new AI_Two("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Four("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer3")&&(C_String == "computer1"))  {  // computer3 VS computer1
//            Player *p1 = new AI_Three("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_One("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer3")&&(C_String == "computer2"))  {  // computer3 VS computer2
//            Player *p1 = new AI_Three("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Two("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer3")&&(C_String == "computer3"))  {  // computer3 VS computer3
//            Player *p1 = new AI_Three("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Three("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer3")&&(C_String == "computer4"))  {  // computer3 VS computer4
//            Player *p1 = new AI_Three("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Four("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer4")&&(C_String == "computer1"))  {  // computer4 VS computer1
//            Player *p1 = new AI_Four("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_One("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer4")&&(C_String == "computer2"))  {  // computer4 VS computer2
//            Player *p1 = new AI_Four("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Two("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer4")&&(C_String == "computer3"))  {  // computer4 VS computer3
//            Player *p1 = new AI_Four("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Three("Black", s->GetBoard());
//            s->SetP2(p2);
//        }else if ((B_String == "computer4")&&(C_String == "computer4"))  {  // computer4 VS computer4
//            Player *p1 = new AI_Four("White", s->GetBoard());
//            s->SetP1(p1);
//            Player *p2 = new AI_Four("Black", s->GetBoard());
//            s->SetP2(p2);
        }
		//TODO: Other levels of AI
    } else if (A_String == "move") {
        if (s->GetBoard()->GetTurn() == 'w') {
            Move *newMove = new Move(false, B_String, C_String, "", false);
            s->GetP1()->Make_Move(newMove);
        } else {
            Move *newMove = new Move(false, B_String, C_String, "", false);
            s->GetP2()->Make_Move(newMove);
        }
    }
}

void Game_Controller::Setup(Game_Setup *s) {
    this->s = s;
}
