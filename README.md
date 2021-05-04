
# Pandemic Board Game  
  
“To practice dealing with global epidemics, we need games” (Bill Gates, 2015). One of the games created to practice dealing with epidemics is Pandemic. This is a board game for 2 to 4 players, playing together to cure diseases and discover medicines.

In this task some of the rules of the game are implemented, for only one player.

## The Board  
The game board is a map of the world, with 48 cities. Some of the cities are connected by a line that allows you to travel between them. You can see the list of cities and their connections in [this picture](https://media.wnyc.org/i/1500/900/c/80/1/1537_Pandemic_main.jpg). The cities are divided into four colors - blue, yellow, black and red - 12 cities of each color.
  
The list of cities, colors and contexts is also in the cities_map.txt file.  
  
In this task, the board is represented by the Board class.


## The Cards  
There are 48 cards - one card per city.

The names of the cities in the code will be just like on the map, with no spaces. For example, the name of New York City is NewYork. Spelling must be observed to avoid compilation errors.  
  
## The Diseases
There are diseases of four colors - blue, yellow, black and red. Each city may have "disease cubes" in a color appropriate to that city.

In the "Board" department, the following methods must be implemented (see example files):  
- Square bracket operator [] - accepts as city-ID parameter, and allows to read and update the level of disease (= number of disease cubes) in that city. For example: `board [City :: HongKong] = 2` places two red disease cubes in Hong Kong.
- Output Operator - Displays the status of the board in any format of your choice. The board mode includes:
	- The level of disease in each of the cities;
	- The drugs discovered so far (see explanation below);
	- Research stations built so far (see explanation below).
- `is_clean`- Boolean method without parameters, which returns "true" if and only if the whole board is clean - there are no disease cubes.
- `remove_cures` - a parameter-free method, which removes from the board all the drugs discovered so far (see explanation below). This method is intended for the purpose of writing tests; It never throws an exception, and there is no need to check it in a special way.
  
## The Player  
The player starts the game in one of the cities, and receives a number of cards. In each turn, he can perform the following actions (see demo files):  
  
- Drive -  `drive` - move from the current city to a nearby city (according to the context map).  
  
- Direct flight - `fly_direct` - Transfer from the current city to the city of any card in his hand. To do this, throw the appropriate card to the city you are flying to.  
  
- Charter flight - `fly_charter` - transfer from the current city to any city. To do this, throw the appropriate card to the city you are in.  
  
- Shuttle flight - `fly_shuttle` - If there is a research station in the current city, you can fly to any other city that has a research station.  
  
- Build Reseach Station - `build` - build a research station in the city that is located in it. To do this, throw the appropriate card to the city you are in.     
	- Each city can have at most one research station. If there is already a research station in the current city, and a "construction" operation is performed again, there is no need to throw an exception, and the card remains in the player's hands.  
- Discover Cure - `discover_cure` - Drug discovery for a disease of a certain color. To do this, you must be in a city that has a research station, and throw 5 colored cards of the disease. The color of the city they are in does not matter.  
	- Each disease has one cure. If a cure for the disease has already been discovered, and a "cure discovery" for the same disease is performed again, there is no need to discard an exception, and the cards remain in the player's hands.  
  
- Treat Disease- `treat` - Deleting one disease cube from the city you are in (reducing the level of the disease by 1).  
	- If a cure for the disease has already been discovered in the color of the city, then the action of "cure the disease" removes all the disease cubes from the city that are in it (reducing the level of the disease to 0).  
	- If there is no infection at all in the city (the disease level is 0), then the action will throw an abnormality.  
  
  
Each action should update the board status and player position accordingly. If the operation is invalid, an appropriate exception must be thrown.

In addition, the following methods were implemented:  
  
- `role` - a function that returns the role of the player (see list of roles below), for display.  
- `take_card` - take a city card. This simulates the process by which the player receives cards from the pot at the beginning or during the game.  
	- There is only one card of each city, so if you take a take_card operation on a card already in the player's possession, there will be no change in the player's position.  
	- There is no need to check the correctness of this method. In particular: there is no need to check that the card is still at the cash register, or that you do not give a card twice, etc. The method always succeeds.  
*Remarks:*  
  
There can be two or more players in the same city - nothing special happens in this situation.

## Roles  
  
There are different roles of players, who have special skills (the skills are similar but not the same as the original game):  
  
1.) OperationsExpert: Can perform a "construction" operation in any city he is in, without throwing a suitable city card.  
  
2.) Dispatcher: When he is at a research station, he can perform a "direct flight" operation to any city he wants, without throwing a city card.  
  
3.) Scientist: Can perform a "drug discovery" operation using only n cards (instead of 5), with the n parameter passed to the constructor (in the original game n = 4).  
  
4.) Researcher: Can perform a "drug discovery" operation in any city - does not have to be at a research station.  
  
5.) Paramedic - Medic: When he performs a "disease treatment" operation, he removes all the disease cubes from the city he is in, and not just one.  
	- If a cure for the disease has already been discovered, it automatically lowers all the disease cubes from any city it is in, even without performing a "disease treatment" action.  
  
6.) Virologist: Can perform a "disease treatment" operation, not only in the city in which it is located, but in any city in the world - by throwing a card of that city.  
  
7.) GeneSplicer: Can perform a "drug discovery" operation with the help of 5 cards - not necessarily from the color of the disease.  
  
8.) Field Doctor - FieldDoctor: Can perform a "disease treatment" operation not only in the city he is in but in any city near the city he is in (according to the context map), without throwing a city card.  
  
  
  
To run the demo files to see how it runs you can run:  
<div dir='ltr'>

    make demo1 && ./demo1
    make demo2 && ./demo2
	make test && ./test

</div>

In addition its possible to check extra remarks and memory leaks using:  

<div dir='ltr'>

    make tidy
    make valgrind

</div>


Enjoy!
</div>
