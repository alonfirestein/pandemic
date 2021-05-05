#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    
    class Board {
    
	std::unordered_set<int> game_cards;					// A set containing all the cards in the game
	std::unordered_map<City, std::unordered_set<City>> city_connections;	// For each city in the map will be a set of cities it is connected to
  	std::unordered_map<City, int> disease_cubes; 				// The disease cubes define the severity of the disease in the city
	std::unordered_map<City, Color> city_colors;				// Mapping all the cities and their corresponding color of the disease
	std::unordered_map<City, bool> research_stations;			// A boolean map answering if a research station is located in all the cities accordingly
	std::array<bool,4> cure_found = {false};				// A boolean array containing if a cure was found for the disease colors
	
	
    	public:
		Board();
		Color get_city_color(City c);			// Returns the color level of the disease in the input city
		bool are_connected(City from, City to);	// If two input cities are connected on the game map
		bool has_station(City c);			// If the input city has a research station in it
		bool add_station(City c);			// Adding a research station to the input city - returns true if successfull and false otherwise
		bool was_cure_found(Color disease);		// Returns true/false if a cure was found for the input disease of a certain color
		void found_cure(Color disease);		// Finding a cure for the input disease of the certain color
		
	
		int& operator[](City c);					// Changing the disease level in the input city	
		const int operator[](City c) const;				// Returning the disease level of the input city
		const bool is_clean() const; 					// True/False if the whole board is clean from diseases!
		void remove_cures(); 						// Completely removes all the discovered diseases (Method only for testing!)
		friend std::ostream& operator<<(std::ostream&, const Board&);	// Printing the board method
		

	    };
	    
	    
}
