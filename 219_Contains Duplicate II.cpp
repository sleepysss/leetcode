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

//method 2 : hash table (用hash table來檢查是否已在裡面(效率為O(1),比慢慢一個一個比O(n)好))

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int> m; //key-value:值-index

        for(int i=0;i<nums.size();++i)
        {
            if((m.count(nums[i]))&&(i-m[nums[i]]<=k)) //值一樣，且索引值之差 ≦ k
                return true;

            m[nums[i]]=i;
        }
        return false;
    }
};


//method 3 : hash table + sliding window

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        //maintain 一個fixed size的sliding window,size為k+1

        unordered_map<int,int> m;
        
        //init
        for(int i=0;i<=k&&i<nums.size();++i)
        {
            if(m.count(nums[i]))
                return true;
            m[nums[i]]=i;
        }

        for(int i=k+1;i<nums.size();++i)
        {
            m.erase(nums[i-k-1]); //window往右一格
            if(m.count(nums[i]))
                return true;
            m[nums[i]]=i;
        }
        return false;
    }
};

