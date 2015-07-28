//
//  Text_Display.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Text_Display.h"
#include <iostream>
#include <string>
using namespace std;

void Text_Display::Read_Command(){
    std::string command, command1, command2, command3;
    while (true) {
    	std::cin>>command;
    	if (cin.eof() || cin.fail()) {
    		cout << "Final Score:" << endl;
    		cout << "White: " << c->GetSetup()->GetP1()->GetScore() << endl;
    		cout << "Black: " << c->GetSetup()->GetP2()->GetScore() << endl;
    		break;
    	}
        if (command == "game") {
            std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command, command1, command2, "");
        } else if (command == "move") {
        	std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command, command1, command2, "");
        }
    }
}

void Text_Display::Read_One_Command(){
	std::string command;
	std::cin >> command;
	if ((command == "Q") || (command == "R") ||
    	(command == "N") || (command == "B")) {
    	c->Interpreter(command, "", "", "");
    }
}

void Text_Display::Print(Chess*** Game_Board, std::string otherMessage) {
    for (int i=7; i>=0 ; i--) {
        std::cout<<i+1<<" ";
        for (int j=0; j<=7; j++) {
            std::cout<<Game_Board[i][j]->Alias;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"  abcdefgh"<<std::endl;
    if (otherMessage != "") {
		std::cout<<otherMessage<<std::endl;
	}
}

void Text_Display::Checkmate(std::string side) {
	cout << "Checkmate! " << side << " Wins" << endl;
	c->End_Game();
}

Text_Display::Text_Display(Game_Controller *c): c(c) {}
