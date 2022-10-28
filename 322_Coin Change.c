//brute force will work when the coin system is canonical

//method 1 : naive recursive

int coinChange(int* coins, int coinsSize, int amount){
    
    // n 為金額， c1… ck為面額
    //f(n) = Min( 1 + f(n- c1), 1+ f(n-c2),…, 1+f(n-ck) )
    //有點像爬樓梯那題的概念
    
    
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

//method 2 : DP

int coinChange(int* coins, int coinsSize, int amount){
    
    // n 為金額， c1… ck為面額
    //f(n) = Min( 1 + f(n- c1), 1+ f(n-c2),…, 1+f(n-ck) )
    
    int *store=(int *)malloc(sizeof(int)*(amount+1)),min,back,coin_index; //store[i]:fewest number of coins when amount is i
    store[0]=0; //init
    //不能有以下,因為可能amount太小,導致會overflow,反正最後個個扣掉後都會到store[0]
    //for(int i=0;i<coinsSize;++i)
    //    store[coins[i]]=1;
    for(int i=1;i<amount+1;++i)
    {
        int min=10001;
        for(int j=0;j<coinsSize;++j) //扣掉各種coin來嘗試看看
        {
            coin_index=i-coins[j];
            if(coin_index>=0&&store[coin_index]!=-1) //-1:cannot be made up by any combination of the coins
            {
                min=min>(store[coin_index]+1)?store[coin_index]+1:min;
            }
        }
        store[i]=(min==10001)?-1:min; //選最小的,都不行的話,則為-1(cannot be made up by any combination of the coins)
    }
    
    back=store[amount]; //替代掉答案
    free(store);
    return back;
}
