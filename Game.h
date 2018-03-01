#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Engine.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game(void);
	~Game(void);
	void runGame();
private:
	Font font;
	enum GameState { MENU, GAME, AUTHOR, END };
	GameState state;
	void levels();
	void single();
	void author();
	void menu();
};

	

