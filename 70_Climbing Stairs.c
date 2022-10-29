int climbStairs(int n){
    //費氏數列  
  
    int *store=(int *)malloc(sizeof(int)*(n+1)),back;
    store[0]=1;
    store[1]=1;
    
    for(int i=2;i<n+1;++i)
        store[i]=store[i-1]+store[i-2];
    
    back=store[n];
    free(store);
    return back;
}
