//method 1: brute force ...TLE

int numTrees(int n){
    if(!n)
        return 1;
    if(n==1)
        return 1;
    else
    {
        int count=0;
        //每個點都當root,看左右子樹有幾個點再相乘(排列組合)
        for(int i=1;i<=n;++i)
        {
            count+=numTrees(i-1)*numTrees(n-i);
        }
        return count;
    } 
}

//method2: DP

int numTrees(int n){
    
    int *store=(int *)malloc(sizeof(int)*(n+1));
    int count;
    
    store[0]=1;
    store[1]=1;
    
    for(int i=2;i<=n;++i)
    {
        count=0;
        for(int j=1;j<=i;++j)
            count+=store[j-1]*store[i-j];
        store[i]=count;
    }
    
    count=store[n];
    free(store);
    return count;
}

