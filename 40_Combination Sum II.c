//method 1 : 和39題一樣想法,但TLE

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combinationSum2_helper(int *candidates,int candidatesSize,int target,int helper_total,int helper_index,int **store,int *where_addr,int *return_arr,int *helper,int start,int *visited) //start:可選的開始
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
        if(!visited[i])
        {
            helper[helper_index++]=candidates[i];
            helper_total+=candidates[i];
            visited[i]=1;

            combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,where_addr,return_arr,helper,i,visited);

            helper_index--;
            helper_total-=candidates[i];
            visited[i]=0;
        }
            
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
    int *visited=(int *)malloc(sizeof(int)*candidatesSize);
    for(int i=0;i<candidatesSize;++i)
        visited[i]=0;
    
    quicksort(candidates, 0, candidatesSize-1);
    
    combinationSum2_helper(candidates,candidatesSize,target,helper_total,helper_index,store,&where,return_arr,helper,0,visited);
    
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
