#pragma once
#include <SFML/Window.hpp>
#include <iostream>
#include "MainMenu.h"
#include "Player.h"

using namespace std;

class InputController
{
public:
	 void checkInput(Player* player);
	 void checkInput_MainMenu(MainMenu *mainMenu);

private:
};

