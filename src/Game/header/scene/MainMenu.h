//
// Created by mhs on 7/16/17.
//

#ifndef ROGUELIKE_SCENE_MAINMENU_H
#define ROGUELIKE_SCENE_MAINMENU_H

#include <vector>
#include "../Button.h"
#include "../IScene.h"
#include "../Settings.h"

namespace Game {
    class MainMenu : public IScene {
    public:
        MainMenu(sf::RenderWindow* windowRef);
        virtual ~MainMenu();
        void setEvent(sf::Event event) override;
        void update(float delta) override;
        void draw() override;

    private:
        std::vector<Button*> buttons;
        sf::RenderWindow *window;
        sf::Texture *bg_texture;
        sf::Font *font;
        sf::Sprite *bg;

        void setButtons();

    };
}


#endif //ROGUELIKE_SCENE_MAINMENU_H
