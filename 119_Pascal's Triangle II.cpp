class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> store;

        for(int i=1;i<=rowIndex;++i)
        {
            store.clear();
            store.push_back(1); 
            for(int j=1;j<i;++j)
                store.push_back(ans[i-1][j-1]+ans[i-1][j]);
            store.push_back(1);
            ans.push_back(store);
        }
        return ans[rowIndex];
    }
};
