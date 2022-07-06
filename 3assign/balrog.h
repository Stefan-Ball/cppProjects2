#include "creature.h"
using namespace std;
#ifndef BALROG_H
#define BALROG_H

class balrog : public creature {
   private:
      static const string species;
   public:
      balrog();
      int get_damage();
};


















#endif
