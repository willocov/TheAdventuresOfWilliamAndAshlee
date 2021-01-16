#pragma once

#include "tinyxml2.h"
#include <sstream>
#include<SFML/Graphics.hpp>
#include "Tileset.h"
#include <iostream>

using namespace tinyxml2;	//Needed for tinyxml2 file parsing for maps

struct TileCoordinate {
	TileCoordinate(int _x, int _y, int _tW, int  _tH) { x = _x; y = _y; tileWidth = _tW; tileHeight = _tH; }
	int x, y, tileWidth, tileHeight;
};

class LevelController
{
public:
	LevelController();
	void LoadLevel();
	int split(const std::string& txt, std::vector<std::string>& strs, char ch);
//private:
	//Variables related to XML file data
	int mapWidth;
	int mapHeight;

	int tileWidth;
	int tileHeight;


	int firstGid;
	const char* source;

	std::vector<std::string> strings;
	std::vector<sf::Texture> textures;
	Tileset tileset;
	
	sf::Texture TestTexture;
	std::vector<TileCoordinate> coordinates;

};

