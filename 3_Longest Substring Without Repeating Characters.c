//想法:只要當前判斷的字元不存在於建立的陣列中，即將該字元加入此陣列；如果這個字元已經存在陣列中，則一直刪除陣列開頭的值，直到當前判斷的字元不存在於陣列中為止。
//即:維護一個滑動窗口(start~i)裡面不能有重複的元素

int lengthOfLongestSubstring(char * s){
    int store[128]={0},i=0,ans=0;  //store:ascii table的值出現次數
    int start=0;
    
    while(s[i])
    {
        store[s[i]]++;
        while(store[s[i]]>1)  //have more than once  有重複,縮小window
        {
            store[s[start]]--;
            start++;  
        }
        if((i-start+1)>ans) //sliding window的長度和當前最大的長度比較
            ans=i-start+1;
        i++; 
    }
    return ans;
}




//brute force:對每一個s中的char都去嘗試(以他當開頭(的字串)),直到碰到一樣的,並且去比較長度

int lengthOfLongestSubstring(char * s){
    int store[128]={0},i=0,j,ans=0,count;  //ascii 
    
    while(s[i])
    {
        j=i;
        count=0;
        for(int i=0;i<128;++i)
            store[i]=0;
        while(s[j])
        {
            store[s[j]]++;
            if(store[s[j]]>1) //same
                break;
            count++;
            j++;
        }
        if(count>ans) //跟現在最大的比
            ans=count;
        i++;
    }
    return ans;
}

int lengthOfLongestSubstring(char * s){
    
    int ascii[128]={0},count=0,max_count=0;
    char *ptr1=s, *ptr2;
    
    while((*ptr1)!='\0')
    {
        for(int i=0;i<128;++i)
            ascii[i]=0;
        count=0;
        ptr2=ptr1;
        while((*ptr2)!='\0')
        {
            if(ascii[*ptr2])
                break;
            ascii[*ptr2]++;
            count++;
            ptr2++;
        }
        
        max_count=max_count>count?max_count:count;
        ptr1++;
    }
    return max_count;
}
