#ifndef LOCATION_H
#define LOCATION_H
#include "event.h"
#include "pokemon.h"

class location {
   private:
      event *whats_here;
   public:
      /*
      location(event *whats_here) {
        this->whats_here = whats_here;
      }
      */

      location() {
	 whats_here = NULL;
      }

      ~location() {
	 //delete [] whats_here;
	 whats_here = NULL;
      }


      void operator=(location new_location) {
	 /*
	 if (whats_here != NULL)
	    delete [] event;
	    */

	 whats_here = new_location.whats_here;
      }

      location(const location &new_location) {

	 whats_here = new_location.whats_here;
      }

      //Gets the event if there is one
      event* get_event() {
	 return whats_here;
      }
      

      void delete_event() {
	 whats_here = NULL;
      }

      //Sets the event
      void set_event(event *new_event) {
	 //if (whats_here != NULL)
	    //delete [] whats_here;

	 whats_here = new_event;
      }

      void set_event(flying poke) {
	 whats_here = &poke;
      }
      void set_event(rock poke) {
	 whats_here = &poke;
      }
      void set_event(psychic poke) {
	 whats_here = &poke;
      }
};

#endif
