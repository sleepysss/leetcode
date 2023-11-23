//method 1 :  two pointer

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    int *store=(int *)malloc(sizeof(int)*2);
    int l=0,r=numbersSize-1;
    
    while(l<r)
    {
        if((numbers[l]+numbers[r])==target)
        {
            store[0]=l+1;
            store[1]=r+1;
            break;
        }
        else if((numbers[l]+numbers[r])<target)
            l++;
        else
            r--;
    }
    *returnSize=2;
    return store;
}

//method 2 : binary search

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    //想法:列舉每個索引i作為index1，對其右方的數字做二分搜，找出target扣掉numbers[i]後還需要的值n
    
    int left,right,mid,num=target,flag=0;
    int *store=(int *)malloc(sizeof(int)*2);
    
    for(int i=0;i<numbersSize;++i)
    {
        //binary search
        num=target-numbers[i]; //target of binary search
        left=i+1;
        right=numbersSize-1;
        
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(numbers[mid]==num)
            {
                store[0]=i+1;
                store[1]=mid+1;
                flag=1;
                break;
            }
            else if(numbers[mid]>num)
                right=mid-1;
            else
                left=mid+1;
        }
        if(flag)
            break; 
    }
    *returnSize=2;
    return store;
}




//c++ ver

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int start=0,end=numbers.size()-1;
        vector<int> ans;

        while(start<=end)
        {
            if(numbers[start]+numbers[end]>target)
                end--;
            else if(numbers[start]+numbers[end]<target)
                start++;
            else
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
        } 
        return ans;   
    }
};
