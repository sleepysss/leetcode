//法1

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



//法2

bool isPalindrome(char* s) {

    int left=0,right=strlen(s)-1;
    
    //left<right&&

    while(left<right) //迴文是對稱的,所以只要比一半就好 ABCBA
    {
        if(!((s[left]>='a'&&s[left]<='z')||(s[left]>='A'&&s[left]<='Z'||(s[left]>='0'&&s[left]<='9')))) //非英文或數字
        {
            left++;
        }
        else if(!((s[right]>='a'&&s[right]<='z')||(s[right]>='A'&&s[right]<='Z'||(s[right]>='0'&&s[right]<='9'))))
        {
            right--;
        }
        else //可以比了
        {
            if(s[left]>='A'&&s[left]<='Z')
                s[left]=s[left]-'A'+'a';
            if(s[right]>='A'&&s[right]<='Z')
                s[right]=s[right]-'A'+'a';

            if(s[left]!=s[right])
                return false;
        
            left++;
            right--;

        }    
    }

    return true;
}

