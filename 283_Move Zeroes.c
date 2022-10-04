void moveZeroes(int* nums, int numsSize){
    
    int temp,last=numsSize; //last:0序列的最前端的index
    
    for(int i=0;i<last;++i)
    {
        if(nums[i]==0)
        {
            for(int j=i;j<last-1;++j)
            {
                nums[j]=nums[j+1];
            }
            nums[last-1]=0;
            i--;  //[0 0 1]
            last--;
        }
    }
}
