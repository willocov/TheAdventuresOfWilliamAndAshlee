#include "GameController.h"

void GameController::StartGame() {
	//Launch the Window
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");  //Sample window test
	window.setFramerateLimit(60);

    //Load Main Menu / Title Screen
    //MainMenu mainMenu;
    //mainMenu.Load();
	
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
    
    return true;
}

void GameController::LoadLevel() {
    //Placeholder function, add code later
    return;
}

int GameController::GetCurrentLevelID() {
    //Placeholder function, add code later
    return 0;
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
    return;
}

