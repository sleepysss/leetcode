//method 1 : hash table

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();++i)
        {
            if(m.count(nums[i]))
                return true;
            m[nums[i]]=i;
        }
        return false;
    }
};


//method 2 : sorting

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        //先將 array 中的數字按大小排序，這樣只需要用一個loop比較自己跟自己身邊的數字就可以，不需要比較鄰居以外的地方
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};
