#include "LevelController.h"

LevelController::LevelController() {
	
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
	ss << "Content/Maps/2LayerTest.tmx";
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
			//tsxStream << ts.tsxSource;
			//tsxStream << "Content/Maps/Terrains_TILESET_B-C-D-E.tsx";
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

				tilesets.push_back(ts);

			}
			
			pTileset = pTileset->NextSiblingElement("tileset");
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

					for (int i = 0; i < tempTileIDs.size(); i++) {
						std::cout << tempTileIDs[i] << std::endl;
					}

					layers.push_back(tempTileIDs);

					pData = pData->NextSiblingElement("data");
				}
			}
			pLayer = pLayer->NextSiblingElement("layer");
		}
	}
	
	//Load the textures
	int tileIDCounter = 1;	//First ID starts at 1 because 0 = "No Tile"
	int leftPos = 0, topPos = 0;
							//Loop by row
	//for (int y = 0; y < tileset.imageHeight; y+=tileHeight) {
	////	//Loop by 
	//	for (int x = 0; x < tileset.imageWidth; x+=tileWidth) {
	//		TileCoordinate tempTile(x, y, tileWidth, tileHeight);
	//		coordinates.push_back(tempTile);

	//	}
	//}
	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < 768; y += 16) {
			//	//Loop by 
			for (int x = 0; x < 768; x += 16) {
				TileCoordinate tempTile(x, y, tileWidth, tileHeight);
				coordinates.push_back(tempTile);

			}
		}
	}
	//TestTexture.loadFromFile("Content/Tilesets/SERENE_VILLAGE_REVAMPED/RPG_MAKER_MV/Terrains_TILESET_B-C-D-E.png");

	sf::Texture texture1, texture2;
	texture1.loadFromFile("Content/Tilesets/SERENE_VILLAGE_REVAMPED/RPG_MAKER_MV/Terrains_TILESET_B-C-D-E.png");
	texture2.loadFromFile("Content/Tilesets/SERENE_VILLAGE_REVAMPED/RPG_MAKER_MV/Outside_Stuff_TILESET_B-C-D-E.png");

	textures.push_back(texture1);
	textures.push_back(texture2);

}

string LevelController::formatSourceString(string source) {
	string result = source;
	//check if source begins with ".."
	if (result.at(0) == '.') {
		//erase 2 leading '.'
		result.erase(result[0]);
		result.erase(result[0]);

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