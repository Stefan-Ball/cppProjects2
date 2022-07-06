#include <iostream>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
ifstream input;
#include "states.h"

void run_program(int argc, char *argv[]) {

   //Create struct to hold filename and number of states
   arguments args;

   //Check to make sure valid file and int in command line args
   valid_file_and_int(argv, argc, args);

   //Create the number of states
   state *state_data = create_states(args.num_states);

   //Get all the data from the file
   read_in_data(state_data, args);


   //Start reading in data

   //Open the filestream output
   ofstream output;

   //Open the file
   output.open("filename");

   //Print the stuff we're supposed to
   print_stuff(state_data, args.num_states, output); 

   cout << state_data[0].c[0].name << endl;

   //delete_info(state_data, args.num_states);

}

void read_in_data(state *state_data, arguments args) {

   //Name input stream
   ifstream input;

   //Open the input file
   input.open(args.filename.c_str());

   //Get state_data information from file
   for (int i = 0; i < args.num_states; i++) {

      //Get the state data for state # that I'm on (i)
      get_state_data(state_data, input, i);

      for (int k = 0; k < state_data[i].counties; k++) {

	 //Create county for state
	 state_data[i].c = create_counties(state_data[i].counties);

	 //Get the data for the counties
	 get_county_data(state_data[i].c, k, input);

	 get_city_data(state_data[i].c, k, state_data[i].c[k].cities, input);

	 cout << "Dog" << endl;
	 cout << state_data[i].c[k].city[0] << endl;

      }

   }

   cout << "Cat" << endl;
   cout << state_data[0].c[0].city[0] << endl;

   //return state_data;

}


void get_state_data(state *state_data, ifstream &input, int state_num) {

   //Get state name
   input >> state_data[state_num].name;

   //Get state population
   input >> state_data[state_num].population;

   //Get num of counties in state
   input >> state_data[state_num].counties;

}

void get_county_data(county *county_data, int county_num, ifstream &input) {

      //Get the name of the county in the state
      input >> county_data[county_num].name;

      cout << "Print county name" << endl;
      cout << county_data[county_num].name << endl;

      //Get the population of the county
      input >> county_data[county_num].population;

      //Get the average income of the county
      input >> county_data[county_num].avg_income;

      //Get the average household price for the county
      input >> county_data[county_num].avg_house;

      //Get the number of cities in the county
      input >> county_data[county_num].cities;

      cout << "Print number of cities in county" << endl;
      cout << county_data[county_num].cities << endl;

      //get_city_data(county_data, county_num, county_data[county_num].cities, input);
}

void get_city_data(county *&county_data, int county_num, int num_cities, ifstream &input) {

   //Create string array for number of cities in the county
   county_data[county_num].city = new string[county_data[county_num].cities];

   //Get the names of all the cities in the county
   for (int k = 0; k < num_cities; k++) {

      input >> county_data[county_num].city[k];

      cout << "Print city name" << endl;
      cout << county_data[county_num].city[k] << endl;
   }


}


































void print_stuff(state *state_data, int num_states, ofstream &output) {

   ;


}




void delete_info(state *state_data, int num_states) {

   //For the number of counties
   for (int j = 0; j < num_states; j++) {

      cout << "Not segfaulting" << endl;
      //For the number of cities
      for (int k = 0; k < state_data[j].counties; k++) {

	 cout << "Not segfaulting" << endl;
	 delete [] state_data[j].c[k].city;
	 cout << "Not segfaulting again" << endl;
      }
   }

   for (int j = 0; j < num_states; j++) {

      delete [] state_data[j].c;
   }


   //For the number of states
   //for (int i = 0; i < num_states; i++) {

   delete [] state_data;

   //}

}








state *create_states(int num_states) {

   state *state_data = new state[num_states];

   return state_data;
}

county *create_counties(int num_counties) {

   county *county_data = new county[num_counties];

   return county_data;
}




void valid_file_and_int(char *argv[], int argc, arguments &args) {

   //If the second arg is an int flag
   int state_arg;
   if (!strcmp(argv[1], "-s")) 
      state_arg = 2;
   else
      state_arg = 4;

   //Check the third arg for valid int
   bool valid_number;
   valid_number = true;
   for (int i = 0; i < strlen(argv[state_arg]); i++) {
      if (argv[state_arg][i] < '0' or argv[state_arg][i] > '9')
	 valid_number = false;
   } 

   //If the command line arg is not a positive integer
   if (!valid_number) {
      do {
	 cin.clear();
	 cout << "Enter valid number of states (postive int): ";
	 cin >> args.num_states;
	 cin.ignore(INT_MAX, '\n');
      } while (cin.fail() or args.num_states < 0);
   }
   //If the command line is a positive integer
   else
      args.num_states = atoi(argv[state_arg]);

   //If the third arg is a string flag
   int filename_arg;
   if (!strcmp(argv[3], "-f"))
      filename_arg = 4;
   else
      filename_arg = 2;

   //Check for a valid file
   input.open(argv[filename_arg]); 
   if (input.fail()) {
      do {
	 cout << "Please enter a valid file: ";
	 cin >> args.filename;
	 cin.ignore(INT_MAX, '\n');
	 input.open(args.filename.c_str());
      } while (input.fail());
   }
   else
      args.filename = argv[filename_arg];

   //Close the file
   input.close();

}

bool is_valid_arguments(char *argv[], int argc) {


   //If there are not the correct amount of arguments, return false
   if (argc != 5)
      return false;

   //If the args are not in the correct order, return false
   if (!strcmp(argv[1], "-f")) {
      if (strcmp(argv[3], "-s")) {
	 return false;
      }
   }
   else if (!strcmp(argv[1], "-s")) {
      if (strcmp(argv[3], "-f")) {
	 return false;
      }
   }
   else if (!strcmp(argv[1], "-s") or !strcmp(argv[1], "-f")) {
      return false;
   }

   //If nothing is false, there are valid arguments
   return true;
}
