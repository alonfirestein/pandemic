#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic {

    // Virologist: Can perform a "disease treatment" operation, not only in the city in which it is located, but in any city in the world - by throwing a card of that city.
    class Virologist: public Player {
 
 	   public:
 	       Virologist(Board& b, City c): Player(b,c){}
 	       Virologist& treat(City);
        
 	       const std::string role() const {
 	       	return "Virologist";
 	       }
    };
}
