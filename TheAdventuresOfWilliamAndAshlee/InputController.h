#pragma once
#include <SFML/Window.hpp>
#include <iostream>
#include "MainMenu.h"
#include "Player.h"
#include "LevelController.h"
#include "Globals.h"

using namespace std;

class InputController
{
public:
	 void checkInput(Player* player, LevelController* level);
	 void checkInput_MainMenu(MainMenu *mainMenu);
private:
};

