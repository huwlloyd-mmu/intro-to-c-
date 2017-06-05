#pragma once
#include "stdafx.h"
class Game;

class Avatar
{
	Game* parent;
	int posX;
	int posY;
	sf::Texture spriteSheet;
	sf::IntRect textureRects[12];

	const int DIRECTION_LEFT = 0;
	const int DIRECTION_RIGHT = 1;
	const int DIRECTION_UP = 2;
	const int DIRECTION_DOWN = 3;

	int direction = DIRECTION_LEFT;

	bool walking = false;

	int tick = 0;
public:
	Avatar(Game *newParent);
	void Update();
	void Draw();
};