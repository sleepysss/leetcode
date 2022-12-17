//method 1 : brute force
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        if(nums.size()<3) //at least three elements
            return 0;
        int count=0;
        for(int i=0;i<nums.size()-2;++i)
        {
            for(int j=i+2;j<nums.size();++j)
            {
                if(nums[j]-nums[j-1]==nums[j-1]-nums[j-2])
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};


//method 2 : DP

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        if(nums.size()<3) //at least three elements
            return 0;
        vector<int> store(nums.size()); //store[i]:比store[i-1]多幾個
        int count=0;
        
        for(int i=2;i<nums.size();++i)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                store[i]=store[i-1]+1;
            count+=store[i]; //因為是多幾個,所以是加總起來
        }
        return count;
    }
};
