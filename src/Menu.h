// Menu.h
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "login.h"

class Menu {
public:
    Menu(sf::RenderWindow &window);
    void displayMenu();

private:
    void drawCenteredText(sf::Text &text, float yPosition);
    void handleOptionSelection(int index);
    void showRules(sf::RenderWindow &window);
    void showDevelopedBy();

    sf::RenderWindow &window;
    float windowWidth;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<sf::Text> options;
    User user;
};

#endif // MENU_H
