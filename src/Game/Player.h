//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_PLAYER_H
#define ROGUELIKE_PLAYER_H

#include <SFML/Graphics.hpp>

namespace Game {
    class Player {
    public:
        Player();
        virtual ~Player();

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
