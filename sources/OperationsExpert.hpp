#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic {

    // OperationsExpert: Can perform a "construction" operation in any city he is in, without throwing a suitable city card.
    class OperationsExpert: public Player {
    
   	 public:
       	 OperationsExpert(Board& b, City c):Player(b, c){} 
      	 	 OperationsExpert& build();
      	  
       	 const std::string role() const{
       	     return "OperationsExpert";
        }
    };
}
