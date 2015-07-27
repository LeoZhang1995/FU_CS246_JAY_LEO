all: pp9k

pp9k: main.o Game_Controller.o Game_View.o Graphical_Display.o Text_Display.o Game_Setup.o AI_Four.o Pawn.o AI_One.o Player.o AI_Three.o Queen.o AI_Two.o Rook.o Bishop.o Human.o Black_Block.o King.o White_Block.o Board.o Knight.o Chess.o Move.o
	g++ main.o Game_Controller.o Game_View.o Graphical_Display.o Text_Display.o Game_Setup.o AI_Four.o Pawn.o AI_One.o Player.o AI_Three.o Queen.o AI_Two.o Rook.o Bishop.o Human.o Black_Block.o King.o White_Block.o Board.o Knight.o Chess.o Move.o -o pp9k

main.o: main.cpp
	g++ -c main.cpp

Game_Controller.o: Game_Controller.cpp
	g++ -c Game_Controller.cpp

Game_View.o: Game_View.cpp
	g++ -c Game_View.cpp

Graphical_Display.o: Graphical_Display.cpp
	g++ -c Graphical_Display.cpp

Text_Display.o: Text_Display.cpp
	g++ -c Text_Display.cpp

Game_Setup.o: Game_Setup.cpp
	g++ -c Game_Setup.cpp

AI_Four.o: AI_Four.cpp
	g++ -c AI_Four.cpp

Pawn.o: Pawn.cpp
	g++ -c Pawn.cpp

AI_One.o: AI_One.cpp
	g++ -c AI_One.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

AI_Three.o: AI_Three.cpp
	g++ -c AI_Three.cpp

Game_View.o: Game_View.cpp
	g++ -c Game_View.cpp

Queen.o: Queen.cpp
	g++ -c Queen.cpp

AI_Two.o: AI_Two.cpp
	g++ -c AI_Two.cpp

Rook.o: Rook.cpp
	g++ -c Rook.cpp

Bishop.o: Bishop.cpp
	g++ -c Bishop.cpp

Human.o: Human.cpp
	g++ -c Human.cpp

Black_Block.o: Black_Block.cpp
	g++ -c Black_Block.cpp

King.o: King.cpp
	g++ -c King.cpp

White_Block.o: White_Block.cpp
	g++ -c White_Block.cpp

Board.o: Board.cpp
	g++ -c Board.cpp

Knight.o: Knight.cpp
	g++ -c Knight.cpp

Chess.o: Chess.cpp
	g++ -c Chess.cpp

Move.o: Move.cpp
	g++ -c Move.cpp

clean:
	rm *o pp9k