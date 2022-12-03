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

//method 2 : hash table

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();++i)
        {
            if((m.count(nums[i]))&&(i-m[nums[i]]<=k)) //用hash table來檢查是否已在裡面(效率為O(1),比慢慢一個一個比O(n)好)
                return true;

            m[nums[i]]=i;
        }
        return false;
    }
};
