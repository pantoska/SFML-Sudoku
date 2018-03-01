#pragma once

//#include "Player.h"
#include "Game.h"
#include <string>

using namespace std;
using namespace sf;

struct Input {
	int val;
	string value;
	Text cell;
};

class Engine
{
private:
	Font font;
	Texture texture;
	enum engineState { GAME, GAMEOVER };
	engineState state;
	int CellSize, FontSize;
	void fillTable(int **m, int &size, RenderWindow &window);
	void setLevel(int **m, bool **b, int size, int difficulty);
	void selectCell(RenderWindow &window, int size, int &index, int **matrix, bool **bloc, Input &input);
	void drawSquare(RenderWindow &window, int **matrix, bool **bloc, int size, int index);
	bool checkRow(int **m, int size, int row, int value);
	bool checkColumn(int **m, int size, int column, int value);
	bool checkSquare(int **m, int size, int row, int column, int value);
	bool removing(bool bol[16], int t);
	bool checkWin(int **m, int size);
public:
	Engine();
	~Engine();
	bool runEngine(RenderWindow &window ,int _level);
};



