#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace pandemic;
const int min_cards_for_cure = 5;

/***********
************
************
Function explanations located in header file!
************
************
************/


Player::Player(Board& board, City c):b(board), city(c){}


// Player takes city card to his hand
Player& Player::take_card(City card) 
{
    cards_in_hand.insert(card);
    return *this;
}

// Player drives to input city if the cities are connected
Player& Player::drive(City to) 
{
    if(b.are_connected(city, to)) 
    {
        city = to;
    }
    else
    {
        throw invalid_argument("ERROR: Cannot drive to this city, the cities are not connected!");
    }
    return *this;
}

// Player flies directly to input city if he has the card
Player& Player::fly_direct(City to) 
{
    if(cards_in_hand.contains(to))
    {
        cards_in_hand.erase(to);
        city = to;
    }
    else
    {
        throw invalid_argument("ERROR: Cannot fly directly to this city because current player doesn't have this city card!");
    }
    return *this;
}

// Player flies charter to input city if he has the card (then throws the card away)
Player& Player::fly_charter(City to) 
{
    if(cards_in_hand.contains(city))
    {
        cards_in_hand.erase(city);
        city = to;
    }
    else
    {
        throw invalid_argument("ERROR: Cannot fly charter to this city because current player doesn't have this city card!");
    }
    return *this;
}

// Player flies shuttle to input city only if both cities have a research station
Player& Player::fly_shuttle(City to) 
{
    if(b.has_station(city) && b.has_station(to)) 
    {
        city = to;
    }
    else
    {
        throw invalid_argument("ERROR: Cannot fly shuttle to this city because research stations are mandatory in both cities!");
    }
    return *this;
}
 
// Player discovers cure for a certain colored disease
Player& Player::discover_cure(Color disease)
{
    if(b.has_station(city)) 
    {
        vector<City> to_throw = color_cards(disease);
        
        if(to_throw.size() >= min_cards_for_cure) 
        {
            for(size_t i = 0; i < min_cards_for_cure; i++)
            {
                cards_in_hand.erase(to_throw.at(i));
            }
            b.found_cure(disease);
        }
        else {
            throw invalid_argument("ERROR: Cannot discover cure because current player doesn't have 5 cards from this colour!");
        }
    }
    else {
        throw invalid_argument("ERROR: A research station is mandatory in order to discover a cure!");
    }
    return *this;
}

// Player builds a research station in current city he's located in (To do this the player throws away the card)
Player& Player::build() {
    if(cards_in_hand.contains(city))
    {
        cards_in_hand.erase(city);
        if(!b.add_station(city))
        {
            throw invalid_argument("ERROR: There is already a research station in this city!");
        }
    }
    else
    {
        throw invalid_argument("ERROR: Current player does not hold the card for this city!");
    }
    return *this;
}

// Player treats the input city
Player& Player::treat(City c)
{
    if(city == c && b[c] > 0)
    {
        if(b.was_cure_found(b.get_city_color(c)))
        {
            b[c] = 0;
        }
        else
        {
            b[c]--;
        }
    }
    else if(b[c] == 0)
    {
        throw invalid_argument("ERROR: There are no current diseases in this city!");
    }
    else
    {
        throw invalid_argument("ERROR: Impossible to treat another city");
    }
    return *this;
}

// Returns all the cards that are the same color of the input color
vector<City> Player::color_cards(Color color)
{
    vector<City> colors;
    for(const auto& card: cards_in_hand) 
    {
        if(b.get_city_color(card) == color) { colors.push_back(card); }
    }
    return colors;
}

  
   
