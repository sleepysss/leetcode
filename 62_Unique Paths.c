//只能用DP,單純的遞迴會超時

int uniquePaths(int m, int n){
    
    int A[m+1][n+1]; //多令一格(0的省略)
    
    for(int i=0;i<m+1;++i)
        A[i][1]=1;
    for(int i=0;i<n+1;++i)
        A[1][i]=1;
    
    for(int i=2;i<m+1;++i)
    {
        for(int j=2;j<n+1;++j)
            A[i][j]=A[i-1][j]+A[i][j-1];
    }
    
    
    return A[m][n];
    
}
