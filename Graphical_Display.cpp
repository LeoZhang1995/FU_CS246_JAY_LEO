// //
// //  Graphical_Display.cpp
// //  Chess_Project
// //
// //  Created by JiaJun Zhou on 2015-07-16.
// //  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
// //

#include "Graphical_Display.h"
#include <iostream>
#include <string>
#include "Window.h"
using namespace std;


// Graphical_Display::Text_Display(Game_Controller *c): c(c) {}

void Graphical_Display::Read_Command() {
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
            Type1 = command1;
            Type2 = command2;
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
    Xwindow w;
    
    bool change_line = true;
    bool change = true;
    for (int i = 1; i < 9; ++i){
        if (change_line){
            for (int j = 1; j < 9; ++j){
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
            for (int j = 1; j < 9; ++j){
                if (change){
                    change = false;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::Black);
                }else{
                    change = true;
                    w.fillRectangle(i*50, j*50, 50, 50, Xwindow::White);
                }
            }
            change_line = true;
        }//print Board
    }
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
                    tmp = Game_Board[j][i]->Alias;
                    if (tmp == "_") {
                        tmp = " ";
                    }
                    w.drawBigString((ver*50)+15,(hor*50)+35, tmp, Xwindow::Black);
                }else{
                    change = true;
                    tmp = Game_Board[j][i]->Alias;
                    if (tmp == "_") {
                        tmp = " ";
                    }
                    w.drawBigString((ver*50)+15,(hor*50)+35, tmp, Xwindow::White);
                }
            }
            hor=0;
            change_line = false;
        }else{
            for (int j = 0; j < 8; ++j){
                hor++;
                if (change){
                    change = false;
                    tmp = Game_Board[j][i]->Alias;
                    if (tmp == "_") {
                        tmp = " ";
                    }
                    w.drawBigString((ver*50)+15,(hor*50)+35, tmp, Xwindow::White);
                }else{
                    change = true;
                    tmp = Game_Board[j][i]->Alias;
                    if (tmp == "_") {
                        tmp = " ";
                    }
                    w.drawBigString((ver*50)+15,(hor*50)+35, tmp, Xwindow::Black);
                }
            }
            hor=0;
            change_line = true;
        }
    }//print Chess
    
    /*
     w.drawBigString(50 + 15, 50 + 35, "R", Xwindow::Black);
     w.drawBigString(100 + 15, 50 + 35, "N", Xwindow::White);
     w.drawBigString(150 + 15, 50 + 35, "B", Xwindow::Black);
     w.drawBigString(200 + 15, 50 + 35, "Q", Xwindow::White);
     w.drawBigString(250 + 15, 50 + 35, "K", Xwindow::Black);
     w.drawBigString(300 + 15, 50 + 35, "B", Xwindow::White);
     w.drawBigString(350 + 15, 50 + 35, "N", Xwindow::Black);
     w.drawBigString(400 + 15, 50 + 35, "R", Xwindow::White);
     
     w.drawBigString(50 + 15, 100 + 35, "P", Xwindow::White);
     w.drawBigString(100 + 15, 100 + 35, "P", Xwindow::Black);
     w.drawBigString(150 + 15, 100 + 35, "P", Xwindow::White);
     w.drawBigString(200 + 15, 100 + 35, "P", Xwindow::Black);
     w.drawBigString(250 + 15, 100 + 35, "P", Xwindow::White);
     w.drawBigString(300 + 15, 100 + 35, "P", Xwindow::Black);
     w.drawBigString(350 + 15, 100 + 35, "P", Xwindow::White);
     w.drawBigString(400 + 15, 100 + 35, "P", Xwindow::Black);
     
     w.drawBigString(50 + 15, 350 + 35, "p", Xwindow::Black);
     w.drawBigString(100 + 15, 350 + 35, "p", Xwindow::White);
     w.drawBigString(150 + 15, 350 + 35, "p", Xwindow::Black);
     w.drawBigString(200 + 15, 350 + 35, "p", Xwindow::White);
     w.drawBigString(250 + 15, 350 + 35, "p", Xwindow::Black);
     w.drawBigString(300 + 15, 350 + 35, "p", Xwindow::White);
     w.drawBigString(350 + 15, 350 + 35, "p", Xwindow::Black);
     w.drawBigString(400 + 15, 350 + 35, "p", Xwindow::White);
     
     w.drawBigString(50 + 15,400 + 35, "r", Xwindow::White);
     w.drawBigString(100 + 15, 400 + 35, "n", Xwindow::Black);
     w.drawBigString(150 + 15, 400 + 35, "b", Xwindow::White);
     w.drawBigString(200 + 15, 400 + 35, "q", Xwindow::Black);
     w.drawBigString(250 + 15, 400 + 35, "k", Xwindow::White);
     w.drawBigString(300 + 15, 400 + 35, "b", Xwindow::Black);
     w.drawBigString(350 + 15, 400 + 35, "n", Xwindow::White);
     w.drawBigString(400 + 15, 400 + 35, "r", Xwindow::Black);
    */
    
    w.fillRectangle(45, 45, 5, 410, Xwindow::Black);
    
    w.fillRectangle(45, 45, 410, 5, Xwindow::Black);
    
    w.fillRectangle(45, 450, 410, 5, Xwindow::Black);
    
    w.fillRectangle(450, 45, 5, 410, Xwindow::Black);
    
    string my_array1[8] = {"1","2","3","4","5","6","7","8"} ;
    string my_array2[8] = {"a","b","c","d","e","f","g","h"};
    
    for (int i = 0; i < 8; ++i)
    {
        w.drawBigString(((i+1)*50)+15, 35, my_array2[i], Xwindow::Black);
    }
    
    for (int i = 0; i < 8; ++i)
    {
        w.drawBigString(15, ((i+1)*50)+35, my_array1[i], Xwindow::Black);
    }
    
    w.drawBigString(450 + 15, 50 + 35, "W", Xwindow::Black);
    
    w.drawBigString(450 + 15, 400 + 35, "b", Xwindow::Black);
    
    //string message = "Checkmate! " +  " Wins";
    
    //w.drawString(50, 450 + 25, message, Xwindow::Black);
    
    if (otherMessage != "") {
        std::cout<<otherMessage<<std::endl;
    }
}

void Graphical_Display::Checkmate(std::string side) {
    
    //string message = "Checkmate! " + side +  " Wins";
    //w.drawString(50, 450 + 25, message, Xwindow::Black);
    
    c->End_Game();
}

void Graphical_Display::Stalemate() {
    c->Stalemate();
}

Graphical_Display::Graphical_Display(Game_Controller *c): c(c) {}