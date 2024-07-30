// login.cpp
#include "login.h"
#include "Menu.h"
#include "dealScreen.h"
#include <iostream>
#include <fstream>
#include <sstream>

User::User(const std::string &dataFilePath) : dataFilePath(dataFilePath)
{
    if (!font.loadFromFile("../../Fonts/arial.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
}

void User::displayMenu(sf::RenderWindow &window)
{
    if (!loadBackgroundTexture())
        return;

    // Define menu options without numbers
    std::vector<std::string> menuOptions = {
        "Sign Up",
        "Log In",
        "Reset Password",
        "Delete Account",
        "Exit"};

    std::vector<sf::Text> menuTexts;

    // Create text object for "Go Back" button
    sf::Text goBackText("Go Back", font, 24);
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Top-left corner
    goBackText.setOrigin(goBackText.getLocalBounds().width / 2, goBackText.getLocalBounds().height / 2);

    // Calculate the total height of all menu options
    float totalMenuHeight = menuOptions.size() * 40;           // 40 pixels per option
    float startY = (window.getSize().y - totalMenuHeight) / 2; // Starting Y position for centering

    // Create text objects for each menu option
    for (size_t i = 0; i < menuOptions.size(); ++i)
    {
        sf::Text text(menuOptions[i], font, 24);
        text.setFillColor(sf::Color::White);
        text.setPosition(window.getSize().x / 2, startY + i * 40); // Adjust the vertical position for each option
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        menuTexts.push_back(text);
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if "Go Back" was clicked
                    sf::FloatRect goBackBounds = goBackText.getGlobalBounds();
                    if (goBackBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        return; // Go back to the previous menu or exit
                    }

                    // Check which menu option was clicked
                    for (size_t i = 0; i < menuTexts.size(); ++i)
                    {
                        sf::FloatRect textBounds = menuTexts[i].getGlobalBounds();
                        if (textBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                        {
                            switch (i)
                            {
                            case 0:
                                signUp(window);
                                break;
                            case 1:
                                logIn(window);
                                break;
                            case 2:
                                resetPassword(window);
                                break;
                            case 3:
                                deleteAccount(window);
                                break;
                            case 4:
                                window.close();
                                break;
                            default:
                                break;
                            }
                            // After handling the click, return to the menu
                            displayMenu(window);
                            return;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(goBackText); // Draw the "Go Back" button
        for (const auto &text : menuTexts)
        {
            window.draw(text);
        }
        window.display();
    }
}
void User::signUp(sf::RenderWindow &window)
{
    if (!loadBackgroundTexture())
        return;

    // Create a "Go Back" button
    sf::Text goBackText("Go Back", font, 24);
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Top-left corner
    goBackText.setOrigin(goBackText.getLocalBounds().width / 2, goBackText.getLocalBounds().height / 2);

    std::string userName, email, password;
    getInput(window, userName, "Enter your username:");
    if (userName.empty())
    {
        displayMessage(window, "Username cannot be empty!");
        return;
    }

    getInput(window, email, "Enter your email:");
    if (email.empty())
    {
        displayMessage(window, "Email cannot be empty!");
        return;
    }

    getInput(window, password, "Enter your password:");
    if (password.empty())
    {
        displayMessage(window, "Password cannot be empty!");
        return;
    }

    std::ofstream file(dataFilePath, std::ios::out | std::ios::app);
    if (!file)
    {
        displayMessage(window, "Error opening file!");
        return;
    }
    file << userName << ' ' << email << ' ' << password << '\n';
    displayMessage(window, "Sign up successful!");

    // Show "Go Back" button
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if "Go Back" was clicked
                    sf::FloatRect goBackBounds = goBackText.getGlobalBounds();
                    if (goBackBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        return; // Go back to the previous menu
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(goBackText); // Draw the "Go Back" button
        window.display();
        startGame(window);
    }
}

void User::logIn(sf::RenderWindow &window)
{
    if (!loadBackgroundTexture())
        return;

    // Create a "Go Back" button
    sf::Text goBackText("Go Back", font, 24);
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Top-left corner
    goBackText.setOrigin(goBackText.getLocalBounds().width / 2, goBackText.getLocalBounds().height / 2);

    std::string userName, password;
    getInput(window, userName, "Enter your username:");
    getInput(window, password, "Enter your password:");

    std::ifstream file(dataFilePath);
    if (!file)
    {
        displayMessage(window, "Error opening file!");
        return;
    }

    std::string storedUserName, storedEmail, storedPassword;
    bool found = false;
    while (file >> storedUserName >> storedEmail >> storedPassword)
    {
        if (storedUserName == userName && storedPassword == password)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        displayMessage(window, "Log in successful!");
        startGame(window);
    }
    else
    {
        displayMessage(window, "Invalid username or password!");
    }

    // Show "Go Back" button
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if "Go Back" was clicked
                    sf::FloatRect goBackBounds = goBackText.getGlobalBounds();
                    if (goBackBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        return; // Go back to the previous menu
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(goBackText); // Draw the "Go Back" button
        window.display();
    }
}

void User::resetPassword(sf::RenderWindow &window)
{
    if (!loadBackgroundTexture())
        return;

    // Create a "Go Back" button
    sf::Text goBackText("Go Back", font, 24);
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Top-left corner
    goBackText.setOrigin(goBackText.getLocalBounds().width / 2, goBackText.getLocalBounds().height / 2);

    std::string userName, email, newPassword;
    getInput(window, userName, "Enter your username:");
    getInput(window, email, "Enter your email:");

    std::ifstream file(dataFilePath);
    if (!file)
    {
        displayMessage(window, "Error opening file!");
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    file.close();

    std::ofstream outFile(dataFilePath);
    if (!outFile)
    {
        displayMessage(window, "Error opening file!");
        return;
    }

    std::string storedUserName, storedEmail, storedPassword;
    bool found = false;
    std::istringstream iss(data);
    while (iss >> storedUserName >> storedEmail >> storedPassword)
    {
        if (storedUserName == userName && storedEmail == email)
        {
            found = true;
            getInput(window, newPassword, "Enter your new password:");
            if (newPassword.empty())
            {
                displayMessage(window, "Password cannot be empty!");
                return;
            }
            outFile << storedUserName << ' ' << storedEmail << ' ' << newPassword << '\n';
        }
        else
        {
            outFile << storedUserName << ' ' << storedEmail << ' ' << storedPassword << '\n';
        }
    }

    if (found)
    {
        displayMessage(window, "Password reset successful!");
    }
    else
    {
        displayMessage(window, "User not found!");
    }

    // Show "Go Back" button
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if "Go Back" was clicked
                    sf::FloatRect goBackBounds = goBackText.getGlobalBounds();
                    if (goBackBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        return; // Go back to the previous menu
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(goBackText); // Draw the "Go Back" button
        window.display();
    }
}

void User::deleteAccount(sf::RenderWindow &window)
{
    if (!loadBackgroundTexture())
        return;

    // Create a "Go Back" button
    sf::Text goBackText("Go Back", font, 24);
    goBackText.setFillColor(sf::Color::White);
    goBackText.setPosition(10, 10); // Top-left corner
    goBackText.setOrigin(goBackText.getLocalBounds().width / 2, goBackText.getLocalBounds().height / 2);

    std::string userName, email, password;
    getInput(window, userName, "Enter your username:");
    getInput(window, email, "Enter your email:");
    getInput(window, password, "Enter your password:");

    std::ifstream file(dataFilePath);
    if (!file)
    {
        displayMessage(window, "Error opening file!");
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    file.close();

    std::ofstream outFile(dataFilePath);
    if (!outFile)
    {
        displayMessage(window, "Error opening file!");
        return;
    }

    std::string storedUserName, storedEmail, storedPassword;
    bool found = false;
    std::istringstream iss(data);
    while (iss >> storedUserName >> storedEmail >> storedPassword)
    {
        if (storedUserName == userName && storedEmail == email && storedPassword == password)
        {
            found = true;
        }
        else
        {
            outFile << storedUserName << ' ' << storedEmail << ' ' << storedPassword << '\n';
        }
    }

    if (found)
    {
        displayMessage(window, "Account deleted successfully!");
    }
    else
    {
        displayMessage(window, "Account not found or incorrect credentials!");
    }

    // Show "Go Back" button
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if "Go Back" was clicked
                    sf::FloatRect goBackBounds = goBackText.getGlobalBounds();
                    if (goBackBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        return; // Go back to the previous menu
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(goBackText); // Draw the "Go Back" button
        window.display();
    }
}

bool User::loadBackgroundTexture()
{
    // Load the background texture from file
    if (!backgroundTexture.loadFromFile("../../images/casino_background.jpg"))
    {
        std::cerr << "Error loading background image\n";
        return false;
    }
    background.setTexture(backgroundTexture);
    return true;
}

void User::displayMessage(sf::RenderWindow &window, const std::string &message)
{
    // Create a text object to display the message
    sf::Text text(message, font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Clear the window, draw the background and the message, and display it
    window.clear();
    window.draw(background);
    window.draw(text);
    window.display();

    // Pause to allow the user to read the message
    sf::sleep(sf::seconds(1));
}

void User::getInput(sf::RenderWindow &window, std::string &input, const std::string &prompt)
{
    // Create text objects for the prompt and user input
    sf::Text promptText(prompt, font);
    promptText.setCharacterSize(24);
    promptText.setFillColor(sf::Color::White);
    promptText.setOrigin(promptText.getLocalBounds().width / 2, promptText.getLocalBounds().height / 2);
    promptText.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 50);

    sf::Text inputText("", font, 24);
    inputText.setFillColor(sf::Color::White);

    std::string userInput;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == '\b')
                {
                    // Handle backspace
                    if (!userInput.empty())
                    {
                        userInput.pop_back();
                    }
                }
                else if (event.text.unicode == '\r')
                {
                    // Handle Enter key
                    input = userInput;
                    return;
                }
                else
                {
                    // Handle normal character input
                    userInput += event.text.unicode;
                }
                // Update input text
                inputText.setString(userInput);
                inputText.setOrigin(inputText.getLocalBounds().width / 2, inputText.getLocalBounds().height / 2);
                inputText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            }
        }

        // Clear the window and draw prompt and input text
        window.clear();
        window.draw(background);
        window.draw(promptText);
        window.draw(inputText);
        window.display();
    }
}
