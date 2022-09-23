/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    
    int **store=(int **)malloc(sizeof(int *)*(intervalsSize+1)); //最多需要intervvalsSize+1個區間
    *returnSize=-1; //我把它當index,所以最後要+1
    int count=0,flag=0;
    
    //traverse intervals array來找第一個start(intervals[count][0])>newInterval[0]的index,存到count
    //把那個點之前的都加入store array中(不用像merge那題要比較因為已排好了且為non-overlapping intervals)
    //要注意邊界(注意是否traverse完了)
    while(intervalsSize>count&&intervals[count][0]<newInterval[0]) //intervalsSize>count: haven't traverse finished
    {
        (*returnSize)++;
        store[*returnSize]=(int *)malloc(sizeof(int)*2);
        store[*returnSize][0]=intervals[count][0];
        store[*returnSize][1]=intervals[count][1];
        count++;
    }
    
    //add newinterval inside store array
    if((*returnSize)!=-1&&store[*returnSize][1]>=newInterval[0]) //(*returnSize)==-1代表新的加在頭,要直接新增點
    {
        store[*returnSize][1]=store[*returnSize][1]>newInterval[1]?store[*returnSize][1]:newInterval[1];
    }
    else
    {
        (*returnSize)++;
        store[*returnSize]=(int *)malloc(sizeof(int)*2);
        store[*returnSize][0]=newInterval[0];
        store[*returnSize][1]=newInterval[1];
    }
    
    //因為intervals後半部仍為排好的,所以可以在確定脫離newinterval的範圍後用和第一步一樣的方法(這樣就不用比較了!)
    //不會脫離的情況:[[1,3],[6,9]] [2,10] (newinterval太長了(到10))
    for(int i=count;i<intervalsSize;++i)
    {
        if(store[*returnSize][1]>=intervals[i][0])
        {
            store[*returnSize][1]=store[*returnSize][1]>intervals[i][1]?store[*returnSize][1]:intervals[i][1];
        }
        else //脫離(start>store[*returnSize][1]代表脫離了,因為addinterval可能延伸原本的end或多加一格或保持原樣,即store[*returnSize][1]>=newInterval[1])
        {
            flag=1;
            count=i;
            break;
        }
    }
    
    if(flag) //脫離 or not
    {
        //把intervals的 count到最後加入store中
        for(int i=count;i<intervalsSize;++i)  
        {
            (*returnSize)++;
            store[*returnSize]=(int *)malloc(sizeof(int)*2);
            store[*returnSize][0]=intervals[i][0];
            store[*returnSize][1]=intervals[i][1];
        }
    }
    
    (*returnSize)++; //記得要加一(因為我是把它當index)
    
    int *ptr=(int *)malloc(sizeof(int)*(*returnSize));  

    for(int i=0;i<(*returnSize);++i)
        ptr[i]=2;
    
    *returnColumnSizes=ptr;
    
    int **store1=realloc(store,sizeof(int *)*(*returnSize)); //縮減
    
    return store1;
    
}
