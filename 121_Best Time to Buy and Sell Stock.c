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
