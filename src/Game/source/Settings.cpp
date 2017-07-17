//
// Created by mhs on 7/16/17.
//

#include "../header/Settings.h"

std::map<std::string, sf::Font>* Game::Settings::fonts  = nullptr;
//Game::GameState*    Game::Settings::state   = nullptr;
sf::Font*           Game::Settings::font                = nullptr;
sf::Mouse*          Game::Settings::mouse               = nullptr;
std::string         Game::Settings::title               = "";
uint                Game::Settings::upd_ratio           = 125;
unsigned            Game::Settings::tileSize            = 32;

void Game::Settings::init() {
    font = new sf::Font();
    //state = new GameState();
    mouse = new sf::Mouse();
    font->loadFromFile("res/font/orange_juice.ttf");
    title = "Flappy Bird";
    //*state = S_MainMenu;
    setFonts();
}

void Game::Settings::setFonts() {
    fonts = new std::map<std::string, sf::Font>();
    std::pair<std::string, sf::Font> tempPair;
    sf::Font tempFont;
    tempFont.loadFromFile("res/font/orange_juice.ttf");
    tempPair.first = "orange_juice";
    tempPair.second = tempFont;
    fonts->insert(tempPair);
    tempFont.loadFromFile("res/font/marlboro.ttf");
    tempPair.first = "marlboro";
    tempPair.second = tempFont;
    fonts->insert(tempPair);

}

void Game::Settings::close() {
    delete font;
    //delete state;
    delete mouse;
    delete fonts;
}

bool Game::Settings::setFont(std::string path) {
    return Settings::font->loadFromFile(path);
}

unsigned Game::Settings::getTileSize() {
    return tileSize;
}
//
//void Game::Settings::setState(Game::GameState _state) {
//    *state = _state;
//}
//
//Game::GameState Game::Settings::getState() {
//    GameState copy = *state;
//    return copy;
//}