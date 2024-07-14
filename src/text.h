#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Text
{
public:
    Text(int windowWidth, int windowHeight)
        : windowWidth(windowWidth), windowHeight(windowHeight)
    {
        if (!font.loadFromFile("../Fonts/arial.ttf"))
        {
            std::cerr << "Couldn't load font Arial." << std::endl;
        }

        text.setFont(font);
        text.setFillColor(sf::Color::White);

    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(text);
    }

    void setPosition(float x, float y)
    {
        text.setPosition(x, y);
    }
    void setText(std::string customText)
    {
        text.setString(customText);
        centerText();
    }

private:
    sf::Font font;
    sf::Text text;
    float windowWidth;
    float windowHeight;

    void centerText()
    {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.0f));
    }
};
