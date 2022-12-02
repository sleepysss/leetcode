//method 1 : brute force ...TLE

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //k格內有兩個相等則為true
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;(j<i+k+1)&&(j<nums.size());++j)
            {
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;   
    }
};
