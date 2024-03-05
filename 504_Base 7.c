char* convertToBase7(int num) {

    char store[100]; //佔存結果和負號
    bool neg=0;
    int index=-1;

    if(num<0)
    {
        index++;
        neg=1;
        num=-num;
        store[index]='-';
    }
    if(num==0)
    {
        char *ans=(char *)malloc(sizeof(char)*2);
        ans[0]='0';
        ans[1]='\0';
        return ans;
    }

    while(num)
    {
        index++;
        store[index]=(num%7)+'0';
        num/=7;
    }

    index++;
    store[index]='\0';

    //reverse string (因為目前的結果是反過來的)
    //正數的話:0~index-1 (index是'\0')
    //負數的話:1~index-1

    int start=neg?1:0;
    int end=index-1;

    while(start<end)
    {
        char temp=store[start];
        store[start]=store[end];
        store[end]=temp;
        start++;
        end--;
    }

    char *ans=(char *)malloc(sizeof(char)*(index+1)); //真正傳回去的

    //strcpy
    for(int i=0;i<index+1;++i)
    {
        ans[i]=store[i];
    }

    return ans;
}
