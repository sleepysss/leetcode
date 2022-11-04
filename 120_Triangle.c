//naive recursive ... TLE

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


//method 2 : DP

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
