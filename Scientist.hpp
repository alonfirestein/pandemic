#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {

    // Scientist: Can perform a "drug discovery" operation with only n cards (instead of 5), where the parameter n is passed in the constructor (in the original game n = 4)
    class Scientist: public Player {
    
        int cards_for_cure;	
    	public:
        	Scientist(Board& b, City c, int cards): Player(b,c), cards_for_cure(cards){}  
        	Scientist& discover_cure(Color);
        	
        	const std::string role() const {
        		return "Scientist";
        	}
    };
}
