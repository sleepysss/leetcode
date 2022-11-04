int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){

    //store[i][j]=uniquePathsWithObstacles((i+1)*(j+1))
    int store[obstacleGridSize][(*obstacleGridColSize)],i; 

    //row init
    for(i=0;i<obstacleGridSize;++i)
    {
        if(obstacleGrid[i][0])
        {
            store[i][0]=0; //因為上面的過不去,所以連帶下面的全部都要設為0
            break;
        }
        else
            store[i][0]=1;
    }
    for(i=i+1;i<obstacleGridSize;++i) //break後設為0
        store[i][0]=0;

    //col init
    for(i=0;i<(*obstacleGridColSize);++i)
    {
        if(obstacleGrid[0][i])
        {
            store[0][i]=0;
            break;
        }
        else
            store[0][i]=1;
    }
    for(i=i+1;i<(*obstacleGridColSize);++i)
        store[0][i]=0;

    
    for(i=1;i<obstacleGridSize;++i)
    {
        for(int j=1;j<(*obstacleGridColSize);++j)
        {
            if(obstacleGrid[i][j]==1)
            {
                store[i][j]=0; //有障礙,設為0
                continue;
            }
            store[i][j]=store[i][j-1]+store[i-1][j];
        }
    }
    
    return store[obstacleGridSize-1][(*obstacleGridColSize)-1];
}
