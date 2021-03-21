#include "InputController.h"

void InputController::checkInput(Player* player, LevelController* level) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //cout << "Button Pressed: W" << endl;
        //Note: Consider combining this if statement with the parent if statement
        if(!player->IsColliding(level, GLOBALS::DIRECTION::UP))
            player->MoveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //cout << "Button Pressed: A" << endl;
        if (!player->IsColliding(level, GLOBALS::DIRECTION::LEFT))
            player->MoveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //cout << "Button Pressed: S" << endl;
        if (!player->IsColliding(level, GLOBALS::DIRECTION::DOWN))
            player->MoveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //cout << "Button Pressed: D" << endl;
        if (!player->IsColliding(level, GLOBALS::DIRECTION::RIGHT))
            player->MoveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        
    }
}

void InputController::checkInput_MainMenu(MainMenu *mainMenu) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //cout << "Button Pressed: W" << endl;
        mainMenu->HandleKeyPress_W();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //cout << "Button Pressed: S" << endl;
        mainMenu->HandleKeyPress_S();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        //cout << "Button Pressed: ENTER" << endl;
        mainMenu->HandleKeyPress_ENTER();
    }
}
