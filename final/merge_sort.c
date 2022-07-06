
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

