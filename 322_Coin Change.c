//method 1 : brute force (permutation) ...TLE

int coinChange(int* coins, int coinsSize, int amount){
    
    //F(amount) = F(amount - coins[i]) + 1
    
    
    int needcoin,min=10001;
    
    if(amount==0)
        return 0;
    if(amount<0)
        return -1;
    
    quicksort(coins,0,coinsSize-1);
    
    for(int i=coinsSize-1;i>=0;--i)
    {
        needcoin=coinChange(coins,coinsSize,amount-coins[i]);
        if(needcoin!=-1)
        {
            min=min>(needcoin+1)?needcoin+1:min;
        }
    }
    
    return min==10001?-1:min;
}
