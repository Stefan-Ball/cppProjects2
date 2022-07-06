#include <string.h>
#include <stdio.h>
#include "world.h"
#include <climits>

world::world() {
   humans = NULL;
   elves = NULL;
   cyberdemons = NULL;
   balrogs = NULL;
}

world::world(int num_humans, int num_elves, int num_cyberdemons, int num_balrogs) {
   humans = new human[num_humans];
   elves = new elf[num_elves];
   cyberdemons = new cyberdemon[num_cyberdemons];
   balrogs = new balrog[num_balrogs];
}

world::~world() {

   delete [] humans;
   delete [] elves;
   delete [] balrogs;
   delete [] cyberdemons;
}

int world::get_money() {
   return user_money;
}

void world::operator=(const world &new_world) {

   if (humans != NULL) {
      delete [] humans;
      humans = NULL;
   }

   if (elves != NULL) {
      delete [] elves;
      elves = NULL;
   }

   if (cyberdemons != NULL) {
      delete [] cyberdemons;
      cyberdemons = NULL;
   }

   if (balrogs != NULL) {
      delete [] balrogs;
      balrogs = NULL;
   }

   humans = new human[new_world.num_humans];
   for (int i = 0; i < num_humans; i++) {
      humans[i] = new_world.humans[i];
   }

   elves = new elf[new_world.num_elves];
   for (int i = 0; i < num_elves; i++) {
      elves[i] = new_world.elves[i];
   }

   cyberdemons = new cyberdemon[new_world.num_cyberdemons];
   for (int i = 0; i < num_cyberdemons; i++) {
      cyberdemons[i] = new_world.cyberdemons[i];
   }

   balrogs = new balrog[new_world.num_balrogs];
   for (int i = 0; i < num_balrogs; i++) {
      balrogs[i] = new_world.balrogs[i];
   }

}

world::world(const world &new_world) {

   humans = new human[new_world.num_humans];
   for (int i = 0; i < num_humans; i++) {
      humans[i] = new_world.humans[i];
   }

   elves = new elf[new_world.num_elves];
   for (int i = 0; i < num_elves; i++) {
      elves[i] = new_world.elves[i];
   }

   cyberdemons = new cyberdemon[new_world.num_cyberdemons];
   for (int i = 0; i < num_cyberdemons; i++) {
      cyberdemons[i] = new_world.cyberdemons[i];
   }

   balrogs = new balrog[new_world.num_balrogs];
   for (int i = 0; i < num_balrogs; i++) {
      balrogs[i] = new_world.balrogs[i];
   }

}

void world::delete_balrog(int balrog_to_delete) {

   cout << "deleting balrog! " << endl;
   //Create temp array
   cout << num_balrogs << endl;
   balrog *temp = new balrog[4];

   for (int i = 0; i < num_balrogs-1; i++) {
      if ( i != balrog_to_delete ) {
	 temp[i] = balrogs[i];
      }
   }

   //Delete the balrogs
   delete [] balrogs;
   balrogs = NULL;

   //Decrement number balrogs by 1
   num_balrogs--;

   //Copy back to balrogs
   balrogs = new balrog[num_balrogs];

   for (int i = 0; i < num_balrogs; i++) {
      balrogs[i] = temp[i];
   }

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

void world::add_balrog() {

   //Create temp array
   balrog *temp = new balrog[num_balrogs + 1];

   for (int i = 0; i < num_balrogs; i++) {
	 temp[i] = balrogs[i];
   }

   //Delete the balrogs
   delete [] balrogs;
   balrogs = NULL;

   //Copy back to balrogs
   balrogs = new balrog[num_balrogs];

   for (int i = 0; i < num_balrogs; i++) {
      balrogs[i] = temp[i];
   }

   //Increment number balrogs by 1
   num_balrogs++;

   //Delete temp array
   delete [] temp;
   temp = NULL;
}


//Human functions
void world::delete_human(int human_to_delete) {

   //Create temp array
   cout << num_humans << endl;
   human *temp = new human[4];

   for (int i = 0; i < num_humans; i++) {
      if ( i != human_to_delete ) {
	 temp[i] = humans[i];
      }
   }

   //Delete the humans 
   delete [] humans;
   humans = NULL;

   //Decrement number humans by 1
   num_humans--;

   //Copy back to humans 
   humans = new human[4];

   for (int i = 0; i < num_humans; i++) {
      humans[i] = temp[i];
   }

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

void world::add_human() {

   int number = num_humans;

   //Create temp array
   cout << "num_humans " << num_humans << endl;
   human *temp = new human[number + 1];

   for (int i = 0; i < number; i++) {
	 temp[i] = humans[i];
   }

   //Delete the humans 
   delete [] humans;
   humans = NULL;

   //Copy back to humans
   humans = new human[number + 1];

   for (int i = 0; i < number; i++) {
      humans[i] = temp[i];
   }

   //Increment number humans by 1
   num_humans++;

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

//Elf functions
void world::delete_elf(int elf_to_delete) {

   //Create temp array
   cout << num_elves << endl;
   elf *temp = new elf[4];

   for (int i = 0; i < num_elves-1; i++) {
      if ( i != elf_to_delete ) {
	 temp[i] = elves[i];
      }
   }

   //Delete the elves 
   delete [] elves;
   elves = NULL;

   //Decrement number elves by 1
   num_elves--;

   //Copy back to elves 
   elves = new elf[4];

   for (int i = 0; i < num_elves; i++) {
      elves[i] = temp[i];
   }

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

void world::add_elf() {

   //Create temp array
   elf *temp = new elf[num_elves + 1];

   for (int i = 0; i < num_elves+1; i++) {
	 temp[i] = elves[i];
   }

   //Delete the elves 
   delete [] elves;
   elves = NULL;

   //Copy back to elves 
   elves = new elf[num_elves];

   for (int i = 0; i < num_elves+1; i++) {
      elves[i] = temp[i];
   }

   //Increment number elves by 1
   num_elves++;

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

//Cyberdemon functions
void world::delete_cyberdemon(int cyberdemon_to_delete) {

   //Create temp array
   cyberdemon *temp = new cyberdemon[4];

   for (int i = 0; i < num_cyberdemons-1; i++) {
      if ( i != 0 ) {
	 temp[i] = cyberdemons[i];
      }
   }

   //Delete the cyberdemons 
   delete [] cyberdemons;
   cyberdemons = NULL;

   //Decrement number cyberdemons by 1
   num_cyberdemons--;

   //Copy back to cyberdemons 
   cyberdemons = new cyberdemon[4];

   for (int i = 0; i < num_cyberdemons; i++) {
      cyberdemons[i] = temp[i];
   }

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

void world::add_cyberdemon() {

   //Create temp array
   cyberdemon *temp = new cyberdemon[num_cyberdemons + 1];

   for (int i = 0; i < num_cyberdemons; i++) {
	 temp[i] = cyberdemons[i];
   }

   //Delete the cyberdemons 
   delete [] cyberdemons;
   cyberdemons = NULL;

   //Copy back to cyberdemons 
   cyberdemons = new cyberdemon[num_cyberdemons];

   for (int i = 0; i < num_cyberdemons; i++) {
      cyberdemons[i] = temp[i];
   }

   //Increment number cyberdemons by 1
   num_cyberdemons++;

   //Delete temp array
   delete [] temp;
   temp = NULL;
}

void world::begin() {

   int answer;

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "Would you like to play on easy (1), medium (2), or hard mode (3)?";
      cin >> answer;
   } while (cin.fail() || answer > 3 || answer < 1);

   if (answer == 1) {
      user_money = 1000;
      num_humans = 3;
      num_elves = 3;
      num_cyberdemons = 2;
      num_balrogs = 2;
   }

   if (answer == 2) {
      user_money = 500;
      num_humans = 3;
      num_elves = 3;
      num_cyberdemons = 3;
      num_balrogs = 3;
   }

   if (answer == 3) {
      user_money = 250;
      num_humans = 2;
      num_elves = 2;
      num_cyberdemons = 3;
      num_balrogs = 3;
   }
}

void world::begin_2() {

   humans = new human[num_humans];
   elves = new elf[num_elves];
   balrogs = new balrog[num_balrogs];
   cyberdemons = new cyberdemon[num_cyberdemons];

   cout << "The humans and elves have paired up to defeat the cyberdemons and balrogs! Help them defeat the forces of evil.";
}

bool world::good_vs_bad() {

   cin.ignore(INT_MAX, '\n');
   while (true) {
      //If good loses, return false
      if ( (num_elves + num_humans) <= 0 )
	 return false;
      if ( (num_balrogs + num_cyberdemons) <= 0)
	 return true;

      //Ask if want to purchase any creatures

      cout << "Battle one random good creature vs one random evil creature!";
      cin.ignore(INT_MAX, '\n');
      good_vs_bad_battle();
   }
}

/*

void world::good_vs_bad_battle() {

   //Which demon creature to battle. 1 - cyberdemon. 0 - balrog
   int which_bad;

   int cyberdemon_to_battle = -1;
   int balrog_to_battle = -1;

   creature *evil_battler;
   creature *good_battler;


   //Determine to battle cyberdemon or balrog
   if (num_cyberdemons != 0 && num_balrogs != 0) {
      //If there are no cyberdemons, battle a balrog
      if (num_cyberdemons == 0)
	 which_bad = 0;
      //If there are no balrogs, battle a cyberdemon
      else if (num_balrogs == 0)
	 which_bad = 1;
      //If there are both, battle a random one
      else if (num_cyberdemons > 0 && num_balrogs > 0)
	 which_bad = (rand() % 2);
      //If there are none, return
      else
	 return;
   }
   else
      return;

   if (which_bad == 0 && num_cyberdemons != 0)
      cyberdemon_to_battle = rand() % num_cyberdemons;
   else if (which_bad == 1 && num_balrogs != 0)
      balrog_to_battle = rand() % num_balrogs;

   if (balrog_to_battle == -1)
      evil_battler = &cyberdemons[cyberdemon_to_battle];
   else if (cyberdemon_to_battle == -1)
      evil_battler = &balrogs[balrog_to_battle];

   cout << "b: " << balrog_to_battle << endl;
   cout << "c: " << cyberdemon_to_battle << endl;


   //Which good creature to battle. O - human. 1 - elf 
   int which_good;


   int human_to_battle = -1;
   int elf_to_battle = -1;


   //Determine to battle elf or human
   if (num_humans != 0 && num_elves != 0) {
      //If there are no humans, battle an elf 
      if (num_humans == 0)
	 which_good = 1;
      //If there are no elves, battle a human 
      else if (num_elves == 0)
	 which_good = 0;
      //If there are both, battle a random one
      else if (num_elves > 0 && num_humans > 0)
	 which_good = rand() % 2;
      //if there are none, return
      else if (num_humans == 0 && num_elves == 0) {
	 cout << "No more humans or elves left!" << endl;
	 return;
      }
   }
   else
      return;

void world::ask_if_purchase_creature() {

   int answer;

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
   cout << "Would you like to purchase an elf (1), human (2), or neither (3) ";
   cin >> answer;
   } while (cin.fail() || answer < 1 || answer > 3);

   if (answer == 3)
      return;

   if (answer == 2)
      add_human();

   if (answer == 1)
      add_elf();
}


   if (which_good == 0 && num_humans != 0)
      human_to_battle = rand() % num_humans;
   else if (which_good == 1 && num_elves != 0)
      elf_to_battle = rand() % num_elves;

   if (elf_to_battle == -1)
      good_battler = &humans[human_to_battle];
   else if (human_to_battle == -1)
      good_battler = &elves[elf_to_battle];


   cout << evil_battler->get_name() << endl;
   battle_creature(evil_battler, good_battler);
   if (!strcmp(evil_battler->get_name().c_str(), "balrog"))
      delete_balrog(balrog_to_battle);
   //Battle good vs evil

   int random = rand() % 2;
   if (random == 0) {
      bool who_won = battle_creature(evil_battler, good_battler);
      if (who_won == true) {
	 if (balrog_to_battle = -1)
	    delete_cyberdemon(cyberdemon_to_battle);
	 else
	    delete_balrog(balrog_to_battle);
      }
      else {
	 if (human_to_battle = -1)
	    delete_elf(elf_to_battle);
	 else
	    delete_human(human_to_battle);
      }

   }
   else if (random == 1) {
      battle_creature(good_battler, evil_battler);
      bool who_won = battle_creature(evil_battler, good_battler);
      if (who_won == true) {
	 if (balrog_to_battle = -1)
	    delete_cyberdemon(cyberdemon_to_battle);
	 else
	    delete_balrog(balrog_to_battle);
   }
   else {
      if (human_to_battle = -1)
	 delete_elf(elf_to_battle);
      else
	 delete_human(human_to_battle);
   }



}
*/
void world::good_vs_bad_battle() {

   //Which demon creature to battle. 1 - cyberdemon. 0 - balrog
   int which_bad;

   int cyberdemon_to_battle = -1;
   int balrog_to_battle = -1;

   creature *evil_battler;
   creature *good_battler;


   if (num_cyberdemons = 0){
      balrog_to_battle = 0;
      which_bad = 0;
   }
   else {
      cyberdemon_to_battle = 0;
      which_bad = 1;
   }

   if (balrog_to_battle == -1)
      evil_battler = &cyberdemons[cyberdemon_to_battle];
   else if (cyberdemon_to_battle == -1)
      evil_battler = &balrogs[balrog_to_battle];

   if (num_humans == 0)
      good_battler = &humans[0];
   else 
      good_battler = &elves[0];


   cout << evil_battler->get_name() << endl;
   bool who_won = battle_creature(evil_battler, good_battler);

   if (who_won) {
      if (!strcmp(evil_battler->get_name().c_str(), "balrog")) {
	 cout << "balrog is gone!" << endl;
	 delete_balrog(0);
      }
      if (!strcmp(evil_battler->get_name().c_str(), "cyberdemon")) {
	 cout << "cyberdemon is gone!" << endl;
	 delete_cyberdemon(0);
      }
   }
   else {
      if (!strcmp(good_battler->get_name().c_str(), "human"))
	 delete_human(0);
      if (!strcmp(good_battler->get_name().c_str(), "elf")) {
	 delete_elf(0);
      }
   }




}


bool world::battle_creature(creature *creature_1, creature *creature_2) {

   while (true) {
      if (creature_1->get_hitpoints() <= 0) {
	 user_money += creature_2->get_payoff();
	 cout << "You gained " << creature_2->get_payoff() << " dollars!" << endl;
	 cout << creature_2->get_name() << " won!" << endl;
	 return true;
      }

      if (creature_2->get_hitpoints() <= 0) {
	 user_money += creature_1->get_payoff();
	 cout << "You lost " << creature_1->get_payoff() << " dollars!" << endl;
	 cout << creature_1->get_name() << " won!" << endl;
	 return false;
      }

      creature_1->decrease_hitpoints(creature_2->get_damage());
      creature_2->decrease_hitpoints(creature_2->get_damage());
   }


}
