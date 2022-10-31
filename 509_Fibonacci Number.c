//method 1 : DP
int fib(int N){
    
    if(N==0)
        return 0;
    if(N==1)
        return 1;
    
    int *store=(int *)malloc(sizeof(int)*(N+1)),back; //store[i]:F(i)
    
    store[0]=0;
    store[1]=1;
    for(int i=2;i<=N;++i)
        store[i]=store[i-1]+store[i-2];
    
    back=store[N];
    free(store);
    return back;
}

//method 2
int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0; //a:fib(i-2) b:fib(i-1) c:fib(i)
        for(int i = 2; i <= N; ++i)
        {
            c = a + b; 
            a = b;
            b = c;
        }
        return c;
    }
