#pragma once

#include "tinyxml2.h"
#include <sstream>
#include<SFML/Graphics.hpp>

using namespace tinyxml2;	//Needed for tinyxml2 file parsing for maps

class LevelController
{
public:
	LevelController();
	void LoadLevel();
private:
	//Variables related to XML file data
	int mapWidth;
	int mapHeight;

	int tileWidth;
	int tileHeight;

	int firstGid;
	const char* source;

};

