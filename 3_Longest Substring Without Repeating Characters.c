//想法:只要當前判斷的字元不存在於建立的陣列中，即將該字元加入此陣列；如果這個字元已經存在陣列中，則一直刪除陣列開頭的值，直到當前判斷的字元不存在於陣列中為止。

int lengthOfLongestSubstring(char * s){
    int store[128]={0},i=0,ans=0;  //store:ascii table 
    int start=0;
    
    while(s[i])
    {
        store[s[i]]++;
        while(store[s[i]]>1)  //have more than once
        {
            store[s[start]]--;
            start++;  
        }
        if((i-start+1)>ans)
            ans=i-start+1;
        i++; 
    }
    return ans;
}
