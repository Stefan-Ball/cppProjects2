#include <iostream>
#include "world.h"
using namespace std;

void run_game() {

   world game;

   game.begin();

   game.begin_2();

   bool good_wins = game.good_vs_bad();

   if (good_wins) {
      cout << "good wins!" << endl;
      cout << "You have " << game.get_money() << " dollars in the bank!" << endl;
   }
   else {
      cout << "bad wins!" << endl;
      cout << "You have " << game.get_money() << " dollars in the bank!" << endl;
   }

}
