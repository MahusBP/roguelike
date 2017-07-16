#include <iostream>
#include "SFML/Graphics.hpp"
#include "header/scene/MainMenu.h"

int main() {
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1024, 600), "q");
    Game::MainMenu *menu = new Game::MainMenu(window);
    while (window->isOpen()) {
        menu->update(1);
        window->clear();
        menu->draw();
        window->display();
    }
    return 0;
}