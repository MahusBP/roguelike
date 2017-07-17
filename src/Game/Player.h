//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_PLAYER_H
#define ROGUELIKE_PLAYER_H

#include <SFML/Graphics.hpp>
#include "header/Settings.h"

namespace Game {
    class Player {
    public:
        Player();
        virtual ~Player();
        virtual void setTexture(std::string path, sf::IntRect rect = sf::IntRect());
        virtual void setScale(float factorX, float factorY);
        virtual void setPosition(float x, float y);
        virtual void update(float delta);
        virtual void draw(sf::RenderWindow * window);
        virtual sf::Vector2f getPosition();

    private:
        sf::Texture * texture;
        sf::Sprite * sprite;
        int healthPoints;
        int manaPoints;
        int damage;
        int speed; // how much actions
    };
}


#endif //ROGUELIKE_PLAYER_H
