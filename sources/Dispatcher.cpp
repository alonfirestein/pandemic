#include "Dispatcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

//Dispatcher: When he is at a research station, he can perform a "direct flight" operation to any city he wants, without throwing a city card.
Dispatcher& Dispatcher::fly_direct(City c) {
        if(city == c)
    {
        throw invalid_argument("ERROR: Can't fly from a city to itself!");

    }
    // In case the current input city does not have a research station, then the player can fly directly to that city
    if(!b.has_station(city)){
        Player::fly_direct(c);
        return *this;
    }
    city = c;
    return *this;
}
