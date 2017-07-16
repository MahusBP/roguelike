//
// Created by mhs on 7/16/17.
//

#ifndef ROGUELIKE_BUTTON_H
#define ROGUELIKE_BUTTON_H

#include <iostream>
#include "../../MhsFloat.h"
#include "SFML/Graphics.hpp"
#include "System.h"
#include "IEventListener.h"

namespace Game {
    class Button : IEventListener {
    public:
        Button();
        virtual ~Button();
        virtual void setPosition(float x, float y);
        virtual void setTexture(sf::Texture * _texture);
        virtual void setScale(float factorX, float factorY);
        virtual void setText(sf::Text * text, sf::Color color = sf::Color::White);
        virtual void draw(sf::RenderWindow * windowRef);
        virtual void update(float delta);
        virtual void setEvent(sf::Event event) override;
        virtual bool isClicked();

        virtual sf::Vector2f getPosition() const;
        virtual sf::FloatRect getBounds() const;

    private:
        sf::Text * text;
        sf::Sprite * sprite;
        sf::Texture * texture;
        sf::Vector2f * position;
        sf::Vector2f defSpriteScale;
        sf::Vector2f defTextScale;
        bool clicked;

        void onMouseHover();
    };
}


#endif //ROGUELIKE_BUTTON_H
