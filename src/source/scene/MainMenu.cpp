//
// Created by mhs on 7/16/17.
//

#include "../../header/scene/MainMenu.h"

Game::MainMenu::MainMenu(sf::RenderWindow* windowRef) {
    window = windowRef;
    bg = new sf::Sprite();
    bg_texture = new sf::Texture();
    bg_texture->loadFromFile("res/img/bg_0.png");
    bg->setTexture(*bg_texture);
    bg->setScale(Settings::width/bg->getGlobalBounds().width, Settings::height/bg->getGlobalBounds().height);
}

Game::MainMenu::~MainMenu() {
    if (bg) {
        delete bg;
        bg = nullptr;
    }
    if (bg_texture) {
        delete bg_texture;
        bg_texture = nullptr;
    }
}

void Game::MainMenu::setEvent() {

}

void Game::MainMenu::update(float delta) {

}

void Game::MainMenu::draw() {
    window->draw(*bg);
}