//method 1 : naive recursive(下到上) ... TLE

int min(int a,int b)
{
    return a>b?b:a;
}

int minimumTotal_helper(int **triangle,int triangleSize,int start_col_index)
{
    if(triangleSize==1)
        return triangle[0][start_col_index];

    return triangle[0][start_col_index]+min(minimumTotal_helper(triangle+1,triangleSize-1,start_col_index),minimumTotal_helper(triangle+1,triangleSize-1,start_col_index+1));
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    return minimumTotal_helper(triangle,triangleSize,0);
}


//method 2 : DP(下到上)

int min(int a,int b)
{
    return a>b?b:a;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int store[triangleSize][triangleColSize[triangleSize-1]],back; //store[i][j]=minmumTotal(triangle's head=[i,j])

    //init
    for(int i=0;i<triangleColSize[triangleSize-1];++i)
        store[triangleSize-1][i]=triangle[triangleSize-1][i];  //最下面一列先設為各自的數字

    for(int i=triangleSize-2;i>=0;--i)
    {
        for(int j=0;j<=i;++j)
        {
            store[i][j]=triangle[i][j]+min(store[i+1][j],store[i+1][j+1]);
        }
    }

    return store[0][0];
}


//method 3 : DP(上到下)

int findmin(int a,int b)
{
    return a>b?b:a;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int store[triangleSize][triangleSize],min; //store[i][j]=從最上面走到i列j行的ans

    //init(base case)
    store[0][0]=triangle[0][0];

    for(int i=1;i<triangleSize;++i)
    {
        for(int j=0;j<=i;++j) //j=0為base case
        {
            if(j==i)
                store[i][j]=triangle[i][j]+store[i-1][j-1];
            else if(j==0)
                store[i][j]=triangle[i][j]+store[i-1][j];
            else
                store[i][j]=triangle[i][j]+findmin(store[i-1][j],store[i-1][j-1]);
        }
    }
    //求最後一列最小的
    min=store[triangleSize-1][0];
    for(int i=1;i<triangleSize;++i)  //triangleSize 和 triangleColSize[triangleSize-1] 一樣大小
    {
        if(store[triangleSize-1][i]<min)
            min=store[triangleSize-1][i];
    }
    return min;
}
