#include "LevelController.h"

LevelController::LevelController() {
	tileHeight = 0;
	tileWidth = 0;
}

int LevelController::split(const std::string& txt, std::vector<std::string>& strs, char ch) {
	int pos = txt.find(ch);	//Searches for the first instance of a character
	int initialPos = 0;
	strs.clear();
	while (pos != std::string::npos) {
		std::string testString = txt.substr(initialPos, pos - initialPos + 1);
		if (testString.at(0) == '\n') { //String contains newline char, remove newline char
			testString.erase(0, 1);
		}
		if (testString.at(testString.size() - 1) == ',') {  //Remove trailing ',' from each input
			testString.erase(testString.size() - 1);
		}
		strs.push_back(testString);
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}
	strs.push_back(txt.substr(initialPos, std::min<int>(pos, txt.size() - (initialPos + 1))));
	return strs.size();
}

void LevelController::LoadLevel() {
	//Open filestream to map file
	XMLDocument doc;
	std::stringstream ss;
	ss << "Content/Maps/MultiLayerTest.tmx";
	doc.LoadFile(ss.str().c_str());

	//Get map and tile dimensions
	XMLElement* mapNode = doc.FirstChildElement("map");
	mapNode->QueryIntAttribute("width", &mapWidth);
	mapNode->QueryIntAttribute("height", &mapHeight);
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);

	//Load tilesets
	XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (pTileset != NULL) {
		while (pTileset) {
			Tileset ts;

			//Get firstgid and tsx souce from tmx file
			pTileset->QueryIntAttribute("firstgid", &ts.firstGid);
			ts.tsxSource = pTileset->Attribute("source");

			//Get remaining tileset values from tsx file
			//Open stream to tsx file
			XMLDocument tsxFile;
			std::stringstream tsxStream;

			string source = formatSourceString(ts.tsxSource);
			tsxStream << source;
			tsxFile.LoadFile(tsxStream.str().c_str());

			XMLElement* tsxMapNode = tsxFile.FirstChildElement("tileset");
			if (tsxMapNode != NULL) {
				ts.name = tsxMapNode->Attribute("name");
				tsxMapNode->QueryIntAttribute("tilewidth", &ts.tileWidth);
				tsxMapNode->QueryIntAttribute("tileheight", &ts.tileHeight);
				tsxMapNode->QueryIntAttribute("tilecount", &ts.tileCount);
				tsxMapNode->QueryIntAttribute("columns", &ts.columns);

				XMLElement* imageNode = tsxMapNode->FirstChildElement("image");
				ts.imageSource = imageNode->Attribute("source");
				imageNode->QueryIntAttribute("width", &ts.imageWidth);
				imageNode->QueryIntAttribute("height", &ts.imageHeight);

				ts.lastGid = GetLastGid(ts.firstGid, ts.tileCount);

				string imageSource = formatSourceString(ts.imageSource);
				sf::Texture tempTexture;
				tempTexture.loadFromFile(imageSource);
				
				textures.push_back(tempTexture);
				tilesets.push_back(ts);

			}
			
			pTileset = pTileset->NextSiblingElement("tileset");
		}
	}

	//Load Collisions and Spawns
	XMLElement* pObjectGroup = mapNode->FirstChildElement("objectgroup");
	if (pObjectGroup != NULL) {
		while (pObjectGroup) {	//Note: Adding additional object group layers will cause them to be read as collisions
			string objectGroupName = pObjectGroup->Attribute("name");

			//Check for Collisions
			if (objectGroupName == "Collisions")
			{
				XMLElement* pCollision = pObjectGroup->FirstChildElement("object");
				if (pCollision != NULL) {
					while (pCollision) {
						Collision col;	//Collision objects

						//Get the collision object properties
						pCollision->QueryIntAttribute("id", &col.id);
						pCollision->QueryFloatAttribute("x", &col.x);
						pCollision->QueryFloatAttribute("y", &col.y);
						pCollision->QueryFloatAttribute("width", &col.width);
						pCollision->QueryFloatAttribute("height", &col.height);

						if (col.x < 1)
							col.x = 0;
						if (col.y < 1)
							col.y = 0;

						//Add to Level Controllers collision stack
						col.x *= GLOBALS::SPRITE_SCALE;
						col.y *= GLOBALS::SPRITE_SCALE;
						col.width *= GLOBALS::SPRITE_SCALE;
						col.height *= GLOBALS::SPRITE_SCALE;

						collisions.push_back(col);

						pCollision = pCollision->NextSiblingElement("object");

					}
				}
			}
			else if (objectGroupName == "Spawns")
			{
				XMLElement* pSpawn = pObjectGroup->FirstChildElement("object");
				if (pSpawn != NULL) {
					while (pSpawn) {
						string spawnName = pSpawn->Attribute("name");
						if (spawnName == "PlayerSpawn") {
							pSpawn->QueryFloatAttribute("x", &playerSpawnX);
							pSpawn->QueryFloatAttribute("y", &playerSpawnY);
						}

						pSpawn = pSpawn->NextSiblingElement("object");
					}
				}

			}
			pObjectGroup = pObjectGroup->NextSiblingElement("objectgroup");
		}
	}

	//Load Layer Data
	XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if (pLayer != NULL) {
		while (pLayer) {
			XMLElement* pData = pLayer->FirstChildElement("data");
			if (pData != NULL) {
				while (pData) {
					std::vector<std::string> tempTileIDs;
					const char* rawFileData = pData->GetText();
					std::string rawFileDataAsString(rawFileData);
					int result = split(rawFileDataAsString, tempTileIDs, ',');

					//for (int i = 0; i < tempTileIDs.size(); i++) {
						//std::cout << tempTileIDs[i] << std::endl;
					//}

					layers.push_back(tempTileIDs);

					pData = pData->NextSiblingElement("data");
				}
			}
			pLayer = pLayer->NextSiblingElement("layer");
		}
	}
	
	//Get tile coordinates for map
	for (int tilesetCounter = 0; tilesetCounter < tilesets.size(); tilesetCounter++) {
		for (int y = 0; y < tilesets[tilesetCounter].imageHeight; y += tilesets[tilesetCounter].tileHeight) {
			for (int x = 0; x < tilesets[tilesetCounter].imageWidth; x += tilesets[tilesetCounter].tileWidth) {
				TileCoordinate tempTile(x, y, tileWidth, tileHeight);
				coordinates.push_back(tempTile);
			}
		}
	}
}

string LevelController::formatSourceString(string source) {
	string result = source;
	//check if source begins with ".."
	if (result.at(0) == '.') {
		//erase 2 leading '.'
		result = result.substr(2, result.length() - 2);

		//Add 'Content' to begining of source string
		result = "Content" + result;
	}
	else {
		result = "Content/Maps/" + result;
	}
	return result;
}

int LevelController::GetLastGid(int firstGid, int tileCount) {
	return firstGid + tileCount - 1;
}