#include <iostream>
#include <climits>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
using namespace std;

int find_grid_size(int argc, char *argv[]) {

   bool valid_command_line_arg = true;
   int grid_size;

   if (argc > 1) {
      for (int i = 0; i < strlen(argv[1]); i++) {
	 if (argv[1][i] < '0' || argv[1][i] > '9')
	    valid_command_line_arg = false;
      }
      if ( valid_command_line_arg = true) {
	 grid_size = atoi(argv[1]);
	 if (grid_size >= 3)
	    return grid_size; 
      }
   }

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "What would you like the grid size to be?";
      cin >> grid_size;
   } while (cin.fail() || grid_size < 3);

   return grid_size;

}

int ask_question(int &answer, int low_bound, int high_bound, string prompt) {

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << prompt;
      cin >> answer;
   } while (cin.fail() || answer < low_bound || answer > high_bound);

}
