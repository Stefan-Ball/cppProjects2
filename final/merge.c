/********************************************************************************
 *  * * Description: sorts nums in increasing order from index left to index right, given that index left to mid and index right to mid ares sorted
 *   * * Parameters: array pointer to ints, int index left, mid, and right
 *    * * Returns: none
 *     * * Pre-Conditions: nums must point to valid int array, nums must be sorted in increasing order from index left to index mid, and from index mid to index right. Left, mid, and right must be indexes of nums in the correct order
 *      * * Post-Conditions: nums will be sorted from index left to index right
 *       * *********************************************************************************/
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

