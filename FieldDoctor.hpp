#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"


namespace pandemic {

    // FieldDoctor: can perform a "disease treatment" operation not only in the city he is in but in any city near the city he is in (according to the context map), without throwing a city card
    class FieldDoctor: public Player {
    
    	public:
        	FieldDoctor(Board& b, City c):Player(b, c){} 
        	FieldDoctor& treat(City);
        
        	const std::string role() const{
    			return "Field Doctor";
		}
    };
}
