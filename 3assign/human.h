#include "creature.h"
using namespace std;
#ifndef HUMAN_H
#define HUMAN_H

class human : public creature {
   private:
      static const string species;
   public:
      //Don't know lol maybe constructor
      int get_damage();
      human(); 
};



#endif
