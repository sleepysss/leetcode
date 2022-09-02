int search(int* nums, int numsSize, int target){
    
    int mid,left=0,right=numsSize-1;
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]==target) //find
            return mid;
        if(nums[mid]>=nums[left]) //mid at left-sub(因為至少會大於等於最左邊)
        {                         //等於發生在只有一個元素
            if(nums[mid]>target&&target>=nums[left]) //target at mid's left
            {
                right=mid-1; //去mid左邊找
            }
            else
            {
                left=mid+1; //target不是上面那區,所以去另一區(mid右邊)找
            }
        }
        else
        {
            if(nums[right]>=target&&target>nums[mid]) //target at mid's right
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
    }
    
    return -1; //找不到
}
