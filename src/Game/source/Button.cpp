//
// Created by mhs on 7/16/17.
//

#include "../header/Button.h"

Game::Button::Button() {
    position = new sf::Vector2f();
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    text = new sf::Text();
    clicked = false;
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

void Game::Button::draw(sf::RenderWindow *windowRef) {
    if (sprite) {
        windowRef->draw(*sprite);
    }
    if (text) {
        windowRef->draw(*text);
    }
}

void Game::Button::setPosition(float x, float y) {
    position->x = x;
    position->y = y;
    sprite->setPosition(*position);
    text->setPosition(*position);
}

void Game::Button::setText(sf::Text *_text, sf::Color color) {
    text = _text;
    text->setColor(color);
    text->setOrigin(text->getPosition().x + text->getGlobalBounds().width/2,
                    text->getPosition().y + text->getGlobalBounds().height/2);
    text->setPosition(sprite->getPosition().x, sprite->getPosition().y - text->getCharacterSize()/3);
    defTextScale = text->getScale();
}

void Game::Button::setScale(float factorX, float factorY) {
    sprite->setScale(factorX, factorY);
    defSpriteScale = sprite->getScale();
}

void Game::Button::setTexture(sf::Texture *_texture) {
    texture = _texture;
    sprite->setTexture(*texture);
    sprite->setOrigin(position->x + sprite->getGlobalBounds().width/2, position->y + sprite->getGlobalBounds().height/2);
}

sf::Vector2f Game::Button::getPosition() const {
    return *position;
}

sf::FloatRect Game::Button::getBounds() const {
    return sprite->getGlobalBounds();
}

void Game::Button::update(float delta) {
    onMouseHover();
}

void Game::Button::onMouseHover() {
    if (sprite->getGlobalBounds().contains(System::mouse->getPosition(System::getWindow()).x,
                                           System::mouse->getPosition(System::getWindow()).y)) {
        if (Mhs::isEqual(sprite->getScale().x, defSpriteScale.x)) {
            sprite->setScale(sprite->getScale().x - 0.03f, sprite->getScale().y - 0.03f);
            text->setScale(text->getScale().x - 0.1f, text->getScale().y - 0.1f);
            sprite->setColor(sf::Color(255, 255, 255, 155));
        }
    } else {
        if (sprite->getScale().x < defSpriteScale.x) {
            sprite->setScale(defSpriteScale);
            text->setScale(defTextScale);
            sprite->setColor(sf::Color::White);
        }
    }
}

void Game::Button::setEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (sprite->getGlobalBounds().contains(System::mouse->getPosition(System::getWindow()).x,
                                               System::mouse->getPosition(System::getWindow()).y)) {
            clicked = true;
        }
    }
}

bool Game::Button::isClicked() {
    if (clicked) {
        clicked = false;
        return true;
    } else {
        return false;
    }
}
