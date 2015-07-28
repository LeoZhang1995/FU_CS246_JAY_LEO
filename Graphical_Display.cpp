// //
// //  Graphical_Display.cpp
// //  Chess_Project
// //
// //  Created by JiaJun Zhou on 2015-07-16.
// //  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
// //

#include "Graphical_Display.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>
#include <string>
using namespace std;


// Graphical_Display::Text_Display(Game_Controller *c): c(c) {}

void Graphical_Display::Read_Command() {
    std::string command, command1, command2, command3;
    while (true) {
        std::cin>>command;
        if (cin.eof() || cin.fail()) {
            std::ostringstream p1s, p2s;
            p1s << c->GetSetup()->GetP1()->GetScore();
            p2s << c->GetSetup()->GetP2()->GetScore();
            string p1str(p1s.str());
            string p2str(p2s.str());
            w->drawString(50, 465, "Final Score:", Xwindow::Black);
            w->drawString(50, 480, "White: " + p1str, Xwindow::Black);
            w->drawString(50, 495, "Black: " + p2str, Xwindow::Black);
            break;
        }
        if (command == "game") {
            std::cin>>command1;
            std::cin>>command2;
            Type1 = command1;
            Type2 = command2;
            delete w;
            this->w = new Xwindow(500, 500);
            c->Interpreter(command, command1, command2, "");
        } else if (command == "move") {
            if (c->GetSetup()->GetBoard()->GetTurn() == 'w') {
                if (Type1 == "human") {
                    std::cin>>command1;
                    std::cin>>command2;
                    c->Interpreter(command, command1, command2, "");
                } else {
                    c->Interpreter(command, "", "", "");
                }
            } else {
                if (Type2 == "human") {
                    std::cin>>command1;
                    std::cin>>command2;
                    c->Interpreter(command, command1, command2, "");
                } else {
                    c->Interpreter(command, "", "", "");
                }
            }
        } else if (command == "resign") {
            c->Interpreter(command, "", "", "");
        } else if (command == "setup") {
            c->Interpreter(command, "", "", "");
        }
    }
}

void Graphical_Display::Read_Setup() {
    string command1, command2, command3;
    while (cin >> command1) {
        if (command1 == "+") {
            cin >> command2 >> command3;
            c->Interpreter(command1, command2, command3, "");
        } else if (command1 == "-") {
            cin >> command2;
            c->Interpreter(command1, command2, "", "");
        } else if (command1 == "=") {
            cin >> command2;
            c->Interpreter(command1, command2, "", "");
        } else if (command1 == "done") {
            break;
        }
    }
    c->Interpreter("done", "", "", "");
}

void Graphical_Display::Setup_Done() {
    c->Setup_Done();
}

void Graphical_Display::Read_One_Command(){
    if (c->GetSetup()->GetBoard()->GetTurn() == 'w') {
        if (Type1 != "human") {
            c->Interpreter("Q", "", "", "");
        } else {
            std::string command;
            std::cin >> command;
            if ((command == "Q") || (command == "R") ||
                (command == "N") || (command == "B")) {
                c->Interpreter(command, "", "", "");
            }
        }
    } else {
        if (Type2 != "human") {
            c->Interpreter("Q", "", "", "");
        } else {
            std::string command;
            std::cin >> command;
            if ((command == "Q") || (command == "R") ||
                (command == "N") || (command == "B")) {
                c->Interpreter(command, "", "", "");
            }
        }
    }
}

void Graphical_Display::Print(Chess*** Game_Board, std::string otherMessage) {
    bool change_line = true;
    bool change = true;
    for (int i = 1; i < 9; ++i){
        if (change_line){
            for (int j = 1; j < 9; ++j){
                if (change){
                    change = false;
                    w->fillRectangle(i*50, j*50, 50, 50, Xwindow::White);
                }else{
                    change = true;
                    w->fillRectangle(i*50, j*50, 50, 50, Xwindow::Black);
                }
            }
            change_line = false;
        }else{
            for (int j = 1; j < 9; ++j){
                if (change){
                    change = false;
                    w->fillRectangle(i*50, j*50, 50, 50, Xwindow::Black);
                }else{
                    change = true;
                    w->fillRectangle(i*50, j*50, 50, 50, Xwindow::White);
                }
            }
            change_line = true;
        }//print Board
    }
    if (Game_Board == NULL) {
        w->drawString(50, 480, otherMessage, Xwindow::Black);
    } else {
        change_line = true;
        change = true;
        std::string tmp="";
        int ver=0;
        int hor=0;
        for (int i=7; i>=0 ; i--) {
            ver++;
            if (change_line){
                for (int j = 0; j < 8; ++j){
                    hor++;
                    if (change){
                        change = false;
                        tmp = Game_Board[i][j]->Alias;
                        if (tmp == "_") {
                            tmp = " ";
                        }
                        w->drawBigString((hor*50)+15,(ver*50)+35, tmp, Xwindow::Black);
                    }else{
                        change = true;
                        tmp = Game_Board[i][j]->Alias;
                        if (tmp == "_") {
                            tmp = " ";
                        }
                        w->drawBigString((hor*50)+15,(ver*50)+35, tmp, Xwindow::White);
                    }
                }
                hor=0;
                change_line = false;
            }else{
                for (int j = 0; j < 8; ++j){
                    hor++;
                    if (change){
                        change = false;
                        tmp = Game_Board[i][j]->Alias;
                        if (tmp == "_") {
                            tmp = " ";
                        }
                        w->drawBigString((hor*50)+15,(ver*50)+35, tmp, Xwindow::White);
                    }else{
                        change = true;
                        tmp = Game_Board[i][j]->Alias;
                        if (tmp == "_") {
                            tmp = " ";
                        }
                        w->drawBigString((hor*50)+15,(ver*50)+35, tmp, Xwindow::Black);
                    }
                }
                hor=0;
                change_line = true;
            }
        }
        
        w->fillRectangle(45, 45, 5, 410, Xwindow::Black);
        
        w->fillRectangle(45, 45, 410, 5, Xwindow::Black);
        
        w->fillRectangle(45, 450, 410, 5, Xwindow::Black);
        
        w->fillRectangle(450, 45, 5, 410, Xwindow::Black);
        
        string my_array1[8] = {"8","7","6","5","4","3","2","1"};
        string my_array2[8] = {"a","b","c","d","e","f","g","h"};
        
        for (int i = 0; i < 8; ++i)
        {
            w->drawBigString(((i+1)*50)+15, 35, my_array2[i], Xwindow::Black);
        }
        
        for (int i = 0; i < 8; ++i)
        {
            w->drawBigString(15, ((i+1)*50)+35, my_array1[i], Xwindow::Black);
        }
        
        w->drawBigString(450 + 15, 50 + 35, "b", Xwindow::Black);
        
        w->drawBigString(450 + 15, 400 + 35, "W", Xwindow::Black);
        
        //string message = "Checkmate! " +  " Wins";
        
        //w.drawString(50, 450 + 25, message, Xwindow::Black);
        
        if (otherMessage != "") {
            w->drawString(50, 480, otherMessage, Xwindow::Black);
        }
    }
}

void Graphical_Display::Checkmate(std::string side) {
    
    string message = "Checkmate! " + side + " Wins";
    w->drawString(50, 480, message, Xwindow::Black);
    
    c->End_Game();
}

void Graphical_Display::Stalemate() {

    string message = "Stalemate!";
    w->drawString(50, 480, message, Xwindow::Black);

    c->Stalemate();
}

Graphical_Display::Graphical_Display(Game_Controller *c) {
    this->c = c;
    this->w = new Xwindow(500, 500);
    string tmp = "By: Peining Zhang & Jiajun Zhou";
    w->fillRectangle(0, 0, 500, 500, Xwindow::Brown);
    w->drawBigString(120,200, "PP9K: Chess Game", Xwindow::White);
    w->drawString(140,300, tmp, Xwindow::White);
}