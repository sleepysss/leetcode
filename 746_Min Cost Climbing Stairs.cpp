//method 1 : naive recursive ...TLE

class Solution {
public:

    int min(int a,int b)
    {
        return a<b?a:b;
    }

    int helper(vector<int>& cost,int size)
    {
        if(size<2)
            return 0;

        return min(helper(cost,size-1)+cost[size-1],helper(cost,size-2)+cost[size-2]);

    }

    int minCostClimbingStairs(vector<int>& cost) {

        return helper(cost,cost.size());
        
    }
};

//method 2 : DP

class Solution {
public:

    int min(int a,int b)
    {
        return a<b?a:b;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> store(cost.size()+2); //store[i]:爬到第i階的mincost
        store[1]=0;
        store[2]=0;
        for(int i=3;i<=cost.size()+1;++i)
            store[i]=min(store[i-1]+cost[i-2],store[i-2]+cost[i-3]);

        return store[cost.size()+1];
    }
};
