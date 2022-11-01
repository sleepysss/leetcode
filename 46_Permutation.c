//method 1-a

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **store;

void per(int *nums,bool visit[],int current,int* count,int numsSize,int temp[]) //using backtracking
{
    if(current==numsSize-1)
    {
        for(int i=0;i<numsSize;++i)
            store[(*count)][i]=temp[i];
        (*count)++;
    }
    for(int i=0;i<numsSize;++i)
    {   
        if(!visit[i])
        {
            temp[current+1]=nums[i];
            visit[i]=true;
            per(nums,visit,current+1,count,numsSize,temp);
            temp[current+1]=0; //revert
            visit[i]=false;  //revert
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int factional=1;
    for(int i=1;i<=numsSize;++i)
        factional*=i;
    
    int count=0; //where does new elemrnt need to store in return's 2d array
    store=(int **)malloc(factional*sizeof(int*));
    for(int i=0;i<factional;++i)
        store[i]=(int *)malloc(sizeof(int)*numsSize);
    
    bool *visit=(bool *)malloc(sizeof(bool)*numsSize);  //each element visit or not
    for(int i=0;i<numsSize;++i)
        visit[i]=0;
    
    int *temp=(int *)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;++i)
        temp[i]==0;
    
    *returnSize=factional;
    *returnColumnSizes=(int *)malloc(sizeof(int)*factional);  //need returnColumnSizes because we dont know each column's size ,in main,this is an int* or int[],which each index
    for(int i=0;i<factional;++i)                              //index store each column's size
        (*returnColumnSizes)[i]=numsSize;
    per(nums,visit,-1,&count,numsSize,temp);
    return store;
}



//method 1-b

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int count_num(int num) //Factorial
{
    int store=1;
    for(int i=1;i<=num;++i)
        store*=i;
    return store;
}

void permutation_helper(int *helper,int count,int *visited,int **store,int *where,int *numsSize,int *nums)  //where 放到store的哪了,count:第幾層
{
    if(count==numsSize)
    {
        //把helper內的東西填入store中
        for(int i=0;i<numsSize;++i)
        {
            store[(*where)][i]=helper[i];
        }
        (*where)++;
        return;
    }
    count++; //next level
    for(int i=0;i<numsSize;++i)
    {
        if(!visited[i])
        {
            //做選擇
            helper[count-1]=nums[i]; //加入候選解
            visited[i]=1;
            
            permutation_helper(helper,count,visited,store,where,numsSize,nums);
            
            //撤銷選擇
            visited[i]=0;
            //helper[count-1]=0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int num=count_num(numsSize),where=0;
    int *helper=(int *)malloc(sizeof(int)*numsSize); //存路徑
    int *visited=(int *)malloc(sizeof(int)*numsSize); //visit or not
    for(int i=0;i<numsSize;++i)
        visited[i]=0;
    
    int **store=(int **)malloc(sizeof(int *)*num);
    for(int i=0;i<num;++i)
        store[i]=(int *)malloc(sizeof(int)*numsSize);
    
    permutation_helper(helper,0,visited,store,&where,numsSize,nums);
    
    int *ptr=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;++i)
        ptr[i]=numsSize;
    *returnColumnSizes=ptr;
    *returnSize=num;
    
    return store; 
}

//method 2

int count_num(int num) //Factorial
{
    int store=1;
    for(int i=1;i<=num;++i)
        store*=i;
    return store;
}

void permutation_helper(int *nums,int k,int j,int **store,int *where,int numsSize)  
{
    int temp;
    if(k==j)
    {
        for(int i=0;i<numsSize;++i)
        {
            store[(*where)][i]=nums[i];
        }
        (*where)++;
        return;
    }
    
    for(int i=k;i<=j;++i)
    {
        temp=nums[i];
        nums[i]=nums[k];
        nums[k]=temp;
        
        
        permutation_helper(nums,k+1,j,store,where,numsSize);
        
        temp=nums[i];
        nums[i]=nums[k];
        nums[k]=temp;  
    } 
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int num=count_num(numsSize),where=0;
    
    int **store=(int **)malloc(sizeof(int *)*num);
    for(int i=0;i<num;++i)
        store[i]=(int *)malloc(sizeof(int)*numsSize);
    
    permutation_helper(nums,0,numsSize-1,store,&where,numsSize);
    
    int *ptr=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;++i)
        ptr[i]=numsSize;
    *returnColumnSizes=ptr;
    *returnSize=num;
    
    return store; 
}

