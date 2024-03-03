char st[200000]; //stack
int top=-1;


bool isPalindrome(char * s){

    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]<='Z'&&s[i]>='A') //轉小寫
        {
            top++;
            st[top]=s[i]-'A'+'a';
        }
        else if(s[i]<='z'&&s[i]>='a')
        {
            top++;
            st[top]=s[i];
        }
        else if(s[i]<='9'&&s[i]>='0') //數字也算
        {
            top++;
            st[top]=s[i];
        }
    }


    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]<='Z'&&s[i]>='A')
        {
            char temp=s[i]-'A'+'a';
            if(temp==st[top])
            {
                top--;
            }
            else
                return false;
        }
        else if(s[i]<='z'&&s[i]>='a')
        {
            char temp=s[i];
            if(temp==st[top])
            {
                top--;
            }
            else
                return false;    
        }
        else if(s[i]<='9'&&s[i]>='0')
        {
            char temp=s[i];
            if(temp==st[top])
            {
                top--;
            }
            else
                return false;
        }
    }
    return true;
}
