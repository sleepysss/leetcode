//naive recursive
int numDecodings(char * s){
    
    //226 = 取一個+numDecodings("26")  +  取兩個+numDecodings("6")
    
    if(!s[0])
        return 1;
    if(s[0]=='0') //"06"
        return 0;
    if(!s[1])
        return 1;

    int x=numDecodings(s+1);
    
    if(s[0]=='1'||(s[0]=='2'&&s[1]<'7')) //介於1~26的話可一次取兩個
        x+=numDecodings(s+2);
    return x;
}

//DP : bottom-up

int numDecodings(char * s){
    
    int i;
    char *ptr;
    
    for(i=0;s[i]!='\0';++i); //count lehgth
    
    int *store=(int *)malloc(sizeof(int)*(i+1));
    
    //ex: for "226"
    //store[0] "226"的numDecodings數
    //store[1] "26"的numDecodings數
    //store[2] "6"的numDecodings數
    //store[3] ""的numDecodings數
    
    //226 = 取一個+numDecodings("26")  +  取兩個+numDecodings("6") ,所以從後面把array建構起來
    
    //bottom up
    store[i]=1;
    for(i=i-1;i>=0;--i)
    {
        ptr=s+i;//基準點(目前字串的頭)
        if(ptr[0]=='0')
            store[i]=0;
        else if(!ptr[1])
            store[i]=1;
        else
        {
            store[i]=store[i+1];
            if(ptr[0]=='1'||(ptr[0]=='2'&&ptr[1]<'7'))
                store[i]+=store[i+2]; 
        }
    }
    return store[0];
}
