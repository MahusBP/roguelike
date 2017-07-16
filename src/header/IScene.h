//
// Created by mhs on 7/16/17.
//

#ifndef ROGUELIKE_ISCENE_H
#define ROGUELIKE_ISCENE_H

namespace Game {
    class IScene {
    public:
        virtual void setEvent() = 0;
        virtual void update(float delta) = 0;
        virtual void draw() = 0;
    };
}


#endif //ROGUELIKE_ISCENE_H
