#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

// OperationsExpert: Can perform a "construction" operation in any city he is in, without throwing a suitable city card.
OperationsExpert& OperationsExpert::build() {

    // The operations expert can't build more than one research station in a city
    if(!b.add_station(city)){
        throw invalid_argument("ERROR: Research station already exists in current city!");
    }
    return *this;
}


