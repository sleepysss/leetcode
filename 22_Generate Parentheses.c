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
