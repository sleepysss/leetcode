char* capitalizeTitle(char* title) {


    for(int i=0;;)
    {
        //數目前word的長度
        int count=0;
        for(int j=i;(title[j]!=' ')&&(title[j]!='\0');j++)
            count++;

        if(count<=2)
        {
            for(int j=0;j<count;++j)
            {
                if(title[i+j]>='A'&&title[i+j]<='Z')
                    title[i+j]=title[i+j]-'A'+'a';
            }
        }
        else
        {
            //第一個
            if(title[i]>='a'&&title[i]<='z')
                title[i]=title[i]-'a'+'A';
            //剩下的
            for(int j=1;j<count;++j)
            {
                if(title[i+j]>='A'&&title[i+j]<='Z')
                    title[i+j]=title[i+j]-'A'+'a';
            }
        }
        i=i+count;
        if(title[i]=='\0')
            return title;
        else
            i++;
    }
    
}
