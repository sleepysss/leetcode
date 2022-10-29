int climbStairs(int n){
    //費氏數列  
    //因为每次只能爬1或2步，那么爬到第n层的方法要么是从第 n-1 层一步上来的，要不就是从 n-2 层2步上来的
  
    int *store=(int *)malloc(sizeof(int)*(n+1)),back;
    store[0]=1;
    store[1]=1;
    
    for(int i=2;i<n+1;++i)
        store[i]=store[i-1]+store[i-2];
    
    back=store[n];
    free(store);
    return back;
}
