#include <iostream>
#include <climits>
using namespace std;
#include "other.h"
#include "board.h"
//#include <time.h>
//#include <stdlib.h>

/******************************************************
 * ** Program: Pokemon_GO.cpp
 * ** Author: Stefan Ball
 * ** Date: 05/30/2017
 * ** Description: Plays a game: Pokemon GO
 * ** Input: Size of board
 * ** Output: The Game!
 * ******************************************************/

int main(int argc, char *argv[]) {

   srand(time(NULL));

   int grid_size = find_grid_size(argc, argv);
   int answer;


   //Create the grid
   board play_area(grid_size);

   //While the player is not at the starting place, and all the pokemon are not captured, and the player doesn't have enough stones
   while (play_area.not_at_starting_place() || play_area.not_all_pokemon_captured() || play_area.not_enough_stones()) {

      //Print where the user currently is
      play_area.print_the_grid();

      //Test grid
#ifdef testing
      play_area.test_grid();
#endif
      
      //Check to see if the user is close to other stuff
      play_area.close_to_other_stuff();

#ifdef user
      //Ask the user where they want to move
      do {
	 if (cin.fail()) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	 }
	 cout << "Would you like to move up (4), down (3), left (1), or right (2)?";
	 cin >> answer;
      } while (cin.fail() || answer < 0 || answer > 4);
#endif

#ifdef ai
      answer = (rand() % 4)+1;
#endif

      //Move the user
      play_area.move(answer);


      //If there is a pokemon there, ask them if they'd like to throw a pokeball
      if (play_area.check_event_type() == 0 && play_area.get_num_balls() > 0) {
#ifdef user
	 do {
	    if (cin.fail()) {
	       cin.clear();
	       cin.ignore(INT_MAX, '\n');
	    }
	    cout << "Would you like to throw a pokeball? Yes (1), No (0): ";
	    cin >> answer;
	 } while (cin.fail() || answer < 0 || answer > 1);
#endif

#ifdef ai
	 answer = rand() % 2;
#endif

	 //If they want to throw a pokeball, throw one
	 if (answer == 1)
	    play_area.throw_pokeball();
      }


   }

   //play_area.delete_board();


   return 0;
}

