#include "LevelController.h"

LevelController::LevelController() {

}

void LevelController::LoadLevel() {
	//Open filestream to map file
	XMLDocument doc;
	std::stringstream ss;
	ss << "Content/Maps/MainMenu.tmx";
	doc.LoadFile(ss.str().c_str());

	//Get map and tile dimensions
	XMLElement* mapNode = doc.FirstChildElement("map");
	mapNode->QueryIntAttribute("width", &mapWidth);
	mapNode->QueryIntAttribute("height", &mapHeight);
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);


	
}