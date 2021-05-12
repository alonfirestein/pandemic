#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {

    // Researcher: Can perform a "drug discovery" operation in any city - does not have to be at a research station.
    class Researcher: public Player {
    
    	public:
        	Researcher(Board& b, City c): Player(b, c){} 
        	Researcher& discover_cure(Color);
        	
        	const std::string role() const {
        		return "Researcher";
        	}
    };
}
