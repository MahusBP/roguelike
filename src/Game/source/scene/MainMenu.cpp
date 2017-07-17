//
// Created by mhs on 7/16/17.
//

#include "../../header/scene/MainMenu.h"

Game::MainMenu::MainMenu(sf::RenderWindow* windowRef) {
    window = windowRef;
    font = new sf::Font();
    bg = new sf::Sprite();
    bg_texture = new sf::Texture();
    bg_texture->loadFromFile("res/img/bg_0.png");
    bg->setTexture(*bg_texture);
    bg->setScale(System::getWindowSize().x/bg->getGlobalBounds().width,
                 System::getWindowSize().y/bg->getGlobalBounds().height);

    setButtons();
}

Game::MainMenu::~MainMenu() {
    for (size_t i = 0; i < buttons.size(); ++i) {
        delete buttons[i];
    }
    if (font) {
        delete font;
        font = nullptr;
    }
    if (bg) {
        delete bg;
        bg = nullptr;
    }
    if (bg_texture) {
        delete bg_texture;
        bg_texture = nullptr;
    }
}

void Game::MainMenu::setEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
                for (auto iter = buttons.begin(); iter != buttons.end(); ++iter)
                    (*iter)->setEvent(event);
            break;
        default:
            break;
    }
}

void Game::MainMenu::update(float delta) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->update(delta);
    }
    /* TRASH BELOW */
    if (buttons[2]->isClicked()) {
        sf::Clock clock;
        sf::Clock clock1;
        sf::Time elapsed;
        float deltaTime;
        sf::Uint8 alpha = 255;
        while (elapsed.asSeconds() < 0.4) {
            clock1.restart();
            elapsed = clock.getElapsedTime();
            deltaTime = elapsed.asMilliseconds() - clock1.getElapsedTime().asMilliseconds();
            if (deltaTime > 3) {
                window->clear();
                //bg->setScale(bg->getScale().x, bg->getScale().y - 0.1f * delta);
                bg->setColor(sf::Color(255, 255, 255, alpha));
                alpha -= 1;
                window->draw(*bg);
                window->display();
            }
        }
        window->close();
    }
}

void Game::MainMenu::draw() {
    window->draw(*bg);
    for (size_t i = 0; i < buttons.size(); ++i) {
        buttons[i]->draw(window);
    }
}

void Game::MainMenu::setButtons() {
    sf::Texture * texture = new sf::Texture();
    texture->loadFromFile("res/img/button_0.png");

    for (size_t i = 0; i < 3; ++i) {
        buttons.push_back(new Button());
        buttons[i]->setTexture(texture);
        buttons[i]->setScale(0.3, 0.2);
        buttons[i]->setPosition(System::getWindowSize().x/2,
                                System::getWindowSize().y/2 - buttons[i]->getBounds().height +
                                        buttons[i]->getBounds().height * i);
    }
    font->loadFromFile("res/font/timeburnerbold.ttf");
    buttons[0]->setText(new sf::Text("New Game", *font, 26), sf::Color::White);
    buttons[1]->setText(new sf::Text("Load Game", *font, 26), sf::Color::White);
    buttons[2]->setText(new sf::Text("Exit", *font, 26), sf::Color::White);
}
