#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game/header/System.h"
#include "Game/header/scene/MainMenu.h"
#include "Game/GameScene.h"


int main() {
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1024, 600), "q");
    Game::System::init();
    Game::System::setWindow(window);
    Game::MainMenu *menu = new Game::MainMenu(window);
    Game::GameScene * gs = new Game::GameScene(window);
    sf::Event event;
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            gs->setEvent(event);
        }
        gs->update(Game::System::delta);
        window->clear();

        gs->draw();
        window->display();
    }
    return 0;
}