//method 1

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        //解法和best time to buy and sell stock 類似

        int max=values[0]+0,ans=0;  //max:记录之前出现过的 A[i] + i 的最大值
        for(int j=1;j<values.size();++j)
        {
            ans=max+values[j]-j>ans?max+values[j]-j:ans; //試試是否比已知ans更大
            max=values[j]+j>max?values[j]+j:max;
        }   
        return ans;
    }
};

//method 2 : method 1 改成DP版本

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        vector<int> store(values.size()); //store[i]: index 0~i中values[i]+i最大的
        store[0]=values[0]+0;
        int ans=0;
        for(int j=1;j<store.size();++j)
        {
            ans=values[j]-j+store[j-1]>ans?values[j]-j+store[j-1]:ans;
            store[j]=values[j]+j>store[j-1]?values[j]+j:store[j-1];
        }
        return ans;
    }
};
