//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_IEVENTLISTENER_H
#define ROGUELIKE_IEVENTLISTENER_H

#include <SFML/Graphics.hpp>

namespace Game {
    class IEventListener {
    public:
        virtual void setEvent(sf::Event event) = 0;
    };
}


#endif //ROGUELIKE_IEVENTLISTENER_H
