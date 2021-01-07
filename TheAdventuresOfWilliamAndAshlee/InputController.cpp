#include "InputController.h"

void InputController::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cout << "Button Pressed: W" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        cout << "Button Pressed: A" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cout << "Button Pressed: S" << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cout << "Button Pressed: D" << endl;
    }
}