//method 1:

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

//method 2 : method1 1改成DP

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
        
        vector<int> store1(nums.size()); //store1[i]:max product subarr ends with index i
        vector<int> store2(nums.size()); //store2[i]:min product subarr ends with index i
        int max=nums[0];
        store1[0]=store2[0]=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<0) //反過來
            {
                store1[i]=MAX(nums[i],nums[i]*store2[i-1]);
                store2[i]=MIN(nums[i],nums[i]*store1[i-1]);
            }
            else
            {
                store1[i]=MAX(nums[i],nums[i]*store1[i-1]);
                store2[i]=MIN(nums[i],nums[i]*store2[i-1]);
            }   
            max=max>store1[i]?max:store1[i];
        }
        return max;
    }
};
