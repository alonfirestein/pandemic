#include "Medic.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

// Medic: When he performs a "disease treatment" operation, he removes all the disease cubes from the city he is in, and not just one.

Medic& Medic::drive(City c)
{
    Player::drive(c);
    if(b.was_cure_found(b.get_city_color(city))) { b[city] = 0; }
    return *this;
}

Medic& Medic::fly_direct(City c)
{
    Player::fly_direct(c);
    if(b.was_cure_found(b.get_city_color(city))) { b[city] = 0; }
    return *this;
}

Medic& Medic::fly_charter(City c)
{
    Player::fly_charter(c);
    if(b.was_cure_found(b.get_city_color(city))) { b[city] = 0; }
    return *this;
}

Medic& Medic::fly_shuttle(City c)
{
    Player::fly_shuttle(c);
    if(b.was_cure_found(b.get_city_color(city))) { b[city] = 0; }
    return *this;
}

Medic& Medic::treat(City c)
{
    if(b[c] > 0) { b[c] = 0; }
    else { throw invalid_argument("ERROR: There are no current diseases in this city!");}
    return *this;
}



