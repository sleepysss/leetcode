int removeDuplicates(int* nums, int numsSize){
    
    
    int j=0; //想要的array最後的位置(目前存放哪個位置)
    
    //traverse all the array
    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]==nums[j])
            continue;
        else
            nums[++j]=nums[i]; //挑想要的(不重複的)放進去array中
    }
    
    return j+1;
}
