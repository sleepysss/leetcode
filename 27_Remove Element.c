int removeElement(int* nums, int numsSize, int val){
    
    int last=numsSize-1,tmp; //last:不是val的最後一個數的位址
   
    for(int i=0;i<=last;++i)
    {   
        while(last>=0&&nums[last]==val)  //全部都是val會導致爆掉 last變-1
            last--;
        if(last<=i) //全軍陣亡(接下來要比的那個也是val)或只剩一個
            break;
        
        if(nums[i]==val)
        {
            nums[i]=nums[last];  //switch
            nums[last--]=val;
        }    
    }
    
    return last+1;

}
