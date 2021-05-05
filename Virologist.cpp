#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

// Virologist: Can perform a "disease treatment" operation, not only in the city in which it is located, but in any city in the world - by throwing a card of that city.
Virologist& Virologist::treat(City c) {
    if(b[c] == 0)
    {
        throw invalid_argument("ERROR: There is no disease in this city!");
    }
    
    if(city == c)
    {
        Player::treat(c);
        return *this;
    }
    if(cards_in_hand.contains(c))
    {
        cards_in_hand.erase(c);
        b[c]--;
    }
    else
    {
        throw invalid_argument("ERROR: Virologist can only treat with the current city card!");
    }
    return *this;
}


