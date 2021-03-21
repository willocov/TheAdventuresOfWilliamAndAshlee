#pragma once

#include<SFML/Graphics.hpp>
#include "Globals.h"
#include "LevelController.h"
#include <iostream>

class Player
{
public:
	Player();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	bool IsColliding(LevelController* level, GLOBALS::DIRECTION direction);

	float x, y;

};

