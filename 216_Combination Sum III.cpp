class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(9,0);
        get_ans(k,n,used,path,ans,1);
        return ans;
    }

    void get_ans(int k,int n,vector<bool> &used,vector<int> &path,vector<vector<int>> &ans,int index)
    {
        if(!n&&!k)
        {
            ans.push_back(path);
            return;
        }
        if(n<1||!k)
            return;

        for(int i=index;i<=9;++i)
        {
            if(!used[i-1])
            {
                path.push_back(i);
                used[i-1]=1;
                get_ans(k-1,n-i,used,path,ans,i+1);
                used[i-1]=0;
                path.pop_back();
            }
        }
    }
};
