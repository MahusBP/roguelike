//
// Created by mhs on 7/17/17.
//

#include "GameScene.h"


Game::GameScene::GameScene(sf::RenderWindow *windowRef) {
    window = windowRef;
    setButtons();
    setLevel();
}

Game::GameScene::~GameScene() {
    for (size_t i = 0; i < buttons.size(); ++i) {
        delete buttons[i];
    }
    for (size_t i = 0; i < objects.size(); ++i) {
        delete objects[i];
    }
}

void Game::GameScene::setButtons() {
    sf::Texture *pauseTexture = new sf::Texture();
    pauseTexture->loadFromFile("res/img/button_pause.png");
    buttons.push_back(new Button());
    buttons[0]->setTexture(pauseTexture);
    buttons[0]->setPosition(System::getWindowSize().x - 30, 30);
    buttons[0]->setScale(0.15f, 0.15f);
}

void Game::GameScene::draw() {
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->draw(window);
    }
    for (size_t i = 0; i < objects.size(); ++i) {
        objects[i]->draw(window);
    }
    player->draw(window);
}

void Game::GameScene::update(float delta) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->update(delta);
    }
}

void Game::GameScene::setEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
    }
}

void Game::GameScene::setLevel() {
    player = new Player();
    player->setTexture("res/img/character_0.png");

    std::ifstream file_in("res/lvl/level1.mhs");
    int rows = 0;
    std::string line;
    while (std::getline(file_in, line)) {
        for (int columns = 0; columns < line.size(); ++columns) {
            objects.push_back(new LevelObject());
            if (line[columns] == '_' || line[columns] == 'P') {
                objects.back()->setTexture("res/img/grass_1.png");
                objects.back()->setObjectType(ObjectType::PASSABLE);
            } else if (line[columns] == '#') {
                objects.back()->setTexture("res/img/wall_0.png");
                objects.back()->setObjectType(ObjectType::IMPASSABLE);
            }
            objects.back()->setPosition(Settings::getTileSize() * columns, Settings::getTileSize() * rows);

            if (line[columns] == 'P') {
                player->setPosition(Settings::getTileSize() * columns, Settings::getTileSize() * rows);
            }
        }
        rows++;
    }
}
