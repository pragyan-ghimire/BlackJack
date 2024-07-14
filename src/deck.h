#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <chrono>
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
        // Use a combination of random_device and system clock to seed the generator
        std::random_device rd;
        auto seed = rd() ^ std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 g(seed);

        std::shuffle(coordinates.begin(), coordinates.end(), g);
    }

public:
    Deck()
    {
        storeCard();
        shuffleDeck();
        shuffleDeck();
    }

    std::pair<int, int> drawCard()
    {
        if (!coordinates.empty())
        {
            std::pair<int, int> lastCard = coordinates.back();
            coordinates.pop_back();
            std::cout<<"Number of cards left:"<<coordinates.size()<<std::endl;
            return lastCard;
        }
        else
        {
            throw std::out_of_range("No more cards to draw.");
        }
    }
};
