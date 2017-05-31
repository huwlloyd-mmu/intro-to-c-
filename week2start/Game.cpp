#include "game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "My Game");
	window->setVerticalSyncEnabled(true);
}

void Game::Init()
{
	// do any one-time game initialization here
}

void Game::Update()
{
	// once-per-frame update
}

void Game::Display()
{
	// draw everything here
}

void Game::Run()
{
	Init();

	while (window->isOpen())
	{
		// Process events
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		// update the world
		Update();
		// draw the world
		Display();
		window->display();
		// kill window if escape is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();
	}
	delete window;
}

sf::RenderWindow* Game::GetSFMLWindow()
{
	return window;
}