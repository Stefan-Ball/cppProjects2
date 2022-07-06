#include <string>
#include <cstring>
using namespace std;
struct arguments {

   int num_states;
   string filename;

};

struct county {

   string name; //name of county
   string *city; //name of cities in county
   int cities; //number of cities in county
   int population; //total population of county
   float avg_income; //avg household income
   float avg_house; //avg household price
};

struct state {

   string name; //name of state
   struct county *c; //name of counties
   int counties; //number of counties in state
   int population; //total population of state
};

bool is_valid_arguments(char *argv[], int argc);

void run_program(int, char **);

state *read_in_data(arguments);

state *create_states(int);

county *create_counties(int);

void get_state_data(state *, ifstream &, int);

void get_county_data(county *county_data, int state_num, int num_counties, ifstream &input);

void valid_file_and_int(char **, int, arguments &);

void delete_info(state *, int num_states);

void print_stuff(state *, int, ofstream &);

void get_city_data(county *&county_data, int county_num, int num_cities, ifstream &);
