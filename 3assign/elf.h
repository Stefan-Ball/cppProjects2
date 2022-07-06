#include "creature.h"
using namespace std;
#ifndef ELF_H
#define ELF_H

class elf : public creature {
   private:
      static const string species;
   public:
      elf();
      int get_damage();
};













#endif
