/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    int *store=(int *)malloc(sizeof(int)*numsSize);
    int count=0,i=0;
    *returnSize=numsSize;
    while(i<n)
    {
        store[count++]=nums[i];  //或store[2*i]=nums[i];
        store[count++]=nums[n+i]; //或store[2*i+1]=nums[i];
        i++;
    }
    return store;
}
