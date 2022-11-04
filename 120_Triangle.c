//naive recursive
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
