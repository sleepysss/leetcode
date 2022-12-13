//method 1

class Solution {
public:

    int max(int a,int b)
    {
        return a>b?a:b;
    }

    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(),nums.end()); //必須
        unordered_map<int,int> m;
        vector<int> v1;

        for(int i=0;i<nums.size();++i)
        {
            if(m.count(nums[i])) //exist in map
                m[nums[i]]=m[nums[i]]+nums[i];
            else //does not exist in map
            {
                m[nums[i]]=nums[i];
                v1.push_back(nums[i]);
            }
        }

        if(v1.size()==1) //for case: [1,1],不會有v1[1]
            return m[v1[0]];

        vector<int> store(v1.size()); //store[i]:index 0~i能得到的最多points
        store[0]=m[v1[0]];

        //核心概念和House Robber一樣,若相鄰則不能搶,所以先判斷和前一個是否差1
        if((v1[1]-v1[0])==1) //相鄰->和 House Robber 一樣方法 ex:[3,4] ,不用abs因為已經sort過
            store[1]=max(m[v1[0]],m[v1[1]]);
        else //不相鄰->前一個能拿到的最多(store[i-1])+這個數字能拿到的points ex:[3,5]
            store[1]=m[v1[0]]+m[v1[1]];

        for(int i=2;i<v1.size();++i)
        {
            if((v1[i]-v1[i-1])==1)
                store[i]=max(store[i-1],store[i-2]+m[v1[i]]);
            else
                store[i]=store[i-1]+m[v1[i]];
        }
        
        return store[v1.size()-1];
    }
};

//method 2

class Solution {
public:

    int max(int a,int b)
    {
        return a>b?a:b;
    }

    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(),nums.end()); //必須
        unordered_map<int,int> m;
        int biggest;  //biggest value in nums
        
        for(int i=0;i<nums.size();++i)
        {
            if(m.count(nums[i])) //exist in map
                m[nums[i]]=m[nums[i]]+nums[i];
            else //does not exist in map
            {
                m[nums[i]]=nums[i];
                biggest=nums[i];
            }
        }
        vector<int> store(biggest+1);  //store[i]:index 0~i biggest
        if(m.size()==1)
            return m[biggest];
        store[1]=m.count(1)?m[1]:0;
        if(m.count(2))
            store[2]=max(store[1],m[2]);
        else
            store[2]=store[1];

        for(int i=3;i<=biggest;++i)
            store[i]=m.count(i)?max(store[i-1],store[i-2]+m[i]):store[i-1];

        return store[biggest];
    }
};
