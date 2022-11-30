//method 1

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {


        for(int i=0;i<nums.size();++i)
            nums[i]=nums[i]*nums[i];
        sort(nums.begin(),nums.end());

        return nums;
    }
};

//method 2-1

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left=0,right=nums.size()-1; 
        vector<int> store(nums);

        for(int i=store.size()-1;i>=0;--i)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                store[i]=nums[left]*nums[left];
                left++;
            }
            else
            {
                store[i]=nums[right]*nums[right];
                right--;
            }
        }

        return store;
    }
};

//method 2-2

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int left=0,right=nums.size()-1,pos=nums.size()-1; 
        vector<int> store(nums);

        while(left<=right)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                store[pos--]=nums[left]*nums[left];
                left++;
            }
            else
            {
                store[pos--]=nums[right]*nums[right];
                right--;
            }
        }

        return store;
    }
};
