/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int pow2(int num)
{
    int store=1;
    for(int i=1;i<=num;++i)
        store*=2;
    return store;
}

void subset_helper(int *nums,int numsSize,int index,int *where_addr,int *helper,int *helper_index_addr,int *return_arr,int **store)
{
    //this time let us loop over the length of combination, rather than the candidate numbers, 
    //and generate all combinations for a given length with the help of backtracking technique.
    
    
    if(index==numsSize)  
    {
        return_arr[(*where_addr)]=(*helper_index_addr);
        store[(*where_addr)]=(int *)malloc(sizeof(int)*(*helper_index_addr)); //因為不確定會有幾個選'要',所以不一開始malloc
        for(int i=0;i<(*helper_index_addr);++i)
            store[(*where_addr)][i]=helper[i];
        (*where_addr)++;
        return;
    }
    for(int i=0;i<=1;++i) //choose or not choose
    {
        if(i==0) //choose
        {
            helper[(*helper_index_addr)++]=nums[index];
            subset_helper(nums,numsSize,index+1,where_addr,helper,helper_index_addr,return_arr,store);
            (*helper_index_addr)--;
        }
        else //not choose (not choose wont add anything to store,so it does not need to revert)
            subset_helper(nums,numsSize,index+1,where_addr,helper,helper_index_addr,return_arr,store);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int x=pow2(numsSize);
    int **store=(int **)malloc(sizeof(int *)*x);
    //index:the index of nums[] we are going to add/not add to store
    int where=0,helper_index=0,index=0; //where:紀錄store[]到哪了,helper_index:紀錄helper[]到哪了
    int *helper=(int *)malloc(sizeof(int)*(numsSize)), *return_arr=(int *)malloc(sizeof(int)*x); //return_arr[]用來記錄某列有幾個
    
    *returnSize=x;
    subset_helper(nums,numsSize,index,&where,helper,&helper_index,return_arr,store);
    *returnColumnSizes=return_arr;
    return store;
}



//C++ ver.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> path;
        get_ans(nums,0,path,ans,0);
        return ans;
    }

    void get_ans(vector<int>& nums,int index,vector<int>& path,vector<vector<int>>& ans,int count)
    {
        if(count==nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i=index;i<nums.size();++i)
        {
            //choose
            path.push_back(nums[i]);
            count++;
            get_ans(nums,i+1,path,ans,count); 
            count--;
            path.pop_back();

            //not choose
            count++;
            get_ans(nums,i+1,path,ans,count); 
            count--;
        }
    }
};


//C++ method 2

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        get_ans(nums,0,ans,path);
        return ans;
    }

    void get_ans(vector<int> &nums,int index, vector<vector<int>> &ans, vector<int> &path)
    {
        ans.push_back(path);
        for(int i=index;i<nums.size();++i)
        {
            path.push_back(nums[i]);
            get_ans(nums,i+1,ans,path);
            path.pop_back();
        }
    }
};
