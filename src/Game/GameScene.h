//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_GAMESCENE_H
#define ROGUELIKE_GAMESCENE_H

#include "header/IScene.h"
#include "header/Button.h"
#include "header/System.h"

namespace Game {
    class GameScene : public IScene {
    public:
        GameScene(sf::RenderWindow* windowRef);
        ~GameScene();
        void setEvent(sf::Event event) override;
        void update(float delta) override;
        void draw() override;
    private:
        std::vector<Button*> buttons;
        sf::RenderWindow *window;
        void setButtons();
    };
}


#endif //ROGUELIKE_GAMESCENE_H
