
//把數倒過來比較
bool isPalindrome(int x){
    
    if(x<0)
        return false;
    long long total=0,mod,store=(long long)x;
    while(x!=0)
    {
        mod=x%10;
        total=total*10+mod;
        x/=10;
    }
    return store==total?true:false;
}
