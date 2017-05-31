#pragma once
#include "stdafx.h"

class Game
{
	sf::RenderWindow* window;
	void Init();
	void Update();
	void Display();
public:
	Game();
	void Run();
	sf::RenderWindow* GetSFMLWindow();
};