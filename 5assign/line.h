#ifndef LINE_H
#define LINE_H
struct args {
   int num_cashiers;
   int min_cashier_time;
   int max_cashier_time;
   int new_customer_time;
};

int command_line_args(int argc, char *argv[], struct args arguments); 

struct lines {
   struct list self_serve;
   struct list line_1;
   struct list line_2;
   struct list line_3;
};
int make_lines(struct lines, struct args);
void print_stuff(struct lines line, int hour);
#endif
