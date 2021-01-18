#pragma once

#include <SFML/Graphics.hpp>
#include "InputController.h"
#include "MainMenu.h"
#include "LevelController.h"
#include "Globals.h"
class GameController
{
public:
	GameController();
	void StartGame();
	bool IsALevelLoaded();
	void LoadLevel();
	int GetCurrentLevelID();
	int GetNextLevelID();

	void CheckAndHandleInput();
	void DrawEverything(sf::RenderWindow* window);

private:
	InputController input;
	int currentLevelID;
	vector<int> levelIDs;

	bool isALevelLoaded;	//Temporary Placeholder bool

	MainMenu mainMenu;
	LevelController level;
};

