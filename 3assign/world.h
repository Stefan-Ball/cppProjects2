#include "human.h"
#include "cyberdemon.h"
#include "elf.h"
#include "balrog.h"
using namespace std;
#ifndef WORLD_H
#define WORLD_H
class world {
   private:
      int user_money;
      human *humans;
      elf *elves;
      cyberdemon *cyberdemons;
      balrog *balrogs;
      int num_humans;
      int num_elves;
      int num_cyberdemons;
      int num_balrogs;
   public:
      world();
      world(int, int, int, int);
      //The big three
      ~world();
      void operator=(const world &);
      world(const world &);

      //Balrog function
      void delete_balrog(int);
      void add_balrog();

      //Human function
      void delete_human(int);
      void add_human();

      //Elf function
      void delete_elf(int);
      void add_elf();

      //Cyberdemon function
      void delete_cyberdemon(int);
      void add_cyberdemon();

      void begin();
      void begin_2();

      bool good_vs_bad();
      void good_vs_bad_battle();

      bool battle_creature(creature *, creature *);

      int get_money();
};

#endif
