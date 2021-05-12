#include "Scientist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <vector>

using namespace std;
using namespace pandemic;

// Scientist: Can perform a "drug discovery" operation with only n cards (instead of 5), where the parameter n is passed in the constructor (in the original game n = 4)
Scientist& Scientist::discover_cure(Color disease) {

    // If the current city has a research station located in it
    if(b.has_station(city)) {
    
        vector<City> to_throw = Player::color_cards(disease);
        if(to_throw.size() >= cards_for_cure)
        {
            for(size_t i = 0; i < cards_for_cure; i++)
            {
                cards_in_hand.erase(to_throw.at(i));
            }
            b.found_cure(disease);
        }
        else
        {
            cout << to_throw.size() << " , " << cards_for_cure << endl;
            throw invalid_argument("ERROR: The scientist doesn't have enough color cards to discover cure!");
        }
    }
    else
    {
        throw invalid_argument("ERROR: A reasearch station is mandatory in order to discover a cure!");
    }
    return *this;
}

