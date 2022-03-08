/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **store;

void per(int *nums,bool visit[],int current,int* count,int numsSize,int temp[])
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
            temp[current+1]=0;
            visit[i]=false;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int factional=1;
    for(int i=1;i<=numsSize;++i)
        factional*=i;
    int count=0;
    store=(int **)malloc(factional*sizeof(int*));
    for(int i=0;i<factional;++i)
        store[i]=(int *)malloc(sizeof(int)*numsSize);
    bool *visit=(bool *)malloc(sizeof(bool)*numsSize);
    for(int i=0;i<numsSize;++i)
        visit[i]=0;
    int *temp=(int *)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;++i)
        temp[i]==0;
    *returnSize=factional;
    *returnColumnSizes=(int *)malloc(sizeof(int)*factional);
    for(int i=0;i<factional;++i)
        (*returnColumnSizes)[i]=numsSize;
    per(nums,visit,-1,&count,numsSize,temp);
    return store;
}
