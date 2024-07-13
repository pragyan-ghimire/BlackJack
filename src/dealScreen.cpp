#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"
#include "background.h"
#include "card.h"

int main() {
    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG game");

    Background background(windowWidth, windowHeight);
    Button button("Deal", windowWidth, windowHeight);
    Card card;
    std::vector<Card> cards; // Vector to store drawn cards

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

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
        sf::FloatRect btnBounds = button.getBtnRect().getGlobalBounds();
        bool dealClicked = false;
        

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (btnBounds.contains(static_cast<sf::Vector2f>(cursorPos))) {
                window.setMouseCursor(handCursor);
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "clicked" << std::endl;
                    dealClicked = true;
                }
            } else {
                window.setMouseCursor(defaultCursor);
            }
        }

        if (dealClicked) {
            card.selectCard();
            card.setPosition(100 + cards.size() * 80, 100); // Adjust position for each card
            cards.push_back(card);
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw things here
        background.draw(window);
        button.draw(window);
        
        for (auto &card : cards) {
            card.draw(window);
        }

        // End the current frame
        window.display();
    }

    return 0;
}
