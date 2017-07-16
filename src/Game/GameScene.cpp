//
// Created by mhs on 7/17/17.
//

#include "GameScene.h"

Game::GameScene::GameScene(sf::RenderWindow *windowRef) {
    window = windowRef;
    setButtons();
}

Game::GameScene::~GameScene() {
    for (size_t i = 0; i < buttons.size(); ++i) {
        delete buttons[i];
    }
}

void Game::GameScene::setButtons() {
    sf::Texture *pauseTexture = new sf::Texture();
    pauseTexture->loadFromFile("res/img/button_pause.png");
    buttons.push_back(new Button());
    buttons[0]->setTexture(pauseTexture);
    buttons[0]->setPosition(System::getWindowSize().x - 30, 30);
    buttons[0]->setScale(0.15f, 0.15f);
}

void Game::GameScene::draw() {
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->draw(window);
    }
}

void Game::GameScene::update(float delta) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->update(delta);
    }
}

void Game::GameScene::setEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
    }
}
