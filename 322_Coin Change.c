//method 1 : 

int coinChange(int* coins, int coinsSize, int amount){
    
    // n 為金額， c1… ck為面額
    //f(n) = Min( 1 + f(n- c1), 1+ f(n-c2),…, 1+f(n-ck) )
    //有點想爬樓梯那題的概念
    
    
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
