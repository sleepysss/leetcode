/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *store=(int *)malloc(sizeof(int)*2*numsSize);
    int *ans_double=(int *)malloc(sizeof(int)*2*numsSize);
    int *monotonic_stack=(int *)malloc(sizeof(int)*2*numsSize);
    int top=-1;
    int *ans=(int *)malloc(sizeof(int)*numsSize);
    
    for(int i=0;i<numsSize;++i)
    {
        store[i]=nums[i];
        store[i+numsSize]=nums[i];
    }
    
    for(int i=2*numsSize-1;i>=0;--i)
    {
        while(top!=-1&&store[i]>=monotonic_stack[top])
            top--;
        ans_double[i]=top==-1?-1:monotonic_stack[top];
        top++;
        monotonic_stack[top]=store[i];
    }
    
    for(int i=0;i<numsSize;++i)
        ans[i]=ans_double[i];
    free(store);
    free(ans_double);
    free(monotonic_stack);
    
    *returnSize=numsSize;
    return ans;
}
