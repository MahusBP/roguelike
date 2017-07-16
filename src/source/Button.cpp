//
// Created by mhs on 7/16/17.
//

#include "../header/Button.h"

Game::Button::Button() {
    position = new sf::Vector2f();
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    text = new sf::Text();
}

Game::Button::~Button() {
    if (position) {
        delete position;
        position = nullptr;
    }
    if (texture) {
        delete texture;
        texture = nullptr;
    }
    if (sprite) {
        delete sprite;
        sprite = nullptr;
    }
    if (text) {
        delete text;
        text = nullptr;
    }
}

void Game::Button::draw(sf::RenderWindow &windowRef) {
    if (sprite) {
        windowRef.draw(*sprite);
    }
    if (text) {
        windowRef.draw(*text);
    }
}

void Game::Button::setPosition(float x, float y) {
    position->x = x;
    position->y = y;
    sprite->setPosition(*position);
    text->setPosition(*position);
}

void Game::Button::setText(sf::Text &_text) {
    *text = _text;
}

void Game::Button::setScale(float factorX, float factorY) {
    sprite->setScale(factorX, factorY);
}

void Game::Button::setTexture(sf::Texture &_texture) {
    *texture = _texture;
    sprite->setTexture(*texture);
}

sf::Vector2f Game::Button::getPosition() const {
    return *position;
}
