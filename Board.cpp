#include <iostream>
#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;


/***********
************
************
Overview function explanations located in header file!
************
************
************/


// Constructor: Creating and initializing the game board for the start
Board::Board() 
{
    // Initializing the disease cube level to 0 for all of the cities at the start of the game
    for(int c = City::Algiers; c<= City::Washington; c++)
    {
        disease_cubes[(City)c] = 0;
    }
    
    // Initializing that none of the cities have research stations at the start of the game
    for(size_t i = City::Algiers; i <= City::Washington; i++)
    {
        game_cards.insert(i);
        research_stations[(City)i] = false;
    }
    
    // Initializing the city_connections map by adding all the cities and adding a set of their neighbouring cities in the game 
    city_connections[Algiers].insert({Madrid, Paris, Istanbul, Cairo});
    city_connections[Atlanta].insert({Chicago, Miami, Washington});
    city_connections[Baghdad].insert({Tehran, Istanbul, Cairo, Riyadh, Karachi});
    city_connections[Bangkok].insert({Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
    city_connections[Beijing].insert({Shanghai, Seoul});
    city_connections[Bogota].insert({MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
    city_connections[BuenosAires].insert({Bogota, SaoPaulo});
    city_connections[Cairo].insert({Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
    city_connections[Chennai].insert({Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
    city_connections[Chicago].insert({SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
    city_connections[Delhi].insert({Tehran, Karachi, Mumbai, Chennai, Kolkata});
    city_connections[Essen].insert({London, Paris, Milan, StPetersburg});
    city_connections[HoChiMinhCity].insert({Jakarta, Bangkok, HongKong, Manila});
    city_connections[HongKong].insert({Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
    city_connections[Istanbul].insert({Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
    city_connections[Jakarta].insert({Chennai, Bangkok, HoChiMinhCity, Sydney});
    city_connections[Johannesburg].insert({Kinshasa, Khartoum});
    city_connections[Karachi].insert({Tehran, Baghdad, Riyadh, Mumbai, Delhi});
    city_connections[Khartoum].insert({Cairo, Lagos, Kinshasa, Johannesburg});
    city_connections[Kinshasa].insert({Lagos, Khartoum, Johannesburg});
    city_connections[Kolkata].insert({Delhi, Chennai, Bangkok, HongKong});
    city_connections[Lagos].insert({SaoPaulo, Khartoum, Kinshasa});
    city_connections[Lima].insert({MexicoCity, Bogota, Santiago});
    city_connections[London].insert({NewYork, Madrid, Essen, Paris});
    city_connections[LosAngeles].insert({SanFrancisco, Chicago, MexicoCity, Sydney});
    city_connections[Madrid].insert({London, NewYork, Paris, SaoPaulo, Algiers});
    city_connections[Manila].insert({Taipei, SanFrancisco, HoChiMinhCity, Sydney});
    city_connections[MexicoCity].insert({LosAngeles, Chicago, Miami, Lima, Bogota});
    city_connections[Miami].insert({Atlanta, MexicoCity, Washington, Bogota});
    city_connections[Milan].insert({Essen, Paris, Istanbul});
    city_connections[Montreal].insert({Chicago, Washington, NewYork});
    city_connections[Moscow].insert({StPetersburg, Istanbul, Tehran});
    city_connections[Mumbai].insert({Karachi, Delhi, Chennai});
    city_connections[NewYork].insert({Montreal, Washington, London, Madrid});
    city_connections[Osaka].insert({Taipei, Tokyo});
    city_connections[Paris].insert({Algiers, Essen, Madrid, Milan, London});
    city_connections[Riyadh].insert({Baghdad, Cairo, Karachi});
    city_connections[SanFrancisco].insert({LosAngeles, Chicago, Tokyo, Manila});
    city_connections[Santiago].insert({Lima});
    city_connections[SaoPaulo].insert({Bogota, BuenosAires, Lagos, Madrid});
    city_connections[Seoul].insert({Beijing, Shanghai, Tokyo});
    city_connections[Shanghai].insert({Beijing, HongKong, Taipei, Seoul, Tokyo});
    city_connections[StPetersburg].insert({Essen, Istanbul, Moscow});
    city_connections[Sydney].insert({Jakarta, Manila, LosAngeles});
    city_connections[Taipei].insert({Shanghai, HongKong, Osaka, Manila});
    city_connections[Tehran].insert({Baghdad, Moscow, Karachi, Delhi});
    city_connections[Tokyo].insert({Seoul, Shanghai, Osaka, SanFrancisco});
    city_connections[Washington].insert({Atlanta, NewYork, Montreal, Miami}); 
    
    // Initializing the city color according to the game map
    city_colors[Algiers] = Black;
    city_colors[Atlanta] = Blue;
    city_colors[Baghdad] = Black;
    city_colors[Bangkok] = Red;
    city_colors[Beijing] = Red;
    city_colors[Bogota] = Yellow;
    city_colors[BuenosAires] = Yellow;
    city_colors[Cairo] = Black;
    city_colors[Chennai] = Black;
    city_colors[Chicago] = Blue;
    city_colors[Delhi] = Black;
    city_colors[Essen] = Blue;
    city_colors[HoChiMinhCity] = Red;
    city_colors[HongKong] = Red;
    city_colors[Istanbul] = Black;
    city_colors[Jakarta] = Red;
    city_colors[Johannesburg] = Yellow;;
    city_colors[Karachi] = Black;
    city_colors[Khartoum] = Yellow;
    city_colors[Kinshasa] = Yellow;
    city_colors[Kolkata] = Black;
    city_colors[Lagos] = Yellow;
    city_colors[Lima] = Yellow;
    city_colors[London] = Blue;
    city_colors[LosAngeles] = Yellow;
    city_colors[Madrid] = Blue;
    city_colors[Manila] = Red;
    city_colors[MexicoCity] = Yellow;
    city_colors[Miami] = Yellow;
    city_colors[Milan] = Blue;
    city_colors[Montreal] = Blue;
    city_colors[Moscow] = Black;
    city_colors[Mumbai] = Black;
    city_colors[NewYork] = Blue;
    city_colors[Osaka] = Red;
    city_colors[Paris] = Blue;
    city_colors[Riyadh] = Black;
    city_colors[SanFrancisco] = Blue;
    city_colors[Santiago] = Yellow;
    city_colors[SaoPaulo] = Yellow;
    city_colors[Seoul] = Red;
    city_colors[Shanghai] = Red;
    city_colors[StPetersburg] = Blue;
    city_colors[Sydney] = Red;
    city_colors[Taipei] = Red;
    city_colors[Tehran] = Black;
    city_colors[Tokyo] = Red;
    city_colors[Washington] = Blue;
        
}
// Changing the disease cube of the input city
int& Board::operator[](City c) 
{
    return disease_cubes[c];
}

// Returning the disease cube of the input city
const int Board::operator[](City c) const 
{
    return disease_cubes.at(c);
}

// Checking if a boarding is completely clean from diseases
const bool Board::is_clean() const
{
    for(const auto& city : this->disease_cubes) 
    {
        if(city.second > 0) { return false; }
    }
    return true;
}

// TESTING METHOD ONLY: removing all the cures found for all the colors
void Board::remove_cures() 
{
    for(size_t i = 0; i < 4; i++) { cure_found.at(i) = false; }
}

// Checking if two cities are connected
bool Board::are_connected(City from, City to) 
{
    return city_connections[from].contains(to);
}

// Checking if the input city has a research station
bool Board::has_station(City c) 
{
    return research_stations[c];
}

// Adding a research station to the input city
bool Board::add_station(City c) 
{
    if(research_stations[c])
    {
	return false;
    }
    research_stations[c] = true;
    return true;
}

//Returns the color level of the disease in the input city
Color Board::get_city_color(City c)
{
    return city_colors[c];
}

// Returns true/false if a cure was found for the input disease of a certain color
bool Board::was_cure_found(Color disease)
{
    return cure_found.at(disease);
}

// Finding a cure of a certain disease color
void Board::found_cure(Color disease)
{
    cure_found.at(disease) = true;
} 


// Printing the board
ostream& pandemic::operator<<(ostream& os, const Board& board)
{
    for(const auto& city: board.disease_cubes)
    {
        os << "[" << city.first << ',' << city.second << "]\n";
    }
    return os;
}
