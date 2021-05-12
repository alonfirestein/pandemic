#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

// FieldDoctor: can perform a "disease treatment" operation not only in the city he is in but in any city near the city he is in (according to the context map), without throwing a city card
FieldDoctor& FieldDoctor::treat(City c) 
{

    if(b[c] == 0) 
    {
        throw invalid_argument("ERROR: There are no current diseases in this city!");
    }
    
    if(!b.are_connected(city, c) && city != c)
    {
        throw invalid_argument("ERROR: The cities are not connected!");
    }
    
    if(b.was_cure_found(b.get_city_color(c)))
    {
        b[c] = 0;
    }
    
    else 
    {
        b[c]--;
    }
    
    return *this;
}



