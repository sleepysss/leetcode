class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> store;

        for(int i=2;i<=numRows;++i)
        {
            store.clear();
            store.push_back(1); 
            for(int j=1;j<i-1;++j)
                store.push_back(ans[i-2][j-1]+ans[i-2][j]);
            store.push_back(1);
            ans.push_back(store);
        }
        return ans;
    }
};
