/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){

    //look up table of words
    //共有wordsSize行
    //每一列為一個table,存某一個word中a~z出現的頻率
    int **temp=(int **)malloc(sizeof(int *)*wordsSize); 
    for(int i=0;i<wordsSize;++i)
        temp[i]=(int *)calloc(26,sizeof(int)); 

    char store[100]; //佔存ans的data
    int count=-1; //目前到store的哪個index

    //記每個word的分布
    for(int i=0;i<wordsSize;++i)
    {
        for(int j=0;words[i][j]!='\0';++j)
        {
            char c=words[i][j];
            temp[i][c-'a']+=1;
        }
    }

    //縱向看look up table
    for(int i=0;i<26;++i) //目前縱向看的字母(a~z)
    {
        int flag=0;
        for(int j=0;j<wordsSize;++j)
        {
            if(!temp[j][i]) //有人沒有某個字母
            {
                flag=1;
                break;
            }
        }
        if(flag)
            continue;

        //數幾次
        int smallest=temp[0][i];
        for(int j=1;j<wordsSize;++j)
        {
            if(temp[j][i]<smallest)
            {
                smallest=temp[j][i];
            }
        }
        
        //寫入
        for(int j=0;j<smallest;++j)
        {
            count++;
            store[count]=i+'a'; 
        }
    }

    char **ans=(char **)malloc(sizeof(char *)*(count+1));

    for(int i=0;i<=count;++i)
    {
        char *ptr=(char *)malloc(sizeof(char)*2);
        ptr[0]=store[i];
        ptr[1]='\0';
        ans[i]=ptr;
    }
    *returnSize=count+1;

    for(int i=0;i<wordsSize;++i)
        free(temp[i]);
    free(temp);

    return ans;
}
