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
    
    int curr=0,max=-10001; //curr:curr's maxSubArray'
    
    //對於每個點來說,看看前人加上他後的值會不會比自己從新當頭來的好
    //ex: [-2,1]
    //對於1來說 -2+1 < 1 ,那我就從我自己開始新的探險,即:curr改為1 (不要帶拖油瓶)
    //curr=curr+nums[i]>nums[i] 等同 curr>0
    //至於每次都要更新max的原因為可能遇到躺分仔 ex:[2,1,-5] ,若最後才更新會剩-2而已(先組一隊,看未來的隊友強不強 ex:[2,3,-2,9999999])
    
    for(int i=0;i<numsSize;++i)
    {
        curr=curr>0?curr+nums[i]:nums[i];
        max=max>curr?max:curr;
    }
    return max;
}

//method 3 : DP (based on method 2)

int maxSubArray(int* nums, int numsSize){
    
    //store[i]: maxSubArray(from 0 to i)
    int *store=(int *)malloc(sizeof(int)*numsSize),max;
    
    store[0]=nums[0];
    max=store[0];
    
    for(int i=1;i<numsSize;++i)
    {
        store[i]=store[i-1]>0?store[i-1]+nums[i]:nums[i];
        max=max>store[i]?max:store[i];
    }
    return max;
}
