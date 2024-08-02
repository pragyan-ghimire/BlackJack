// Menu.h
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "login.h"

class Menu {
public:
    Menu(sf::RenderWindow &window); //renders the window   
    void displayMenu();     

private:
    void drawCenteredText(sf::Text &text, float yPosition); //to position the text at the center of the window
    void handleOptionSelection(int index);  //handles click event
    void showRules(sf::RenderWindow &window);  
    void showDevelopedBy(sf::RenderWindow &window);

    sf::RenderWindow &window;
    float windowWidth;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<sf::Text> options;
    User user;
};

#endif // MENU_H
