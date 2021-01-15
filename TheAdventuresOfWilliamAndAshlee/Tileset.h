#pragma once

#include <string>

using namespace std;

class Tileset
{
public:
	//Constructor
	Tileset();

	//Getter Functions
	int GetFirstGid();
	string GetName();
	string GetTsxSource();
	string GetImageSource();
	int GetTileWidth();
	int GetTileHeight();
	int GetTileCount();
	int GetColumns();

	//Setter Functions
	void SetFirstGid(int x);
	void SetName(string s);
	void SetTsxSource(string s);
	void SetImageSource(string s);
	void SetTileWidth(int x);
	void SetTileHeight(int x);
	void SetTileCount(int x);
	void SetColumns(int x);
//private:

	int firstGid;
	string name;	//Tileset name
	string tsxSource;	//.tsx accociated with .tmx file
	string imageSource;	//Location of the .png file used as the tileset
	int tileWidth, tileHeight, tileCount, columns, imageWidth, imageHeight;	//.png related variables


};

