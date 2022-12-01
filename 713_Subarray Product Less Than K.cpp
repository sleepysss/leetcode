//method 1-1

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int count=0,sum=1;
        int left=0,right=0;

        if(k<=1) //因為 1 <= nums[i] <= 1000 且 為strictly less than k , 所以k<=1不可能會有subarray
            return 0;

        for(right=0;right<nums.size();++right)
        {
            sum*=nums[right];
            
            while(sum>=k)
            {
                sum/=nums[left];
                left++;
            }
            count+=(right-left+1); 
        }
        return count;
    }
};


//method 1-2

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int count=0,sum=1;
        int left=0,right=0;

        /*if(k<=1) 
            return 0;*/

        for(right=0;right<nums.size();++right)
        {
            sum*=nums[right];
            
            while(left<=right&&sum>=k)
            {
                sum/=nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
};
