int findMin(int* nums, int numsSize){
    
    int left=0,right=numsSize-1,mid;
    
    if(numsSize==1)
        return nums[0];

    if(nums[right]>nums[left]) //not rotate
        return nums[0];
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]>=nums[0])
            left=mid+1;
        else
            right=mid-1;
    }
    
    return nums[left];
}
