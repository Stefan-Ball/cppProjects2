#include "creature.h"
#include <iostream>
//#include <time.h>
//#include <cstdlib>
//#include <cstdio>

using namespace std;

//Get_damage
int creature::get_damage() {
   int damage;

   damage = (rand() % strength) + 1;
}

//Hitpoint functions
void creature::set_hitpoints(int hitpoints) {
   this->hitpoints = hitpoints;
}

void creature::decrease_hitpoints(int reduction) {
   hitpoints -= reduction;
}

int creature::get_hitpoints() {
   return hitpoints;
}


//Strength functions
void creature::set_strength(int new_strength) {
   strength = new_strength;
} 

int creature::get_strength() {
   return strength;
}

//Name functions
void creature::set_name(string name) {
   this->name = name;
}

string creature::get_name() {
   return name;
}

//Payoff functions
void creature::set_payoff(double payoff) {
   this->payoff = payoff;
}

double creature::get_payoff() {
   return payoff;
}

//Cost functions
void creature::set_cost(double cost) {
   this->cost = cost;
}

double creature::get_cost() {
   return cost;
}

creature::creature() {

   ;
}
