using namespace std;
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#ifndef CREATURE_H
#define CREATURE_H

class creature {
   protected:
      int hitpoints; //Damage can sustain
      int strength; //Damage to inflict
      string name; //Name of creature
      double payoff; //Money won for creature
      double cost; //Money it takes to purchase creature
   public:
      //Constructor, not much to do with this
      creature();

      //Hitpoint functions
      void set_hitpoints(int);
      void decrease_hitpoints(int);
      int get_hitpoints();

      //Strength functions
      void set_strength(int);
      int get_strength();

      //Name functions
      void set_name(string);
      string get_name();

      //Payoff functions
      void set_payoff(double);
      double get_payoff();

      //Cost functions
      void set_cost(double cost);
      double get_cost();

      //Function that returns the damage for creature depending on variables
      virtual int get_damage();
};

#endif
