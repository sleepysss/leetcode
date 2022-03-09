/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//brute force
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int flag=0,i,j,store;
    
    for(i=0;i<numsSize;++i)
    {
        store=target;
        store-=nums[i];
        for(j=i+1;j<numsSize;++j) //不用重0開始,因為答案必在i之後
        {
            if(nums[j]==store)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    int *Store=(int *)malloc(sizeof(int)*2);
    Store[0]=i;
    Store[1]=j;
    *returnSize=2;
    return Store;
}
