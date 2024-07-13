#include <iostream>
#include <SFML/Graphics.hpp>
class Background
{
public:
    Background(float windowWidth, float windowHeight)
    {

        if (!tBackground.loadFromFile("../images/casino_background.jpg"))
        {
            std::cerr << "Couldn't load background.";
        }

        setBackground(windowWidth,windowHeight);
    }
    void draw(sf::RenderWindow& window){
        window.draw(sBackground);
    }

private:
    sf::Texture tBackground;
    sf::Sprite sBackground;

    void setBackground(float windowWidth, float windowHeight){
        sBackground.setTexture(tBackground);
        sBackground.setTextureRect(sf::IntRect(0, 0, windowWidth, windowHeight));
    }
};
