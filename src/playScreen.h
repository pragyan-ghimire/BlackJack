#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "card.h"
#include "text.h"
#include "menu.h"

class PlayScreen
{
private:
    void checkWinner(int playerScore, int dealersScore, Text &text)
    {
        // player losing conditions
        if (playerScore < 21 && playerScore < dealersScore && dealersScore <= 21)
        {
            text.setText("You lost!");
        }
        else if (playerScore > 21 && dealersScore > 21)
        {
            text.setText("You lost!");
        }
        else if (playerScore == dealersScore)
        {
            text.setText("You lost!");
        }

        // player winning conditions
        if (playerScore == 21)
        {
            text.setText("You won!");
        }
        else if (playerScore < 21 && playerScore > dealersScore && dealersScore <= 21)
        {
            text.setText("You won!");
        }
    }

public:
    void playAgain()
    {
        playWindow();
    }
    void playWindow()
    {

        int windowWidth = 800;
        int windowHeight = 600;


        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BlackJack Game", sf::Style::Titlebar | sf::Style::Close);
        Menu menu(window);

        Background background(windowWidth, windowHeight);
        Button btnHit("Hit", windowWidth, windowHeight);
        Button btnStand("Stand", windowWidth, windowHeight);
        Button btnPlayAgain("Play Again", windowWidth, windowHeight);
        Button btnGoBack("Go Back", windowWidth, windowHeight);

        Text text(windowWidth, windowHeight);

        Card card;
        std::vector<Card> playerCards; // Vector to store drawn playerCards
        std::vector<Card> dealerCards; // Vector to store drawn dealersCards

        // dummy to hide first card
        sf::Texture cardTexture;
        if (!cardTexture.loadFromFile("../../images/cardBack.png"))
        {
            std::cerr << "Couldn't load background.";
        }
        sf::Sprite cardSprite;

        sf::Cursor defaultCursor;
        if (!defaultCursor.loadFromSystem(sf::Cursor::Arrow))
        {
            std::cerr << "Couldn't load system cursor." << std::endl;
        }

        sf::Cursor handCursor;
        if (!handCursor.loadFromSystem(sf::Cursor::Hand))
        {
            std::cerr << "Couldn't load hand cursor." << std::endl;
        }

        //////////////////////////////position of hit and stand button////////////////////////////////
        btnHit.setPosition(200, 300);
        btnStand.setPosition(600, 300);
        btnPlayAgain.setPosition(400, 400);
        btnGoBack.setPosition(80, 30);

        int playerScore = 0;
        int dealerScore = 0;

        for (int i = 0; i < 2; i++)
        {
            card.selectCard();
            card.setPosition(300 + playerCards.size() * 80, 450); // Adjust position for each card
            playerCards.push_back(card);
            playerScore += card.rank;
        }
        // std::cout << "player score" << playerScore << std::endl;
        for (int i = 0; i < 2; i++)
        {
            card.selectCard();
            card.setPosition(300 + dealerCards.size() * 80, 100); // Adjust position for each card
            dealerCards.push_back(card);
            dealerScore += card.rank;
        }
        // std::cout << "DealerScore" << dealerScore << std::endl;
        bool playerTurn = true;
        bool hideFirstCard = true;
        bool gameFinished = false;

        while (window.isOpen())
        {
            sf::Event event;
            sf::Vector2i cursorPos = sf::Mouse::getPosition(window);
            sf::FloatRect btnHitBounds = btnHit.getBtnRect().getGlobalBounds();
            sf::FloatRect btnStandBounds = btnStand.getBtnRect().getGlobalBounds();
            sf::FloatRect btnPlayAgainBounds = btnPlayAgain.getBtnRect().getGlobalBounds();
            sf::FloatRect btnGoBackBounds = btnGoBack.getBtnRect().getGlobalBounds();

            // Initializing flags
            bool hitClicked = false;
            bool standClicked = false;
            bool playagainClicked = false;

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
                            hideFirstCard = false;
                        }
                    }
                    else if (btnGoBackBounds.contains(static_cast<sf::Vector2f>(cursorPos)))
                    {
                        window.setMouseCursor(handCursor);
                        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                            // std::cout << "stand clicked" << std::endl;
                            menu.displayMenu();
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
                // std::cout << playerScore << std::endl;
                if (playerScore > 21 || playerScore == 21)
                {
                    playerTurn = false;
                    standClicked = true;
                    hideFirstCard = false;
                    // std::cout << "player lost" << std::endl;
                    // std::cout<<playerTurn;
                    text.setText("You Lost!");
                    gameFinished = true;
                }
            }
            // else if (removed as else if) replace by if
            if (standClicked)
            {
                // std::cout << "Dealers turn";
                playerTurn = false;
                while (dealerScore < 17)
                {
                    card.selectCard();
                    card.setPosition(300 + dealerCards.size() * 80, 100); // Adjust position for each card
                    dealerCards.push_back(card);
                    dealerScore += card.rank;
                    // std::cout << dealerScore << std::endl;
                }
                if (dealerScore > 21 && playerScore < 21)
                {
                    // std::cout << "Dealer lost";
                    text.setText("You Won!");
                    gameFinished = true;
                }
                else
                {
                    checkWinner(playerScore, dealerScore, text);
                    gameFinished = true;
                }
            }

            // Clear the window with black color
            window.clear(sf::Color::Black);

            // Draw things here
            background.draw(window);
            btnHit.draw(window);
            btnStand.draw(window);
            btnGoBack.draw(window);

            if (gameFinished)
            {
                window.clear(sf::Color::Black);
                background.draw(window);
                btnPlayAgain.draw(window);
                while (window.pollEvent(event))
                {
                    if (btnPlayAgainBounds.contains(static_cast<sf::Vector2f>(cursorPos)))
                    {
                        window.setMouseCursor(handCursor);
                        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                            // std::cout << "play again clicked" << std::endl;
                            window.close();
                            // std::cout<<"mathi"<<std::endl;
                            playAgain();
                            // std::cout<<"tala"<<std::endl;
                        }
                    }
                }
            }

            // display playerCards
            for (auto &card : playerCards)
            {
                card.draw(window);
            }

            // display dealerCards
            for (size_t i = 0; i < dealerCards.size(); ++i)
            {
                if (i == 0 && hideFirstCard)
                {
                    cardSprite.setTexture(cardTexture);
                    cardSprite.setPosition(300, 100);
                    window.draw(cardSprite);
                }
                else
                {
                    dealerCards[i].draw(window);
                }
            }
            text.draw(window);

            // End the current frame
            window.display();
        }
    }
};
