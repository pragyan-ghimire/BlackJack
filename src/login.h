#ifndef LOGIN_H
#define LOGIN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class User
{
public:
    // Constructor that initializes the user class with a path to the data file
    User(const std::string &dataFilePath);

    // Display the main menu
    void displayMenu(sf::RenderWindow &window);

    // Handles user sign-up
    void signUp(sf::RenderWindow &window);

    // Handles user login
    void logIn(sf::RenderWindow &window);

    // Handles password reset
    void resetPassword(sf::RenderWindow &window);

    // Handles account deletion
    void deleteAccount(sf::RenderWindow &window);

private:
    // Load background texture for the window
    bool loadBackgroundTexture();

    // Display a message to the user
    void displayMessage(sf::RenderWindow &window, const std::string &message);

    // Get user input for various prompts
    void getInput(sf::RenderWindow &window, std::string &input, const std::string &prompt);

    // Data file path for storing user information
    std::string dataFilePath ;

    // SFML objects for displaying text and background
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Font font;
};

#endif // LOGIN_H
