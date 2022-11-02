//只能用DP,單純的遞迴會超時

int uniquePaths(int m, int n){
    
    //uniquePaths(m,n)=uniquePaths(m-1,n)+uniquePaths(m,n-1)
    
    int store[m+1][n+1];  //store[i][j]:uniquePaths(i,j)
    
    for(int i=1;i<=m;++i) //row
        store[i][1]=1;
    for(int i=1;i<=n;++i)  //column
        store[1][i]=1;
    
    for(int i=2;i<=m;++i)
    {
        for(int j=2;j<=n;++j)
            store[i][j]=store[i-1][j]+store[i][j-1];
    }
    
    return store[m][n];
}
