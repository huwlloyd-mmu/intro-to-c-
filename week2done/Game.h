#pragma once
#include "stdafx.h"
#include "Avatar.h"

class Game
{
	sf::RenderWindow* window;
	void Init();
	void Update();
	void Display();

	Avatar *avatar;
public:
	Game();
	void Run();
	sf::RenderWindow* GetSFMLWindow();
};