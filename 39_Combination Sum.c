/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combinationSum_helper(int *candidates,int candidatesSize,int target,int *helper_total_addr,int *helper_index_addr,int **store,int *where_addr,int *return_arr,int *helper,int start) //start:可選的開始
{
    if((*helper_total_addr)==target)
    {
        return_arr[(*where_addr)]=(*helper_index_addr);
        store[(*where_addr)]=(int *)malloc(sizeof(int)*(*helper_index_addr));
        for(int i=0;i<(*helper_index_addr);++i)
            store[(*where_addr)][i]=helper[i];
        (*where_addr)++;
        return;
    }
    else if((*helper_total_addr)>target)
    {
        return;
    }
    
    for(int i=start;i<candidatesSize;++i) //[2 2 3] 和 [3 2 2] 視為同一個,所以要有start這個東西
    {
        helper[(*helper_index_addr)++]=candidates[i];
        (*helper_total_addr)+=candidates[i];
        
        combinationSum_helper(candidates,candidatesSize,target,helper_total_addr,helper_index_addr,store,where_addr,return_arr,helper,i);
        
        (*helper_index_addr)--;
        (*helper_total_addr)-=candidates[i];
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **store=(int **)malloc(sizeof(int *)*150), **store1;  //store[]最多只會有150列(題目給的)
    for(int i=0;i<150;++i) //初始化,好方便之後算實際究竟有幾個
        store[i]=NULL;
    int where=0,helper_index=0,index=0,helper_total=0;
    int *helper=(int *)malloc(sizeof(int)*150), *return_arr2; //每列最多20個數字 (40/2=20)
    int *return_arr=(int *)malloc(sizeof(int)*150);
    
    
    combinationSum_helper(candidates,candidatesSize,target,&helper_total,&helper_index,store,&where,return_arr,helper,0);
    
    //算實際數量
    for(int i=0;i<150;++i)
    {
        if(store[i]==NULL)
        {
            *returnSize=i;
            return_arr2=realloc(return_arr,sizeof(int)*i);
            store1=realloc(store,sizeof(int *)*i);
            break;
        }  
    }
    *returnColumnSizes=return_arr2;
    return store1;
}





//和上面寫法一樣,只是helper_total和helper_index改成call by value
//helper_total和helper_index可以不用pass by addr,但where一定要

void combinationSum_helper(int *candidates,int candidatesSize,int target,int helper_total,int helper_index,int **store,int *where_addr,int *return_arr,int *helper,int start) //start:可選的開始
{
    if(helper_total==target)
    {
        return_arr[(*where_addr)]=helper_index;
        store[(*where_addr)]=(int *)malloc(sizeof(int)*helper_index);
        for(int i=0;i<helper_index;++i)
            store[(*where_addr)][i]=helper[i];
        (*where_addr)++;
        return;
    }
    else if(helper_total>target)
    {
        return;
    }
    
    for(int i=start;i<candidatesSize;++i) //[2 2 3] 和 [3 2 2] 視為同一個,所以要有start這個東西
    {
        helper[helper_index++]=candidates[i];
        helper_total+=candidates[i];
        
        combinationSum_helper(candidates,candidatesSize,target,helper_total,helper_index,store,where_addr,return_arr,helper,i);
        
        helper_index--;
        helper_total-=candidates[i];
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **store=(int **)malloc(sizeof(int *)*150), **store1;  //store[]最多只會有150列(題目給的)
    for(int i=0;i<150;++i) //初始化,好方便之後算實際究竟有幾個
        store[i]=NULL;
    int where=0,helper_index=0,index=0,helper_total=0;
    int *helper=(int *)malloc(sizeof(int)*150), *return_arr2; //每列最多20個數字 (40/2=20)
    int *return_arr=(int *)malloc(sizeof(int)*150);
    
    
    combinationSum_helper(candidates,candidatesSize,target,helper_total,helper_index,store,&where,return_arr,helper,0);
    
    //算實際數量
    for(int i=0;i<150;++i)
    {
        if(store[i]==NULL)
        {
            *returnSize=i;
            return_arr2=realloc(return_arr,sizeof(int)*i);
            store1=realloc(store,sizeof(int *)*i);
            break;
        }  
    }
    *returnColumnSizes=return_arr2;
    return store1;
}



//C++ ver

class Solution {
public:

    void get_ans(vector<int>& candidates,int target,vector<int>& path,vector<vector<int>>& ans,int index)
    {
        if(target==0)
        {
            ans.push_back(path);
            return;
        }
        else if(target<0)
            return;
            
        for(int i=index;i<candidates.size();++i)
        {
            if(target>=candidates[i])
            {
                path.push_back(candidates[i]);
                target-=candidates[i];
                get_ans(candidates,target,path,ans,i);
                target+=candidates[i];
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        int index=0;
        get_ans(candidates,target,path,ans,index);
        return ans;
    }
};
