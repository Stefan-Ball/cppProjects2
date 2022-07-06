#ifndef EVENT_H
#define EVENT_H
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;


class event {
   protected:
      int num_stones;
      int num_pokeballs;
      int type;
      int level;
   public:
      //Getters
      event() {
	 num_stones = 0;
	 num_pokeballs = 0;
	 type = 0;
	 level = 0;
      }
      virtual int get_level() {
	 return -1;
      }
      virtual int get_stones(){
	 return false;
      }
      virtual int get_type(){
	 return type;
      }
      virtual string get_type_name() {
	 return "No name found";
      }
      virtual int get_pokeballs() {
	 return 0;
      }
      virtual bool get_capture() {
	 cout << "BAD" << endl;
	 return false;
      }
};

class cave : public event {
   private:
   public:
      cave() {
	 srand(time(NULL));
	 num_stones = (rand() % 7) + 3;
      }
      int get_stones() {
	 return num_stones;
      }
};

class pokestop : public event {
   private:
   public:
      pokestop() {
	 srand(time(NULL));
	 num_pokeballs = (rand() %7)+3;
      }
      int get_pokeballs() {
	 return num_pokeballs;
      }
}
;
#endif
