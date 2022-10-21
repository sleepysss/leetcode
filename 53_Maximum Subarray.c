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


//method 2 : 隊友強不強(?)理論
int maxSubArray(int* nums, int numsSize){
    
    int curr=0,max=-10001; //curr:curr's maxSubArray
    
    //對於每個點來說,看看前人加上他後的值會不會比自己從新當頭來的好
    //ex: [-2,1]
    //對於1來說 -2+1 < 1 ,那我就從我自己開始新的探險,即:curr改為1 (不要帶拖油瓶)
    //curr=curr+nums[i]>nums[i] 等同 curr>0
    //至於每次都要更新max的原因為可能遇到躺分仔 ex:[2,1,-5] ,若最後才更新會剩0而已
    
    for(int i=0;i<numsSize;++i)
    {
        curr=curr>0?curr+nums[i]:nums[i];
        max=max>curr?max:curr;
    }
    return max;
}
