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
    city_connections[City::Algiers].insert({Madrid, Paris, Istanbul, Cairo});
    city_connections[City::Atlanta].insert({Chicago, Miami, Washington});
    city_connections[City::Baghdad].insert({Tehran, Istanbul, Cairo, Riyadh, Karachi});
    city_connections[City::Bangkok].insert({Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
    city_connections[City::Beijing].insert({Shanghai, Seoul});
    city_connections[City::Bogota].insert({MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
    city_connections[City::BuenosAires].insert({Bogota, SaoPaulo});
    city_connections[City::Cairo].insert({Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
    city_connections[City::Chennai].insert({Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
    city_connections[City::Chicago].insert({SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
    city_connections[City::Delhi].insert({Tehran, Karachi, Mumbai, Chennai, Kolkata});
    city_connections[City::Essen].insert({London, Paris, Milan, StPetersburg});
    city_connections[City::HoChiMinhCity].insert({Jakarta, Bangkok, HongKong, Manila});
    city_connections[City::HongKong].insert({Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
    city_connections[City::Istanbul].insert({Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
    city_connections[City::Jakarta].insert({Chennai, Bangkok, HoChiMinhCity, Sydney});
    city_connections[City::Johannesburg].insert({Kinshasa, Khartoum});
    city_connections[City::Karachi].insert({Tehran, Baghdad, Riyadh, Mumbai, Delhi});
    city_connections[City::Khartoum].insert({Cairo, Lagos, Kinshasa, Johannesburg});
    city_connections[City::Kinshasa].insert({Lagos, Khartoum, Johannesburg});
    city_connections[City::Kolkata].insert({Delhi, Chennai, Bangkok, HongKong});
    city_connections[City::Lagos].insert({SaoPaulo, Khartoum, Kinshasa});
    city_connections[City::Lima].insert({MexicoCity, Bogota, Santiago});
    city_connections[City::London].insert({NewYork, Madrid, Essen, Paris});
    city_connections[City::LosAngeles].insert({SanFrancisco, Chicago, MexicoCity, Sydney});
    city_connections[City::Madrid].insert({London, NewYork, Paris, SaoPaulo, Algiers});
    city_connections[City::Manila].insert({Taipei, HongKong, SanFrancisco, HoChiMinhCity, Sydney});
    city_connections[City::MexicoCity].insert({LosAngeles, Chicago, Miami, Lima, Bogota});
    city_connections[City::Miami].insert({Atlanta, MexicoCity, Washington, Bogota});
    city_connections[City::Milan].insert({Essen, Paris, Istanbul});
    city_connections[City::Montreal].insert({Chicago, Washington, NewYork});
    city_connections[City::Moscow].insert({StPetersburg, Istanbul, Tehran});
    city_connections[City::Mumbai].insert({Karachi, Delhi, Chennai});
    city_connections[City::NewYork].insert({Montreal, Washington, London, Madrid});
    city_connections[City::Osaka].insert({Taipei, Tokyo});
    city_connections[City::Paris].insert({Algiers, Essen, Madrid, Milan, London});
    city_connections[City::Riyadh].insert({Baghdad, Cairo, Karachi});
    city_connections[City::SanFrancisco].insert({LosAngeles, Chicago, Tokyo, Manila});
    city_connections[City::Santiago].insert({Lima});
    city_connections[City::SaoPaulo].insert({Bogota, BuenosAires, Lagos, Madrid});
    city_connections[City::Seoul].insert({Beijing, Shanghai, Tokyo});
    city_connections[City::Shanghai].insert({Beijing, HongKong, Taipei, Seoul, Tokyo});
    city_connections[City::StPetersburg].insert({Essen, Istanbul, Moscow});
    city_connections[City::Sydney].insert({Jakarta, Manila, LosAngeles});
    city_connections[City::Taipei].insert({Shanghai, HongKong, Osaka, Manila});
    city_connections[City::Tehran].insert({Baghdad, Moscow, Karachi, Delhi});
    city_connections[City::Tokyo].insert({Seoul, Shanghai, Osaka, SanFrancisco});
    city_connections[City::Washington].insert({Atlanta, NewYork, Montreal, Miami}); 
    
    // Initializing the city color according to the game map
    city_colors[City::Algiers] = Black;
    city_colors[City::Atlanta] = Blue;
    city_colors[City::Baghdad] = Black;
    city_colors[City::Bangkok] = Red;
    city_colors[City::Beijing] = Red;
    city_colors[City::Bogota] = Yellow;
    city_colors[City::BuenosAires] = Yellow;
    city_colors[City::Cairo] = Black;
    city_colors[City::Chennai] = Black;
    city_colors[City::Chicago] = Blue;
    city_colors[City::Delhi] = Black;
    city_colors[City::Essen] = Blue;
    city_colors[City::HoChiMinhCity] = Red;
    city_colors[City::HongKong] = Red;
    city_colors[City::Istanbul] = Black;
    city_colors[City::Jakarta] = Red;
    city_colors[City::Johannesburg] = Yellow;;
    city_colors[City::Karachi] = Black;
    city_colors[City::Khartoum] = Yellow;
    city_colors[City::Kinshasa] = Yellow;
    city_colors[City::Kolkata] = Black;
    city_colors[City::Lagos] = Yellow;
    city_colors[City::Lima] = Yellow;
    city_colors[City::London] = Blue;
    city_colors[City::LosAngeles] = Yellow;
    city_colors[City::Madrid] = Blue;
    city_colors[City::Manila] = Red;
    city_colors[City::MexicoCity] = Yellow;
    city_colors[City::Miami] = Yellow;
    city_colors[City::Milan] = Blue;
    city_colors[City::Montreal] = Blue;
    city_colors[City::Moscow] = Black;
    city_colors[City::Mumbai] = Black;
    city_colors[City::NewYork] = Blue;
    city_colors[City::Osaka] = Red;
    city_colors[City::Paris] = Blue;
    city_colors[City::Riyadh] = Black;
    city_colors[City::SanFrancisco] = Blue;
    city_colors[City::Santiago] = Yellow;
    city_colors[City::SaoPaulo] = Yellow;
    city_colors[City::Seoul] = Red;
    city_colors[City::Shanghai] = Red;
    city_colors[City::StPetersburg] = Blue;
    city_colors[City::Sydney] = Red;
    city_colors[City::Taipei] = Red;
    city_colors[City::Tehran] = Black;
    city_colors[City::Tokyo] = Red;
    city_colors[City::Washington] = Blue;
        
}
// Changing the disease cube of the input city
int& Board::operator[](City c) 
{
    return disease_cubes[c];
}

// Checking if a boarding is completely clean from diseases
bool Board::is_clean()
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
