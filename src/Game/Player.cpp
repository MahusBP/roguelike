//
// Created by mhs on 7/17/17.
//

#include "Player.h"

Game::Player::Player() {
    texture = new sf::Texture();
    sprite = new sf::Sprite();
}

Game::Player::~Player() {
    delete texture;
    texture = nullptr;
    delete sprite;
    sprite = nullptr;
}

void Game::Player::setTexture(std::string path, sf::IntRect rect) {
    texture->loadFromFile(path, rect);
    sprite->setTexture(*texture);
    setScale(Settings::getTileSize()/sprite->getLocalBounds().width,
             Settings::getTileSize()/sprite->getLocalBounds().height);
}

void Game::Player::setScale(float factorX, float factorY) {
    sprite->setScale(factorX, factorY);
}

void Game::Player::setPosition(float x, float y) {
    sprite->setPosition(x, y);
}

sf::Vector2f Game::Player::getPosition() {
    return sprite->getPosition();
}

void Game::Player::update(float delta) {

}

void Game::Player::draw(sf::RenderWindow *window) {
    window->draw(*sprite);
}

