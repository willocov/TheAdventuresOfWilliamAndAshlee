#pragma once

#include "tinyxml2.h"
#include <sstream>
#include<SFML/Graphics.hpp>
#include "Tileset.h"
#include <iostream>
#include "Globals.h"

using namespace tinyxml2;	//Needed for tinyxml2 file parsing for maps

struct TileCoordinate {
	TileCoordinate(int _x, int _y, int _tW, int  _tH) { x = _x; y = _y; tileWidth = _tW; tileHeight = _tH; }
	int x, y, tileWidth, tileHeight;
};

struct Collision {
	int id;	
	float x, y, width, height; //Note: Consider changing these to ints and rounding up to simplify
	Collision() { id = -1; x = y = width = height = 0; }
	Collision(int _id, float _x, float _y, float _width, float _height) { id = _id; x = _x; y = _y; width = _width; height = _height; }
};

class LevelController
{
public:
	LevelController();
	void LoadLevel();
	int split(const std::string& txt, std::vector<std::string>& strs, char ch);
	string formatSourceString(string source);
	int GetLastGid(int firstGid, int tileCount);

	void SortCollisions();

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
	
	//sf::Texture TestTexture;
	std::vector<TileCoordinate> coordinates;
	std::vector<Tileset> tilesets;

	std::vector<std::string> tileIDs;
	std::vector<std::vector<std::string>> layers;

	std::vector<Collision> collisions;
};

