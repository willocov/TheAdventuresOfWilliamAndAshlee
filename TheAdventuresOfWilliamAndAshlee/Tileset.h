#pragma once

#include <string>

using namespace std;

class Tileset
{
public:
	//Constructor
	Tileset();

	
//private:

	int firstGid, lastGid;
	string name;	//Tileset name
	string tsxSource;	//.tsx accociated with .tmx file
	string imageSource;	//Location of the .png file used as the tileset
	int tileWidth, tileHeight, tileCount, columns, imageWidth, imageHeight;	//.png related variables


};

