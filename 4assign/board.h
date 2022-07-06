#ifndef BOARD_H
#define BOARD_H
#include "location.h"
#include "pokemon.h"
#include "event.h"
#include "other.h"
#include <iostream>
using namespace std;
class board {
   private:
      int grid_size;
      int num_pokeballs;
      int num_pokemon; //What do with this?
      int num_stones;
      location **grid;
      int starting_place[2];
      int current_place[2];
      event **pokemon_captured; // problem
      //event *pokemon_captured[6];
      int num_pokemon_captured;
      //Things to point to
      //Don't know why can't include constructor in this
      /*
      flying charizard(3);
      flying rayquaza(4);
      rock geodude(1);
      rock onix(2);
      psychic mewtwo(5);
      psychic espeon(6);
      cave the_cave;
      pokestop the_pokestop;
      */
      //Things to point to
      flying charizard;
      flying rayquaza;
      rock geodude;
      rock onix;
      psychic mewtwo;
      psychic espeon;
      cave the_cave;
      pokestop the_pokestop;

   public:
      ~board() {
	 for (int i = 0; i < grid_size; i++)
	    delete [] grid[i];

	 delete [] grid;

	 delete [] (pokemon_captured);

      }
      //Creates event, grid, populates map
      board(int grid_size) {
	 //event* pokemon_captured = new event[6]; // not working
	 pokemon_captured = new event*[6]; // not working
	 this->grid_size = grid_size;
	 num_pokemon_captured = 0;

	 //Set num_pokeballs and num_stones to 0
	 num_pokeballs = 0;
	 num_stones = 0;

	 //Create grid grid_size x grid_size
	 grid = new location*[grid_size];
	 for (int i = 0; i < grid_size; i ++)
	    grid[i] = new location[grid_size];

	 //Initialize starting place to random location
	 starting_place[0] = rand() % grid_size;
	 starting_place[1] = rand() % grid_size;

	 //Initialize current place to starting place
	 current_place[0] = starting_place[0];
	 current_place[1] = starting_place[1];

	 //Holder
	 event *new_event; 

	 //event holder_event;

	 for (int i = 0; i < 8; i++) {
#ifdef testing
	    cout << i << endl;
#endif
	    switch(i) {
	       case 0:
		  new_event = &charizard;
		  break;
	       case 1:
		  new_event = &rayquaza;
		  break;
	       case 2:
		  new_event = &geodude;
		  break;
	       case 3:
		  new_event = &onix;
		  break;
	       case 4:
		  new_event = &mewtwo;
		  break;
	       case 5:
		  new_event = &espeon;
		  break;
	       case 6:
		  new_event = &the_cave;
		  break;
	       case 7:
		  new_event = &the_pokestop;
		  break;
	    }

	    while (true) {
	       int x = rand() % grid_size;
	       int y = rand() % grid_size;
	       if (grid[x][y].get_event() == NULL && (x != starting_place[0]  || y != starting_place[1])) {
		  grid[x][y].set_event(new_event);
#ifdef testing
		  cout << "Type: " << grid[x][y].get_event()->get_type() << endl;
#endif
		  break;
	       }
	    }
	 }
	 new_event = NULL;
      }

      //Allows player to move on the grid
      void move(int where) {
	 //1 = up
	 //2 = down
	 //3 = left
	 //4 = right
	 //ask_question(where
	 if (where == 1) {
	    if (current_place[1] >= grid_size-1) {
	       cout << "You can't move off the board!" << endl;
	       return;
	    }
	    current_place[1] += 1;
	 }

	 if (where == 2) {
	    if (current_place[1] <= 0) {
	       cout << "You can't move off the board!" << endl;
	       return;
	    }
	    current_place[1] -= 1;
	 }

	 if (where == 3) {
	    if (current_place[0] <= 0) {
	       cout << "You can't move off the board!" << endl;
	       return;
	    }
	    current_place[0] -= 1;
	 }

	 if (where == 4) {
	    if (current_place[0] >= grid_size-1) {
	       cout << "You can't move off the board!" << endl;
	       return;
	    }
	    current_place[0] += 1;
	 }
      }

      //Allows player to capture a pokemon
      void throw_pokeball() {

	 //Decrement the number of pokeballs
	 num_pokeballs--;

	 //cout << "get_capture: " << new_event->get_capture() << endl;
	 if (grid[current_place[0]][current_place[1]].get_event() != NULL) {


	    //Check to see if there is a pokemon at the location
	    if (grid[current_place[0]][current_place[1]].get_event()->get_type() != 0) {

	       if (grid[current_place[0]][current_place[1]].get_event()->get_capture()) {
		  cout << "You captured a " <<  grid[current_place[0]][current_place[1]].get_event()->get_type_name() << endl;
		  //Put the pokemon in the next place in array 
		  pokemon_captured[num_pokemon_captured++] = grid[current_place[0]][current_place[1]].get_event();
		  grid[current_place[0]][current_place[1]].set_event(NULL);
	       }
	       else {
		  cout << "You didn't capture the pokemon!" << endl;
		  //If the grid size is > 3, the pokemon will fly away
		  if (grid_size > 3) {
		     run_away();
		  }
	       }

	    }
	    else
	       cout << "No pokemon:(" << endl;
	 }
	 else
	    cout << "No event at this location." << endl;
      }

      //New functions
      //New functions
      //New functions


      //x and y are the coordinates to check
      int check_event(int x, int y) {
	 event *this_event = grid[x][y].get_event();

	 if (this_event == NULL) {
	    return 1;
	 }

	 //Return 0 for pokemon
	 if (this_event->get_stones() == 0 && this_event->get_pokeballs() ==0) {
	    cout << "There's a pokemon nearby!" << endl;
	    return 0;
	 }

	 //Return 1 for cave
	 if (this_event->get_stones() > 0) {
	    cout << "There's a cave nearby!" << endl;
	    return 1;
	 }

	 //Return 2 for pokestop
	 if (this_event->get_pokeballs() > 0) {
	    cout << "There's a pokestop nearby!" << endl;
	    return 2;
	 }
      }

      void close_to_other_stuff() {
	 if (current_place[0] > 0) {
	    check_event(current_place[0]-1, current_place[1]);
	 }
	 if (current_place[0] < grid_size-1) {
	    check_event(current_place[0]+1, current_place[1]);
	 }
	 if (current_place[1] < grid_size-1) {
	    check_event(current_place[0], current_place[1]+1);
	 }
	 if (current_place[1] > 0) {
	    check_event(current_place[0], current_place[1]-1);
	 }
      }

      void run_away() {
	 cout << "The pokemon is flying away!";
	 while (true) {
	    int x = rand() % grid_size;
	    int y = rand() % grid_size;
	    if (grid[x][y].get_event() == NULL && (x != starting_place[0]  || y != starting_place[1])) {
	       grid[x][y].set_event(grid[current_place[0]][current_place[1]].get_event());
	       //Set the current grid to 0
	       grid[current_place[0]][current_place[1]].set_event(NULL);
	       break;
	    }
	 }


      }

      //Check to seee if the player has enough stones
      bool not_enough_stones() {
	 if (num_stones < 3)
	    return true;

	 cout << "You have enough stones." << endl;
	 return false;
      }


      //Check if theres an event at the current location
      bool is_there_an_event() {
	 if (grid[current_place[0]][current_place[1]].get_event() == NULL)
	    return false;

	 return true;
      }

      int check_event_type() {
	 event *this_event = grid[current_place[0]][current_place[1]].get_event();
	 if (this_event == NULL) {
	    cout << "No event here." << endl;
	    return 1;
	 }

	 //Return 0 for pokemon
	 if (this_event->get_stones() == 0 && this_event->get_pokeballs() ==0)
	    return 0;

	 //Return 1 for cave
	 if (this_event->get_stones() > 0) {
	    cout << "You found a cave and a megastone!" << endl;
	    num_stones += 1;
	    return 1;
	 }

	 //Return 2 for pokestop
	 if (this_event->get_pokeballs() > 0) {
	    cout << "You found " << this_event->get_pokeballs() << " pokeballs!" << endl;
	    num_pokeballs += this_event->get_pokeballs();
	    return 2;
	 }
      }

      //Returns the number of pokeballs
      //Don't need this anymore
      int get_the_pokeballs() {
	 //Returns the number of pokeballs
	 cout << "You got: " << grid[current_place[0]][current_place[1]].get_event()->get_pokeballs() << " pokeballs!" << endl;
	 //Add the number of pokeballs to pokeballs
	 num_pokeballs += grid[current_place[0]][current_place[1]].get_event()->get_pokeballs();
      }
      //Don't need above function

      //Print the grid and the current location of the player
      void print_the_grid() {

	 for (int i = grid_size-1; i >= 0; i--) {
	    for (int j = grid_size-1; j >= 0; j--) {
	       if (current_place[0] == i && current_place[1] == j)
		  cout << "X ";
	       else
		  cout << "Y ";
	    }
	    cout << endl;
	 }
      }

      int get_num_balls() {
	 return num_pokeballs;
      }


      void test_grid() {
	 cout << endl;
	 for (int i = grid_size-1; i >= 0; i--) {
	    for (int j = grid_size-1; j >= 0; j--) {
	       check_event_print(i, j);
	    }
	    cout << endl;
	 }

      }

      int check_event_print(int x, int y) {
	 event *this_event = grid[x][y].get_event();

	 if (this_event == NULL) {
	    cout << "N ";
	    return 1;
	 }

	 //Return 0 for pokemon
	 if (this_event->get_stones() == 0 && this_event->get_pokeballs() ==0) {
	    cout << "P "; 
	    return 0;
	 }

	 //Return 1 for cave
	 if (this_event->get_stones() > 0) {
	    cout << "C ";
	    return 1;
	 }

	 //Return 2 for pokestop
	 if (this_event->get_pokeballs() > 0) {
	    cout << "S";
	    return 2;
	 }
      }



      //End new functions
      //End new functions
      //End new functions
      //End new functions


      //Checks to see if the player is at the starting place
      bool not_at_starting_place() {
	 if (starting_place[0] == current_place[0])
	    if (starting_place[1] == current_place[1]) {
	       cout << "You are at the starting place" << endl;
	       return false;
	    }

	 return true;
      }

      //Checks to see if the player has captured all the pokemon and upgraded them
      bool not_all_pokemon_captured() {
	 for (int i = 0; i < 6; i++) {
	    if (pokemon_captured[i] == NULL) {
	       return true;
	    }
	 }
	 for (int i = 0; i < 6; i++) {

	 }
	 cout << "You have captured all the pokemon" << endl;
	 return false;
      }
};

#endif

