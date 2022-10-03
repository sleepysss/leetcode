/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    int *store=(int *)malloc(sizeof(int)*2);
    int l=0,r=numbersSize-1;
    
    while(l<r)
    {
        if((numbers[l]+numbers[r])==target)
        {
            store[0]=l+1;
            store[1]=r+1;
            break;
        }
        else if((numbers[l]+numbers[r])<target)
            l++;
        else
            r--;
    }
    *returnSize=2;
    return store;
}
