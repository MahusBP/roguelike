//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_LEVELOBJECT_H
#define ROGUELIKE_LEVELOBJECT_H

#include <SFML/Graphics.hpp>
#include "ObjectType.h"
#include "header/System.h"
#include "header/Settings.h"

namespace Game {
    class LevelObject {
    public:
        LevelObject();
        virtual ~LevelObject();
        virtual void setPosition(float x, float y);
        virtual void setObjectType(ObjectType _type);
        virtual void setTexture(std::string path);
        virtual void setScale(float factorX, float factorY);
        virtual void update(float delta);
        virtual void draw(sf::RenderWindow * window);
        virtual ObjectType getObjectType() ;
    private:
        sf::Texture * texture;
        sf::Sprite * sprite;
        ObjectType type;
    };
}


#endif //ROGUELIKE_LEVELOBJECT_H
