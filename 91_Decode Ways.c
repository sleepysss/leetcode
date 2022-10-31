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
