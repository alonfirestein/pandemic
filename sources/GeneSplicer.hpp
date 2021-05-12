#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp" 

namespace pandemic {

    // GeneSplicer: Can perform a "drug discovery" operation with the help of 5 cards - not necessarily from the color of the disease.
    class GeneSplicer: public Player {
    
	    public:
	        GeneSplicer(Board& b, City c):Player(b, c){} 
	        GeneSplicer& discover_cure(Color disease);
	        const std::string role() const {
	        	return "GeneSplicer";
	        }
    };
}

