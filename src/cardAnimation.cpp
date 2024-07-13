#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "background.h"

int main()
{
    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG game");
    Background background(windowWidth, windowHeight);

    sf::Texture cardTexture;
    if (!cardTexture.loadFromFile("../images/cardBack.png"))
    {
        std::cerr << "Couldn't load background.";
        return -1;
    }
    sf::Sprite cardSprite;
    cardSprite.setTexture(cardTexture);

    // Center the card sprite
    sf::FloatRect cardBounds = cardSprite.getLocalBounds();
    cardSprite.setOrigin(cardBounds.width / 2, cardBounds.height / 2);
    cardSprite.setPosition(windowWidth / 2, windowHeight / 2);

    sf::RectangleShape smallRectangle(sf::Vector2f(40.f, 50.f)); 
    smallRectangle.setFillColor(sf::Color::Red); 
    smallRectangle.setPosition(windowWidth - 80, 25.f); 

    bool moving = true; 
    bool cardVisible = true; 
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update the position of the card sprite
        if (moving)
        {
            cardSprite.move(2, -2); // Move right by 2 pixels and up by 2 pixels

            // Check if the sprite has reached the top-right corner
            sf::Vector2f position = cardSprite.getPosition();
            if (position.x + cardBounds.width / 2 >= windowWidth && position.y - cardBounds.height / 2 <= 0)
            {
                moving = false; // Stop moving the sprite
                cardVisible = false; // Hide the card sprite
                
            }
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw things here
        background.draw(window);
        if (cardVisible)
        {
            window.draw(cardSprite);
        }
        else
        {
            window.draw(smallRectangle);
        }

        // End the current frame
        window.display();
    }

    return 0;
}
