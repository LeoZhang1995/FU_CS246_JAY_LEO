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

void Text_Display::Read_Command(){
    std::string command, command1, command2, command3;
    while (std::cin>>command) {
        if(command == "game"){
            std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command1, command2, command3);
        } else if (command == "move"){
        	std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command1, command2, command3);
};

void Text_Display::Print(std::string A_String){
    for (int i=7; i>=0 ; i--) {
        std::cout<<i+1<<" ";
        for (int j=0; j<=7; j++) {
            std::cout<<Borad[i][j]->Alias;
        }
        std::cout<<std::endl;
        std::cout<<"  abcdefgh"<<std::endl;
    }
}

Text_Display::Text_Display(){};

Text_Display::~Text_Display(){};