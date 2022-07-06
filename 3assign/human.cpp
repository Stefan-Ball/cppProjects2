#include "human.h"

const string human::species = "Human";

int human::get_damage() {
   int damage;

   damage = (rand() % strength) + 1;

   cout << species << " attacks for " << damage << " points!" << endl;

   return damage;
}

human::human() {
   strength = 10;
   hitpoints = 10;
   payoff = 100;
   cost = 50;
   name = "human";
}
