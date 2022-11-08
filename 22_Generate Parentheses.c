//method 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** Store;

void parenthesis(int left,int right,int num,char store[],int n,int *count) //num:現在在哪一格 ie:n=3共會有7格
{
    if(num==2*n-1) //插完了
    {
        store[2*n]='\0';
        strcpy(Store[(*count)++],store);
        return;
    }  
    if(left<n) //可插左括號 ie:3 pairs做多會有3個左括號
    {
        store[num+1]='('; //下一格插一個左括號
        parenthesis(left+1,right,num+1,store,n,count);
        store[num+1]=NULL; //不能影響到別人(revert back)
    }   
    if(left>right) //可插右括號
    {
        store[num+1]=')'; 
        parenthesis(left,right+1,num+1,store,n,count);
        store[num+1]=NULL;
    } 
}


char ** generateParenthesis(int n, int* returnSize){
    
    Store=(char **)malloc(sizeof(char *)*2000);
    for(int i=0;i<2000;++i)
        Store[i]=(char *)malloc(sizeof(char)*(2*n+1));
    char *temp = (char *)malloc(sizeof(char)*(2 * n + 1));
    int count=0; //看已經插到傳回去的二維array的哪裡了
    
    parenthesis(0,0,-1,temp,n,&count);
    free(temp);
    *returnSize=count;
    Store = (char **)realloc(Store, sizeof(char *) *count); //多的捨棄
    return Store;

}

//method 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void gP_helper(int n,int **store,char *helper,int helper_index,int left,int right,int *where)
{
    if(helper_index==(2*n))
    {
        helper[2*n]='\0';
        store[(*where)]=(char *)malloc(sizeof(char)*(2*n+1));
        strcpy(store[(*where)],helper);
        *where=(*where)+1;
        return;
    }

    if(left<n)
    {
        helper[helper_index]='(';
        gP_helper(n,store,helper,helper_index+1,left+1,right,where);
    }
    if(left>right)
    {
        helper[helper_index]=')';
        gP_helper(n,store,helper,helper_index+1,left,right+1,where);
    }
}

char ** generateParenthesis(int n, int* returnSize){

    int where=0;
    char **store=(char **)malloc(sizeof(char *)*3000), **store2;
    char helper[2*n+1];
    gP_helper(n,store,helper,0,0,0,&where);
    store2=realloc(store,sizeof(char *)*where);
    *returnSize=where;

    return store2;
}
