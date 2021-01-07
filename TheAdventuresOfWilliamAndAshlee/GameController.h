#pragma once

#include <SFML/Graphics.hpp>
#include "InputController.h"
#include "MainMenu.h"
class GameController
{
public:
	void StartGame();
private:
	InputController input;
};

