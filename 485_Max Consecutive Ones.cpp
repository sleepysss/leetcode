class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans=0,count=0;

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==1)
                count++;
            else
            {
                ans=count>ans?count:ans;
                count=0;
            }
        }

        ans=count>ans?count:ans; //for all 1
        return ans;
    }
    
};
