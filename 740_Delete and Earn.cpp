class Solution {
public:

    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int abs(int a,int b)
    {
        return a>b?a-b:b-a;
    }

    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        //mapping (選某個值可拿到多少points)
        unordered_map<int,int> m;
        vector<int> v1;
        int sum=nums[0];
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]==nums[i+1]) //和後一個一樣
            {
                sum+=nums[i];
                if(i==nums.size()-2) //traverse到最後了
                {
                    m[nums[i]]=sum;
                    v1.push_back(nums[i]);
                }
            }
            else //和後一個值不一樣
            {
                m[nums[i]]=sum;
                sum=nums[i+1];
                v1.push_back(nums[i]);
                if(i==nums.size()-2)  //traverse到最後了
                {
                    m[nums[i+1]]=nums[i+1];
                    v1.push_back(nums[i+1]);
                }
            }
        }
        if(v1.size()==0)  //for case: [1],不會有v1[0]...
            return nums[0];
        if(v1.size()==1) //for case: [1,1],不會有v1[1]...
            return m[v1[0]];

        vector<int> store(v1.size()); //store[i]:index 0~i能得到的最多points
        store[0]=m[v1[0]];

        //核心概念和House Robber一樣,若相鄰則不能搶,所以先判斷和前一個是否是相鄰的
        if(abs(v1[0],v1[1])==1) //相鄰->和 House Robber 一樣方法 ex:[3,4]
            store[1]=max(m[v1[0]],m[v1[1]]);
        else //不相鄰->前一個能拿到的最多(store[i-1])+這個數字能拿到的points ex:[3,5]
            store[1]=m[v1[0]]+m[v1[1]];

        for(int i=2;i<v1.size();++i)
        {
            if(abs(v1[i],v1[i-1])==1)
                store[i]=max(store[i-1],store[i-2]+m[v1[i]]);
            else
                store[i]=store[i-1]+m[v1[i]];
        }
        
        return store[v1.size()-1];
    }
};
