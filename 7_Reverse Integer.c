int reverse(int x){

    //mod(%)可取尾數 搭配除法即可反轉        -5%10=-5
    
    long long total=0,mod;  
   
    while(x!=0)
    {
        mod=x%10;
        if(total>(INT_MAX/10)||total<(INT_MIN/10))
            return 0;
        if(total==(INT_MAX/10)&&mod>7)
            return 0;
        if(total==(INT_MIN/10)&&mod>8)
            return 0;
        total=total*10+mod;
        x/=10;    
    }
    return total;
    
}
