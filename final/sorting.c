#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);
void quicksort(int arr[], int low, int high); 

int main(){
   int *nums=NULL;
   int size=0;
   time stop, start;

   fill_array(&nums, &size);
   print_array(nums, size);

   //Time the function here
   gettimeofday(&start, NULL);
   
   quicksort(nums, 0, size-1);
   //bubble_sort(nums, size);
   //insertion_sort(nums, size);
   //merge_sort(nums, 0, size-1);
   //selection_sort(nums, size);

   gettimeofday(&stop, NULL);

   printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
   //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   //print_array(nums, size);
   free(nums);

   return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of 
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
/********************************************************************************
 * * Description: sorts the array of ints, nums, with the smallest number being at the beginning and the largest number being at the end
 * * Parameters: array pointer to ints, int size of the array pointer to ints
 * * Returns: none
 * * Pre-Conditions: nums points to a valid size array or NULL and size is the correct number for the size of the array nums
 * * Post-Conditions: the array nums is ordered with the smallest numbers at the beginning of the array and the largest numbers at the end
 * *********************************************************************************/

void merge(int *nums, int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];

   lower_half=left;  //What is this for?
   upper_half=mid+1;  //What is this for?
   
   //What does this loop do?
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      //What does this condition do?
      if(nums[lower_half]<=nums[upper_half]){
	 temp[i]=nums[lower_half];
	 lower_half++;
      }
      //What does this condition do?
      else{
	 temp[i]=nums[upper_half];
	 upper_half++;
      }
   }

   //What does this condition and loop do?
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
	 temp[i]=nums[j];
   //What does this else and loop do?
   else
      for(j=lower_half;j<=mid;j++, i++)
	 temp[i]=nums[j];

   //What does this loop do?
   for(j=0,i=left;i<=right;i++,j++)
      nums[i]=temp[j];
}

/********************************************************************************
 * * Description: sorts the array of ints, nums, with the smallest number being at the beginning and the largest number being at the end
 * * Parameters: array pointer to ints, int size of the array pointer to ints
 * * Returns: none
 * * Pre-Conditions: nums points to a valid size array or NULL and size is the correct number for the size of the array nums
 * * Post-Conditions: the array nums is ordered with the smallest numbers at the beginning of the array and the largest numbers at the end
 * *********************************************************************************/
void merge_sort(int *nums, int left, int right) {
   int mid; 
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(nums, left, mid);  //what does this call do?
      merge_sort(nums, mid+1, right); //what does this call do?
      merge(nums, left, mid, right);  //what does this call do?
   }
}

/********************************************************************************
 * * Description: sorts the array of ints, nums, with the smallest number being at the beginning and the largest number being at the end
 * * Parameters: array pointer to ints, int size of the array pointer to ints
 * * Returns: none
 * * Pre-Conditions: nums points to a valid size array or NULL and size is the correct number for the size of the array nums
 * * Post-Conditions: the array nums is ordered with the smallest numbers at the beginning of the array and the largest numbers at the end
 * *********************************************************************************/
void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //What does this loop do?
   for(i=0; i<size-1; i++) {
      min=i;
      //What does this loop do?
      for(j=i; j<size; j++)
	 if(nums[j]<nums[min]) 
	    min=j;
      //What elements are being swapped?
      temp=nums[i];
      nums[i]=nums[min];
      nums[min]=temp;
   }
}

/********************************************************************************
 * * Description: sorts the array of ints, nums, with the smallest number being at the beginning and the largest number being at the end
 * * Parameters: array pointer to ints, int size of the array pointer to ints
 * * Returns: none
 * * Pre-Conditions: nums points to a valid size array or NULL and size is the correct number for the size of the array nums
 * * Post-Conditions: the array nums is ordered with the smallest numbers at the beginning of the array and the largest numbers at the end
 * *********************************************************************************/
void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for(i=0; i<size; i++) {
      temp=nums[i]; 
      //What does this loop do?
      for(j=i; j>0 && nums[j-1]>temp; j--) 
	 nums[j]=nums[j-1];
      //What does this statment do?
      nums[j]=temp;
   }
}

/********************************************************************************
 * * Description: sorts the array of ints, nums, with the smallest number being at the beginning and the largest number being at the end
 * * Parameters: array pointer to ints, int size of the array pointer to ints
 * * Returns: none
 * * Pre-Conditions: nums points to a valid size array or NULL and size is the correct number for the size of the array nums
 * * Post-Conditions: the array nums is ordered with the smallest numbers at the beginning of the array and the largest numbers at the end
 * *********************************************************************************/
void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for(i=0; i<size; i++) {
      //What does this loop do?
      for(j=0; j<size-i-1; j++) {
	 if(nums[j]>nums[j+1]) {
	    temp=nums[j];
	    nums[j]=nums[j+1];
	    nums[j+1]=temp;
	 }
      }
   }
}

//Quicksort
void swap(int* a, int* b) {
   int t = *a;
   *a = *b;
   *b = t;
}
/*
   This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot
   */
int partition (int arr[], int low, int high) {
   int pivot = arr[high];    // pivot
   int i = (low - 1);  // Index of smaller element
   int j;
   for (j = low; j <= high- 1; j++)  {
      // If current element is smaller than or
      //equal to pivot
      if (arr[j] <= pivot) {
	 i++;    // increment index of smaller element
	 swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}
/*
 * The main function that implements QuickSort
 *  arr[] --> Array to be sorted,
 *    low  --> Starting index,
 *      high  --> Ending index 
 *      */
void quicksort(int arr[], int low, int high) {
   if (low < high) {
      //pi is partitioning index, arr[p] is now at right place
      int pi = partition(arr, low, high);

      //seperately sort elements before
      //partition and after partition
      quicksort(arr, low, pi - 1);
      quicksort(arr, pi + 1, high);
   }
}


/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];
   int count = 0;

   printf("Enter the filename: ");
   scanf("%s",filename);
   fptr=fopen(filename,"r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
      count++;
   }

   printf("Numbers in file: %d\n", count);
   fclose(fptr);
}
