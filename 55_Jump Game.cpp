//method 1 : naive recursive  ...TLE

public:

    bool helper(vector<int>& nums,int index)
    {
        if(index==nums.size()-1)
            return true;
        if(index>=nums.size())
            return false;

        for(int i=1;i<=nums[index];++i)
        {
            if(helper(nums,index+i))
                return true;
        }
        return false;
    }


    bool canJump(vector<int>& nums) {

        return helper(nums,0); 
    }
};

//method 2 : DP ...TLE

class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<int> store(nums.size()); //到每個點的可能性

        store[0]=1;
        //從 index 0，也就是起點開始，每一個位置都更新一輪 store[]
        for(int i=0;i<nums.size()-1;++i)
        {
            if(!store[i]) //不會到那位置
                continue;
            for(int j=1;(j+i)<nums.size()&&j<=nums[i];++j)
                store[i+j]=1;
        }
        return store[nums.size()-1];
    }
};


//method 3 : DP

class Solution {
public:
    bool canJump(vector<int>& nums) {
    
        vector<bool> store(nums.size()); //store[i]:可否從index i到最後一個index
        store[store.size()-1]=true;
        for(int i=nums.size()-2;i>=0;--i)
        {
            for(int j=i+1;j<=nums[i]+i;++j)
            {
                if(store[j])
                {
                    store[i]=true;
                    break;
                }
            }
        }
        return store[0];
    }
};
