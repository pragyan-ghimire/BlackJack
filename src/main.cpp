// main.cpp
#include <SFML/Graphics.hpp>
#include "Menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Blackjack Game");
    Menu menu(window);
    menu.displayMenu();
    return 0;
}
