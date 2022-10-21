//method 1 : brute force ...TLE

int maxSubArray(int* nums, int numsSize){
    
    int sum,max_sum=-10001;
    
    for(int i=0;i<numsSize;++i)
    {
        sum=0;
        for(int j=i;j<numsSize;++j)
        {
            sum+=nums[j];
            max_sum=max_sum>sum?max_sum:sum;
        }
    }
    
    return max_sum;
}
