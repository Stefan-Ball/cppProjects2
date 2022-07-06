#include "creature.h"
using namespace std;
#ifndef CYBERDEMON_H
#define CYBERDEMON_H

class cyberdemon : public creature {
   private:
      static const string species;
   public:
      cyberdemon();
      int get_damage();
};















#endif
