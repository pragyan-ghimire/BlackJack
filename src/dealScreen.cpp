#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.h"
int main()
{
    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG game");
    sf::Texture tBackground;
     sf::Sprite sBackground;

    if (!tBackground.loadFromFile("../images/casino_background.jpg"))
    {
        std::cerr << "Couldn't load background.";
        return -1;
    }

    sBackground.setTexture(tBackground);
    sBackground.setTextureRect(sf::IntRect(0, 0, windowWidth, windowHeight));
    Button button = Button("Deal",windowWidth,windowHeight);
    
    

    // Creating cursor objects
    sf::Cursor defaultCursor;
    if (!defaultCursor.loadFromSystem(sf::Cursor::Arrow))
    {
        std::cerr << "Couldn't load system cursor.";
        return -1;
    }

    sf::Cursor handCursor;
    if (!handCursor.loadFromSystem(sf::Cursor::Hand))
    {
        std::cerr << "Couldn't load hand cursor.";
        return -1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
        sf::FloatRect btnBounds = button.getBtnRect().getGlobalBounds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (btnBounds.contains(static_cast<sf::Vector2f>(cursorPos)))
            {
                window.setMouseCursor(handCursor);
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Clicked" << std::endl;
                }
            }
            else
            {
                window.setMouseCursor(defaultCursor);
            }
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw things here
        window.draw(sBackground);
        button.draw(window);

        // End the current frame
        window.display();
    }

    return 0;
}
