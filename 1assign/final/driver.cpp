#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "states.h"
using namespace std;
/*********************************************
 * Program Filename: states.cpp
 * Author: Stefan Ball
 * Date: 04/16/17
 * Description: Gets state data, spits out state data
 * Input: state_data
 * Output: Ordered state data
********************************************/

/********************************************
 * Function: int main
 * Description: Runs the program
 * Parameters: argc, argv
 * Pre-Conditions: int, char **
 * Post-Conditions: none
 * Return: 1 or 0 depending on if file went correctly
*******************************************/ 
int main(int argc, char *argv[]) {

   //Create struct to hold filename and number of states
   arguments args;

   if (is_valid_arguments(argv, argc)) {
      //Check to make sure valid file and int in command line args
      valid_file_and_int(argv, argc, args);
      run_program(args);
   }
   else {
      cout << "Incorrect implementation of arguments" << endl;
      return 1;
   }

   play_again();

   cout << "Success!" << endl;

   return 0;

}
