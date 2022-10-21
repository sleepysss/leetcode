//method 1 : brute force...TLE
int maxProfit(int* prices, int pricesSize){
    
    int max=0;
    
    for(int i=0;i<pricesSize;++i)
    {
        for(int j=i+1;j<pricesSize;++j)
        {
            max=max>(prices[j]-prices[i])?max:prices[j]-prices[i];
        }
    }
    return max;
}

//method 2 : DP
int maxProfit(int* prices, int pricesSize){
    
    //核心想法:單一元素最大獲利 = 目前價錢 - 前面出現的最低價格
    //store[i] 0到i的最低價格
    int *store=(int *)malloc(sizeof(int)*pricesSize);
    
    store[0]=prices[0];
    int max=0;
    
    for(int i=1;i<pricesSize;++i)
    {
        max=max>(prices[i]-store[i-1])?max:prices[i]-store[i-1];
        store[i]=store[i-1]>prices[i]?prices[i]:store[i-1];
    }
    return max;
}
