#include "GameController.h"

void GameController::StartGame() {
	//Launch the Window
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");  //Sample window test
	window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    //Load Main Menu / Title Screen
    MainMenu mainMenu;
    mainMenu.Load();
	
    //Game Loop
    while (window.isOpen())
    {
        //Check for keyboard input on main menu
        input.checkInput_MainMenu(&mainMenu);



        window.clear();
        //window.draw(shape); //Part of the shape drawing example from above
        //window.display();




        window.display();

    }
}