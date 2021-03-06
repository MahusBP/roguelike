//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_GAMESCENE_H
#define ROGUELIKE_GAMESCENE_H

#include <fstream>
#include "LevelObject.h"
#include "ObjectType.h"
#include "Player.h"
#include "header/IScene.h"
#include "header/Button.h"
#include "header/System.h"

namespace Game {
    class GameScene : public IScene {
    public:
        GameScene(sf::RenderWindow* windowRef);
        ~GameScene();
        virtual void setEvent(sf::Event event) override;
        virtual void update(float delta) override;
        virtual void draw() override;
    private:
        std::vector<LevelObject*> objects;
        std::vector<Button*> buttons;
        sf::RenderWindow *window;
        Player * player;
        void setButtons();
        void setLevel();
    };
}


#endif //ROGUELIKE_GAMESCENE_H
