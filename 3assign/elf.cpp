#include "elf.h"

const string elf::species = "Elf";

int elf::get_damage() {
   int damage;

   damage = (rand() % strength) + 1;

   cout << species << " attacks for " << damage << " points!" << endl;

   if ( (rand() % 10) == 0) {
      cout << "Magical attack inflicts " << damage 
	   << " additional damage points! " << endl;

      damage += damage;
   }

   return damage;
}

elf::elf() {
   strength = 15;
   hitpoints = 10;
   payoff = 100;
   cost = 50;
   name = "elf";
}
