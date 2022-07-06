#include "cyberdemon.h"

//Constant species name
const string cyberdemon::species = "Cyberdemon";

//Constructor
cyberdemon::cyberdemon() {
   strength = 15;
   hitpoints = 15;
   payoff = -25;
   cost = -25;
   name = "cyberdemon";
};

//Get_damage function
int cyberdemon::get_damage() {
   int damage;

   damage = (rand() % strength) + 1;

   cout << species << " attacks for " << damage << " points!" << endl;

   return damage;
}
