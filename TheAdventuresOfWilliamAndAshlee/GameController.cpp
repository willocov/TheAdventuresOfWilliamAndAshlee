#include "GameController.h"

GameController::GameController() {
    currentLevelID = 0; //0 = Main Menu ID
    isALevelLoaded = false;
    
}

void GameController::StartGame() {
	//Launch the Window
	sf::RenderWindow window(sf::VideoMode(1200, 1600), "SFML works!");  //Sample window test


    //std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes(); //Used to get most compatible fullscreen mode (Necessary for fullscreen mode
    //sf::RenderWindow window(i.front(), "SFML WORKS!", sf::Style::Fullscreen);   //Creates a full screen window


    //window.setFramerateLimit(60);
    
    //Game Loop
    while (window.isOpen())
    {
        //Check if a level is currently loaded
        if (!IsALevelLoaded()) {
            //No level is loaded, get next level and load
            LoadLevel();
        }

        //Check for keyboard input on main menu
        CheckAndHandleInput();

        //Clears the previous window frame
        window.clear(); 

        //Draw everything
        DrawEverything(&window);

        //Display the new frame
        window.display();
    }
}

bool GameController::IsALevelLoaded() {
    //Placeholder function, add code later
    if (isALevelLoaded == false) {
        isALevelLoaded = true;
        return false;
    }
    return isALevelLoaded;
}

void GameController::LoadLevel() {
    //Placeholder function, add code later
    level.LoadLevel();
    player.x = level.playerSpawnX * GLOBALS::SPRITE_SCALE;
    player.y = level.playerSpawnY * GLOBALS::SPRITE_SCALE;
    return;
}

int GameController::GetCurrentLevelID() {
    return currentLevelID;
}

int GameController::GetNextLevelID() {
    //Placeholder function, add code later
    return 1;
}

void GameController::CheckAndHandleInput() {
    //Input Handling during gameplay
    //if (currentLevelID != 0) {
    //    input.checkInput();
    //}
    ////Input handling on main menu screen
    //else {
    //    //Main Menu / Title Screen is Active
    //    input.checkInput_MainMenu(&mainMenu);
    //}

    input.checkInput(&player, &level);


    return;
}

void GameController::DrawEverything(sf::RenderWindow* window) {
    //Placeholder function, add code later
    int tileCount;  //Number of tiles per map layer
    tileCount = level.strings.size();

    //int counter = 0;
    for (int layerCounter = 0; layerCounter < level.layers.size(); layerCounter++) {
        std::vector<std::string> currentLayer = level.layers[layerCounter];
        int counter = 0;
        //cout << "DRAWING LAYER " << layerCounter + 1 << endl;
        for (int y = 0; y < level.mapHeight; y++) {
            for (int x = 0; x < level.mapWidth; x++) {
                int tileGid = std::stoi(currentLayer[counter]);
               
                if (tileGid != 0) {
                    sf::Sprite tempSprite;

                    //Determine which texture to use
                    sf::Texture tempTexture;
                    for (int i = 0; i < level.textures.size(); i++) {
                        if (tileGid >= level.tilesets[i].firstGid && tileGid <= level.tilesets[i].lastGid) {
                            tempTexture = level.textures[i];
                        }
                    }
                    tempSprite.setTexture(tempTexture);
                    tempSprite.setTextureRect(sf::IntRect(level.coordinates[tileGid - 1].x, level.coordinates[tileGid - 1].y, level.coordinates[tileGid - 1].tileWidth, level.coordinates[tileGid - 1].tileHeight));
                    tempSprite.setPosition(x * 16 * GLOBALS::SPRITE_SCALE, y * 16 * GLOBALS::SPRITE_SCALE);
                    
                    tempSprite.setScale(sf::Vector2f(GLOBALS::SPRITE_SCALE, GLOBALS::SPRITE_SCALE));

                    //cout << "Drawing Tile: " << tileGid << endl;
                    window->draw(tempSprite);
                }
                counter++;
            }
        }
    }

    //Draw the Player
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::CircleShape playerTest(25.f);
    playerTest.setFillColor(sf::Color(150, 50, 250));
    playerTest.setPosition(player.x, player.y);
    window->draw(playerTest);


    //Test code for drawing collision boundary
    //sf::RectangleShape rectangle;
    //rectangle.setSize(sf::Vector2f(125, 71));
    //rectangle.setOutlineColor(sf::Color::Red);
    //rectangle.setOutlineThickness(5);
    //rectangle.setPosition(0 * GLOBALS::SPRITE_SCALE, 190 * GLOBALS::SPRITE_SCALE);
    //rectangle.setScale(sf::Vector2f(GLOBALS::SPRITE_SCALE, GLOBALS::SPRITE_SCALE));
    //window->draw(rectangle);



    return;
}

