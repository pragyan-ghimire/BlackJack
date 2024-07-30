// Menu.cpp
#include "Menu.h"
#include <iostream>
#include <sstream>
#include "dealScreen.h"

Menu::Menu(sf::RenderWindow &window) : window(window), user("loginData.txt")
{
    sf::Vector2u windowSize = window.getSize();
    this->windowWidth = windowSize.x;
    if (!font.loadFromFile("../../Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font\n";
    }

    if (!backgroundTexture.loadFromFile("../../images/casino_background.jpg"))
    {
        std::cerr << "Error loading background image\n";
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);

    std::string menuItems[] = {"Play Game", "Account", "Rules", "Developed By"};
    for (int i = 0; i < 3; ++i)
    {
        sf::Text text(menuItems[i], font, (24 * windowWidth / 800));
        text.setFillColor(sf::Color::White);
        options.push_back(text);
    }
}

void Menu::drawCenteredText(sf::Text &text, float yPosition)
{
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(window.getSize().x / 2, yPosition);
}

void Menu::displayMenu()
{
    for (int i = 0; i < options.size(); ++i)
    {
        drawCenteredText(options[i], 200 + i * 100);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                for (int i = 0; i < options.size(); ++i)
                {
                    if (options[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        handleOptionSelection(i);
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        for (const auto &option : options)
        {
            window.draw(option);
        }
        window.display();
    }
}

void Menu::handleOptionSelection(int index)
{
    switch (index)
    {
    case 0:
        startGame(window);
    case 1:
        user.displayMenu(window); // Play Game
        break;
    case 2:
        showRules(window); // Rules
        break;
    case 3:
        showDevelopedBy(); // Developed By
        break;
    }
}

void Menu::showRules(sf::RenderWindow &window)
{
    sf::Font font;
    if (!font.loadFromFile("../../Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font\n";
        return;
    }

    std::string rulesText = R"(
        \t\t\tRules of Blackjack:
        
        1. Objective:
           The goal is to have a hand value closer to 21 than the dealer without going over 21.
        sta
        2. Card Values:
           - Cards 2 to 10 are worth their face value.
           - Face cards (Jack, Queen, King) are worth 10 points each.
           - Aces can be worth 1 or 11 points, depending on the hand.
        
        3. Gameplay:
           - Players are dealt two cards face up.
           - The dealer gets one card face up and one face down (hole card).
           - Players can hit (take another card) or stand (keep current hand) to get closer to 21.
        
        4. Dealer's Turn:
           - The dealer reveals their hole card and hits until their hand is at least 17.
        
        5. Winning:
           - Players win by having a hand value closer to 21 than the dealer's without busting.
           - Blackjack (Ace + 10-value card) pays 3 to 2.
        
        6. Losing:
           - Players lose if their hand exceeds 21 (bust).
           - Dealer wins ties (pushes).
        
        7. Additional Options:
           - Players can split pairs, double down, or take insurance (if dealer shows an Ace).
        
        8. Strategy:
           - Basic strategy uses probabilities to make optimal decisions.
           - Strategies vary based on player hand, dealer upcard, and casino rules.
        
        9. Variations:
           - Blackjack rules may vary by casino, including splitting, doubling down, and payouts.

















    )";

    sf::Text rulesMessage(rulesText, font, (18 * windowWidth / 800)); // Adjusted font size to 18px
    rulesMessage.setFillColor(sf::Color::White);

    // Adjusting line length
    float maxWidth = window.getSize().x - 100; // Allow some margin on the sides
    std::stringstream ss(rulesText);
    std::string line;
    std::string formattedText;
    sf::Text tempText("", font, (18 * windowWidth / 800)); // Temporary text object for measurement

    while (std::getline(ss, line))
    {
        tempText.setString(line);
        if (tempText.getLocalBounds().width > maxWidth)
        {
            std::string word;
            std::stringstream lineStream(line);
            float lineWidth = 0.0f;
            while (lineStream >> word)
            {
                tempText.setString(word);
                float wordWidth = tempText.getLocalBounds().width;
                if (lineWidth + wordWidth > maxWidth)
                {
                    formattedText += "\n";
                    lineWidth = 0.0f;
                }
                formattedText += word + " ";
                lineWidth += wordWidth;
            }
            formattedText += "\n";
        }
        else
        {
            formattedText += line + "\n";
        }
    }

    rulesMessage.setString(formattedText);

    // Calculate the height of the text
    float textHeight = rulesMessage.getLocalBounds().height;

    // Go Back button
    sf::Text goBackText("<< Go Back", font, (18 * windowWidth / 800));
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Adjust position as needed

    float scrollSpeed = 10.0f; // Pixels per frame to scroll
    float scrollPosition = 0.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                // Handle scrolling with arrow keys
                if (event.key.code == sf::Keyboard::Up)
                {
                    scrollPosition -= scrollSpeed;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    scrollPosition += scrollSpeed;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Check if "Go Back" text is clicked
                if (goBackText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    return; // Return from function to go back
            }
        }

        // Adjust scroll position bounds
        if (scrollPosition < 0.0f)
            scrollPosition = 0.0f;
        if (scrollPosition > textHeight - window.getSize().y)
            scrollPosition = textHeight - window.getSize().y;

        // Set the text position based on scroll position
        rulesMessage.setPosition(50, 50 - scrollPosition);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(rulesMessage);
        window.draw(goBackText); // Draw the "Go Back" button
        window.display();
    }
}

void Menu::showDevelopedBy()
{

    std::string aboutText = R"(

        Three passionate friends, currently pursuing BE in Computer at Pulchowk Campus, Lalitpur
        collaborated to create an engaging game of Blackjack. Driven by their deep understanding
        of Object-Oriented Programming principles in C++, they aimed to showcase their skills
        while crafting an enjoyable gaming experience.

        This project not only reflects their dedication to learning and application of OOP concepts
        but also highlights their teamwork and problem-solving abilities. Through this game, they
        demonstrated how theoretical knowledge can be transformed into practical, interactive software.

        Developers:
        - Nitesh Baniya    (079BCT051)
        - Prabesh Regmi    (079BCT058)
        - Pragyan Ghimire  (079BCT059)

    )";
    sf::Text aboutMessage(aboutText, font, (18 * windowWidth / 800));
    // aboutMessage.setFont(font);
    // aboutMessage.setString(
    //     "Developed By:\n"
    //     "Your Name\n"
    //     "Project Information\n"
    //     "Additional Details\n"
    // );
    // aboutMessage.setCharacterSize(18);
    aboutMessage.setFillColor(sf::Color::White);
    drawCenteredText(aboutMessage, window.getSize().y / 2);

    sf::Text backText("Go Back", font, (24 * windowWidth / 800));
    backText.setFillColor(sf::Color::White);
    drawCenteredText(backText, window.getSize().y - 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (backText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    return; // Go back to main menu
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(aboutMessage);
        window.draw(backText);
        window.display();
    }
}
