/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//method1
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    
    int *store=(int *)malloc(sizeof(int)*2);
    int left=0,right=numsSize,mid;
    *returnSize=2;
    
    if(!numsSize)
    {
        store[0]=-1;
        store[1]=-1;
        return store;
    }
    
    //目標:在 array 中，找到 >= target 的元素裡面，最小的那個的 index
    while(left<right)
    {
        mid=left+(right-left)/2; 
        if(nums[mid]>=target)
            right=mid;
        else
            left=mid+1;
    }
    
    if(left>(numsSize-1))   //因為有可能array中每個都比target小,這樣導致最小的那個index超過array的範圍
        store[0]=-1;
    else
        store[0]=(nums[left]==target)?left:-1;
        
    //目標:在 array 中，找到 > target 的元素裡面，最小的那個的 index , 然後再把該index-1在經過對比就可拿到target所在的最後位置
    left=0;
    right=numsSize;
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]>target)
            right=mid;
        else
            left=mid+1;
    }
    
    if(!left)  //因為有可能array中每個都比target大,導致最小的那個index為0
        store[1]=-1;
    else
        store[1]=(nums[left-1]==target)?left-1:-1;
    return store;

}


//method2 ver1
int find_first(int *nums,int numsSize,int target)
{
    int left=0,right=numsSize-1,mid,firstpos=numsSize;   //用個變數firstpos來記可能的答案  firstpos用非numsSize會出錯,ex:使用-1 [1] target:1,在store[1]那邊會得到-1,但應該是0才對(因為target會+1)
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        
        if(nums[mid]>=target)
        {
            firstpos=mid;
            right=mid-1;
            
        }
        else
            left=mid+1;
    }
    return firstpos;
    
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    
    int *store=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    
    store[0]=find_first(nums,numsSize,target);
    store[1]=find_first(nums,numsSize,target+1)-1;  //8的最後一個,可以想成>=9扣1
    if(store[0]<=store[1])
    {
        return store;
    }
    else    //利用 store[1]有多扣1這個特性來防止都找不到時store[0]和store[1]會一樣,也可防止完全沒有,ex:[7 8 12] target:10
    {
        store[0]=-1;
        store[1]=-1;
    }
    return store;
    
}


//method2 ver2
int find_first(int *nums,int numsSize,int target)
{
    int left=0,right=numsSize-1,mid,firstpos=numsSize;   //用個變數firstpos來記可能的答案
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        
        if(nums[mid]>=target)
        {
            firstpos=mid;
            right=mid-1;
            
        }
        else
            left=mid+1;
    }
    return firstpos;
    
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    
    int *store=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    
    store[0]=find_first(nums,numsSize,target);
    if(store[0]==numsSize||nums[store[0]]!=target)  //firstpos exist and same as target
    {
        store[0]=-1;
        store[1]=-1;
        return store;
    }
    store[1]=find_first(nums,numsSize,target+1)-1;  //8的最後一個,可以想成>=9扣1  不用做檢查是因為store0(131行)已經檢查過了
    return store;
    
}


