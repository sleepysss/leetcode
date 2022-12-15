class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int max=values[0]+0,ans=0;  //max:记录之前出现过的 A[i] + i 的最大值
        for(int j=1;j<values.size();++j)
        {
            ans=max+values[j]-j>ans?max+values[j]-j:ans; //試試是否比已知ans更大
            max=values[j]+j>max?values[j]+j:max;
        }   
        return ans;
    }
};
