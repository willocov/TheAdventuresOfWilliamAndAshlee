#pragma once

#include<SFML/Graphics.hpp>
#include "Globals.h"
class Player
{
public:
	Player();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	int x, y;

};

