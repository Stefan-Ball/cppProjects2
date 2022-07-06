#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //rand, srand
#include <time.h> //time
#include "compiler.h"
#include "line.h"

//Working function
/********************************************************************************
 * * Description: take command line arguments, check for correctness, place in struct arguments
 * * Parameters: argc, **argv
 * * Returns: int, valid or invalid command line arguments
 * * Pre-Conditions: int, char **, args
 * * Post-Conditions: arguments is initialized if valid command line arguments
 * *********************************************************************************/
int command_line_args(int argc, char *argv[], struct args arguments) {
   int i;
   struct lines line;
   line.line_1.head = NULL;
   line.line_1.tail = NULL;
   line.line_2.head = NULL;
   line.line_2.tail = NULL;
   line.line_3.head = NULL;
   line.line_3.tail = NULL;
   line.self_serve.head = NULL;
   line.self_serve.tail = NULL;

   for (i = 0; i < argc; i++) {
      if (!strcmp(argv[i], "-n")) {
	 if (i < (argc-1) ) {
	    printf("num: %s\n", argv[i+1]);
	    arguments.num_cashiers = atoi(argv[i+1]);
	 }
      }
      if (!strcmp(argv[i], "-s")) {
	 if (i < (argc-1) ) {
	    printf("min time: %s\n", argv[i+1]);
	    arguments.min_cashier_time = atoi(argv[i+1]);
	 }
      }
      if (!strcmp(argv[i], "-e")) {
	 if (i < (argc-1) ) {
	    printf("max time: %s\n", argv[i+1]);
	    arguments.max_cashier_time = atoi(argv[i+1]);
	 }
      }
      if (!strcmp(argv[i], "-c")) {
	 if (i < (argc-1) ) {
	    arguments.new_customer_time = atoi(argv[i+1]);
	 }
      }
   }
   if (arguments.new_customer_time < 1)
      return 0;
   if (arguments.max_cashier_time < 1)
      return 0;
   if (arguments.min_cashier_time < 1)
      return 0;
   if (arguments.num_cashiers < 1)
      return 0;

   make_lines(line, arguments);

   return 1;

}
/********************************************************************************
 * * Description: Runs the functionality for the line comparison
 * * Parameters: lines, args
 * * Returns: 0
 * * Pre-Conditions: line, arguments
 * * Post-Conditions: line is cleared
 * *********************************************************************************/
int make_lines(struct lines line, struct args arguments) {
   srand(time(NULL));
   int i;
   //create and initialize cashier times
   int customer_serve_time_1 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
   int customer_serve_time_2 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
   int customer_serve_time_3 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
   //For ten hours
   for (i = 0; i < 60*10; i++) {
      //If a new customer is coming, put them in the shortest line
      if (i % arguments.new_customer_time == 0) {
	 if (size(line.line_1) <= size(line.line_2) && size(line.line_1) <= size(line.line_3))
	    push_front(&line.line_1, 1);
	 else if (size(line.line_2) <= size(line.line_1) && size(line.line_2) <= size(line.line_3))
	    push_front(&line.line_2, 1);
	 else
	    push_front(&line.line_3, 1);

	 //Put a customer in the one line
	 push_front(&line.self_serve, 1);
      }
      //If the first cashier serves a customer, take a customer off the stack for the first line
      if (i % customer_serve_time_1 == 0) {
	 customer_serve_time_1 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
	 pop_back(&line.line_1);
	 pop_back(&line.self_serve);
      }
      //If the second cashier serves a customer, take a customer off the stack for the second line
      if (i % customer_serve_time_2 == 0) {
	 customer_serve_time_2 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
	 pop_back(&line.line_2);
	 pop_back(&line.self_serve);
      }
      //If the third cashier serves a customer, take a customer off the stack for the third line
      if (i % customer_serve_time_3 == 0) {
	 customer_serve_time_3 = (rand() % (arguments.max_cashier_time - arguments.min_cashier_time)) + arguments.min_cashier_time;
	 pop_back(&line.line_3);
	 pop_back(&line.self_serve);
      }
      //Print information at one hour
      if (i == 60)
	 print_stuff(line, 1);
      //Print information at 5 hours
      if (i == 60*5)
	 print_stuff(line, 5);
   }

   //Print information at ten hours
   print_stuff(line, 10);

   delete(&line.line_1);
   delete(&line.line_2);
   delete(&line.line_2);
   delete(&line.line_3);
   delete(&line.self_serve);

   return 0;

}
/********************************************************************************
 * * Description: Prints the information of the lines for an hour
 * * Parameters: line, hour
 * * Returns: none
 * * Pre-Conditions: lines, int
 * * Post-Conditions: no change
 * *********************************************************************************/
void print_stuff(struct lines line, int hour) {
   printf("%d hour: \n", hour);
   printf("Self-Select queues have\n");
   printf("%d people in queue 1\n", size(line.line_1));
   printf("%d people in queue 2\n", size(line.line_2));
   printf("%d people in queue 3\n", size(line.line_3));
   printf("One queue, select first available\n");
   printf("%d people remaining in queue\n", size(line.self_serve));
}
