//
//  Graphical_Display.cpp
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#include "Graphical_Display.h"
#include <iostream>
#include "window.h"

void Graphical_Display::Read_Command(){
    std::string command, command1, command2, command3;
    while (std::cin>>command) {
        if(command == "game"){
            std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command, command1, command2, "");
        } else if (command == "move"){
            std::cin>>command1;
            std::cin>>command2;
            c->Interpreter(command, command1, command2, "");
        }
    }
}

void Graphical_Display::Print(Chess*** Game_Board, std::string otherMessage) {
    Xwindow w;
    
    //for (int i = Xwindow::White ; i <= Xwindow::Brown; i++) {
    //  w.fillRectangle(50 * i, 200, 50, 250, i);
    //}
    
    //w.fillRectangle(0, 0, 50, 50, Xwindow::Blue);
    //w.fillRectangle(0, 50, 50, 50, Xwindow::Brown);
    
    bool change_line = true;
    bool change = true;
    for (int i = 0; i < 8; ++i){
        if (change_line){
            for (int j = 0; j < 8; ++j){
                if (change){
                    change = false;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::White);
                }else{
                    change = true;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::Black);
                }
            }
            change_line = false;
        }else{
            for (int j = 0; j < 8; ++j){
                if (change){
                    change = false;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::Black);
                }else{
                    change = true;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::White);
                }
            }
            change_line = true;
        }
    }//print Board
    change_line = true;
    change = true;
    std::string tmp="";
    for (int i=7; i>=0 ; i--) {
        if (change_line){
            for (int j = 0; j < 8; ++j){
                if (change){
                    change = false;
                    tmp = Game_Board[i][j]->Alias;
                    w.drawBigString(((7-i)*50)+15,(j*50)+35, tmp, Xwindow::Black);
                }else{
                    change = true;
                    w.drawBigString(((7-i)*50)+15,(j*50)+35, tmp, Xwindow::White);
                }
            }
            change_line = false;
        }else{
            for (int j = 0; j < 8; ++j){
                if (change){
                    change = false;
                    w.drawBigString(((7-i)*50)+15,(j*50)+35, tmp, Xwindow::White);
                }else{
                    change = true;
                    w.drawBigString(((7-i)*50)+15,(j*50)+35, tmp, Xwindow::Black);
                }
            }
            change_line = true;
        }
    }//print Chess

    char c;
    std::cin >> c;
}

Graphical_Display::Text_Display(Game_Controller *c): c(c) {}