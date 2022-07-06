#include <stdio.h>
#include <stdlib.h>
void best_case(int, FILE *);
void worst_case(int, FILE *);
void random_num(int, FILE *); 


int main(int argc, char *argv[]) {
   srand(time(NULL));
   FILE *to;
   int total;
   int answer;

   //open the file numbers and write to it
   to = fopen("numbers", "w");

   //Get the number of nums to print
   total = atoi(argv[1]);

   //Get which algorithm to run
   answer = atoi(argv[2]);

   if (answer == 1)
      best_case(total, to);
   else if (answer == 2)
      worst_case(total, to);
   else
      random_num(total, to);

   return 0;
}

void best_case(int total, FILE *to) {
   int i;
   //best case
   for (i = 0; i < total; i++) {
      fprintf(to, "%d\n", i);
   }
}

void worst_case(int total, FILE *to) {
   int i;
   //worst case
   for (i = total; i > 0; i--) {
      fprintf(to, "%d\n", i);
   }
}

void random_num(int total, FILE *to) {
   srand(time(NULL));
   int temp;
   int i;
   // random
   for (i = 0; i < total; i++) {
      temp = rand() % 1000;
      fprintf(to, "%d\n", temp);
   }
}
