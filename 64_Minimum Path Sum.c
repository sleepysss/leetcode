int min(int a,int b)
{
    return a<b?a:b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
      
    //和62題的思路一樣
    int store[gridSize+1][(*gridColSize)+1],sum; //store[i][j]:minPathSum of i*j array
    
    store[1][1]=grid[0][0];
    for(int i=2;i<=gridSize;++i)
        store[i][1]=grid[i-1][0]+store[i-1][1];
    for(int i=2;i<=(*gridColSize);++i)
        store[1][i]=store[1][i-1]+grid[0][i-1];
    
    for(int i=2;i<=gridSize;++i)
    {
        for(int j=2;j<=(*gridColSize);++j)
            store[i][j]=grid[i-1][j-1]+min(store[i-1][j],store[i][j-1]);
    }
    
    return store[gridSize][(*gridColSize)];
}
