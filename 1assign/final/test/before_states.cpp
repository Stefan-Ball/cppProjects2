#include <iostream>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
//Open the filestream input
ifstream input;
//Open the filestream output
ofstream output;
#include "states.h"

/********************************************
 * Function: play_again
 * Description: Asks the user if they want to run another file through
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Conditions: none
 * Return: none
********************************************/
void play_again() {

   int answer;

   do {

      do {
	 if (cin.fail()) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	 }
	 cout << "Would you like to get input from another file? Input 0 for no and 1 for yes. ";
	 cin >> answer;
	 cin.ignore(INT_MAX, '\n');

      } while (cin.fail() || (answer != 0 && answer != 1));

      if (answer == 1) {

	 program();
      }

   } while (answer == 1);

}

/********************************************
 * Function: run_program
 * Description: Runs the first run through
 * Parameters: args
 * Pre-Conditions: arguments
 * Post-Conditions: none
 * Return: none
********************************************/
void run_program(arguments args) {

   int print_to_file;
   string output_file;

   //Create the number of states
   state *state_data = create_states(args.num_states);

   //Get all the data from the file
   read_in_data(state_data, args);

   //Ask user if they want to print to screen or file
   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "Would you like to print the information to the screen or to a file? Press 0 for screen and 1 for file ";
      cin >> print_to_file;
      cin.ignore(INT_MAX, '\n');

   } while (cin.fail() || (print_to_file != 0 && print_to_file != 1));

   //Ask user for file they want to print to if they want to print to a file
   if (print_to_file) {

      //Open the file
      do {
	 if (cin.fail()) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	 }
	 cout << "What file would you like to print to? ";
	 cin >> output_file;
	 cin.ignore(INT_MAX, '\n');
      } while(cin.fail() || !strcmp(output_file.c_str(), args.filename.c_str()));

      output.open(output_file.c_str());
   }


   //Print the stuff we're supposed to
   print_stuff(state_data, args.num_states, output, print_to_file); 

   delete_info(&state_data, args.num_states);

   input.close();
   output.close();
}

/********************************************
 * Function: program
 * Description: Runs the program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
********************************************/
void program() {

   arguments args;
   string output_file;

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "What file would you like to get input from? ";
      cin >> args.filename;
      cin.ignore(INT_MAX, '\n');

   } while(cin.fail());

   input.open(args.filename.c_str()); 
   if (input.fail()) {
      do {
	 cout << "Please enter a valid file: ";
	 cin >> args.filename;
	 cin.ignore(INT_MAX, '\n');
	 input.open(args.filename.c_str());
      } while (input.fail());
   } 

   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "How many states are ther in the file? ";
      cin >> args.num_states;
      cin.ignore(INT_MAX, '\n');

   } while(cin.fail() || args.num_states < 1 || args.num_states > INT_MAX);


   run_program(args);
}

/********************************************
 * Function: read_in_data
 * Description: Reads in all the data from a file
 * Parameters: state_data, args
 * Pre-Conditions: state*, arguments
 * Post-Conditions: state_data is initialized
 * Return: none
********************************************/
void read_in_data(state *state_data, arguments args) {

   //Name input stream
   ifstream input;

   //Open the input file
   input.open(args.filename.c_str());

   //Get state_data information from file
   for (int i = 0; i < args.num_states; i++) {

      //Get the state data for state # that I'm on (i)
      get_state_data(state_data, input, i);

      //Create county for state
      state_data[i].c = create_counties(state_data[i].counties);

      for (int k = 0; k < state_data[i].counties; k++) {

	 //Get the data for the counties
	 get_county_data(state_data[i].c, k, input);

	 //Create string array for number of cities in the county
	 state_data[i].c[k].city = new string[state_data[i].c[k].cities];

	 get_city_data(state_data[i].c, k, state_data[i].c[k].cities, input);

      }

   }

}


/********************************************
 * Function: get_state_data
 * Description: Gets the data for a state
 * Parameters: state_data, input, state_num
 * Pre-Conditions: state*, ifstream&, int
 * Post-Conditions: state_data is initialized for a state
 * Return: none
********************************************/
void get_state_data(state *state_data, ifstream &input, int state_num) {

   //Get state name
   input >> state_data[state_num].name;

   //Get state population
   input >> state_data[state_num].population;

   //Get num of counties in state
   input >> state_data[state_num].counties;

}

/********************************************
 * Function: get_county_data
 * Description: Gets the data for a county in a state
 * Parameters: county_data, conty_num, input
 * Pre-Conditions: county*, int, ifstream &
 * Post-Conditions: county_data for a state is initialized
 * Return: none
********************************************/
void get_county_data(county *county_data, int county_num, ifstream &input) {

   //Get the name of the county in the state
   input >> county_data[county_num].name;

   //Get the population of the county
   input >> county_data[county_num].population;

   //Get the average income of the county
   input >> county_data[county_num].avg_income;

   //Get the average household price for the county
   input >> county_data[county_num].avg_house;

   //Get the number of cities in the county
   input >> county_data[county_num].cities;

}

/********************************************
 * Function: get_city_data
 * Description: gets the data for a city
 * Parameters: county_data, county_num, num_cities, input
 * Pre-Conditions: county*&, int, ifstream &
 * Post-Conditions: county_data is initialized
 * Return: none
********************************************/
void get_city_data(county *&county_data, int county_num, int num_cities, ifstream &input) {

   //Get the names of all the cities in the county
   for (int k = 0; k < num_cities; k++) {

      input >> county_data[county_num].city[k];
   }


}







/********************************************
 * Function: income_limit
 * Description: Prints the counties above a certain income limit
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int, ofstream &
 * Post-Conditions: none
 * Return: none
********************************************/
void income_limit(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int income_limit;


   do {
      if (cin.fail()) {
	 cin.clear();
	 cin.ignore(INT_MAX, '\n');
      }
      cout << "What would you like the minimum income limit to be?";
      cin >> income_limit;
      cin.ignore(INT_MAX, '\n');
   } while (cin.fail() || income_limit < 0);

   for (int k = 0; k < num_states; k++) {

      for (int i = 0; i < state_data[k].counties; i++) {

	 if (state_data[k].c[i].avg_income >= income_limit) {

	    if (print_to_file) {
	       output << state_data[k].c[i].name << ": " << state_data[k].c[i].avg_income << endl;
	    }
	    else {
	       cout << state_data[k].c[i].name << ": " << state_data[k].c[i].avg_income << endl;
	    }
	 }

      }
   }

}

/********************************************
 * Function: average_household
 * Description: Prints the average household income for a state
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int , ofstream &
 * Post-Conditions: none
 * Return: none
********************************************/
void average_household(state *state_data, int num_states, ofstream &output, int print_to_file) {

   float sum, avg;

   for (int i = 0; i < num_states; i++) {

      sum = 0;
      avg = 0;

      for (int k = 0; k < state_data[i].counties; k++) {

	 //Make the sum equal to all the data for the county
	 sum += state_data[i].c[k].avg_income;

      }
      //The average is the sum divided by number of counties in the state
      avg = sum / state_data[i].counties;

      if (print_to_file) {
	 output << "Average income for " << state_data[i].name << ": " << avg << endl;
      }
      else {
	 cout << "Average income for " << state_data[i].name << ": " << avg << endl;
      }

   }
}


/********************************************
 * Function: states_by_population
 * Description: Prints the states in accordance to population
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int, ofstream &, int
 * Post-Conditions: none
 * Return: none
********************************************/
void states_by_population(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int i, j;
   bool flag = true;
   int temp;
   string temp2;

   state *states_in_order = new state[num_states];

   for (int k = 0; k < num_states; k++) {
      states_in_order[k].population = state_data[k].population;
      states_in_order[k].name = state_data[k].name;
   }

   for (i = 0; (i < num_states) && flag; i++) {
      flag = false;
      for (j = 0; j < (num_states - 1); j++) {
	 if (states_in_order[j+1].population > states_in_order[j].population) {
	    temp = states_in_order[j].population;
	    temp2 = states_in_order[j].name;

	    states_in_order[j].population = states_in_order[j+1].population;
	    states_in_order[j].name = states_in_order[j+1].name;

	    states_in_order[j+1].population = temp;
	    states_in_order[j+1].name = temp2;

	    flag = true;
	 }
      }
   }
   if (print_to_file) {
      output << "States sorted by population" << endl;

      for (int k = 0; k < num_states; k++) {
	 output << states_in_order[k].name << endl;
      }

      output << "State with the largest population: " << states_in_order[num_states-1].name << endl;

   }
   else {
      cout << "States sorted by population" << endl;

      for (int k = 0; k < num_states; k++) {
	 cout << states_in_order[k].name << endl;
      }

      cout << "State with the largest population: " << states_in_order[num_states-1].name << endl;
   }

   //delete states_in_order
   delete [] states_in_order;
   //*states_in_order = NULL;
}

/********************************************
 * Function: states_by_name
 * Description: prints the states according to name
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int, ofstream &
 * Post-Conditions: none
 * Return: none
********************************************/
void states_by_name(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int i, j;
   bool flag = true;
   string temp;

   state *states_in_order = new state[num_states];

   for (int k = 0; k < num_states; k++) {
      states_in_order[k].name = state_data[k].name;
   }

   for (i = 0; (i < num_states) && flag; i++) {
      flag = false;
      for (j = 0; j < (num_states - 1); j++) {
	 for (int y = 0; y < states_in_order[j+1].name.length() || y < states_in_order[j].name.length(); y++) {
	    if (states_in_order[j+1].name.at(y) < states_in_order[j].name.at(y)) {
	       temp = states_in_order[j].name;

	       states_in_order[j].name = states_in_order[j+1].name;

	       states_in_order[j+1].name = temp;

	       flag = true;

	       break;
	    }
	    else if (states_in_order[j+1].name.at(y) > states_in_order[j].name.at(y)) {
	       break;
	    }
	 }
      }
   }

   if (print_to_file) {
      output << "States sorted by name" << endl;

      for (int k = 0; k < num_states; k++) {
	 output << states_in_order[k].name << endl;
      }
   }
   else {
      cout << "States sorted by name" << endl;

      for (int k = 0; k < num_states; k++) {
	 cout << states_in_order[k].name << endl;
      }
   }

   //delete states_in_order
   delete [] states_in_order;
   //*states_in_order = NULL;
}


/********************************************
 * Function: counties_by_population
 * Description: prints the counties in a state according to population
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, ofstream&, int
 * Post-Conditions: none
 * Return: none
********************************************/
void counties_by_population(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int i, j;
   bool flag = true;
   int temp;
   string temp2;

   for (int y = 0; y < num_states; y++) {

      county *counties_in_order = new county[state_data[y].counties];

      for (int k = 0; k < num_states; k++) {
	 counties_in_order[k].population = state_data[y].c[k].population;
	 counties_in_order[k].name = state_data[y].c[k].name;
      }

      for (i = 0; (i < state_data[y].counties) && flag; i++) {
	 flag = false;
	 for (j = 0; j < (state_data[y].counties - 1); j++) {

	    if (counties_in_order[j+1].population > counties_in_order[j].population) {

	       temp = counties_in_order[j].population;
	       temp2 = counties_in_order[j].name;

	       counties_in_order[j].population = counties_in_order[j+1].population;
	       counties_in_order[j].name = counties_in_order[j+1].name;

	       counties_in_order[j+1].population = temp;
	       counties_in_order[j+1].name = temp2;

	       flag = true;
	    }
	 }
      }
      if (print_to_file) {
	 output << "Counties in " << state_data[y].name << " sorted by population: " << endl;

	 for (int k = 0; k < num_states; k++) {
	    output << counties_in_order[k].name << endl;
	 }

      }
      else {
	 cout << "Counties in " << state_data[y].name << " sorted by population: " << endl;

	 for (int k = 0; k < num_states; k++) {
	    cout << counties_in_order[k].name << endl;
	 }
      }

      //delete counties_in_order
      delete [] counties_in_order;
   //*counties_in_order = NULL;
   }


}

/********************************************
 * Function: counties_by_population
 * Description: prints the counties in order by population
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int, ofstream &
 * Post-Conditions: none
 * Return: none
********************************************/
void counties_by_name(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int i, j;
   bool flag = true;
   string temp;

   for (int y = 0; y < num_states; y++) {

      county *counties_in_order = new county[state_data[y].counties];

      for (int k = 0; k < num_states; k++) {
	 counties_in_order[k].population = state_data[y].c[k].population;
	 counties_in_order[k].name = state_data[y].c[k].name;
      }

      for (i = 0; (i < state_data[y].counties) && flag; i++) {
	 flag = false;
	 for (j = 0; j < (state_data[y].counties - 1); j++) {
	    for (int y = 0; y < counties_in_order[j+1].name.length() || y < counties_in_order[j].name.length(); y++) {

	       if (counties_in_order[j+1].name.at(y) > counties_in_order[j].name.at(y)) {

		  temp = counties_in_order[j].name;

		  counties_in_order[j].name = counties_in_order[j+1].name;

		  counties_in_order[j+1].name = temp;

		  flag = true;

		  break;
	       }
	       else if (counties_in_order[j+1].name.at(y) > counties_in_order[j].name.at(y)) {
		  break;
	       }
	    }
	 }
      }

      if (print_to_file) {
	 output << "Counties in " << state_data[y].name << " sorted by name: " << endl;

	 for (int k = 0; k < num_states; k++) {
	    output << counties_in_order[k].name << endl;
	 }
      }
      else {
	 cout << "Counties in " << state_data[y].name << " sorted by name: " << endl;

	 for (int k = 0; k < num_states; k++) {
	    cout << counties_in_order[k].name << endl;
	 }
      }

      //delete counties_in_order
      delete [] counties_in_order;
      //*counties_in_order = NULL;
   }


}

/********************************************
 * Function: county_largest_population
 * Description: prints the county with the largest population
 * Parameters: state_data, num_states, ouput, print_to_file
 * Pre-Conditions: state*, int, ofstream &
 * Post-Conditions: none 
 * Return: none
 ********************************************/
void county_largest_population(state *state_data, int num_states, ofstream &output, int print_to_file) {

   int i, j;
   bool flag = true;
   int temp;
   string temp2;

   int num_counties = 0;

   for (int k = 0; k < num_states; k++) {

      num_counties += state_data[k].counties;
   }

   county *county_by_pop = new county[num_counties];

   int count = 0;

   for (int k = 0; k < num_states; k++) {

      for (int y = 0; y < state_data[k].counties; y++) {

	 county_by_pop[count].population = state_data[i].c[y].population;
	 county_by_pop[count].name = state_data[i].c[y].name;

	 count++;

      }
   }

   for (i = 0; (i < num_counties) && flag; i++) {
      flag = false;
      for (j = 0; j < (num_states - 1); j++) {
	 if (county_by_pop[j+1].population > county_by_pop[j].population) {
	    temp = county_by_pop[j].population;
	    temp2 = county_by_pop[j].population;

	    county_by_pop[j].population = county_by_pop[j+1].population;
	    county_by_pop[j].name = county_by_pop[j+1].name;

	    county_by_pop[j+1].population = temp;
	    county_by_pop[j+1].name = temp2;
	 }
      }
   }

   if (print_to_file) {
      output << "County with the largest population: " << county_by_pop[0].name << endl;
   }
   else {
      cout << "County with the largest population: " << county_by_pop[0].name << endl;
   }

   //Delete the special array I made
   delete [] county_by_pop;
   //*counties_by_pop = NULL;

}


/********************************************
 * Function: print_stuff
 * Description: prints all the stuff I want
 * Parameters: state_data, num_states, output, print_to_file
 * Pre-Conditions: state*, int, ofstream &
 * Post-Conditions: none
 * Return: none
 ********************************************/
void print_stuff(state *state_data, int num_states, ofstream &output, int print_to_file) {

   income_limit(state_data, num_states, output, print_to_file);

   average_household(state_data, num_states, output, print_to_file);

   states_by_population(state_data, num_states, output, print_to_file);

   counties_by_population(state_data, num_states, output, print_to_file);

   county_largest_population(state_data, num_states, output, print_to_file);

   states_by_name(state_data, num_states, output, print_to_file);

   counties_by_name(state_data, num_states, output, print_to_file);

}



/********************************************
 * Function: delete_info
 * Description: Deletes all of state_data
 * Parameters: state_data, num_states
 * Pre-Conditions: state **, int
 * Post-Conditions: state** is freed
 * Return: none
 ********************************************/

void delete_info(state **state_data, int num_states) {

   //For the number of counties
   for (int j = 0; j < num_states; j++) {

      //For the number of cities
      for (int k = 0; k < (*state_data)[j].counties; k++) {

	 delete [] (*state_data)[j].c[k].city;
         //*(*state_data)[j].c[k].city = NULL;
      }
   }

   for (int j = 0; j < num_states; j++) {

      delete [] (*state_data)[j].c;
      //*(*state_data)[j].c = NULL;
   }


   //For the number of states
   //for (int i = 0; i < num_states; i++) {

   delete [] (*state_data);
   //*(*state_data) = NULL;
   //}

}

/********************************************
 * Function: create_states
 * Description: creates the number of states that there is in an input file
 * Parameters: num_states 
 * Pre-Conditions: int
 * Post-Conditions: none
 * Return: state_data
 ********************************************/
state *create_states(int num_states) {

   state *state_data = new state[num_states];

   return state_data;
}

/********************************************
 * Function: create_counties
 * Description: Creates the number of counties in a state
 * Parameters: num_counties
 * Pre-Conditions: int
 * Post-Conditions: none
 * Return: county_data
 ********************************************/
county *create_counties(int num_counties) {

   county *county_data = new county[num_counties];

   return county_data;
}




/********************************************
 * Function: valid_file_and_int
 * Description: Checks to make sure the user inputted a valid file and int for num_states
 * Parameters: argv, argc, args
 * Pre-Conditions: char **, int, arguments
 * Post-Conditions: args is initialized
 * Return: none
 ********************************************/
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
   if (argv[state_arg][0] < '1')
      valid_number = false;

   //If the command line arg is not a positive integer
   if (!valid_number) {
      do {
	 if (cin.fail()) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	 }
	 cout << "Enter valid number of states (postive int): ";
	 cin >> args.num_states;
	 cin.ignore(INT_MAX, '\n');
      } while (cin.fail() or args.num_states < 1);
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

/********************************************
 * Function: is_valid_arguments
 * Description: Checks to make sure the user inputted valid command line arguments
 * Parameters: argv, argc
 * Pre-Conditions: char **, int
 * Post-Conditions: None
 * Return: False, true
 ********************************************/
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
