int MAX(int a,int b)
{
    return a>b?a:b;
}

int longestCommonSubsequence(char * text1, char * text2){

    int len1=0,len2=0;

    for(int i=0;text1[i]!='\0';++i)
        len1++;
    for(int i=0;text2[i]!='\0';++i)
        len2++;
    
    int **store=(int **)malloc(sizeof(int *)*(len2+1));
    for(int i=0;i<len2+1;++i)
        store[i]=(int *)malloc(sizeof(int)*(len1+1));

    //base case
    for(int i=0;i<len2+1;++i) //vertical
        store[i][0]=0;
    for(int i=0;i<len1+1;++i) //horizon
        store[0][i]=0;

    //逐列   
    for(int i=1;i<len2+1;++i)
    {
        for(int j=1;j<len1+1;++j)
        {
            if(text2[i-1]==text1[j-1])
                store[i][j]=1+store[i-1][j-1];
            else
                store[i][j]=MAX(store[i-1][j],store[i][j-1]);
        }
    }

    int longest=store[len2][len1];

    for(int i=0;i<len2+1;++i)
        free(store[i]);
    free(store);

    return longest;
}
