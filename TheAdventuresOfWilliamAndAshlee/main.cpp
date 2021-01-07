#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "tinyxml2.h"
#include <sstream>
#include <string>
#include <iostream>
#include <chrono>
#include "GameController.h";

#include "InputController.h"

using namespace tinyxml2;
//tileset structure
struct Tileset {
    sf::Texture Texture;
    int FirstGid;
    Tileset() {
        this->FirstGid = -1;
    }
    Tileset(sf::Texture texture, int firstGid) {
        this->Texture = texture;
        this->FirstGid = firstGid;
    }
};

int split(const std::string& txt, std::vector<std::string>& strs, char ch) {
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

int main()
{
    //sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");  //Sample window test
    //window.setFramerateLimit(60);

    ////std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes(); //Used to get most compatible fullscreen mode (Necessary for fullscreen mode
    ////sf::RenderWindow window(i.front(), "SFML WORKS!", sf::Style::Fullscreen);   //Creates a full screen window

    ////Shape drawing example
    ///*sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);*/

    ////Music playing example (not audio, which is a short audio snippet like a gunshot
    ////sf::Music music;
    ////if (!music.openFromFile("Content/Music/TestWav.wav"))
    ////    return -1; // error
    ////music.play();


    // //XML File Parsing Test

    //XMLDocument doc;
    //std::stringstream ss;
    //ss << "Content/Maps/TestMap.tmx";
    //doc.LoadFile(ss.str().c_str());

    //XMLElement* mapNode = doc.FirstChildElement("map");
    ////Get height and width and store it in _size
    //int width, height;
    //mapNode->QueryIntAttribute("width", &width);
    //mapNode->QueryIntAttribute("height", &height);

    //std::vector<Tileset> _tilesets;
    //std::vector<std::string> strings;
    ////Load Tilesets
    //XMLElement* pTileset = mapNode->FirstChildElement("tileset");
    //if (pTileset != NULL) {
    //    while (pTileset) {
    //        int firstgid;
    //        const char* source = "Content/Tilesets/Beach.png";
    //        char* path;

    //        std::stringstream ss;
    //        ss << source;
    //        pTileset->QueryIntAttribute("firstgid", &firstgid);
    //        sf::Texture tex;
    //        if (!tex.loadFromFile(source)) {
    //            return 1;
    //        }
    //        _tilesets.push_back(Tileset(tex, firstgid));

    //        pTileset = pTileset->NextSiblingElement("tileset");

    //    }

    //    //Loading the layers
    //    XMLElement* pLayer = mapNode->FirstChildElement("layer");
    //    if (pLayer != NULL) {
    //        //while (pLayer) {
    //            //Loading the data element
    //        XMLElement* pData = pLayer->FirstChildElement("data");
    //        if (pData != NULL) {
    //            while (pData) {
    //                const char* test = pData->GetText();
    //                std::string testString(test);
    //                int result = split(testString, strings, ',');

    //                for (int i = 0; i < strings.size(); i++) {
    //                    std::cout << strings[i] << std::endl;
    //                }

    //                //Add code here to split string into individual tile IDs, and save them into a 2d structure (1 for each layer)

    //                pData = pData->NextSiblingElement("data");


    //            }
    //        }
    //        //   pLayer = pLayer->NextSiblingElement("layer");
    //       //}
    //    }



    //}

    ////load texture from png test
    //sf::Texture testTexture;
    //if (!testTexture.loadFromFile("Content/Tilesets/Beach.png", sf::IntRect(64, 16, 16, 16))) {
    //    return 1;
    //}
    //sf::Sprite sprite;
    //sprite.setTexture(testTexture);
    //sprite.setScale(sf::Vector2f(10.0f, 10.0f));
    //sprite.setPosition(0.0f, 0.0f);

    //sf::Sprite sprite2;
    //sprite2.setTexture(testTexture);
    //sprite2.setScale(sf::Vector2f(10.0f, 10.0f));
    //sprite2.setPosition(160.0f, 0.0f);

    //InputController IC;

    ////Game loop while window is open
    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    IC.checkInput();

    //    window.clear();
    //    //window.draw(shape); //Part of the shape drawing example from above
    //    //window.display();

    //    window.draw(sprite);
    //    window.draw(sprite2);

    //    window.display();

    //}

GameController gc;
gc.StartGame();

    return 0;
}