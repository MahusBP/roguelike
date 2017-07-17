//
// Created by mhs on 7/17/17.
//

#include "LevelObject.h"

Game::LevelObject::LevelObject() {
    sprite = new sf::Sprite();
    texture = new sf::Texture();
}

Game::LevelObject::~LevelObject() {
    delete texture;
    texture = nullptr;
    delete sprite;
    sprite = nullptr;
}


void Game::LevelObject::setPosition(float x, float y) {
    sprite->setPosition(x, y);
}

void Game::LevelObject::setObjectType(ObjectType _type) {
    type = _type;
}

Game::ObjectType Game::LevelObject::getObjectType() {
    return type;
}

void Game::LevelObject::update(float delta) {

}

void Game::LevelObject::draw(sf::RenderWindow *window) {
    window->draw(*sprite);
}

void Game::LevelObject::setTexture(std::string path) {
    texture->loadFromFile(path);
    sprite->setTexture(*texture);
    setScale(Settings::getTileSize()/sprite->getLocalBounds().width,
             Settings::getTileSize()/sprite->getLocalBounds().height);
}

//void Game::LevelObject::setTexture(sf::Texture *_texure) {
//    sprite->setTexture(*_texure);
//    setScale(32/sprite->getLocalBounds().width, 32/sprite->getLocalBounds().height);
//}
void Game::LevelObject::setScale(float factorX, float factorY) {
    sprite->setScale(factorX, factorY);
}
