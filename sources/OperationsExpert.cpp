#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

// OperationsExpert: Can perform a "construction" operation in any city he is in, without throwing a suitable city card.
OperationsExpert& OperationsExpert::build() {

    b.add_station(city);
    return *this;
}


