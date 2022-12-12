//method 1 : naive brute force

class Solution {
public:

    int helper(vector<int>& nums,int start,int end) //start,end :搶的範圍
    {
        if(start==end)
            return nums[start];
        if(start>end)
            return 0;
        int biggest=0;

        for(int i=start;i<=end;++i)
        {
            int temp=nums[i]+helper(nums,i+2,end);
            if(temp>biggest)
                biggest=temp;
        }
        return biggest;
    }

    int rob(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);   //helper:某範圍內能搶到的最多錢
    }
};

//method 2 : naive recursive

//max = Max( 現在這棟 + 前前一棟可以拿到的最大金額 , 前一棟可以拿到的最大金額 )

class Solution {
public:

    int helper(vector<int>& nums,int last)
    {
        if(last==0)
            return nums[0];
        else if(last==1)
            return nums[0]>nums[1]?nums[0]:nums[1];

        return nums[last]+helper(nums,last-2)>helper(nums,last-1)?nums[last]+helper(nums,last-2):helper(nums,last-1);
    }

    int rob(vector<int>& nums) {
        return helper(nums,nums.size()-1);
    }
};


//method 3 : DP (method 2 改為DP)

class Solution {
public:

    int max(int a,int b)
    {
        return a>b?a:b;
    }

    int rob(vector<int>& nums) {

        if(nums.size()==1)
            return nums[0];

        vector<int> store(nums.size());   //store[i]:index 0~i能搶到的最多錢

        store[0]=nums[0];
        store[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();++i)
            store[i]=max(store[i-1],store[i-2]+nums[i]); //i不搶(store[i-1])或i搶+store[i-2]

        return store[nums.size()-1];
    }
};
