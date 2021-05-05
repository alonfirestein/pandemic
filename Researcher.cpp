#include "Researcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <stdexcept>

using namespace std;
using namespace pandemic;
const int min_cards_for_cure = 5;

// Researcher: Can perform a "drug discovery" operation in any city - does not have to be at a research station.
Researcher& Researcher::discover_cure(Color disease){
    
    vector<City> to_throw = color_cards(disease);
    if(to_throw.size() >= min_cards_for_cure) 
    {
        for(size_t i = 0; i < min_cards_for_cure; i++)
        {
            cards_in_hand.erase(to_throw.at(i));
        }
        b.found_cure(disease);
    }
    
    else 
    {
        throw invalid_argument("ERROR: Current player doesn't have 5 cards of this color!");
    }
    
    return *this;
}



