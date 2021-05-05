#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;


TEST_CASE("Board Initialization and Test") 
{

	CHECK_NOTHROW(Board board;);
        Board board;
        CHECK(board.is_clean());
        CHECK_NOTHROW(board.are_connected(Bogota, Miami));
        CHECK_NOTHROW(board.are_connected(NewYork, London));
        CHECK(board.are_connected(Mumbai, Lima) == false);
        CHECK(board.get_city_color(Montreal) == board.get_city_color(Chicago));
        CHECK(board.has_station(Atlanta) == false);
        CHECK_NOTHROW(board.add_station(Atlanta));
        CHECK(board.has_station(Atlanta) == true);
        CHECK(board.was_cure_found(Yellow) == false);

}


TEST_CASE("Player Initialization") 
{

        Board board;
     	Player player(board, Lima);
        CHECK_NOTHROW(Player p(board, Montreal));
        CHECK(player.role() == "Player");
        CHECK_NOTHROW(player.drive(Bogota));	   // Connected
        CHECK_THROWS(player.fly_direct(Bogota));  // No card
        CHECK_THROWS(player.fly_charter(Bogota)); // No card
        CHECK_THROWS(player.fly_shuttle(Bogota)); // No research station in both cities
        player.take_card(Bogota);
	CHECK_NOTHROW(player.fly_direct(Bogota));	// Has card
        player.take_card(Bogota);
        CHECK_NOTHROW(player.fly_charter(Bogota));	// Has card
        player.take_card(Paris)
              .take_card(Bogota);
        
        board.add_station(Paris);			// Adding a station in paris to test flying shuttle
        player.build();				// Building a station in Bogota
        CHECK_NOTHROW(player.fly_shuttle(Paris));	// Has paris card and both cities have a research station!
        CHECK_THROWS(player.discover_cure(Yellow)); // No 5 yellow cards 
        CHECK_THROWS(player.build());		     // There is already a station here
        CHECK_THROWS(player.treat(Bogota));	     // No diseases here
        
        player.take_card(NewYork)
        	.take_card(Montreal)
        	.take_card(Chicago)
        	.take_card(Atlanta)
        	.take_card(Washington)
        	.take_card(Madrid)
        	.take_card(Paris);

        CHECK_NOTHROW(player.fly_direct(Madrid));		// Has card
        board[Madrid] = 3;
        CHECK(board[Madrid] == 3);
   	player.take_card(Madrid);
        player.treat(Madrid);
        CHECK(board[Madrid] == 2);
        player.build();
   	player.take_card(Madrid);
        CHECK_NOTHROW(player.discover_cure(Blue));
        
}


TEST_CASE("[] Operation")
{
	Board board;  			// Initializing an empty board
	board[Montreal] = 4;      // Ptting 4 yellow disease cubes in Montreal.
	board[London] = 2;    	// Putting 2 yellow disease cubes in London
	board[Paris] = 2; 	// Putting 2 yellow disease cubes in Paris
	board[Miami] = 1; 	// Putting 1 yellow disease cubes in Miami
	board[Montreal] = 3;      // Changing the number of disease cubes in Montreal to 3
	
	
	CHECK_EQ(board[Montreal], 3);
	CHECK_NE(board[City::Montreal], 4);
	CHECK(board[City::London] == 2);
	CHECK(board[City::Paris] == 2);
	CHECK(board[City::Miami] == 1);
	CHECK_NOTHROW(board[Miami] = 2);
	
	board[Montreal] = 1;
	board[Paris] = 0;
	
	CHECK(board[Montreal] != 3);
	CHECK(board[Madrid] == 0);
	CHECK(board[Chicago] == 0); // Initialized cities are automatically at 0!
	
	board[Chicago] = 2;
	CHECK(board[Chicago] != 0);
	CHECK(board[Chicago] == 2);
	board[NewYork] = 4;
	CHECK(board[NewYork] == 4);
	board[NewYork] = 1;
	CHECK(board[NewYork] == 1);
}


// OperationsExpert: Can perform a "construction" operation in any city he is in, without throwing a suitable city card.
TEST_CASE("Operations Expert")
{
	Board board;
	CHECK_NOTHROW(OperationsExpert operationsExpert(board, Paris););
        OperationsExpert operationsExpert(board, Paris);
        operationsExpert.build();
	operationsExpert.take_card(Manila)
			.take_card(Washington)
			.take_card(Atlanta); 
	operationsExpert.fly_direct(Washington);
	operationsExpert.build();
	operationsExpert.take_card(Washington)
			.take_card(Chicago)
			.take_card(London)
			.take_card(Essen)
			.take_card(Montreal);
			
	CHECK_THROWS(operationsExpert.fly_shuttle(Essen)); // No research station in Essen
	CHECK_NOTHROW(operationsExpert.fly_direct(London));
	operationsExpert.build();
	board[London] = 4;
	CHECK(board.is_clean() == false);
	board.remove_cures();
	CHECK_NOTHROW(operationsExpert.discover_cure(Blue));
	CHECK_NOTHROW(operationsExpert.treat(London));
	CHECK(board.is_clean() == true);

}

// Dispatcher: When he is at a research station, he can perform a "direct flight" operation to any city he wants, without throwing a city card.
TEST_CASE("Dispatcher")
{
	Board board;
	CHECK_NOTHROW(Dispatcher dispatcher(board, Jakarta););
	Dispatcher dispatcher{board, Jakarta};
	dispatcher.take_card(NewYork)
		  .take_card(Seoul);
	CHECK(dispatcher.cards_in_hand.count(Seoul) == true); // True
	dispatcher.fly_direct(Seoul);				// No research station then he throws away the card
	CHECK(dispatcher.cards_in_hand.count(Seoul) == false); // False
	board.add_station(Seoul); // Station exists
	CHECK(dispatcher.cards_in_hand.count(NewYork) == true);
	dispatcher.fly_direct(NewYork);			// Station exists => No card will be thrown
	CHECK(dispatcher.cards_in_hand.count(NewYork) == true);
	

}


// Scientist: Can perform a "drug discovery" operation using only n cards (instead of 5), with the n parameter passed to the constructor (in the original game n = 4).
TEST_CASE("Scientist")
{
	Board board;
	Scientist scientist{board, NewYork, 4};
	scientist.take_card(Atlanta);
	CHECK_NOTHROW(scientist.fly_direct(Atlanta));
	scientist.take_card(Atlanta);
	scientist.build();
	CHECK_THROWS(scientist.discover_cure(Red));
	scientist.take_card(City::Chicago)
	   .take_card(City::Montreal)
	   .take_card(City::Paris)
	   .take_card(City::Milan);
	CHECK_THROWS(scientist.discover_cure(Black));
	CHECK_NOTHROW(scientist.discover_cure(Blue));


}


// Researcher: Can perform a "drug discovery" operation in any city - does not have to be at a research station.
TEST_CASE("Researcher")
{
	Board board;
	Researcher researcher(board, Mumbai);
	CHECK_THROWS(researcher.discover_cure(Black)); // Not enough cards 
	researcher.take_card(Tehran)
	      .take_card(Istanbul)
	      .take_card(Cairo)
	      .take_card(Delhi)
	      .take_card(Algiers);
	      
	CHECK_NOTHROW(researcher.discover_cure(Black));  // Doesn't have to be at a station
	board[Mumbai] = 2;
	CHECK(board[Mumbai] ==  2);
	researcher.treat(Mumbai);
	CHECK(board[Mumbai] ==  0);


}


// Medic: When he performs a "disease treatment" operation, he removes all the disease cubes from the city he is in, and not just one.
TEST_CASE("Medic")
{
	Board board;
	Medic medic{board, Bangkok};
	board[Bangkok] = 3;
	CHECK(board[Bangkok] == 3);
	medic.treat(Bangkok);
	CHECK(board[Bangkok] == 0);

	medic.take_card(Tokyo)
		.take_card(Sydney)
		.take_card(City::HongKong)
		.take_card(Seoul)
		.take_card(Jakarta)
		.take_card(Taipei);
		
	CHECK_THROWS(medic.discover_cure(Red)); 	// Must have a research station in Bangkok
	medic.take_card(Bangkok);
	medic.build();
	board[Bangkok] = 3;
	CHECK_EQ(board[Bangkok], 3);
	CHECK_EQ(board.was_cure_found(Red), false);
	CHECK_NOTHROW(medic.discover_cure(Red));
	CHECK_EQ(board.was_cure_found(Red), true);

	board.add_station(Manila);
	medic.take_card(Manila);
	medic.fly_shuttle(Manila);
	CHECK_EQ(board[Manila], 0);

}


// Virologist: Can perform a "disease treatment" operation, not only in the city in which it is located, but in any city in the world - by throwing a card of that city.
TEST_CASE("Virologist")
{
	Board board;
	Virologist virologist{board, Moscow};
	CHECK_THROWS(virologist.treat(Moscow)); 	// No disease in Moscow	
	board[Moscow] = 2;
	CHECK_NOTHROW(virologist.treat(Moscow));
	CHECK(board[Moscow] == 1);
	
	
	// Virologist **DID NOT** fly to miami, but he can treat that city using that city card!
	board[Miami] = 4;
	CHECK_THROWS(virologist.treat(Miami));		// No miami card so he can't treat that city
	virologist.take_card(Miami);
	CHECK_NOTHROW(virologist.treat(Miami));
	CHECK(board[Miami] == 3);
	board[Miami] = 0;
	virologist.take_card(Miami);
	CHECK_THROWS(virologist.treat(Miami));
}


// GeneSplicer: Can perform a "drug discovery" operation with the help of 5 cards - not necessarily from the color of the disease.
TEST_CASE("Gene Splicer")
{
	Board board;
	GeneSplicer geneSplicer{board, LosAngeles};
	geneSplicer.take_card(LosAngeles);
	CHECK_THROWS(geneSplicer.discover_cure(Yellow));	// No research station in LA
	geneSplicer.build();
	CHECK_THROWS(geneSplicer.discover_cure(Yellow));	// Not enough cards to discover cure
	geneSplicer.take_card(MexicoCity)
		   .take_card(Bogota)
		   .take_card(Miami)
		   .take_card(Lima);
		   
	CHECK_THROWS(geneSplicer.discover_cure(Yellow));	// After building the station in LA, the card was thrown
	geneSplicer.take_card(City::LosAngeles);
	CHECK_NOTHROW(geneSplicer.discover_cure(Yellow));
	CHECK_THROWS(geneSplicer.discover_cure(Red));
	
	// Finding a cure while holding cards of different colors (The specialty of the Gene Splicer)!
	geneSplicer.take_card(Lagos)		// Yellow
		   .take_card(Madrid)		// Blue
		   .take_card(Jakarta) 	// Red
		   .take_card(Algiers)		// Black
		   .take_card(Sydney);		// Red
		   
	CHECK_NOTHROW(geneSplicer.discover_cure(Red));

}



// Field Doctor: Can perform a "disease treatment" operation not only in the city he is in but in any city near the city he is in (according to the context map), without throwing a city card.
TEST_CASE("Field Doctor")
{
	Board board;
	FieldDoctor fieldDoctor{board, Sydney};
	board[Sydney] = 3;
	CHECK_NOTHROW(fieldDoctor.treat(Sydney));
	CHECK(board[Sydney] == 2);
	
	// Syney is connected to Los Angeles on the map, but not to Paris!
	// Therefore the Field Doctor, can treat Los Angeles from Sydney without having or throwing a city card!
	board[LosAngeles] = 4;
	board[Paris] = 4;
	CHECK(board[LosAngeles] == 4);
	CHECK_NOTHROW(fieldDoctor.treat(LosAngeles));
	CHECK(board[LosAngeles] == 3);
	CHECK_THROWS(fieldDoctor.treat(Paris));	// Not connected to Sydney!

}

