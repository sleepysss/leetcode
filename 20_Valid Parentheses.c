void push(char store[],char s,int *top)
{
    store[++(*top)]=s;
}

void pop(int *top)
{
    (*top)--;
}


bool isValid(char * s){
    
    char store[10001]={NULL};
    int top=-1;
    
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            push(store,s[i],&top);
        else
        {
            if(s[i]==')')
            {
                //we cant use return in ternary opoerator , The C grammar says that 
                //the things after the '?' and the ':' must be expressions - return is not an expression, 
                //it is a statement.            

                if(top!=-1&&store[top]=='(') //there is somrthing in stack and top is symmetric parentheses
                    pop(&top);
                else
                    return false;   
            }
            else if(s[i]==']')
            {
                if(top!=-1&&store[top]=='[')
                    pop(&top);
                else
                    return false;   
            }
            else if(s[i]=='}')
            {
                if(top!=-1&&store[top]=='{')
                    pop(&top);
                else
                    return false;   
            } 
        }
    }
    if(top!=-1)  //still something in stack
        return false;
    else
        return true;
}
