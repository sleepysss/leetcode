char * addBinary(char * a, char * b){
    
    int count1=0,count2=0,carry=0,value_a,value_b,sum;
    
    //cal length of string
    count1=strlen(a);
    count2=strlen(b);
    
    char *store=count1>count2?(char *)malloc(sizeof(char)*(count1+2)):(char *)malloc(sizeof(char)*(count2+2)); //2:'\0' and carry(預留一bit)
    int x=count1>count2?count1:count2;
    store[x+1]='\0';
    
    //traverse from LSB to MSB
    while(count1>=1||count2>=1||carry)
    {
        //if exist then change to number
        if(count1>=1)
            value_a=a[count1-1]-'0';
        else
            value_a=0;
        
        if(count2>=1)
            value_b=b[count2-1]-'0';
        else
            value_b=0;
        
        sum=value_a+value_b+carry; //the result of that bit
        carry=sum/2;
        sum=sum%2;
        store[x]=sum+'0';
        x--;
        count1--;
        count2--;
    }
    if(x==0) //no carry
        return store+1;  
    else
        return store;
}
