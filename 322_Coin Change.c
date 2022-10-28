int partition(int *coins,int first,int end)
{
    int s=first-1,pivot=coins[end],temp;
    
    for(int i=first;i<=end;++i)
    {
        if(coins[i]<pivot)
        {
            s++;
            temp=coins[s];
            coins[s]=coins[i];
            coins[i]=temp;
        }
    }
    s++;
    temp=coins[s];
    coins[s]=coins[end];
    coins[end]=temp;
    return s;
}

void quicksort(int *coins,int first,int end)
{
    if(end>first)
    {
        int pivot=partition(coins,first,end);
        quicksort(coins,first,pivot-1);
        quicksort(coins,pivot+1,end);
    }
}


int coinChange(int* coins, int coinsSize, int amount){
    
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
