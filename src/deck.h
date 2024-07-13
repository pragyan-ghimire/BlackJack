#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <utility>
#include <stdexcept>

class Deck
{
private:
    std::vector<std::pair<int, int>> coordinates; // Coordinates of cards

    void storeCard()
    {
        for (int x = 0; x <= 12; ++x)
        {
            for (int y = 0; y <= 3; ++y)
            {
                coordinates.emplace_back(x, y); // Constructing the pair in place
            }
        }
    }

    void shuffleDeck()
    {
        // Use a random number generator to shuffle the coordinates
        std::random_device rd; // Seed generator
        std::mt19937 g(rd());  // Random number generator

        std::shuffle(coordinates.begin(), coordinates.end(), g);
    }

public:
    Deck()
    {
        storeCard();
        shuffleDeck();
    }

    std::pair<int, int> drawCard()
    {
        if (!coordinates.empty())
        {
            std::pair<int, int> lastCard = coordinates.back();
            coordinates.pop_back();
            return lastCard;
        }
        else
        {
            throw std::out_of_range("No more cards to draw.");
        }
    }

    std::pair<int, int> getCard()
    {
        return drawCard();
    }
};
