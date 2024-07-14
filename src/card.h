
#include <SFML/Graphics.hpp>
#include <iostream>
#include "deck.h"

class Card
{
private:
    sf::Texture cardTexture;
    sf::Sprite cardSprite;
    Deck deck = Deck();

    void loadCard()
    {
        if (!cardTexture.loadFromFile("../images/card_sprite_sheet.png"))
        {
            std::cerr << "Couldn't load card sprite sheet";
        }
    }

public:
    int rank;

    Card()
    {
        loadCard();
    }
    void selectCard()
    {
        std::pair<int, int> card = deck.drawCard();
        int XIndex = card.first;
        int YIndex = card.second;
        rank = value(XIndex);
        // std::cout << "Card coordinate : " << card.first << ", " << card.second << std::endl;
        cardSprite.setTexture(cardTexture);
        cardSprite.setTextureRect(sf::IntRect(XIndex * 71, YIndex * 96, 71, 96));
    }

    void setPosition(float x, float y)
    {
        cardSprite.setPosition(x, y);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(cardSprite);
    }
    int value(int rank) const
    {
        if (rank == 0)
        {
            return 1;
        }
        else if (rank == 10 || rank == 11 || rank == 12)
        {
            return 10;
        }
        else
        {
            return rank+1;
        }
    }
};

