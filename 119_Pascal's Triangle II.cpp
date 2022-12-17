// method 1

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

// method 2

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int temp1,temp2;
        vector<int> ans(rowIndex+1);
        ans[0]=1;
        for(int i=1;i<=rowIndex;++i)
        {
            temp2=1; //init
            for(int j=1;j<i;++j)
            {
                temp1=ans[j]; //curr
                ans[j]=temp2+temp1;
                temp2=temp1; //pre
            }
            ans[i]=1;
        }
        return ans;
    }
};
