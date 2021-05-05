#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;
const int min_cards_for_cure = 5;

// GeneSplicer: Can perform a "drug discovery" operation with the help of 5 cards - not necessarily from the color of the disease.
GeneSplicer& GeneSplicer::discover_cure(Color disease) {

    if(b.has_station(city)) 
    {
        if(cards_in_hand.size() >= min_cards_for_cure)
        {
            int card_counter = 0;
            for(const auto& card : cards_in_hand)
            {
                if(card_counter < min_cards_for_cure) 
                {
                    cards_in_hand.erase(card);
                    card_counter++;
                }
            }
            b.found_cure(disease);
        }
        else 
        {
            throw invalid_argument("ERROR: Current player does not have 5 or more cards!");
        }
    }
    else{
        throw invalid_argument("ERROR: Research station needed in order to discover cure");
    }
    
    return *this;
}



