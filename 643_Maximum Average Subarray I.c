double findMaxAverage(int* nums, int numsSize, int k){
    
    int start=0,end=k-1,sum=0;
    double max_avg,avg;
    
    //init
    for(int i=0;i<k;++i)
    {
        sum+=nums[i];
    }
    max_avg=(double)sum/(double)k;
    
    while(end<numsSize-1) //because end+1 will overflow
    {
        //new window
        sum-=nums[start++];
        sum+=nums[++end];
        
        avg=(double)sum/(double)k;
        if(avg>max_avg)
            max_avg=avg;
    }
    
    return max_avg;
}
