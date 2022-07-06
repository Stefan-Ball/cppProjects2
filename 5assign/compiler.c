#include <stdio.h> //printf, scanf
#include <stdlib.h> //malloc, free, NULL
#include "list.h"
#include "compiler.h"

void compiler() {

   //Create/initialize list
   struct list the_list;
   init(&the_list);

   get_input(&the_list);

   return;
}

int check_input(struct list *the_list) {

   if (remove_front(the_list) != pop_back(the_list)) {
      printf("ERROR: BRACKETS / BRACES / PARENTHESIS\n");
      return 1;
   }
   return 0;

}
/********************************************************************************
 * * Description: Checks for valid string of curly braces, brackets, and parentheses
 * * Parameters: *the_list
 * * Returns: nothing
 * * Pre-Conditions: struct list
 * * Post-Conditions: the_list is empty
 * *********************************************************************************/
void get_input(struct list *the_list) {
   int answer;
   int i = 0;
   char *input;
   input = NULL;

   printf("Enter a string: ");
   take_in_input(&input);

   while (input[i] != '\0'){
      if (input[i] == '[')
	 push_front(the_list, 0);

      else if (input[i] == '{')
	 push_front(the_list, 1);

      else if (input[i] == '(')
	 push_front(the_list, 2);

      else if (input[i] == ']') {
	 push_back(the_list, 0);
	 if (!check_input(the_list)) {
	    delete(the_list);
	    free(input);
	    return;
	 }
      }

      else if (input[i] == '}') {
	 push_back(the_list, 1);
	 if (!check_input(the_list)) {
	    delete(the_list);
	    free(input);
	    return;
	 }
      }

      else if (input[i] == ')') {
	 push_back(the_list, 2);
	 if (!check_input(the_list)) {
	    delete(the_list);
	    free(input);
	    return;
	 }
      }
      i++;
   }
   if (!empty(*the_list)) {
      printf("ERROR: BRACKETS / BRACES / PARENTHESIS\n");
      delete(the_list);
      free(input);
      return;
   }
   free(input);

   printf("Compiled\n");

}

void take_in_input(char **c) {
   char *temp;
   char input;
   int size = 0;
   int i;

   if (*c != NULL)
      free(*c);
   *c = NULL;

   *c = (char *) malloc(1);
   do {
      //Get input
      scanf("%c", &input);
      //if input is break, break
      if (input == '\n' /*|| input == ' '*/)
	 break;
      //Make temp array
      temp = (char *) malloc(size);
      //copy c to temp
      for (i = 0; i < size; i++)
	 temp[i] = (*c)[i];
      size++;
      free(*c);
      *c = (char *) malloc(size+1);
      //copy temp to c
      for (i = 0; i < size-1; i++)
	 (*c)[i] = temp[i];
      //Put in input
      (*c)[size-1] = input;
      //Put in null delimeter
      (*c)[size] = '\0';
      free(temp);
   } while (input != '\n');
}
