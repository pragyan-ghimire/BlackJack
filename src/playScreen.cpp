#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"
#include "background.h"
#include "card.h"

void checkWinner(int playerScore, int dealersScore)
{

    // player losing conditions
    if (playerScore < 21 && playerScore < dealersScore && dealersScore <= 21)
    {
        std::cout << "player lost";
    }
    else if (playerScore == dealersScore)
    {
        std::cout << "player lost";
    }

    // player winning conditions
    if (playerScore == 21)
    {
        std::cout << "player wins";
    }
    else if (playerScore < 21 && playerScore > dealersScore && dealersScore <= 21)
    {
        std::cout << "player wins";
    }
}

int main()
{

    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG game");

    Background background(windowWidth, windowHeight);
    Button btnHit("Hit", windowWidth, windowHeight);
    Button btnStand("Stand", windowWidth, windowHeight);
    Card card;
    std::vector<Card> playerCards; // Vector to store drawn playerCards
    std::vector<Card> dealerCards; // Vector to store drawn dealersCards

    sf::Cursor defaultCursor;
    if (!defaultCursor.loadFromSystem(sf::Cursor::Arrow))
    {
        std::cerr << "Couldn't load system cursor." << std::endl;
        return -1;
    }

    sf::Cursor handCursor;
    if (!handCursor.loadFromSystem(sf::Cursor::Hand))
    {
        std::cerr << "Couldn't load hand cursor." << std::endl;
        return -1;
    }

    //////////////////////////////position of hit and stand button////////////////////////////////
    btnHit.setPosition(200, 300);
    btnStand.setPosition(600, 300);

    int playerScore = 0;
    int dealerScore = 0;

    for (int i = 0; i < 2; i++)
    {
        card.selectCard();
        card.setPosition(300 + playerCards.size() * 80, 450); // Adjust position for each card
        playerCards.push_back(card);
        playerScore += card.rank;
    }
    std::cout << "player score" << playerScore << std::endl;
    for (int i = 0; i < 2; i++)
    {
        card.selectCard();
        card.setPosition(300 + dealerCards.size() * 80, 100); // Adjust position for each card
        dealerCards.push_back(card);
        dealerScore += card.rank;
    }
    std::cout << "DealerScore" << dealerScore << std::endl;
    bool playerTurn = true;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
        sf::FloatRect btnHitBounds = btnHit.getBtnRect().getGlobalBounds();
        sf::FloatRect btnStandBounds = btnStand.getBtnRect().getGlobalBounds();

        // Initializing flags
        bool hitClicked = false;
        bool standClicked = false;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (playerTurn)
            {

                if (btnHitBounds.contains(static_cast<sf::Vector2f>(cursorPos)))
                {
                    window.setMouseCursor(handCursor);
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // std::cout << "hit clicked" << std::endl;
                        hitClicked = true;
                    }
                }
                else if (btnStandBounds.contains(static_cast<sf::Vector2f>(cursorPos)))
                {
                    window.setMouseCursor(handCursor);
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // std::cout << "stand clicked" << std::endl;
                        standClicked = true;
                    }
                }
            }
            else
            {
                window.setMouseCursor(defaultCursor);
            }
        }

        if (hitClicked && playerTurn)
        {
            card.selectCard();
            card.setPosition(300 + playerCards.size() * 80, 450); // Adjust position for each card
            playerCards.push_back(card);
            playerScore += card.rank;
            std::cout << playerScore << std::endl;
            if (playerScore > 21)
            {
                playerTurn = false;
                std::cout << "player lost"<<std::endl;
                // std::cout<<playerTurn;
            }

        }
        else if (standClicked)
        {
            std::cout << "Dealers turn";
            playerTurn = false;
            while (dealerScore < 17)
            {
                card.selectCard();
                card.setPosition(300 + dealerCards.size() * 80, 100); // Adjust position for each card
                dealerCards.push_back(card);
                dealerScore += card.rank;
                std::cout << dealerScore << std::endl;
            }
            if (dealerScore > 21)
            {
                std::cout << "Dealer lost";
            }
            checkWinner(playerScore, dealerScore);
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw things here
        background.draw(window);
        btnHit.draw(window);
        btnStand.draw(window);

        for (auto &card : playerCards)
        {
            card.draw(window);
        }
        for (auto &card : dealerCards)
        {
            card.draw(window);
        }

        // End the current frame
        window.display();
    }

    return 0;
}
