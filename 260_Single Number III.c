//mrethod 1 : sort and compare

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int partition(int *nums,int left,int right)
{
    int t=left-1;
    int pivot=nums[right],temp;
    
    for(int i=left;i<right;++i)
    {
        if(nums[i]<pivot)
        {
            t++;
            temp=nums[t];
            nums[t]=nums[i];
            nums[i]=temp;
        }
    }
    t++;
    temp=nums[t];
    nums[t]=pivot;
    nums[right]=temp;
    
    return t;
    
}


void quicksort(int *nums,int left,int right)
{
    if(left<right)
    {
        int pivot=partition(nums,left,right);
        quicksort(nums,left,pivot-1);
        quicksort(nums,pivot+1,right);
    }
}

int* singleNumber(int* nums, int numsSize, int* returnSize){
    
    int *store=(int *)malloc(sizeof(int)*2);
    quicksort(nums,0,numsSize-1);
    store[1]=nums[numsSize-1];
    int count=0;
    
    //看自己和後面的是否相同來抓出single num
    for(int i=0;i<numsSize-1;++i)
    {
        if(nums[i]!=nums[i+1])
            store[count++]=nums[i];
        else
            i++; //到下一組
    }
    
    *returnSize=2;
    return store;
}
