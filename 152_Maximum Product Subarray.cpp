class Solution {
public:

    int MAX(int a,int b)
    {
        return a>b?a:b;
    }
    int MIN(int a,int b)
    {
        return a<b?a:b;
    }
    int maxProduct(vector<int>& nums) {
        int min=nums[0],max=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<0)
            {
                int temp=max;
                max=min;
                min=temp;
            }
            max=MAX(nums[i],max*nums[i]);
            min=MIN(nums[i],min*nums[i]);
            ans=MAX(max,ans);
        }
        return ans;
    }
};
