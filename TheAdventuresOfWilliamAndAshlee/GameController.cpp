#include "GameController.h"

GameController::GameController() {
    currentLevelID = 0; //0 = Main Menu ID
    isALevelLoaded = false;
    
}

void GameController::StartGame() {
	//Launch the Window
	sf::RenderWindow window(sf::VideoMode(1200, 1600), "SFML works!");  //Sample window test
	window.setFramerateLimit(60);

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
    if (currentLevelID != 0) {
        input.checkInput();
    }
    //Input handling on main menu screen
    else {
        //Main Menu / Title Screen is Active
        input.checkInput_MainMenu(&mainMenu);
    }


    return;
}

void GameController::DrawEverything(sf::RenderWindow* window) {
    //Placeholder function, add code later
    int tileCount;  //Number of tiles per map layer
    tileCount = level.strings.size();

    //Map dimensions = 20 x 20
    int counter = 0;
    for (int y = 0; y < level.mapHeight; y++) {
        for (int x = 0; x < level.mapWidth; x++) {
            sf::Sprite tempSprite;
            int t = std::stoi(level.strings[counter++]);
            int test = level.textures.size();
            tempSprite.setTexture(level.textures[t - 1]);
            tempSprite.setPosition(x * 16, y * 16);
            tempSprite.setScale(sf::Vector2f(10.0f, 10.0f));

            cout << "Drawing Tile: " << t << endl;
            window->draw(tempSprite);
        }

    }

    return;
}

