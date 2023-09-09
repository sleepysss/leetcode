/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//mathod 1: brute force
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int flag=0,i,j,store;
    
    for(i=0;i<numsSize;++i)
    {
        store=target;
        store-=nums[i];
        for(j=i+1;j<numsSize;++j) //不用重0開始,因為答案必在i之後
        {
            if(nums[j]==store)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    int *Store=(int *)malloc(sizeof(int)*2);
    Store[0]=i;
    Store[1]=j;
    *returnSize=2;
    return Store;
}

//method 2: hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int,int> m1={{nums[0],0}};
        for(int i=1;i<nums.size();++i)
        {
            if(m1.find(target-nums[i])!=m1.end())
            {
                ans={m1[target-nums[i]],i};
                return ans;
            }
            else
                m1[nums[i]]=i;
        }  
        return ans; 
    }
};
