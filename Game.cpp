#include "Game.h"

RenderWindow window(VideoMode(800, 600), "Sudoku", sf::Style::Titlebar | sf::Style::Close);


Game::Game()
{
	state = END;

	if (!font.loadFromFile("Andada-Bold.otf"))
		return;

	state = MENU;
}


Game::~Game(void)
{
}


void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
			menu();
			break;
		case GameState::AUTHOR:
			author();
			break;
		case GameState::GAME:
			levels();
			break;
		}		
	}
}


void Game::menu()
{
	//window.setFramerateLimit(60);
	Text title("Sudoku", font, 80);
	title.setStyle(Text::Bold);

	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 60);

	const int ile = 3;

	Text tekst[ile];

	string str[] = { "Play","Author","Exit" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 200 + i * 120);
	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			//klikniêcie MENU                                        
			else if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
			}

			//klikniecie AUTHOR
			else if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = AUTHOR;
			}

			//klikniêcie EXIT
			else if (tekst[2].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
		}
		for (int i = 0; i<ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Red);
			else tekst[i].setColor(Color::White);

			window.clear();

			window.draw(title);
			for (int i = 0; i<ile; i++)
				window.draw(tekst[i]);

			window.display();
	}
}

void Game::levels()
{
	sf::Text title("Levels", font, 90);
	title.setStyle(sf::Text::Bold);

	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 30);
	title.setStyle(sf::Text::Bold);
	
	string easy, medium, hard;
	const int ile = 4;

	sf::Text tekst[ile];

	std::string aut[] = { "Easy","Medium","Hard", "back" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);
		tekst[i].setString(aut[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 150 + i * 120);
	}


	while (state == GAME && window.isOpen())
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;
		Engine engine;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (tekst[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				if (engine.runEngine(window,0))
					state = GAME;
				else
					state = MENU;
			}

			else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (engine.runEngine(window, 1))
					state = GAME;
				else
					state = MENU;
			}

			else if (tekst[2].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (engine.runEngine(window, 2))
					state = GAME;
				else
					state = MENU;
			}

			else if (tekst[3].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				state = MENU;
			}
		}

		for (int i = 0; i<ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Red);
			else tekst[i].setColor(Color::White);


		window.clear();
		window.draw(title);
		for (int i = 0; i<ile; i++)
			window.draw(tekst[i]);
		window.display();
	}
	
}

void Game::author()
{
	sf::Text title("Author", font, 90);
	title.setStyle(sf::Text::Bold);

	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 60);
	title.setStyle(sf::Text::Bold);

	const int ile = 2;

	sf::Text tekst[ile];

	std::string aut[] = { "Patrycja Zan", "back" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);
		tekst[i].setString(aut[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 200 + i * 120);
	}


	while (state == AUTHOR && window.isOpen())
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//klikniecie EXIT
			else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				state = MENU;
			}
		}
		
		if (tekst[1].getGlobalBounds().contains(mouse))
			tekst[1].setColor(Color::Red);
		else tekst[1].setColor(Color::White);


		window.clear();
		window.draw(title);
		for (int i = 0; i<ile; i++)
			window.draw(tekst[i]);
		window.display();
	}
}
