/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int partition(int **intervals,int first,int last)
{
    int pivot=intervals[last][0];
    int i=first-1,temp1,temp2;
    
    for(int j=first;j<last;++j)
    {
        if(intervals[j][0]<pivot)
        {
            i++;
            temp1=intervals[j][0];
            temp2=intervals[j][1];
            intervals[j][0]=intervals[i][0];
            intervals[j][1]=intervals[i][1];
            intervals[i][0]=temp1;
            intervals[i][1]=temp2;
        }
    }
    i++;
    temp1=intervals[last][0];
    temp2=intervals[last][1];
    intervals[last][0]=intervals[i][0];
    intervals[last][1]=intervals[i][1];
    intervals[i][0]=temp1;
    intervals[i][1]=temp2;
    
    return i;
}

void quicksort(int **intervals,int first,int last)
{
    
    if(first<last)
    {
        int pivot=partition(intervals,first,last);
        quicksort(intervals,pivot+1,last);    
        quicksort(intervals,first,pivot-1);
    }
}



int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    quicksort(intervals,0,intervalsSize-1);
    
    int **store=(int **)malloc(sizeof(int *)*10000);
    *returnSize=1;
    int *ptr=(int *)malloc(sizeof(int)*2);
    store[0]=ptr;
    store[0][0]=intervals[0][0];
    store[0][1]=intervals[0][1];
    
    for(int i=1;i<intervalsSize;++i)
    {
        if(store[(*returnSize)-1][1]>=intervals[i][0])  //[1,5],[2,4]
            store[(*returnSize)-1][1]=intervals[i][1]>store[(*returnSize)-1][1]?intervals[i][1]:store[(*returnSize)-1][1];
        else  //[1,2],[4,5]
        {
            (*returnSize)++;
            store[(*returnSize)-1]=(int *)malloc(sizeof(int)*2);
            store[(*returnSize)-1][0]=intervals[i][0];
            store[(*returnSize)-1][1]=intervals[i][1];
        }
    }
    
    //main function有個int *是returnColumnSize,而這裡的 int** returnColumnSizes是那個東西的address
    //所以下面一行的*returnColumnSizes就是幫main的那個把一個int array指向他
    //而那個array會記錄col 0 的大小,col 1 的大小...
    //概念上和int *returnSize有點像,只是從變數變成array
    ptr=(int *)malloc(sizeof(int)*(*returnSize));  

    for(int i=0;i<(*returnSize);++i)
        ptr[i]=2;
    
    *returnColumnSizes=ptr;
    
    //char* q = realloc(p,2048);
    //1.如果 當前連續記憶體塊足夠 realloc 的話，只是將p所指向的空間擴大，並返回p的指標地址。這個時候 q 和 p 指向的地址是一樣的。
    //2.如果 當前連續記憶體塊不夠長度，再找一個足夠長的地方，分配一塊新的記憶體，q，並將 p指向的內容 copy到 q，返回 q。並將p所指向的記憶體空間刪除。
    //這樣也就是說 realloc 有時候會產生一個新的記憶體地址有的時候不會。所以在分配完成後。我們需要判斷下 p 是否等於 q。並做相應的處理。
    //這裡有點要注意的是要避免 p = realloc(p,2048); 這種寫法。有可能會造成 realloc 分配失敗後，p原先所指向的記憶體地址丟失。
    int **store1=realloc(store,sizeof(int *)*(*returnSize));
    
    return store1;
}




//method 2


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    const int *arr1 = *(const int **)a;
    const int *arr2 = *(const int **)b;

    if(arr1[0]!=arr2[0])
        return arr1[0]-arr2[0];
    else
        return arr1[1]-arr2[1];
}



int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
    //intervals = [[1,3],[2,6],[8,10],[15,18]]
    //intervalsSize: interval的長度 4
    //intervalsColSize: interval中每個col的長度 2 2 2 2
    //int * returnSize之所以是*,因為main裡面有一個int *returnSize
    //int** returnColumnSizes 之所以是**,因為我們要修改他main function中的 int *returnColumnSize指的address
    //且 returnColumnSize是每個col的大小,如同上面的intervalsColSize
    //也可*returnColumnSizes = (int *)malloc(sizeof(int) * index);
    //然後(*returnColumnSizes)[i] = 2


    int temp[10000][2];

    //array = {(int *), (int *), (int *), ... , (int *) } 所以要sizeof(int *)
    //我猜qsort的內部做法應該是直接swap int*存的address,而不會管到每一個col內的元素
    //可能只適用於malloc的(?)靜態應該不能這樣弄???
    qsort(intervals,intervalsSize,sizeof(int *),cmp); 

    int start_index=intervals[0][0],end_index=intervals[0][1]; //記目前的區間

    *returnSize=0;
    for(int i=1;i<intervalsSize;++i)
    {
        if(intervals[i][0]<=end_index) //overlap
            end_index=(intervals[i][1]>end_index)?intervals[i][1]:end_index;
        else
        {
            //舊的存起來
            temp[*returnSize][0]=start_index;
            temp[*returnSize][1]=end_index;
            (*returnSize)++; //記得要括號
            //開始一個新的
            start_index=intervals[i][0];
            end_index=intervals[i][1];
        }
    }
    //加入目前的區間
    temp[*returnSize][0]=start_index;
    temp[*returnSize][1]=end_index;
    (*returnSize)++;


    int *ptr=(int *)malloc(sizeof(int)*(*returnSize));
    int **store=(int **)malloc(sizeof(int *)*(*returnSize));
    

    for(int i=0;i<(*returnSize);++i)
    {
        store[i]=(int *)malloc(sizeof(int)*2);
        store[i][0]=temp[i][0];
        store[i][1]=temp[i][1];
        ptr[i]=2;
    }
    
    *returnColumnSizes=ptr;

    return store;
}














