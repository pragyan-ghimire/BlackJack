#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"
#include "background.h"
#include "playScreen.h"

int main() {
    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BlackJack Game");

    Background background(windowWidth, windowHeight);
    Button button("Deal", windowWidth, windowHeight);

    PlayScreen playScreen;


    sf::Cursor defaultCursor;
    if (!defaultCursor.loadFromSystem(sf::Cursor::Arrow)) {
        std::cerr << "Couldn't load system cursor." << std::endl;
        return -1;
    }

    sf::Cursor handCursor;
    if (!handCursor.loadFromSystem(sf::Cursor::Hand)) {
        std::cerr << "Couldn't load hand cursor." << std::endl;
        return -1;
    }
    bool openPlayWindow = false;

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
        sf::FloatRect btnBounds = button.getBtnRect().getGlobalBounds();
        
        

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (btnBounds.contains(static_cast<sf::Vector2f>(cursorPos))) {
                window.setMouseCursor(handCursor);
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "clicked" << std::endl;
                    openPlayWindow = true;
                    window.close();
                }
            } else {
                window.setMouseCursor(defaultCursor);
            }
        }


        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw things here
        background.draw(window);
        button.draw(window);
        


        // End the current frame
        window.display();
    }
    if(openPlayWindow){
        playScreen.playWindow();
    }

    return 0;
}
