#include "InputController.h"

void InputController::checkInput(Player* player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cout << "Button Pressed: W" << endl;
        player->MoveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        cout << "Button Pressed: A" << endl;
        player->MoveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cout << "Button Pressed: S" << endl;
        player->MoveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cout << "Button Pressed: D" << endl;
        player->MoveRight();
    }
}

void InputController::checkInput_MainMenu(MainMenu *mainMenu) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cout << "Button Pressed: W" << endl;
        mainMenu->HandleKeyPress_W();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cout << "Button Pressed: S" << endl;
        mainMenu->HandleKeyPress_S();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        cout << "Button Pressed: ENTER" << endl;
        mainMenu->HandleKeyPress_ENTER();
    }
}