//method 1 : brute force ... TLE
int minSubArrayLen(int target, int* nums, int numsSize){
    
    int count,total,min_count=numsSize+1;
    for(int i=0;i<numsSize;++i) //traverse every num
    {
        count=0;
        total=0;
        for(int j=i;j<numsSize;++j) //candiadate of subarr
        {
            if(total<target) //add
            {
                total+=nums[j];
                count++;
            }
            else
                break;
        }
        
        if(total>=target) //we need this because total may smaller than target 
        {
            if(count<min_count) //smaller than smallest
                min_count=count;
        }
        else //有num[i]都小於目標了,後面沒num[i]更不可能>=目標(因為<目標會一直加直到數列尾)
            break; 
    }
    
    return min_count==numsSize+1?0:min_count;
}

// method 2 : sliding window
int minSubArrayLen(int target, int* nums, int numsSize){
    
    int l=0,r=0,sum=0,min_len=numsSize+1;
    
    for(int r=0;r<numsSize;++r)
    {
        sum+=nums[r];
        
        while(sum>=target)
        {
            min_len=min_len>(r-l+1)?r-l+1:min_len;
            sum-=nums[l];
            l++;
        }
    }
    return min_len==numsSize+1?0:min_len;
}
