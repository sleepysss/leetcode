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
    if(store[0]==numsSize||nums[store[0]]!=target)  //check firstpos exist and same as target
    {
        store[0]=-1;
        store[1]=-1;
        return store;
    }
    store[1]=find_first(nums,numsSize,target+1)-1;  //8的最後一個,可以想成>=9扣1  不用做檢查是因為store0(131行)已經檢查過了
    return store;
    
}

//method3

//for solving binary search problems is to set the start and the end on the elements, not outside of the array.
//The key point in solving binary search problems (and many other loop-based solutions) is a set of good invariants.
//int start = 0; 
//int end = a.length - 1; 
//Now the invariant. The array right now we have is [start, end]. We don't know anything yet about the elements. 
//All of them might be greater than the target, or all might be smaller, or some smaller and some larger. 
//So we can't make any assumptions so far about the elements. 
//Our goal is to find the first element greater than the target. So we choose the invariants like this:

//Any element to the right of the end is greater than the target.
//Any element to the left of the start is smaller than or equal to the target.

//We can easily see that our invariant is correct at the start (ie before going into any loop). 
//All the elements to the left of the start (no elements basically) are smaller than or equal to the target, same reasoning for the end.


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    int *store=(int *)malloc(sizeof(int)*2);
    int left=0,right=numsSize-1,mid;
    store[0]=-1;
    store[1]=-1;
    *returnSize=2;
    
    if(!numsSize)
        return store;
    
    while(left<=right)
    {
        mid=left+(right-left)/2; 
        if(nums[mid]>=target)
            right=mid-1;
        else
            left=mid+1;
    }
    if(left==numsSize||nums[left]!=target)  //最小的target不在範圍內or取到的只有>,沒有=
        return store;
    else
        store[0]=left;
    
    left=0;
    right=numsSize-1;
    while(left<=right)
    {
        mid=left+(right-left)/2; 
        if(nums[mid]>target)
            right=mid-1;
        else
            left=mid+1;
    }
    store[1]=left-1;
    
    return store;
}

//method 4
    
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bsearch1(int *nums,int numsSize,int target). // >=的第一個
{
    int left=0,right=numsSize-1,mid,flag=0;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]<target)
            left=mid+1;
        else if(nums[mid]>target)
            right=mid-1;
        else
        {
            right=mid-1;
            flag=1; //確認有碰到target,或者回去再比較也行
        }
    }
    return flag?left:-1;
    
}

int bsearch2(int *nums,int numsSize,int target) //>=原本target的第一個,不用去管會不會碰到因為bsearch1有用
{
    int left=0,right=numsSize-1,mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    int *ptr=(int *)malloc(sizeof(int)*2);
    ptr[0]=bsearch1(nums,numsSize,target);  //找>=target的第一個,且比較是否有碰到
    if(ptr[0]==-1)
        ptr[1]=-1;
    else
        ptr[1]=bsearch2(nums,numsSize,target+1)-1; //找>=target+1的第一個再扣回去
    
    *returnSize=2;
    return ptr;
}



