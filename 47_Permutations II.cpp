class Solution {
public:
    void permutation2_helper(vector<int> &nums, vector<bool> &visited, vector<int> &store, vector<vector<int>> &ans)
    {
        if(store.size()==nums.size())
        {
            ans.push_back(store);
            return;
        }

        for(int i=0;i<nums.size();++i)
        {
            if(i!=0&&(nums[i]==nums[i-1])&&(visited[i-1]))
                continue;
            if(!visited[i])
            {
                visited[i]=1;
                store.push_back(nums[i]);
                permutation2_helper(nums,visited,store,ans);
                store.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(),0);
        vector<int> store;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        permutation2_helper(nums,visited,store,ans);
        return ans;
        
    }
};


//c++ ver.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> checked(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> path;
        get_ans(nums,ans,checked,path);
        return ans;
    }

    void get_ans(vector<int> &nums,vector<vector<int>> &ans,vector<int> &checked,vector<int> &path)
    {
        if(path.size()==nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();++i)
        {
            if(!checked[i])
            {
                if(i>0 && nums[i]==nums[i-1] && !checked[i-1])
                    continue;
                path.push_back(nums[i]);
                checked[i] = 1;
                get_ans(nums,ans,checked,path);
                checked[i] = 0;
                path.pop_back();
            }
        }
    }
};



