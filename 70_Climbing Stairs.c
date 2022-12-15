//method 1 : Bottom-Up DP

int climbStairs(int n){
    //費氏數列  
    //因为每次只能爬1或2步，那么爬到第n层的方法要么是从第 n-1 层一步上来的，要不就是从 n-2 层2步上来的
  
    int *store=(int *)malloc(sizeof(int)*(n+1)),back;
    store[0]=1;
    store[1]=1;
    
    for(int i=2;i<n+1;++i)
        store[i]=store[i-1]+store[i-2];
    
    back=store[n];
    free(store);
    return back;
}


//method 2 : Top-Down DP

class Solution {
public:
    int helper(int n,vector<int> &store)  //到該step的方法數
    {
        if(store[n])
            return store[n];
        else
        {
            store[n]=helper(n-1,store)+helper(n-2,store);
            return store[n];
        }
    }

    int climbStairs(int n) {
        vector<int> store(n+1);
        store[0]=1;
        store[1]=1;
        return helper(n,store);
    }
};
