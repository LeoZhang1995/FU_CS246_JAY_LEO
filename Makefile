all: pp9k

pp9k: main.o Game_Controller.o Game_View.o Graphical_Display.o Window.o Text_Display.o Game_Setup.o AI_Four.o Pawn.o AI_One.o Player.o AI_Three.o Queen.o AI_Two.o Rook.o Bishop.o Human.o Black_Block.o King.o White_Block.o Board.o Knight.o Chess.o Move.o
	g++ main.o Game_Controller.o Game_View.o Graphical_Display.o Window.o Text_Display.o Game_Setup.o AI_Four.o Pawn.o AI_One.o Player.o AI_Three.o Queen.o AI_Two.o Rook.o Bishop.o Human.o Black_Block.o King.o White_Block.o Board.o Knight.o Chess.o Move.o -o pp9k  -lX11

main.o: main.cpp
	g++ -c -g main.cpp

Game_Controller.o: Game_Controller.cpp
	g++ -c -g Game_Controller.cpp

Game_View.o: Game_View.cpp
	g++ -c -g Game_View.cpp

Graphical_Display.o: Graphical_Display.cpp
	g++ -c Graphical_Display.cpp -lX11

Window.o: Window.cc
	g++ -c Window.cc -lX11

Text_Display.o: Text_Display.cpp
	g++ -c -g Text_Display.cpp

Game_Setup.o: Game_Setup.cpp
	g++ -c -g Game_Setup.cpp

AI_Four.o: AI_Four.cpp
	g++ -c -g AI_Four.cpp

Pawn.o: Pawn.cpp
	g++ -c -g Pawn.cpp

AI_One.o: AI_One.cpp
	g++ -c -g AI_One.cpp

Player.o: Player.cpp
	g++ -c -g Player.cpp

AI_Three.o: AI_Three.cpp
	g++ -c -g AI_Three.cpp

Game_View.o: Game_View.cpp
	g++ -c -g Game_View.cpp

Queen.o: Queen.cpp
	g++ -c -g Queen.cpp

AI_Two.o: AI_Two.cpp
	g++ -c -g AI_Two.cpp

Rook.o: Rook.cpp
	g++ -c -g Rook.cpp

Bishop.o: Bishop.cpp
	g++ -c -g Bishop.cpp

Human.o: Human.cpp
	g++ -c -g Human.cpp

Black_Block.o: Black_Block.cpp
	g++ -c -g Black_Block.cpp

King.o: King.cpp
	g++ -c -g King.cpp

White_Block.o: White_Block.cpp
	g++ -c -g White_Block.cpp

Board.o: Board.cpp
	g++ -c -g Board.cpp

Knight.o: Knight.cpp
	g++ -c -g Knight.cpp

Chess.o: Chess.cpp
	g++ -c -g Chess.cpp

Move.o: Move.cpp
	g++ -c -g Move.cpp

clean:
	rm *o pp9k