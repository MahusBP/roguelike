#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game/header/System.h"
#include "Game/header/scene/MainMenu.h"


int main() {
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1024, 600), "q");
    Game::MainMenu *menu = new Game::MainMenu(window);
    Game::System::init();
    Game::System::setWindow(window);
    sf::Event event;
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            menu->setEvent(event);
        }
        menu->update(Game::System::delta);
        window->clear();
        menu->draw();
        window->display();
    }
    return 0;
}