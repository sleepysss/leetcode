/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    
    int *store=(int *)malloc(sizeof(int)*2);
    int left=0,right=numsSize,mid;
    *returnSize=2;
    
    if(!numsSize)
    {
        store[0]=-1;
        store[1]=-1;
        return store;
    }
    
    //目標:在 array 中，找到 >= target 的元素裡面，最小的那個的 index
    while(left<right)
    {
        mid=left+(right-left)/2; 
        if(nums[mid]>=target)
            right=mid;
        else
            left=mid+1;
    }
    
    if(left>(numsSize-1))   //因為有可能array中每個都比target小,這樣導致最小的那個index超過array的範圍
        store[0]=-1;
    else
        store[0]=(nums[left]==target)?left:-1;
        
    //目標:在 array 中，找到 > target 的元素裡面，最小的那個的 index , 然後再把該index-1在經過對比就可拿到target所在的最後位置
    left=0;
    right=numsSize;
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]>target)
            right=mid;
        else
            left=mid+1;
    }
    
    if(!left)  //因為有可能array中每個都比target大,導致最小的那個index為0
        store[1]=-1;
    else
        store[1]=(nums[left-1]==target)?left-1:-1;
    return store;

}
