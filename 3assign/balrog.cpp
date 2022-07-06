#include "balrog.h"

//Set species to const
const string balrog::species = "Balrog";

//Initial values
balrog::balrog() {
   strength = 20;
   hitpoints = 5;
   payoff = -50;
   cost = -50;
   name = "balrog";
}

int balrog::get_damage() {
   int damage;

   damage = (rand() % strength) + 1;

   cout << species << " attacks for " << damage << " points!" << endl;

   int damage2 = ( rand() % strength) + 1;

   cout << "Balrog speed attack inflicts " << damage2
        << " additional damage points!" << endl;

   damage = damage + damage2;

   return damage;

}
