//method 1

void moveZeroes(int* nums, int numsSize){
    
    int j=-1; //last index of target array
    
    for(int i=0;i<numsSize;++i)
    {
        if(nums[i]==0)
            continue;
        else
            nums[++j]=nums[i];
    }
    
    for(int i=j+1;i<numsSize;++i)
        nums[i]=0;
}



// method 2

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

// method 3

void moveZeroes(int* nums, int numsSize){
    
    //lomuto
    
    int j=-1; //非0的數字所形成的數列的最後位置
    int temp;
    
    for(int i=0;i<numsSize;++i)
    {
        if(nums[i]!=0)
        {
            j++;
            temp=nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            
        }  
    }
}
