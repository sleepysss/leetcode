//method 1 : 和39題一樣想法,但TLE

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combinationSum2_helper(int *candidates,int candidatesSize,int target,int helper_total,int helper_index,int **store,int *where_addr,int *return_arr,int *helper,int start) //start:可選的開始
{
    int flag;
    if(helper_total==target)
    {
        //check
        for(int i=0;i<(*where_addr);++i)
        {
            flag=1;
            if((helper_index==return_arr[i]))
            {
                flag=0;
                for(int j=0;j<helper_index;++j)
                {
                    if(helper[j]!=store[i][j])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
                return;
        }
        
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
        

            combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,where_addr,return_arr,helper,i+1);

            helper_index--;
            helper_total-=candidates[i];
            
            
    }
}

int Partition(int store[],int first, int last)
{
	int pivot = store[last];
	int i = first - 1,temp;  //i:小於pivot的數所形成的數列的最後位置

	for (int j = first; j < last; ++j) //traverse each element
	{
		if (pivot > store[j])    //過程類似找到小於pivot的數,就把他插到小於pivot的數所形成的數列的尾端  
		{
			i++;
			temp = store[i];
			store[i] = store[j];
			store[j] = temp;
		}
	}
	//做完上述步驟,整個數列會變成 <pivot >=pivot pivot  這時要將pivot插到中間來完成 <pivot pivot >=pivot
	i++;    
	temp = store[i];
	store[i] = pivot;
	store[last] = temp;

	return i; //pivot's index
}

void quicksort(int store[],int first,int last)
{
	if(first < last)  //因為這個條件,所以剩一個或沒有的會被自動擋掉
	{
		int pivot = Partition(store,first,last); //比pivot大於等於的都在pivot右邊,比pivot小的都在左邊,pivot固定住了
		quicksort(store, first, pivot - 1); //左排
		quicksort(store, pivot + 1, last); //右排
	}
}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **store=(int **)malloc(sizeof(int *)*300), **store1;  //
    for(int i=0;i<300;++i) //初始化,好方便之後算實際究竟有幾個
        store[i]=NULL;
    int where=0,helper_index=0,index=0,helper_total=0;
    int *helper=(int *)malloc(sizeof(int)*30), *return_arr2; //
    int *return_arr=(int *)malloc(sizeof(int)*300);
    
    quicksort(candidates, 0, candidatesSize-1);
    
    combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,&where,return_arr,helper,0);
    
    //算實際數量
    for(int i=0;i<300;++i)
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

//method 2 : 只改了combinationSum2_helper內的for的一部份和移除check

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combinationSum2_helper(int *candidates,int candidatesSize,int target,int helper_total,
                            int helper_index,int **store,int *where_addr,int *return_arr,int *helper,int start) //start:可選的開始
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
        //ex:[1 2 2 2] 5 如果沒下面那個if則會拿到三個[1 2 2],但這不被允許
        //解法為先對candidates做排序,且當前和當前的前一個不能同樣,經過這樣做後只會拿到第一個[1 2 2],其他都會被continue掉
        //因為數字一樣的關係,前面那個2已經把他後面那個2的所有可能都跑過ㄌ,要先排序的原因為要讓這些2相鄰好'方便管理'
        if((i>start)&&(candidates[i-1]==candidates[i])) 
            continue;
        helper[helper_index++]=candidates[i];
        helper_total+=candidates[i];
        

        combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,where_addr,return_arr,helper,i+1); //i+1而非i,因為一個只能用一次

        helper_index--;
        helper_total-=candidates[i];     
    }
}

int Partition(int store[],int first, int last)
{
	int pivot = store[last];
	int i = first - 1,temp;  //i:小於pivot的數所形成的數列的最後位置

	for (int j = first; j < last; ++j) //traverse each element
	{
		if (pivot > store[j])    //過程類似找到小於pivot的數,就把他插到小於pivot的數所形成的數列的尾端  
		{
			i++;
			temp = store[i];
			store[i] = store[j];
			store[j] = temp;
		}
	}
	//做完上述步驟,整個數列會變成 <pivot >=pivot pivot  這時要將pivot插到中間來完成 <pivot pivot >=pivot
	i++;    
	temp = store[i];
	store[i] = pivot;
	store[last] = temp;

	return i; //pivot's index
}

void quicksort(int store[],int first,int last)
{
	if(first < last)  //因為這個條件,所以剩一個或沒有的會被自動擋掉
	{
		int pivot = Partition(store,first,last); //比pivot大於等於的都在pivot右邊,比pivot小的都在左邊,pivot固定住了
		quicksort(store, first, pivot - 1); //左排
		quicksort(store, pivot + 1, last); //右排
	}
}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **store=(int **)malloc(sizeof(int *)*300), **store1;  //300我隨便另的@@
    for(int i=0;i<300;++i) //初始化,好方便之後算實際究竟有幾個
        store[i]=NULL;
    int where=0,helper_index=0,index=0,helper_total=0;
    int *helper=(int *)malloc(sizeof(int)*30), *return_arr2; // 每列最多:30/1=30個
    int *return_arr=(int *)malloc(sizeof(int)*300);
    
    quicksort(candidates, 0, candidatesSize-1);
    
    combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,&where,return_arr,helper,0);
    
    //算實際數量
    for(int i=0;i<300;++i)
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        int index = 0;
        vector<int> path;
        get_ans(candidates,target,path,index,ans);
        return ans;
    }

    void get_ans(vector<int>& candidates,int target,vector<int>& path,int index,vector<vector<int>>& ans)
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
            if(i>index && candidates[i]==candidates[i-1])
                continue;

            path.push_back(candidates[i]);
            target-=candidates[i];
            get_ans(candidates,target,path,i+1,ans);
            target+=candidates[i];
            path.pop_back();
        }
    }
};


