int missingNumber(int* nums, int numsSize){
    
    //xor符合交換率
    //A^A=0
    //A^0=A
    //想法為[0,n]的數字除了少了的那個其他都被traverse到兩次,所以最後只會剩少了的那個
    
    int num=0;
    
    for(int i=0;i<=numsSize;++i)
        num^=i;
    
    for(int i=0;i<numsSize;++i)
        num^=nums[i];
    
    return num;
}
