//
// Created by mhs on 7/17/17.
//

#include "../header/System.h"

sf::RenderWindow*   Game::System::window    = nullptr;
sf::Mouse*          Game::System::mouse     = nullptr;
const float         Game::System::delta     = 0.017;

void Game::System::init() {
    mouse = new sf::Mouse();
}

void Game::System::close() {
    if (mouse) {
        delete mouse;
        mouse = nullptr;
    }
}

void Game::System::setWindow(sf::RenderWindow *_window) {
    window = _window;
}

sf::RenderWindow &Game::System::getWindow() {
    return *window;
}

sf::Vector2u Game::System::getWindowSize() {
    return window->getSize();
}

void Game::System::setWindowSize(sf::Vector2u size) {
    window->setSize(size);
}
