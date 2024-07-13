// card.h
#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "deck.h"

enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Card {
private:
    sf::Texture cardTexture;
    sf::Sprite cardSprite;
    Deck deck = Deck();

    void loadCard() {
        if (!cardTexture.loadFromFile("../images/card_sprite_sheet.png")) {
            std::cerr << "Couldn't load card sprite sheet";
        }
  
    }

public:
    Suit suit;
    Rank rank;

    Card() {
        loadCard();
    }
    void selectCard(){
              
        std::pair<int, int> card = deck.drawCard();
        int XIndex = card.first;
        int YIndex = card.second;
        std::cout << "Card coordinate : "<<card.first << ", " << card.second<<std::endl;
        cardSprite.setTexture(cardTexture);
        cardSprite.setTextureRect(sf::IntRect(XIndex * 71, YIndex * 96, 71, 96));
    }

    void setPosition(float x, float y) {
        cardSprite.setPosition(x, y);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(cardSprite);
    }
};

#endif
