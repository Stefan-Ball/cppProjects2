#include <stdio.h> //printf, scanf
#include <stdlib.h> //malloc, free, NULL
#include "list.h"

/********************************************************************************
 * * Description: Initialize the list
 * * Parameters: the_list
 * * Returns: none
 * * Pre-Conditions: list
 * * Post-Conditions: the_list initialized to NULL
 * *********************************************************************************/
void init(struct list *the_list) {
   //struct node *first = (node*) malloc(sizeof(node));

   (*the_list).head = NULL;
   (*the_list).tail = NULL;
}

/********************************************************************************
 * * Description: Push a node onto the front of the list and initalize it with a number
 * * Parameters: the_list, num
 * * Returns: none
 * * Pre-Conditions: list, int
 * * Post-Conditions: the_list has another node on the front of int num
 * *********************************************************************************/
void push_front(struct list *the_list, int num) {

   //Initialize the node
   struct node *another = malloc(sizeof(struct node));
   another->val = num;
   another->next = NULL;

   if (size(*the_list) > 0) {
      another->next = the_list->head;
      the_list->head = another;
   }
   else {
      the_list->head = another;
      the_list->tail = another;
   }
}

/********************************************************************************
 * * Description: Push a node onto the back of the list and initalize it with a number
 * * Parameters: the_list, num
 * * Returns: none
 * * Pre-Conditions: list, int
 * * Post-Conditions: the_list has another node on the back of int num
 * *********************************************************************************/
void push_back(struct list *the_list, int value) {

   //Create node to point to
   struct node *another =  malloc(sizeof(struct node));
   another->val = value;
   another->next = NULL;

   if (the_list->head == NULL)
      the_list->head = another;

   if (size(*the_list) > 0)
      the_list->tail->next = another;

   the_list->tail = another;
}

/********************************************************************************
 * * Description: Delete all the nodes on the list
 * * Parameters: the_list
 * * Returns: none
 * * Pre-Conditions: list
 * * Post-Conditions: ALl the nodes on the list are gone
 * *********************************************************************************/
void delete(struct list *the_list) {

   while (the_list->head != NULL)
      remove_front(the_list);
}

/********************************************************************************
 * * Description: Remove a node from the back of the list 
 * * Parameters: the_list
 * * Returns: none
 * * Pre-Conditions: list
 * * Post-Conditions: the_list has one less node from the front
 * *********************************************************************************/
int remove_front(struct list *the_list) {
   struct node *holder;
   int temp;

   if (the_list->head == NULL)
      return 9;

   if (size(*the_list) == 1) {
      temp = the_list->head->val;
      free(the_list->head);
      the_list->head = NULL;
      the_list->tail = NULL;
      return temp;
   }

   temp = the_list->head->val;
   holder = the_list->head->next;
   free(the_list->head);

   the_list->head = holder;

   return temp;
}


/********************************************************************************
 * * Description: Remove a node from the back of the list 
 * * Parameters: the_list
 * * Returns: none
 * * Pre-Conditions: list
 * * Post-Conditions: the_list has one less node from the back 
 * *********************************************************************************/
int pop_back(struct list *the_list) {
   int temp;
   struct node *holder_1;
   struct node *holder_2;
   struct node *holder_3;

   //If there's no tail, return nothing
   if (the_list->tail == NULL) {
      //printf("ERROR: There's nothing to pop_back.\n");
      return 8;
   }
   //The temporary int holds on to the value of the top of the list
   temp = the_list->tail->val;


   if (size(*the_list) == 1) {
      free (the_list->tail);
      the_list->tail = NULL;
      the_list->head = NULL;
      return temp;
   }

   //Make the first holder point to head
   holder_1 = the_list->head;
   holder_2 = holder_1;
   holder_3 = holder_1;

   while (1) {
      //Make holder_2 equal to the next holder
      holder_2 = holder_1->next;
      if (holder_2 == NULL || holder_2->next == NULL) {
	 the_list->tail = holder_3;
	 break;
      }
      //holder 1 equals the next value
      holder_1 = holder_2;
      holder_3 = holder_1;
   }
   free (holder_2);
   the_list->tail->next = NULL;

   return temp;
}

/********************************************************************************
 * * Description: Prints all the values on the list
 * * Parameters: the_list
 * * Returns: none
 * * Pre-Conditions: list
 * * Post-Conditions: no change
 * *********************************************************************************/
void print(struct list the_list) {
   struct node *holder;
   int count = 0;
   if (size(the_list) > 0)
      holder = the_list.head;
   else
      return;

   while(1) {
      printf("Num %d: %d\n", count, holder->val);
      if (holder->next == NULL)
	 return;
      count++;
      holder = holder->next;

   }
}

/********************************************************************************
 * * Description: Tells whether list is empty or not
 * * Parameters: the_list
 * * Returns: 0 for false, 1 for true
 * * Pre-Conditions: list
 * * Post-Conditions: no change
 * *********************************************************************************/
int empty(struct list the_list) {

   if (size(the_list) > 0)
      return 0;

   return 1;
}

/********************************************************************************
 * * Description: Prints the size of the list
 * * Parameters: the_list
 * * Returns: int size of list
 * * Pre-Conditions: list
 * * Post-Conditions: no change
 * *********************************************************************************/
int size(struct list the_list) {
   int count = 0;
   struct node *holder_1;
   struct node *holder_2;

   //If there's no tail, return nothing
   if (the_list.tail == NULL) {
      return 0;
   }

   //The list and tail aren't pointing to each other or nothing
   else {
      //Make the first holder point to head
      holder_1 = the_list.head;
      holder_2 = holder_1;

      while (1) {
	 //Make holder_2 equal to the next holder
	 holder_2 = holder_1->next;
	 count++;
	 if (holder_2 == NULL) {
	    break;
	 }
	 //holder 1 equals the next value
	 holder_1 = holder_2;
      }
   }

   return count;
}


/********************************************************************************
 * * Description: Returns the back value of the list
 * * Parameters: the_list
 * * Returns: Back value of list
 * * Pre-Conditions: list
 * * Post-Conditions: no change
 * *********************************************************************************/
int back(struct list the_list) {
   int temp;

   //If there's no tail, return nothing
   if (the_list.tail == NULL) {
      printf("ERROR: There's no value in the linked list.\n");
      return 0;
   }
   //The temporary int holds on to the value of the top of the list
   temp = the_list.tail->val;

   return temp;
}

/********************************************************************************
 * * Description: Returns the front value of the list
 * * Parameters: the_list
 * * Returns: Front value of list
 * * Pre-Conditions: list
 * * Post-Conditions: no change
 * *********************************************************************************/
int front(struct list the_list) {
   int temp;

   //If there's no tail, return nothing
   if (the_list.head == NULL) {
      printf("ERROR: There's no value in the linked list.\n");
      return 0;
   }
   //The temporary int holds on to the value of the top of the list
   temp = the_list.head->val;

   return temp;
}

/*
int main() {

   int answer;

   struct list the_list;

   init(&the_list);

   while (1) {
      printf("Would you like to push_front a number onto the list? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer != 1) {
	 printf("What number?");
	 scanf("%d", &answer);
	 push_front(&the_list, answer);
	 printf("value: %d\n", the_list.tail->val);
	 printf("Size: %d\n", size(the_list));
	 print(the_list);
	 printf("front: %d.\n", front(the_list));
	 printf("back: %d.\n", back(the_list));
	 if (empty(the_list))
	    printf("empty!: %d.\n", back(the_list));
      }
      printf("Would you like to push_back a number onto the list? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer != 1) {
	 printf("What number?");
	 scanf("%d", &answer);
	 push_back(&the_list, answer);
	 printf("value: %d\n", the_list.tail->val);
	 printf("Size: %d\n", size(the_list));
	 print(the_list);
      }
      printf("Would you like to pop_back a number from the list? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer != 1) {
	 if (the_list.tail != NULL)
	    printf("value: %d\n", the_list.tail->val);
	 printf("Size: %d\n", size(the_list));
	 pop_back(&the_list);
	 print(the_list);
	 if (empty(the_list))
	    printf("empty!: %d.\n", back(the_list));
      }
      printf("Would you like to pop_front a number from the list? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer != 1) {
	 if (the_list.tail != NULL)
	    printf("value: %d\n", the_list.tail->val);
	 printf("Size: %d\n", size(the_list));
	 remove_front(&the_list);
	 print(the_list);
      }

      printf("Would you like to delete everything? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer == 0)
	 delete(&the_list);

      printf("Would you like to quit? 0-yes, 1-no");
      scanf("%d", &answer);
      if (answer == 0)
	 break;


   }

}

*/
