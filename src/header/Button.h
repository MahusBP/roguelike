//
// Created by mhs on 7/16/17.
//

#ifndef ROGUELIKE_BUTTON_H
#define ROGUELIKE_BUTTON_H

#include <iostream>
#include "SFML/Graphics.hpp"

namespace Game {
    class Button {
    public:
        Button();
        virtual ~Button();
        virtual void setPosition(float x, float y);
        virtual void setTexture(sf::Texture &_texture);
        virtual void setScale(float factorX, float factorY);
        virtual void setText(sf::Text& text);
        virtual void draw(sf::RenderWindow & windowRef);

        virtual sf::Vector2f getPosition() const;

    private:
        sf::Text * text;
        sf::Sprite * sprite;
        sf::Texture * texture;
        sf::Vector2f * position;
    };
}


#endif //ROGUELIKE_BUTTON_H
