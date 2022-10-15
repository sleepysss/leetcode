int minSubArrayLen(int target, int* nums, int numsSize){
    
    int count,total,min_count=numsSize+1;
    for(int i=0;i<numsSize;++i)
    {
        count=0;
        total=0;
        for(int j=i;j<numsSize;++j)
        {
            if(total<target)
            {
                total+=nums[j];
                count++;
            }
            else
                break;
        }
        
        if(total>=target)
        {
            if(count<min_count)
                min_count=count;
        }
        else
            break; 
    }
    
    return min_count==numsSize+1?0:min_count;
}
