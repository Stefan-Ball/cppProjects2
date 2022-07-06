#include "compiler.h"
#include "line.h"
#include <stdio.h>

/********************************************
 * Program: Compiler / test_queue.c
 * Author: Stefan Ball
 * Date: 06/09/17
 * Description: Mini compiler, Queue system
 * Input: Command line arguments; brackets, parentheses, curly braces
 * Output: Compiled or not, line size at 1, 5, 10 hours
**************************************************/
int main(int argc, char *argv[]) {
   struct args stuff;

   compiler();

   if (!command_line_args(argc, argv, stuff))
      printf("Invalid command line arguments.\n");

   return 0;
}
