#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {

    // Dispatcher: When he is at a research station, he can perform a "direct flight" operation to any city he wants, without throwing a city card.
    class Dispatcher: public Player {
    
	    public:
	        Dispatcher(Board& b, City c):Player(b, c){} 
	        Dispatcher& fly_direct(City);
        
	        const std::string role() const {
	            return "Dispatcher";
	        }
    };
}
