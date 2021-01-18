#pragma once

#include<SFML/Graphics.hpp>

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

