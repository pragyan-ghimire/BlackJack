#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Button {
public:
    Button(const std::string& buttonText, float windowWidth, float windowHeight) 
        : btnBgColor(0x1679ABFF), btnBgRect(sf::Vector2f(120.f, 50.f)), 
          windowWidth(windowWidth), windowHeight(windowHeight) 
    {
        if (!font.loadFromFile("../Fonts/arial.ttf")) {
            std::cerr << "Couldn't load font Arial." << std::endl;
        }
        
        text.setFont(font);
        text.setString(buttonText);
        text.setFillColor(sf::Color::White);

        setButtonProperties();
        centerButton();
        centerText();
    }

    void draw(sf::RenderWindow& window) {
        window.draw(btnBgRect);
        window.draw(text);
    }

    sf::RectangleShape getBtnRect() { return btnBgRect; }

    void setBtnRect(float x, float y) {
        btnBgRect.setSize(sf::Vector2f(x, y));
        centerText();
        centerButton();
    }

    void setPosition(float x, float y) {
        btnBgRect.setPosition(x, y);
        centerText();
    }

private:
    sf::Color btnBgColor;
    sf::Font font;
    sf::RectangleShape btnBgRect;
    sf::Text text;
    float windowWidth;
    float windowHeight;

    void centerText() {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(btnBgRect.getPosition());
    }

    void centerButton() {
        sf::FloatRect btnRect = btnBgRect.getLocalBounds();
        btnBgRect.setOrigin(btnRect.left + btnRect.width / 2.0f, btnRect.top + btnRect.height / 2.0f);
        btnBgRect.setPosition(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.0f));
    }


    void setButtonProperties() {
        btnBgRect.setFillColor(btnBgColor);
        btnBgRect.setScale(1.05f, 1.1f);
    }
};
