#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>


namespace pandemic {

    class Player {
    
    	public:
    	        Board& b;
        	City city;
        	std::vector<City> color_cards(Color);	  // Returning all the cards of the same input color
        	std::unordered_set<City> cards_in_hand;   // A set of all the cards located in the players hands
		Player(Board&, City);
		Player& take_card(City);
		City& get_location() {
			return city;
		}
		virtual Player& drive(City); 		// Player drives to connected input city
		virtual Player& fly_direct(City);	// Player flies directly to input city
		virtual Player& fly_charter(City);	// Player flies charter to input city
		virtual Player& fly_shuttle(City);	// Player flies shuttle to input city
		virtual Player& discover_cure(Color);	// Player discovers cure for disease of input color
		virtual Player& build();		// Player builds a research station in current city he's located in
		virtual Player& treat(City);		// Player treats disease in input city
		virtual const std::string role() {
			return "Player";
		}

    };
}
