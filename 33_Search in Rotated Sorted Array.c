int search(int* nums, int numsSize, int target){
     
    int left=0,right=numsSize-1,mid;
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>nums[right])  //mid at left sub
        {
            if(nums[mid]>target&&target>=nums[left])  //target at nums[left]~nums[mid-1]
                right=mid-1;
            else  //target at nums[mid+1]~nums[right]
                left=mid+1;
        }
        else  //mid at right sub
        {
            if(nums[mid]<target&&target<=nums[right]) //target at nums[mid+1]~nums[right]
                left=mid+1;
            else //target at nums[left]~nums[mid-1]
                right=mid-1;
        }    
    }
    return -1;
}
