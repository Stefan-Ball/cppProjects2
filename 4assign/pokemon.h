#ifndef POKEMON_H
#define POKEMON_H
#include "event.h"
#include <time.h>
#include <string>
using namespace std;

class pokemon : public event {
   protected:
      //type?;
   public:
      //Maybe something
};

class flying : public pokemon {
   private:
      //Type or something
   public:
      //Something else
      flying() {
	 srand(time(NULL));
	 type = (rand() % 2) + 3;
      }

      flying(int type) {
	 this->type = type;
      }

      string get_type_name() {
	 if (type == 3) {
	    return "charizard";
	 }
	 if (type == 4) {
	    return "rayquaza";
	 }
	 else
	    return "Not found";
      }
      int get_type() {
	 return type;
      }
      bool get_capture() {
	 srand(time(NULL));
	 int chance = rand() % 2;
	 cout << "good" << endl;
	 if (chance ==1 )
	    return true;
	 else
	    return false;
      }
};


class rock : public pokemon {
   private:
   public:
      //Something else
      rock() {
	 srand(time(NULL));
	 type = (rand() % 2) + 1;
      }
      rock(int type) {
	 this->type = type;
      }
      string get_type_name() {
	 if (type == 1) {
	    return "geodude";
	 }
	 if (type == 2) {
	    return "onix";
	 }
	 else
	    return "not found";
      }
      int get_type() {
	 return type;
      }
      bool get_capture() {
	 cout << "good" << endl;
	 srand(time(NULL));
	 int chance = rand() % 4;
	 if (chance == 3)
	    return false;
	 else 
	    return true;
      }
};


class psychic : public pokemon {
   private:
      //Type or something
   public:
      //Something else
      psychic() {
	 srand(time(NULL));
	 type = (rand() % 2) + 5;
      }
      psychic(int type) {
	 this->type = type;
      }
      string get_type_name() {
	 if (type == 5) {
	    return "mewtwo";
	 }
	 if (type == 6) {
	    return "espeon";
	 }
	 else
	    return "Not found";
      }
      int get_type() {
	 return type;
      }

      bool get_capture() {
	 cout << "good" << endl;
	 srand(time(NULL));
	 int chance = rand() % 4;
	 if (chance == 0)
	    return true;
	 else
	    return false;
      }

};

#endif
