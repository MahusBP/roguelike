//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_SYSTEM_H
#define ROGUELIKE_SYSTEM_H

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"

namespace Game {
    class System {
    public:
        static void init();
        static void close();
        static void setWindow(sf::RenderWindow *_window);
        static void setWindowSize(sf::Vector2u size);
        static sf::Mouse * mouse;
        static sf::RenderWindow & getWindow();
        static sf::Vector2u getWindowSize();

        static const float delta;
    private:
        static sf::RenderWindow * window;
    };
}


#endif //ROGUELIKE_SYSTEM_H
