#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic {

    // Medic: When he performs a "disease treatment" operation, he removes all the disease cubes from the city he is in, and not just one.
    class Medic: public Player {
    
	    public:
	        Medic(Board& b, City c):Player(b, c){} 
	        Medic& drive(City);
	        Medic& fly_direct(City);
	        Medic& fly_charter(City);
	        Medic& fly_shuttle(City);
	        Medic& treat(City);
	        
	        const std::string role() const {
    			return "Medic";
		}

    };
}
