/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

long long count_num(int num) //Factorial
{
    long long store=1;
    for(int i=1;i<=num;++i)
        store*=i;
    return store;
}

void combine_helper(int *helper,int k,int **store,int *where,int count,int start,int end)
{
    if(count==k)
    {
        //把helper內的東西填入store中
        for(int i=0;i<k;++i)
        {
            store[(*where)][i]=helper[i];
        }
        (*where)++;
        return;
    }
    count++;
    for(int i=start;i<=end;++i)
    {
        helper[count-1]=i;
        combine_helper(helper,k,store,where,count,i+1,end);
        //helper[count-1]=0;
    }
}


int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    
    long long num=count_num(n)/(count_num(k)*count_num(n-k)),where=0;
    int *helper=(int *)malloc(sizeof(int)*k);
    int **store=(int **)malloc(sizeof(int *)*num);
    for(int i=0;i<num;++i)
        store[i]=(int *)malloc(sizeof(int)*k);
    combine_helper(helper,k,store,&where,0,1,n);
    
    
    int *ptr=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;++i)
        ptr[i]=k;
    *returnColumnSizes=ptr;
    *returnSize=num;
    
    return store; 
}
